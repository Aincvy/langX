#include <stdio.h>
#include <string.h>
#include <sstream>
#include "../include/ExecNode.h"
#include "../include/YLlangX.h"
#include "../include/Object.h"
#include "../include/Number.h"
#include "../include/String.h"
#include "../extern/y.tab.h"
#include "../include/Allocator.h"
#include "../include/Environment.h"
#include "../include/ClassInfo.h"
#include "../include/langXObject.h"
#include "../include/langXObjectRef.h"
#include "../include/XArray.h"
#include "../include/Exception.h"

namespace langX {
	// 内存的 管理器
	Allocator m_exec_alloc;

	// 将节点的值更新到环境中
	void setValueToEnv2(const char*name, Object *val, Environment *env) {
		if (val == NULL || name == NULL || env == NULL)
		{
			printf("setValueToEnv Node Args Error. \n");
			return;
		}

		Object *obj = env->getObject(name);
		if (obj == NULL)
		{
			env->putObject(name, val->clone());
		}
		else {
			if (obj->getType() != val->getType())
			{
				printf("setValueToEnv left type not equal right.\n");
				return;
			}
			obj->update(val);
		}
	}

	/*
	将节点的值更新到当前环境中
	*/
	void setValueToEnv(const char*name, Object *val) {
		setValueToEnv2(name, val, getState()->getCurrentEnv());
	}

	/*
	  执行这个节点的所有子节点
	*/
	void doSubNodes(Node *n) {
		if (n == NULL)
		{
			return;
		}

		for (int i = 0; i < n->opr_obj->op_count; i++)
		{
			Node *run = n->opr_obj->op[i];
			if (run == NULL)
			{
				continue;
			}

			// 不继承 suffix 状态
			bool flag = run->state.isSuffix;
			run->state = n->state;   //状态继承
			run->state.isSuffix = flag;

			__execNode(run);
			if (run->state.isBreak || run->state.isReturn)
			{
				n->state.isBreak = run->state.isBreak;
				n->state.isReturn = run->state.isReturn;
				return;
			}
		}
	}

	// 做后缀操作符的 工作
	void doSuffixOperation(Node *n) {
		if (n == NULL)
		{
			return;
		}

		if (n->type == NODE_OPERATOR)
		{
			for (int i = 0; i < n->opr_obj->op_count; i++)
			{
				doSuffixOperation(n->opr_obj->op[i]);
			}
		}
		else if (n->type == NODE_VARIABLE && n->postposition != NULL)
		{
			setValueToEnv(n->var_obj->name, n->postposition);
			m_exec_alloc.free(n->postposition);
			n->postposition = NULL;
		}
	}

	void doSuffixOperationArgs(XArgsList *args) {
		if (args == NULL)
		{
			return;
		}

		for (int i = 0; i < args->index; i++)
		{
			doSuffixOperation(args->args[i]);
		}
	}

	// 状态继承， n 的所有子节点都会继承n的状态
	void stateExtends(Node *n) {
		if (n == NULL)
		{
			return;
		}

		for (int i = 0; i < n->opr_obj->op_count; i++)
		{
			n->opr_obj->op[i]->state = n->state;
		}
	}

	// 将 n 及 n 下的所有子节点 的状态更新为在循环内
	void stateInLoop(Node *n) {
		if (!n)
		{
			return;
		}

		n->state.in_loop = true;

		if (n->type == NODE_OPERATOR)
		{
			for (int i = 0; i < n->opr_obj->op_count; i++)
			{
				stateInLoop(n->opr_obj->op[i]);
			}
		}

	}

	//  释放 n 及 n 下的所有节点的参数列表内存
	void freeAllArgList(Node *n) {
		if (!n)
		{
			return;
		}
		if (n->state.in_func)
		{
			return;
		}

		if (n->type == NODE_OPERATOR)
		{
			if (n->opr_obj->opr == FUNC_CALL)
			{
				if (n->ptr_u != NULL)
				{
					freeArgsList((ArgsList*)n->ptr_u);
					n->ptr_u = NULL;
				}
			}

			for (int i = 0; i < n->opr_obj->op_count; i++)
			{
				freeAllArgList(n->opr_obj->op[i]);
			}
		}

	}

	//递归释放节点值的内存, 如果节点是 一个获得数组元素的节点， 同样释放 indexNode 节点的值内存
	void recursiveFreeNodeValue(Node *n) {

		if (n == NULL)
		{
			return;
		}

		if (n->value != NULL)
		{
			m_exec_alloc.free(n->value);
			n->value = NULL;
		}

		if (n->type == NODE_ARRAY_ELE)
		{
			Node * t = n->arr_obj->indexNode;
			if (t != NULL && t->value != NULL)
			{
				m_exec_alloc.free(t->value);
				t->value = NULL;
			}
		}

		if (n->type == NODE_OPERATOR)
		{
			for (int i = 0; i < n->opr_obj->op_count; i++)
			{
				recursiveFreeNodeValue(n->opr_obj->op[i]);
			}
		}

	}

	/*
	  释放当前节点的子节点的值 内存
	*/
	void freeSubNodes(Node *n) {
		if (n == NULL)
		{
			return;
		}

		if (n->type != NODE_OPERATOR)
		{
			return;
		}

		for (int i = 0; i < n->opr_obj->op_count; i++)
		{
			if (n->opr_obj->op[i] == NULL)
			{
				continue;
			}

			//printf("freeSubNodes: %d\n" , i);
			m_exec_alloc.free(n->opr_obj->op[i]->value);
			n->opr_obj->op[i]->value = NULL;
		}
	}



	/* 如果这个变量不存在， 则new 一个放上去
	   并且会放到当前的环境里面
	   调用这个函数之后 会强制改写 left->value 的值

	   0730 赋值给左值的值为 放入 Environment 里面的值的克隆
	   0820 这个函数只会保证 左节点存在值， 并且值得类型和 右类型一样  这个函数在左值的产生环境中进行操作
	*/
	void checkVarValue(Node *left, ObjectType rightType) {
		if (left == NULL)
		{
			return;
		}

		// 不是变量，也不是this 操作  就不做任何处理
		if (left->type != NODE_VARIABLE && !(left->type == NODE_OPERATOR && left->opr_obj->opr == THIS))
		{
			return;
		}
		if (left->value != NULL)
		{
			// left 的value 是有值的
			if (left->value->getType() != rightType)
			{
				// 类型不一样
				// 先不管 left 原来指向的值
				Object *obj = left->value;
				Object *t = m_exec_alloc.allocate(rightType);
				t->setEmergeEnv(obj->getEmergeEnv());
				obj->getEmergeEnv()->putObject(left->var_obj->name, t);
				left->value = t->clone();
			}

			return;
		}
		if (getState()->getCurrentEnv()->isDead())
		{
			return;
		}

		Object *obj = getState()->getObject(left->var_obj->name);
		if (obj == NULL)
		{
			// 左值没声明过, 那么左值的产生环境就为 当前环境
			obj = m_exec_alloc.allocate(rightType);
			obj->setEmergeEnv(getState()->getCurrentEnv());
			getState()->putObject(left->var_obj->name, obj);
		}
		else {
			//  左值声明过
			if (obj->getType() != rightType)
			{
				Object *t = m_exec_alloc.allocate(rightType);
				// 变量的产生环境不变
				t->setEmergeEnv(obj->getEmergeEnv());
				obj->getEmergeEnv()->putObject(left->var_obj->name, t);

				// 释放掉原值   0820  上面那条 putObject 语句执行结束之后， 好像就访问不到 obj 了 以后需要查看是为什么 TODO 
				// 上述语句会调用 langXObject::setMember  ，这个函数会检查类型， 如果类型不一致， 会释放掉原有内存
				//m_exec_alloc.free(obj);

				// 赋值到新值
				obj = t;
			}
		}

		left->value = obj->clone();
	}

	/* 检测一下节点是否存在 值， 如果不存在， 则运算他 */
	void checkValue(Node * node) {
		if (node == NULL)
		{
			return;
		}

		if (node->value == NULL)
		{
			__execNode(node);
		}
	}

	//  尝试吧这个节点的 值 转换成一个 布尔值。
	// 如果这个节点并没有被运算， 则会运算这个节点
	// 判断之后， 并不会释放这个节点的内存
	bool __tryConvertToBool(Node *n) {
		if (n == NULL)
		{
			return false;
		}

		checkValue(n);
		if (n->value == NULL)
		{
			return false;
		}

		return n->value->isTrue();
	}

	// +  
	// 操作结果， 会将结果存储在当前节点中 
	void __exec43(Node *n) {
		doSubNodes(n);

		Node *n1 = n->opr_obj->op[0];
		Node *n2 = n->opr_obj->op[1];

		if (n1->value == NULL || n2->value == NULL)
		{
			getState()->throwException(newArithmeticException("value is null on opr '+'!")->addRef());
			freeSubNodes(n);
			return;
		}

		// 子节点的值是为了计算当前结点的值， 如果当前结点的值 计算 结束， 则释放掉子节点值得内存
		// 子节点的值如果是一个常量， 则该值是一个 new 的内存， 如果是一个变量， 则该值是一个 clone 出现的对象
		Object * left = n1->value;
		Object * right = n2->value;

		if (left->getType() == NUMBER && right->getType() == NUMBER)
		{
			n->value = m_exec_alloc.allocateNumber(((Number*)left)->getDoubleValue() + ((Number*)right)->getDoubleValue());
		}
		else if ((left != NULL && left->getType() == STRING) || (right != NULL  && right->getType() == STRING))
		{
			// 字符串拼接 
			std::stringstream ss;
			if (left == NULL)
			{
				ss << "null";
			}
			else
				if (left->getType() == STRING)
				{
					ss << ((String*)left)->getValue();
				}
				else if (left->getType() == NUMBER)
				{
					ss << ((Number*)left)->getDoubleValue();
				}
				else if (left->getType() == NULLOBJECT)
				{
					ss << "null";
				}
				else if (left->getType() == OBJECT)
				{
					ss << "object";
				}
				else {
					printf("error type in do add opr! \n");
					return;
				}

				if (right == NULL)
				{
					ss << "null";
				}
				else
					if (right->getType() == STRING)
					{
						ss << ((String*)right)->getValue();
					}
					else if (right->getType() == NUMBER)
					{
						ss << ((Number*)right)->getDoubleValue();
					}
					else if (right->getType() == NULLOBJECT)
					{
						ss << "null";
					}
					else if (right->getType() == OBJECT)
					{
						ss << "object";
					}
					else {
						printf("error type in do add opr! \n");
						return;
					}

					n->value = m_exec_alloc.allocateString(ss.str().c_str());
		}
		else {
			getState()->throwException(newArithmeticException("args type error when do opr '+' .")->addRef());
		}

		freeSubNodes(n);

		//printf("%.2f\n", ((Number*)n->value)->getDoubleValue());
	}

	// -
	void __exec45(Node *n) {
		doSubNodes(n);

		Node *n1 = n->opr_obj->op[0];
		Node *n2 = n->opr_obj->op[1];

		if (n1->value == NULL || n2->value == NULL)
		{
			getState()->throwException(newArithmeticException("value is null on opr '-'!")->addRef());
			freeSubNodes(n);
			return;
		}
		if (n1->value->getType() != NUMBER || n2->value->getType() != NUMBER)
		{
			getState()->throwException(newArithmeticException("type error on opr '-'!")->addRef());
			freeSubNodes(n);
			return;
		}

		n->value = m_exec_alloc.allocateNumber(((Number*)n1->value)->getDoubleValue() - ((Number*)n2->value)->getDoubleValue());
		freeSubNodes(n);
	}

	// *
	void __exec42(Node *n) {
		doSubNodes(n);

		Node *n1 = n->opr_obj->op[0];
		Node *n2 = n->opr_obj->op[1];

		if (n1->value == NULL || n2->value == NULL)
		{
			getState()->throwException(newArithmeticException("value is null on opr '*'!")->addRef());
			freeSubNodes(n);
			return;
		}
		if (n1->value->getType() != NUMBER || n2->value->getType() != NUMBER)
		{
			getState()->throwException(newArithmeticException("type error on opr '*'!")->addRef());
			freeSubNodes(n);
			return;
		}

		n->value = m_exec_alloc.allocateNumber(((Number*)n1->value)->getDoubleValue() * ((Number*)n2->value)->getDoubleValue());
		freeSubNodes(n);

	}

	// /
	void __exec47(Node *n) {
		doSubNodes(n);

		Node *n1 = n->opr_obj->op[0];
		Node *n2 = n->opr_obj->op[1];

		if (n1->value == NULL || n2->value == NULL)
		{
			getState()->throwException(newArithmeticException("value is null on opr '/'!")->addRef());
			freeSubNodes(n);
			return;
		}
		if (n1->value->getType() != NUMBER || n2->value->getType() != NUMBER)
		{
			getState()->throwException(newArithmeticException("type error on opr '/'!")->addRef());
			freeSubNodes(n);
			return;
		}

		double d2 = ((Number*)n2->value)->getDoubleValue();
		if (d2 == 0)
		{
			getState()->throwException(newArithmeticException("/ by zero on opr '/'!")->addRef());
			freeSubNodes(n);
			return;
		}

		n->value = m_exec_alloc.allocateNumber(((Number*)n1->value)->getDoubleValue() / d2);
		freeSubNodes(n);

	}

	// 赋值操作 = 
	void __exec61(Node *n) {
		//printf("__exec61 start\n");
		Node *left = n->opr_obj->op[0];

		langXObjectRef *objectRef = NULL;
		ArrayInfo *arrayInfo = NULL;
		if (left->type == NODE_OPERATOR)
		{
			if (left->opr_obj->opr == CLAXX_MEMBER)
			{
				__execNode(left);
				objectRef = (langXObjectRef *)left->ptr_u;
			}
			else if (left->opr_obj->opr == THIS)
			{
				__execNode(left);
			}
			else {
				//printf("left not the CLAXX_MEMBER! \n");
				getState()->throwException(newException("left not the CLAXX_MEMBER!")->addRef());
				freeSubNodes(n);
				return;
			}
		}
		else if (left->type == NODE_ARRAY_ELE)
		{
			arrayInfo = left->arr_obj;
		}
		else
			if (left->type != NODE_VARIABLE)
			{
				//printf("left not the NODE_VARIABLE\n");
				getState()->throwException(newTypeErrorException("left not the NODE_VARIABLE")->addRef());
				freeSubNodes(n);
				return;
			}

		if (getState()->getCurrentEnv()->isDead()) {
			return;
		}

		//printf("__exec61 left name: %s\n", left->var_obj->name);
		Node *right = n->opr_obj->op[1];
		//printf("right->value: %p\n", right->value);
		checkValue(right);
		if (getState()->getCurrentEnv()->isDead()) {
			return;
		}

		// 赋值操作的结果 为 右值的结果
		if (right->value == NULL)
		{
			right->value = m_exec_alloc.allocate(NULLOBJECT);
		}

		if (objectRef == NULL && arrayInfo == NULL)
		{
			checkVarValue(left, right->value->getType());
			if (getState()->getCurrentEnv()->isDead()) {
				return;
			}
			left->value->update(right->value);

			// 释放右值的内存 
			m_exec_alloc.free(right->value);
			right->value = NULL;

			// 更新值到 Environment 
			setValueToEnv2(left->var_obj->name, left->value, left->value->getEmergeEnv());

			n->value = m_exec_alloc.copy(left->value);
			// 左值是指向 Environment 内的内存的复制， 需要释放
			m_exec_alloc.free(left->value);
			left->value = NULL;
		}
		else if (arrayInfo != NULL)
		{
			Object *obj = getValue(arrayInfo->name);
			if (obj == NULL || obj->getType() != XARRAY)
			{
				getState()->throwException(newUnsupportedOperationException("left value is not array with array operator!")->addRef());
				freeSubNodes(n);
				//printf("left value is not array with array operator!\n");
				return;
			}

			int index = arrayInfo->index;
			if (arrayInfo->indexNode != NULL)
			{
				Node *t = arrayInfo->indexNode;
				__execNode(t);

				if (t->value == NULL || t->value->getType() != NUMBER)
				{
					getState()->throwException(newException("error array length!")->addRef());
					freeSubNodes(n);
					//printf("error array length !\n");
					return;
				}

				index = ((Number*)t->value)->getIntValue();
				m_exec_alloc.free(t->value);
				t->value = NULL;
			}

			XArrayRef *ref = (XArrayRef*)obj;
			ref->set(index, right->value);
			m_exec_alloc.free(right->value);
			right->value = NULL;

			n->value = m_exec_alloc.copy(right->value);
		}
		else {
			// 这里的Left 已经被执行过了   
			char * name = left->opr_obj->op[1]->var_obj->name;
			if (!objectRef->getClassInfo()->hasMember(name))
			{
				char tmp[100] = { 0 };
				sprintf(tmp, "cannot find member %s in class %s!", name, objectRef->getClassInfo()->getName());
				getState()->throwException(newNoClassMemberException(tmp)->addRef());

			}
			else {
				objectRef->setMember(name, right->value);
				n->value = m_exec_alloc.copy(right->value);
			}

			m_exec_alloc.free(right->value);
			right->value = NULL;
		}

		if (left->type == NODE_OPERATOR && left->opr_obj->opr == THIS) {
			if (left->var_obj != NULL)
			{
				free(left->var_obj);
				left->var_obj = NULL;
			}

		}

		doSuffixOperation(n);
	}

	void __execADD_EQ(Node *n) {
		doSubNodes(n);

		Node *n1 = n->opr_obj->op[0];
		Node *n2 = n->opr_obj->op[1];

		if (n1->value == NULL || n2->value == NULL)
		{
			getState()->throwException(newArithmeticException("value is null on opr '+='!")->addRef());
			freeSubNodes(n);
			return;
		}
		if (n1->value->getType() != NUMBER || n2->value->getType() != NUMBER)
		{
			getState()->throwException(newArithmeticException("type error on opr '+='!")->addRef());
			freeSubNodes(n);
			return;
		}

		n->value = m_exec_alloc.allocateNumber(((Number*)n1->value)->getDoubleValue() + ((Number*)n2->value)->getDoubleValue());

		setValueToEnv(n1->var_obj->name, n->value);

		freeSubNodes(n);
	}

	void __execSUB_EQ(Node *n) {
		doSubNodes(n);

		Node *n1 = n->opr_obj->op[0];
		Node *n2 = n->opr_obj->op[1];

		if (n1->value == NULL || n2->value == NULL)
		{
			getState()->throwException(newArithmeticException("value is null on opr '-='!")->addRef());
			freeSubNodes(n);
			return;
		}
		if (n1->value->getType() != NUMBER || n2->value->getType() != NUMBER)
		{
			getState()->throwException(newArithmeticException("type error on opr '-='!")->addRef());
			freeSubNodes(n);
			return;
		}

		n->value = m_exec_alloc.allocateNumber(((Number*)n1->value)->getDoubleValue() - ((Number*)n2->value)->getDoubleValue());

		setValueToEnv(n1->var_obj->name, n->value);

		freeSubNodes(n);
	}

	void __execMUL_EQ(Node *n) {
		doSubNodes(n);

		Node *n1 = n->opr_obj->op[0];
		Node *n2 = n->opr_obj->op[1];

		if (n1->value == NULL || n2->value == NULL)
		{
			getState()->throwException(newArithmeticException("value is null on opr '*='!")->addRef());
			freeSubNodes(n);
			return;
		}
		if (n1->value->getType() != NUMBER || n2->value->getType() != NUMBER)
		{
			getState()->throwException(newArithmeticException("type error on opr '*='!")->addRef());
			freeSubNodes(n);
			return;
		}

		n->value = m_exec_alloc.allocateNumber(((Number*)n1->value)->getDoubleValue() * ((Number*)n2->value)->getDoubleValue());

		setValueToEnv(n1->var_obj->name, n->value);

		freeSubNodes(n);
	}

	void __execDIV_EQ(Node *n) {
		doSubNodes(n);

		Node *n1 = n->opr_obj->op[0];
		Node *n2 = n->opr_obj->op[1];

		if (n1->value == NULL || n2->value == NULL)
		{
			getState()->throwException(newArithmeticException("value is null on opr '/='!")->addRef());
			freeSubNodes(n);
			return;
		}
		if (n1->value->getType() != NUMBER || n2->value->getType() != NUMBER)
		{
			getState()->throwException(newArithmeticException("type error on opr '/='!")->addRef());
			freeSubNodes(n);
			return;
		}

		double d2 = ((Number*)n2->value)->getDoubleValue();
		if (d2 == 0)
		{
			getState()->throwException(newArithmeticException("/ by zero on opr '/='!")->addRef());
			freeSubNodes(n);
			return;
		}

		n->value = m_exec_alloc.allocateNumber(((Number*)n1->value)->getDoubleValue() / ((Number*)n2->value)->getDoubleValue());

		setValueToEnv(n1->var_obj->name, n->value);

		freeSubNodes(n);
	}

	void __execBREAK(Node *n) {
		if (n == NULL)
		{
			return;
		}

		if (!n->state.in_loop && !n->state.in_switch)
		{
			getState()->throwException(newUnsupportedOperationException("invalid break stmt.")->addRef());
			//printf("无效的BREAK 语句 ");
			return;
		}

		n->state.isBreak = true;
	}

	void __execRETURN(Node *n) {
		if (n == NULL)
		{
			return;
		}

		// 不在函数内 也能使用 return 语句？
		// 回头再调整吧， 这个 无伤大雅
		if (!n->state.in_func)
		{
			getState()->throwException(newUnsupportedOperationException("invalid return stmt.")->addRef());
			//printf("无效的 return 语句");
			return;
		}

		n->state.isReturn = true;
		if (n->opr_obj->op_count <= 0)
		{
			n->value = NULL;
		}
		else {
			// 存在返回值
			Node * a = n->opr_obj->op[0];
			if (a == NULL)
			{
				n->value = NULL;
				return;
			}

			a->state.in_func = n->state.in_func;
			a->state.in_loop = n->state.in_loop;
			__execNode(a);
			n->value = a->value->clone();

			freeSubNodes(n);
		}
	}

	// 自增运算符 ++ 
	void __execINC_OP(Node *n) {
		doSubNodes(n);

		Node *n1 = n->opr_obj->op[0];

		if (n1 == NULL)
		{
			getState()->throwException(newArithmeticException("node is null on opr '++'!")->addRef());
			freeSubNodes(n);
			return;
		}

		if (n1->value == NULL)
		{
			getState()->throwException(newArithmeticException("value is null on opr '++'!")->addRef());
			freeSubNodes(n);
			return;
		}

		if (!n->state.isSuffix)
		{
			// 前缀自增
			n->value = m_exec_alloc.allocateNumber(((Number*)n1->value)->getDoubleValue() + 1);
			n1->postposition = n->value->clone();
		}
		else {
			//  后缀自增
			n->value = n1->value->clone();
			n1->postposition = m_exec_alloc.allocateNumber(((Number*)n1->value)->getDoubleValue() + 1);
		}

		freeSubNodes(n);
	}

	// 自减运算符 -- 
	void __execDEC_OP(Node *n) {
		doSubNodes(n);

		/*
		 * 后置值 被加到 变量身上， 而非 ++/-- 操作符身上了。
		 */

		Node *n1 = n->opr_obj->op[0];
		if (n1 == NULL)
		{
			getState()->throwException(newArithmeticException("node is null on opr '--'!")->addRef());
			freeSubNodes(n);
			return;
		}

		if (n1->value == NULL)
		{
			getState()->throwException(newArithmeticException("value is null on opr '--'!")->addRef());
			freeSubNodes(n);
			return;
		}

		if (!n->state.isSuffix)
		{
			// 前缀自减
			n->value = m_exec_alloc.allocateNumber(((Number*)n1->value)->getDoubleValue() - 1);
			n1->postposition = n->value->clone();
		}
		else {
			//  后缀自减
			n->value = n1->value->clone();
			n1->postposition = m_exec_alloc.allocateNumber(((Number*)n1->value)->getDoubleValue() - 1);
		}

		freeSubNodes(n);
	}


	// 分号 ;
	void __exec59(Node *n) {
		if (n == NULL)
		{
			return;
		}

		if (n->opr_obj == NULL || n->opr_obj->op_count == 0)
		{
			return;
		}

		for (size_t i = 0; i < n->opr_obj->op_count; i++)
		{
			Node *run = n->opr_obj->op[i];
			if (run == NULL)
			{
				continue;
			}
			run->state.in_func = n->state.in_func;   // state 传递
			run->state.in_loop = n->state.in_loop;
			run->state.in_switch = n->state.in_switch;
			__execNode(run);

			if (getState()->getCurrentEnv()->isDead())
			{
				freeSubNodes(n);
				return;
			}

			if (run->state.isBreak)
			{
				n->state.isBreak = true;
				break;
			}
			if (run->state.isReturn)
			{
				n->state.isReturn = true;
				if (run->value == NULL)
				{
					n->value = NULL;
				}
				else {
					n->value = run->value->clone();
				}
				break;
			}
		}

		// 遍历节点
		doSuffixOperation(n);

		freeSubNodes(n);
	}

	// 逗号表达式
	void __exec44(Node *n) {
		// 操作和 分号表达式差不多应该， 这样应该就OK了。 
		__exec59(n);
	}

	// 符号： >
	void __exec62(Node *n) {
		doSubNodes(n);


		Node *n1 = n->opr_obj->op[0];
		Node *n2 = n->opr_obj->op[1];

		if (n1->value == NULL || n2->value == NULL)
		{
			getState()->throwException(newArithmeticException("value is null on opr '>'!")->addRef());
			freeSubNodes(n);
			return;
		}
		if (n1->value->getType() != NUMBER || n2->value->getType() != NUMBER)
		{
			getState()->throwException(newArithmeticException("type error on opr '>'!")->addRef());
			freeSubNodes(n);
			return;
		}

		double a = ((Number*)n1->value)->getDoubleValue();
		double b = ((Number*)n2->value)->getDoubleValue();

		if (a > b)
		{
			n->value = m_exec_alloc.allocateNumber(1);
		}
		else {
			n->value = m_exec_alloc.allocateNumber(0);
		}

		doSuffixOperation(n);
		freeSubNodes(n);
	}

	// 大于等于
	void __execGE_OP(Node *n) {
		doSubNodes(n);


		Node *n1 = n->opr_obj->op[0];
		Node *n2 = n->opr_obj->op[1];

		if (n1->value == NULL || n2->value == NULL)
		{
			getState()->throwException(newArithmeticException("value is null on opr '>='!")->addRef());
			freeSubNodes(n);
			return;
		}
		if (n1->value->getType() != NUMBER || n2->value->getType() != NUMBER)
		{
			getState()->throwException(newArithmeticException("type error on opr '>='!")->addRef());
			freeSubNodes(n);
			return;
		}

		double a = ((Number*)n1->value)->getDoubleValue();
		double b = ((Number*)n2->value)->getDoubleValue();

		if (a >= b)
		{
			n->value = m_exec_alloc.allocateNumber(1);
		}
		else {
			n->value = m_exec_alloc.allocateNumber(0);
		}

		doSuffixOperation(n);
		freeSubNodes(n);
	}

	// 符号： <
	void __exec60(Node *n) {
		doSubNodes(n);


		Node *n1 = n->opr_obj->op[0];
		Node *n2 = n->opr_obj->op[1];

		if (n1->value == NULL || n2->value == NULL)
		{
			getState()->throwException(newArithmeticException("value is null on opr '<'!")->addRef());
			freeSubNodes(n);
			return;
		}
		if (n1->value->getType() != NUMBER || n2->value->getType() != NUMBER)
		{
			getState()->throwException(newArithmeticException("type error on opr '<'!")->addRef());
			freeSubNodes(n);
			return;
		}

		double a = ((Number*)n1->value)->getDoubleValue();
		double b = ((Number*)n2->value)->getDoubleValue();

		if (a < b)
		{
			n->value = m_exec_alloc.allocateNumber(1);
		}
		else {
			n->value = m_exec_alloc.allocateNumber(0);
		}

		doSuffixOperation(n);
		freeSubNodes(n);
	}

	// 小于等于
	void __execLE_OP(Node *n) {
		doSubNodes(n);


		Node *n1 = n->opr_obj->op[0];
		Node *n2 = n->opr_obj->op[1];

		if (n1->value == NULL || n2->value == NULL)
		{
			getState()->throwException(newArithmeticException("value is null on opr '<='!")->addRef());
			freeSubNodes(n);
			return;
		}
		if (n1->value->getType() != NUMBER || n2->value->getType() != NUMBER)
		{
			getState()->throwException(newArithmeticException("type error on opr '<='!")->addRef());
			freeSubNodes(n);
			return;
		}

		double a = ((Number*)n1->value)->getDoubleValue();
		double b = ((Number*)n2->value)->getDoubleValue();

		if (a <= b)
		{
			n->value = m_exec_alloc.allocateNumber(1);
		}
		else {
			n->value = m_exec_alloc.allocateNumber(0);
		}

		doSuffixOperation(n);
		freeSubNodes(n);
	}

	// 等于
	void __execEQ_OP(Node *n) {
		doSubNodes(n);


		Node *n1 = n->opr_obj->op[0];
		Node *n2 = n->opr_obj->op[1];

		if (n1->value == NULL || n2->value == NULL)
		{
			getState()->throwException(newArithmeticException("value is null on opr '=='!")->addRef());
			freeSubNodes(n);
			return;
		}

		if (n1->value->getType() == NUMBER && n2->value->getType() == NUMBER)
		{
			double a = ((Number*)n1->value)->getDoubleValue();
			double b = ((Number*)n2->value)->getDoubleValue();

			if (a == b)
			{
				n->value = m_exec_alloc.allocateNumber(1);
			}
			else {
				n->value = m_exec_alloc.allocateNumber(0);
			}
		}
		else if (n1->value->getType() == STRING && n2->value->getType() == STRING)
		{
			// 字符串比较
			const char * a = ((String*)n1->value)->getValue();
			const char * b = ((String*)n2->value)->getValue();

			if (strcmp(a, b) == 0)
			{
				n->value = m_exec_alloc.allocateNumber(1);
			}
			else {
				n->value = m_exec_alloc.allocateNumber(0);
			}
		}
		else {
			//printf("类型不同，无法比较");
			getState()->throwException(newArithmeticException("type error on opr '=='! only can number or string!")->addRef());
			n->value = m_exec_alloc.allocateNumber(0);
		}

		doSuffixOperation(n);
		freeSubNodes(n);
	}

	// 不等于
	void __execNE_OP(Node *n) {
		doSubNodes(n);

		Node *n1 = n->opr_obj->op[0];
		Node *n2 = n->opr_obj->op[1];

		if (n1->value == NULL || n2->value == NULL)
		{
			getState()->throwException(newArithmeticException("value is null on opr '=='!")->addRef());
			freeSubNodes(n);
			return;
		}

		if (n1->value->getType() == NUMBER && n2->value->getType() == NUMBER)
		{
			double a = ((Number*)n1->value)->getDoubleValue();
			double b = ((Number*)n2->value)->getDoubleValue();

			if (a != b)
			{
				n->value = m_exec_alloc.allocateNumber(1);
			}
			else {
				n->value = m_exec_alloc.allocateNumber(0);
			}
		}
		else if (n1->value->getType() == STRING && n2->value->getType() == STRING)
		{
			// 字符串比较
			const char * a = ((String*)n1->value)->getValue();
			const char * b = ((String*)n2->value)->getValue();

			if (strcmp(a, b) != 0)
			{
				n->value = m_exec_alloc.allocateNumber(1);
			}
			else {
				n->value = m_exec_alloc.allocateNumber(0);
			}
		}
		else {
			//printf("类型不同，无法比较");
			getState()->throwException(newArithmeticException("type error on opr '!='! only can number or string!")->addRef());
			n->value = m_exec_alloc.allocateNumber(0);
		}

		doSuffixOperation(n);
		freeSubNodes(n);
	}

	void __execOPAND(Node *n) {
		if (n == NULL)
		{
			return;
		}

		stateExtends(n);
		if (__tryConvertToBool(n->opr_obj->op[0]))
		{
			n->value = __tryConvertToBool(n->opr_obj->op[1]) ? n->value = m_exec_alloc.allocateNumber(1) : n->value = m_exec_alloc.allocateNumber(0);
		}
		else {
			n->value = m_exec_alloc.allocateNumber(0);
		}

		freeSubNodes(n);
	}

	void __execOPOR(Node *n) {
		if (n == NULL)
		{
			return;
		}

		stateExtends(n);
		if (__tryConvertToBool(n->opr_obj->op[0]))
		{
			n->value = m_exec_alloc.allocateNumber(1);
		}
		else {
			n->value = __tryConvertToBool(n->opr_obj->op[1]) ? n->value = m_exec_alloc.allocateNumber(1) : n->value = m_exec_alloc.allocateNumber(0);
		}

		freeSubNodes(n);
	}

	void __execIF(Node *n) {
		if (n == NULL)
		{
			return;
		}

		stateExtends(n);
		if (__tryConvertToBool(n->opr_obj->op[0]))
		{
			Node * a = n->opr_obj->op[1];
			if (a != NULL)
			{
				__execNode(a);
				n->state.isBreak = a->state.isBreak;
				n->state.isReturn = a->state.isReturn;

				if (a->value == NULL)
				{
					n->value = NULL;
				}
				else {
					n->value = a->value->clone();
				}
			}

		}
		else {
			if (n->opr_obj->op_count >= 3)
			{
				Node * a = n->opr_obj->op[2];
				if (a != NULL)
				{
					__execNode(a);
					n->state.isBreak = a->state.isBreak;
					n->state.isReturn = a->state.isReturn;
					if (a->value == NULL)
					{
						n->value = NULL;
					}
					else {
						n->value = a->value->clone();
					}
				}

			}
		}

		doSuffixOperation(n);
		// 清理掉 所有复制  值 占用的内存
		freeSubNodes(n);
	}

	void __execWHILE(Node *n) {
		if (n == NULL || n->opr_obj == NULL || n->opr_obj->op_count != 2)
		{
			return;
		}

		// 先执行条件 节点 ,然后判断条件 节点的值， 然后释放条件 节点的内存
		// 循环执行结束 ， 释放掉  所有节点值 的内存
		//stateExtends(n);
		// TODO 处理节点， 以及子节点的状态
		stateInLoop(n);

		Node *conNode = n->opr_obj->op[0];
		while (__tryConvertToBool(conNode))
		{
			m_exec_alloc.free(conNode->value);
			conNode->value = NULL;

			Node *run = n->opr_obj->op[1];
			if (run == NULL)
			{
				return;
			}
			__execNode(run);
			if (run->state.isBreak)
			{
				break;
			}
			if (run->state.isReturn)
			{
				n->state.isReturn = true;

				if (run->value == NULL)
				{
					n->value = NULL;
				}
				else {
					n->value = run->value->clone();
				}

				break;
			}

			// 如果当前环境为一个死亡环境， 则直接返回
			// TODO 清理内存
			if (getState()->getCurrentEnv()->isDead())
			{
				return;
			}
		}

		// 释放循环内的参数列表的内存
		if (!n->state.in_func)
		{
			// 释放
			freeAllArgList(n);
		}

		doSuffixOperation(n);
		freeSubNodes(n);
	}

	void __execFOR(Node *n) {
		if (n == NULL || n->opr_obj == NULL || n->opr_obj->op_count != 4)
		{
			return;
		}
		//stateExtends(n);
		// TODO 处理节点， 以及子节点的状态
		stateInLoop(n);

		Node *conNode = n->opr_obj->op[1];
		// 后置节点
		Node *sNode = n->opr_obj->op[2];
		for (__execNode(n->opr_obj->op[0]); __tryConvertToBool(conNode); freeSubNodes(sNode), __execNode(sNode), doSuffixOperation(sNode))
		{
			m_exec_alloc.free(conNode->value);
			conNode->value = NULL;

			Node *run = n->opr_obj->op[3];
			if (run == NULL)
			{
				continue;
			}
			run->state.in_loop = true;
			__execNode(run);
			recursiveFreeNodeValue(run);
			if (run->state.isBreak)
			{
				break;
			}
			if (run->state.isReturn)
			{
				n->state.isReturn = true;
				if (run->value == NULL)
				{
					n->value = NULL;
				}
				else {
					n->value = run->value->clone();
				}
				break;
			}

			// 如果当前环境为一个死亡环境， 则直接返回
			// TODO 清理内存
			if (getState()->getCurrentEnv()->isDead())
			{
				return;
			}

		}

		// 释放循环内的参数列表的内存
		if (!n->state.in_func)
		{
			// 释放
			freeAllArgList(n);
		}

		freeSubNodes(n);
	}

	void __execSWITCH(Node *n) {
		if (n == NULL)
		{
			return;
		}

		bool flag = true;
		Node * id_expr = n->opr_obj->op[0];
		__execNode(id_expr);
		if (id_expr->value == NULL)
		{
			getState()->throwException(newUnsupportedOperationException("null condition value in switch()!")->addRef());
			return;
		}
		//printf("switch id_expr value: %f\n" , ((Number*)id_expr->value)->getDoubleValue());

		n->state.in_switch = true;
		Node * case_list = n->opr_obj->op[1];
		//printf("case_list op_count: %d\n", case_list->opr_obj->op_count);
		for (int i = 0; i < case_list->opr_obj->op_count; i++)
		{
			// 如果当前环境为一个死亡环境， 则直接返回
			// TODO 清理内存
			if (getState()->getCurrentEnv()->isDead())
			{
				return;
			}

			Node * t = case_list->opr_obj->op[i];
			if (t == NULL)
			{
				continue;
			}

			t->state.isCaseNeedCon = n->state.isCaseNeedCon;
			t->state.in_switch = true;
			t->ptr_u = id_expr->value;
			t->switch_info.doDefault = false;
			__execNode(t);

			// 设置default 节点
			if (t->switch_info.isDefault)
			{
				n->switch_info.defaultNode = t;
			}
			else if (t->switch_info.defaultNode != NULL)
			{
				n->switch_info.defaultNode = t->switch_info.defaultNode;
			}

			if (t->switch_info.isInCase)
			{
				flag = false;
			}
			n->state.isCaseNeedCon = t->state.isCaseNeedCon;

			if (t->state.isBreak)
			{
				break;
			}
			if (t->state.isReturn)
			{
				if (t->value == NULL)
				{
					n->value = NULL;
				}
				else {
					n->value = t->value->clone();
				}
				break;
			}
		}

		if (flag && n->switch_info.defaultNode != NULL)
		{
			n->switch_info.defaultNode->switch_info.doDefault = true;
			__execNode(n->switch_info.defaultNode);
		}

		freeSubNodes(n);
	}

	void __execCASE_LIST(Node *n) {

		bool flag = true;
		for (int i = 0; i < n->opr_obj->op_count; i++)
		{
			// 如果当前环境为一个死亡环境， 则直接返回
			// TODO 清理内存
			if (getState()->getCurrentEnv()->isDead())
			{
				return;
			}

			Node * t = n->opr_obj->op[i];
			if (t == NULL)
			{
				continue;
			}

			t->state.in_switch = true;
			t->state.isCaseNeedCon = n->state.isCaseNeedCon;
			// case 语句中  ptr_u 属性保存的是 指向 switch(a)  a 的值
			t->ptr_u = n->ptr_u;
			t->switch_info.doDefault = false;
			__execNode(t);

			// 设置default 节点
			if (t->switch_info.isDefault)
			{
				n->switch_info.defaultNode = t;
			}
			else if (t->switch_info.defaultNode != NULL)
			{
				n->switch_info.defaultNode = t->switch_info.defaultNode;
			}

			if (t->switch_info.isInCase)
			{
				flag = false;
			}
			n->state.isCaseNeedCon = t->state.isCaseNeedCon;

			if (t->state.isBreak)
			{
				n->state.isBreak = true;
				break;
			}
			if (t->state.isReturn)
			{
				if (t->value == NULL)
				{
					n->value = NULL;
				}
				else {
					n->value = t->value->clone();
				}
				break;
			}
		}

		Node *defaultNode = n->switch_info.defaultNode;
		if (flag && defaultNode != NULL)
		{
			defaultNode->state.in_switch = true;
			defaultNode->switch_info.doDefault = true;
			__execNode(n->switch_info.defaultNode);
		}

		freeSubNodes(n);
	}

	void __execCASE(Node *n) {
		if (n == NULL || n->ptr_u == NULL)
		{
			return;
		}

		double a = ((Number*)n->ptr_u)->getDoubleValue();

		Node * con = n->opr_obj->op[0];
		__execNode(con);

		if (a == ((Number*)con->value)->getDoubleValue() || !n->state.isCaseNeedCon)
		{
			n->state.isCaseNeedCon = false;
			n->switch_info.isInCase = true;
			Node * t = n->opr_obj->op[1];
			if (t != NULL)
			{
				t->state.in_switch = true;
				__execNode(t);

				n->state.isBreak = t->state.isBreak;
				if (t->state.isReturn)
				{
					n->state.isReturn = true;
					if (t->value == NULL)
					{
						n->value = NULL;
					}
					else {
						n->value = t->value->clone();
					}
				}
			}

		}

		freeSubNodes(n);
	}

	void __execDeafult(Node *n) {
		//printf("\ngoin default\n");

		if (!n->switch_info.doDefault)
		{
			n->switch_info.isDefault = true;
			return;
		}

		stateExtends(n);
		__execNode(n->opr_obj->op[0]);

		freeSubNodes(n);
	}

	void __execUMINUS(Node *n) {
		if (n == NULL)
		{
			return;
		}

		doSubNodes(n);
		Node *n1 = n->opr_obj->op[0];

		if (n1->value == NULL) {
			//printf("__execUMINUS n1->value is NULL\n");
			getState()->throwException(newArithmeticException("value is null on opr '-'!")->addRef());
			freeSubNodes(n);
			return;
		}
		if (n1->value->getType() != NUMBER)
		{
			//printf("ERROR:  __execUMINUS is NOT NUMBER...  \n");
			getState()->throwException(newArithmeticException("type error on opr '-'! only can number!")->addRef());
			freeSubNodes(n);

			return;
		}
		else {
			n->value = m_exec_alloc.allocateNumber(-((Number*)n1->value)->getDoubleValue());
		}

		freeSubNodes(n);
		//printf("%.2f\n", ((Number*)n->value)->getDoubleValue());
	}

	// 执行一个函数
	void __execFUNC_CALL(Node *n) {
		if (n == NULL)
		{
			return;
		}

		char * name = n->opr_obj->op[0]->var_obj->name;
		XArgsList *args = (XArgsList *)n->opr_obj->op[1]->ptr_u;
		n->value = call(name, args, fileInfoString(n->fileinfo).c_str());
		//printf("func %s exec end\n" , name);
		doSuffixOperationArgs(args);

		if (!n->state.in_func && !n->state.in_loop)
		{
			freeArgsList(args);
		}
	}

	void __execNEW(Node *n) {
		// new 一个对象
		char *className = n->opr_obj->op[0]->var_obj->name;
		langXObject *object = getState()->newObject(className);
		if (object == NULL)
		{
			getState()->throwException(newClassNotFoundException(className)->addRef());
			return;
		}
		langXObjectRef * objectRef = object->addRef();
		objectRef->setEmergeEnv(getState()->getCurrentEnv());
		Environment *env = objectRef->getRefObject()->getObjectEnvironment();

		//objectRef->setMembersEmergeEnv(env);
		//getState()->addEnvToList(env);

		Node *argNode = n->opr_obj->op[1];
		if (argNode != NULL)
		{
			Function *func = objectRef->getConstructor();
			if (func != NULL)
			{
				XArgsList *args = (XArgsList *)argNode->ptr_u;

				getState()->newEnv(env);
				callFunc(func, args, fileInfoString(n->fileinfo).c_str());

				if (getState()->getCurrentEnv()->isDead())
				{
					return;
				}
				getState()->backEnv(false);

			}
		}

		n->value = objectRef;
	}

	void __execCLAXX_BODY(Node *n) {

		doSubNodes(n);

		freeSubNodes(n);
	}

	// 变量声明
	void __execVAR_DECLAR(Node *n) {

		// 都初始为 null
		// 数组要赋值
		Object *obj = m_exec_alloc.allocate(NULLOBJECT);
		obj->setEmergeEnv(getState()->getCurrentEnv());
		for (int i = 0; i < n->opr_obj->op_count; i++)
		{
			Node *t = n->opr_obj->op[i];
			if (t == NULL || t->type != NODE_VARIABLE)
			{
				if (t->type == NODE_OPERATOR && t->opr_obj->opr == VAR_DECLAR)
				{
					__execVAR_DECLAR(t);
				}
				else if (t->type == NODE_ARRAY)
				{
					if (t->ptr_u == NULL)
					{
						//printf("delar array erorr!\n");
						getState()->throwException(newException("Inner Error! delar array erorr!")->addRef());
						m_exec_alloc.free(obj);
						return;
					}

					XArrayNode *an = (XArrayNode *)t->ptr_u;
					int len = an->length;
					if (an->lengthNode != NULL)
					{
						Node *t = an->lengthNode;
						__execNode(t);

						if (t->value == NULL || t->value->getType() != NUMBER)
						{
							//printf("error array length !\n");
							getState()->throwException(newException("error array length !")->addRef());
							return;
						}

						len = ((Number*)t->value)->getIntValue();
						m_exec_alloc.free(t->value);
					}
					XArray *array1 = new XArray(len);
					char *name = an->name;
					Object *arrayRef = array1->addRef();
					arrayRef->setEmergeEnv(getState()->getCurrentEnv());
					setValueToEnv(name, arrayRef);

				}
				continue;
			}

			char *name = t->var_obj->name;
			setValueToEnv(name, obj);
		}

		m_exec_alloc.free(obj);
	}

	void __execCLAXX_MEMBER(Node *n) {
		//  执行节点1， 获得 类对象
		Node *n1 = n->opr_obj->op[0];
		__execNode(n1);

		if (n1->value == NULL)
		{
			//printf("left value %s is not class object or array  !\n", n1->var_obj->name);
			char tmp[100] = { 0 };
			sprintf(tmp, "left value %s is not class object or array  !\n", n1->var_obj->name);
			getState()->throwException(newTypeErrorException(tmp)->addRef());
			freeSubNodes(n);
			return;
		}

		char *memberName = n->opr_obj->op[1]->var_obj->name;

		if (n1->value->getType() == XARRAY)
		{
			XArrayRef *arrayRef = (XArrayRef*)n1->value;
			// 如果是数组， 则执行
			if (strcmp(memberName, "length") == 0)
			{
				// array.length.
				n->value = m_exec_alloc.allocateNumber(arrayRef->getLength());
			}
			else {
				getState()->throwException(newNoClassMemberException(memberName)->addRef());
			}

			freeSubNodes(n);
			return;
		}

		if (n1->value->getType() != OBJECT)
		{
			getState()->throwException(newTypeErrorException("left value is not a object.")->addRef());
			//printf("left value %s is not class object or array  !\n", n1->var_obj->name);
			freeSubNodes(n);
			return;
		}

		langXObjectRef* objectRef = (langXObjectRef*)n1->value;
		Object *t = objectRef->getMember(memberName);
		if (t == NULL)
		{
			getState()->throwException(newNoClassMemberException(memberName)->addRef());
			freeSubNodes(n);
			return;
		}
		n->value = t->clone();
		n->ptr_u = objectRef->clone();

		freeSubNodes(n);
	}

	void __execCLAXX_FUNC_CALL(Node *n) {
		Node *n1 = n->opr_obj->op[0];
		__execNode(n1);

		if (n1->value == NULL || n1->value->getType() != OBJECT)
		{
			getState()->throwException(newTypeErrorException("left value is not class object !")->addRef());
			//printf("left value %s is not class object !\n", n1->var_obj->name);
			freeSubNodes(n);
			return;
		}

		langXObjectRef* objectRef = (langXObjectRef*)n1->value;
		Environment *env = objectRef->getRefObject()->getObjectEnvironment();
		getState()->newEnv(env);

		// 根据语法解析文件可知， 第二个节点为一个函数调用节点
		Node *n2 = n->opr_obj->op[1];
		__execNode(n2);
		if (getState()->getCurrentEnv()->isDead())
		{
			freeSubNodes(n);
			return;
		}
		if (n2->value != NULL)
		{
			n->value = n2->value->clone();
		}
		else {
			n->value = NULL;
		}

		getState()->backEnv(false);

		freeSubNodes(n);
	}

	void __execRESTRICT(Node *n) {
		// 对当前环境进行限定， 限定后，不去搜索父级环境内容

		if (n->opr_obj->op_count <= 0)
		{
			getState()->getCurrentEnv()->setRestrict(true);
		}
		else {

			getState()->getCurrentEnv()->setRestrict(__tryConvertToBool(n->opr_obj->op[0]));

			freeSubNodes(n);
		}
	}

	// 执行 this.xxx
	void __execTHIS(Node *n) {

		Environment * env = getState()->getNearestObjectEnv();
		if (!env)
		{
			//printf("cannot find the object on use this!\n");
			getState()->throwException(newUnsupportedOperationException("invalid this stmt! cannot find the object on use this!")->addRef());
			return;
		}

		ObjectBridgeEnv *objEnv = (ObjectBridgeEnv*)env;
		if (n->opr_obj->op_count <= 0)
		{
			// no args.  获得自己就好了
			n->value = objEnv->getEnvObject()->addRef();
			return;
		}

		bool flag = env->isRestrict();
		Environment *currEnv = getState()->getCurrentEnv();

		// 限定好像没什么卵用。。 
		env->setRestrict(true);
		getState()->setCurrentEnv(env);

		langXObject *thisObj = objEnv->getEnvObject();
		Node *n1 = n->opr_obj->op[0];
		//  产生变量的名字
		n->var_obj = (Variable*)calloc(1, sizeof(Variable));
		if (n1->type == NODE_VARIABLE)
		{
			n->var_obj->name = n1->var_obj->name;
			if (!thisObj->hasMember(n->var_obj->name))
			{
				// 没有那个成员
				char tmp[100] = { 0 };
				sprintf(tmp, "no class member %s in class %s!", n->var_obj->name, thisObj->getClassName());
				getState()->throwException(newNoClassMemberException(tmp)->addRef());
				free(n->var_obj);
				n->var_obj = NULL;
				return;
			}
		}
		else if (n1->type == NODE_OPERATOR)
		{
			// 语法解释器并没有实现这部分， 所以暂时先不管。
			n->var_obj->name = n1->opr_obj->op[1]->var_obj->name;
		}

		__execNode(n1);

		if (n1->value == NULL)
		{
			//printf("error in __execTHIS, n1->value == NULL");
			getState()->throwException(newException("error in __execTHIS, n1->value == NULL")->addRef());
		}
		else {
			n->value = n1->value->clone();
		}

		getState()->backEnv(false);
		env->setRestrict(flag);
		getState()->setCurrentEnv(currEnv);
		freeSubNodes(n);
	}

	// 执行 try {}
	void __execXTRY(Node *n) {
		if (n == NULL)
		{
			return;
		}

		TryEnvironment * tryEnv = new TryEnvironment();
		tryEnv->setCatchNode(n->opr_obj->op[1]);
		getState()->newEnv(tryEnv);
		__execNode(n->opr_obj->op[0]);
		getState()->backEnv();

		// OK ,这就算执行完毕了。 如果出发了异常 会走另外一个地方。
		// 正常执行完毕， 会无视 catch 内的东西
	}

	/*
	 * 执行节点，  节点的结果 将 放在  Node.value 上
	 * 这是一个 Object 类型的指针    07-24
	 */
	void __execNode(Node *node) {
		if (node == NULL)
		{
			return;
		}
		// 如果节点存在值， 那说明这个节点已经运算过了
		// 会重新进行计算和赋值
		//if (node->value != NULL)
		//{
		//	return;
		//}

		// 如果当前环境为一个死亡环境， 则什么都不做
		if (getState()->getCurrentEnv()->isDead())
		{
			return;
		}

		if (node->state.isBreak || node->state.isReturn)
		{
			//  节点中断
			return;
		}

		if (!getInException())
		{
			setExecNode(node);
		}

		//printf("__execNode 01x\n");
		//printf("node addr: %p\n",node);
		if (node->type == NODE_VARIABLE)
		{
			//printf("__execNode NODE_VARIABLE\n");
			// 协调程序， 使变量的 obj 处于赋值状态
			if (node->value == NULL)
			{
				//printf("__execNode 01\n");
				Object *obj = getValue(node->var_obj->name);

				if (obj == NULL)
				{
					//printf("var %s=null \n", node->var_obj->name);
					node->value = NULL;
				}
				else {
					if (obj->getType() == NUMBER)
					{
						Number * number = (Number*)obj;
						//printf("var %s=%.2f \n", node->var_obj->name, number->getDoubleValue());
					}
					else if (obj->getType() == STRING)
					{
						String *string = (String*)obj;
						//printf("var %s=\"%s\" \n" , node->var_obj->name, string->getValue());
					}

					// 变量类型为 一个 copy 
					node->value = obj->clone();
				}

			}

			return;
		}
		else if (node->type == NODE_CONSTANT_NUMBER)
		{
			//printf("__execNode NODE_CONSTANT_NUMBER\n");
			node->value = m_exec_alloc.allocateNumber(node->con_obj->dValue);
			return;
		}
		else if (node->type == NODE_CONSTANT_STRING)
		{
			//printf("__execNode NODE_CONSTANT_STRING\n");
			//  因为匹配出的字符串是带有 双引号的， 现在要去掉这个双引号
			char *tmp = strndup(node->con_obj->sValue + 1, strlen(node->con_obj->sValue) - 2);
			node->value = m_exec_alloc.allocateString(tmp);
			free(tmp);

			return;
		}
		else if (node->type == NODE_CLASS)
		{
			// 类
			if (node->ptr_u == NULL)
			{
				return;
			}
			ClassInfo *cinfo = (ClassInfo*)node->ptr_u;
			getState()->regClass(cinfo);
			return;
		}
		else if (node->type == NODE_FUNCTION)
		{
			// 函数
			if (node->value == NULL)
			{
				return;
			}
			Function *func = (Function*)node->value;
			getState()->getCurrentEnv()->putFunction(func->getName(), func);
			return;
		}
		else if (node->type == NODE_NULL)
		{
			node->value = m_exec_alloc.allocate(NULLOBJECT);
			return;
		}
		else if (node->type == NODE_ARRAY_ELE)
		{
			ArrayInfo * arrayInfo = node->arr_obj;
			Object *obj = getValue(arrayInfo->name);
			if (obj == NULL || obj->getType() != XARRAY)
			{
				//printf("left value is not array with array operator!\n");
				getState()->throwException(newUnsupportedOperationException("left value is not array with array operator!")->addRef());
				return;
			}

			XArrayRef *ref = (XArrayRef*)obj;
			int index = arrayInfo->index;
			if (arrayInfo->indexNode != NULL)
			{
				Node *t = arrayInfo->indexNode;
				__execNode(t);

				if (t->value == NULL || t->value->getType() != NUMBER)
				{
					//printf("error array length !\n");
					getState()->throwException(newException("error array length !")->addRef());
					return;
				}

				index = ((Number*)t->value)->getIntValue();
				m_exec_alloc.free(t->value);
				t->value = NULL;
			}
			node->value = ref->at(index)->clone();
			return;
		}


		if (node->type != NODE_OPERATOR)
		{
			//printf("undeal type: %d\n", node->type);
			char tmp[100] = { 0 };
			sprintf(tmp, "undeal type: %d", node->type);
			getState()->throwException(newException(tmp)->addRef());
			return;
		}


		//printf("exec operator node. opr is: %d\n", node->opr_obj->opr);
		switch (node->opr_obj->opr)
		{
		case '+':
			__exec43(node);
			break;
		case '-':
			__exec45(node);
			break;
		case '*':
			__exec42(node);
			break;
		case '/':
			__exec47(node);
			break;
		case '=':
			__exec61(node);
			break;
		case ';':
			__exec59(node);
			break;
		case '>':
			__exec62(node);
			break;
		case '<':
			__exec60(node);
			break;
		case UMINUS:
			__execUMINUS(node);
			break;
		case INC_OP:
			__execINC_OP(node);
			break;
		case DEC_OP:
			__execDEC_OP(node);
			break;
		case ADD_EQ:
			__execADD_EQ(node);
			break;
		case SUB_EQ:
			__execSUB_EQ(node);
			break;
		case MUL_EQ:
			__execMUL_EQ(node);
			break;
		case DIV_EQ:
			__execDIV_EQ(node);
			break;
		case LE_OP:
			__execLE_OP(node);
			break;
		case GE_OP:
			__execGE_OP(node);
			break;
		case EQ_OP:
			__execEQ_OP(node);
			break;
		case NE_OP:
			__execNE_OP(node);
			break;
		case AND_OP:
			__execOPAND(node);
			break;
		case OR_OP:
			__execOPOR(node);
		case IF:
			__execIF(node);
			break;
		case WHILE:
			__execWHILE(node);
			break;
		case FOR:
			__execFOR(node);
			break;
		case FUNC_CALL:
			__execFUNC_CALL(node);
			break;
		case BREAK:
			__execBREAK(node);
			break;
		case RETURN:
			__execRETURN(node);
			break;
		case SWITCH:
			__execSWITCH(node);
			break;
		case CASE_LIST:
			__execCASE_LIST(node);
			break;
		case CASE:
			__execCASE(node);
			break;
		case DEFAULT:
			__execDeafult(node);
			break;
		case NEW:
			__execNEW(node);
			break;
		case CLAXX_BODY:
			__execCLAXX_BODY(node);
			break;
		case CLAXX_MEMBER:
			__execCLAXX_MEMBER(node);
			break;
		case CLAXX_FUNC_CALL:
			__execCLAXX_FUNC_CALL(node);
			break;
		case VAR_DECLAR:
			__execVAR_DECLAR(node);
			break;
		case RESTRICT:
			__execRESTRICT(node);
			break;
		case THIS:
			__execTHIS(node);
			break;
		case XTRY:
			__execXTRY(node);
			break;
		default:
			break;
		}

	}

}

