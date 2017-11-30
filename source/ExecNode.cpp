#include <stdio.h>
#include <string.h>
#include <stdlib.h>
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
#include "../include/XNameSpace.h"
#include "../include/StackTrace.h"
#include "../include/NullObject.h"
#include "../include/InnerFunction.h"
#include "../include/langXThread.h"


namespace langX {


	// 根据数组信息获得结果， 返回的结果为一个 nullptr 或者复制好的结果
	Object * getValueFromArrayInfo(ArrayInfo *arrayInfo) {
		Object *obj = NULL;
		if (arrayInfo->name != NULL)
		{
			obj = getValue(arrayInfo->name);
		}
		else if (arrayInfo->objNode != NULL)
		{
			__execNode(arrayInfo->objNode);
			obj = arrayInfo->objNode->value;
		}

		if (obj == NULL)
		{
			getState()->curThread()->throwException(newUnsupportedOperationException("left value is not array with array operator!")->addRef());
			return nullptr;
		}

		if (obj->getType() == OBJECT) {
			langXObjectRef * ref1 = (langXObjectRef*)obj;
			Function *func1 = ref1->getFunction("operator[]");
			if (func1)
			{
				// 处理参数
				Object * arg1 = nullptr;
				Number num1(0);
				arg1 = &num1;
				if (arrayInfo->indexNode != NULL)
				{
					Node *t = arrayInfo->indexNode;
					__execNode(t);
					if (t == nullptr)
					{
						getState()->curThread()->throwException(newException("error index !")->addRef());
						return nullptr;
					}
					arg1 = t->value;
				}
				X3rdArgs _3rdArgs;
				memset(&_3rdArgs, 0, sizeof(X3rdArgs));
				_3rdArgs.args[0] = arg1;
				_3rdArgs.index = 1;
				return callFunction(obj, func1, &_3rdArgs);
			}
		}

		if (obj->getType() != XARRAY)
		{
			getState()->curThread()->throwException(newUnsupportedOperationException("left value is not array with array operator!")->addRef());
			return nullptr;
		}

		int index = arrayInfo->index;
		if (arrayInfo->indexNode != NULL)
		{
			Node *t = arrayInfo->indexNode;
			__execNode(t);

			if (t->value == NULL || t->value->getType() != NUMBER)
			{
				getState()->curThread()->throwException(newException("error array length !")->addRef());
				return nullptr;
			}

			index = ((Number*)t->value)->getIntValue();
			Allocator::free(t->value);
			t->value = NULL;
		}

		XArrayRef *ref = (XArrayRef*)obj;
		if (index < 0 || index >= ref->getLength())
		{
			char tmp[1024] = { 0 };
			sprintf(tmp, "index %d,array length %d", index, ref->getLength());
			getState()->curThread()->throwException(newIndexOutOfBoundsException(tmp)->addRef());
			return nullptr;
		}

		Object * ret = ref->at(index);
		if (ret == nullptr)
		{
			// 内部异常
			getState()->curThread()->throwException(newInnerException(" array element is null... ")->addRef());
			return nullptr;
		}

		return ret->clone();
	}


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
			env->putObject(name, val);
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
		setValueToEnv2(name, val, getState()->curThread()->getCurrentEnv());
	}

	/*
	  执行这个节点的所有子节点
	*/
	void doSubNodes(Node *n) {
		if (n == NULL)
		{
			return;
		}

		langXThread *thread = getState()->curThread();

		for (int i = 0; i < n->opr_obj->op_count; i++)
		{
			Node *run = n->opr_obj->op[i];
			if (run == NULL)
			{
				continue;
			}

			NodeLink * nodeLink = thread->beginExecute(run);
			nodeLink->backAfterExec = true;
		}
	}

	// 做后缀操作符的 工作 也包括前缀操作符
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
			Allocator::free(n->postposition);
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
			Node *tmp = n->opr_obj->op[i];
			tmp->state = n->state;

			if (tmp->type == NODE_OPERATOR)
			{
				if (tmp->opr_obj->opr == FUNC_CALL)
				{
					// 参数
					XArgsList *args = (XArgsList *)n->opr_obj->op[1]->ptr_u;
					if (args != nullptr)
					{
						for (size_t i = 0; i < args->index; i++)
						{
							stateExtends(args->args[i]);
						}
					}
				}

			}
		}
	}


	//递归释放节点及子节点值的内存  | 会遍历所有节点， 发现值都会进行释放操作
	void recursiveFreeNodeValue(Node *n) {

		if (n == NULL)
		{
			return;
		}

		if (n->value != NULL)
		{
			Allocator::free(n->value);
			n->value = NULL;
		}

		if (n->type == NODE_OPERATOR)
		{
			for (int i = 0; i < n->opr_obj->op_count; i++)
			{
				recursiveFreeNodeValue(n->opr_obj->op[i]);
			}
		}

	}

	// 释放数组信息
	void freeArrayInfo(ArrayInfo *arrayInfo) {
		if (arrayInfo == nullptr)
		{
			return;
		}
		recursiveFreeNodeValue(arrayInfo->objNode);
		recursiveFreeNodeValue(arrayInfo->indexNode);
	}


	/*
	  释放当前节点的子节点的值 内存 | 只释放一层的值内存 
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
			Allocator::free(n->opr_obj->op[i]->value);
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
				Object *t = Allocator::allocate(rightType);
				t->setEmergeEnv(obj->getEmergeEnv());
				t->setConst(obj->isConst());
				t->setLocal(obj->isLocal());
				obj->getEmergeEnv()->putObject(left->var_obj->name, t);
				left->value = t;
			}

			return;
		}
		
		// TODO  判定一下是否出现了异常

		Object *obj = getState()->curThread()->getObject(left->var_obj->name);
		if (obj == NULL)
		{
			// 左值没声明过, 那么左值的产生环境就为 当前环境
			obj = Allocator::allocate(rightType);
			obj->setEmergeEnv(getState()->curThread()->getCurrentEnv());
			getState()->curThread()->putObject(left->var_obj->name, obj);
		}
		else {
			//  左值声明过
			if (obj->getType() != rightType)
			{
				Object *t = Allocator::allocate(rightType);
				// 变量的常量和local属性也不应该变化
				t->setLocal(obj->isLocal());
				t->setConst(obj->isConst());
				// 变量的产生环境不变
				t->setEmergeEnv(obj->getEmergeEnv());
				obj->getEmergeEnv()->putObject(left->var_obj->name, t);

				// 释放掉原值   0820  上面那条 putObject 语句执行结束之后， 好像就访问不到 obj 了 以后需要查看是为什么 TODO 
				// 上述语句会调用 langXObject::setMember  ，这个函数会检查类型， 如果类型不一致， 会释放掉原有内存
				//Allocator::free(obj);

				// 赋值到新值
				obj = t;
			}
			else {
				obj = obj->clone();
			}
		}

		left->value = obj;
	}

	/* 检测一下节点是否存在 值， 如果不存在， 则运算他 */
	void checkValue(Node * node, langXThread *thread) {
		if (node == NULL)
		{
			return;
		}

		if (node->value == NULL)
		{
			thread->beginExecute(node, true);
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

		//checkValue(n, getState()->curThread());      // 2017年11月30日 在外层确保值是有的吧
		if (n->value == NULL)
		{
			return false;
		}

		return n->value->isTrue();
	}

	void __realExec43(Node *n) {
		Node *n1 = n->opr_obj->op[0];
		Node *n2 = n->opr_obj->op[1];

		if (n1->value == NULL || n2->value == NULL)
		{
			getState()->curThread()->throwException(newArithmeticException("value is null on opr '+'!")->addRef());
			freeSubNodes(n);
			return;
		}

		// 子节点的值是为了计算当前结点的值， 如果当前结点的值 计算 结束， 则释放掉子节点值得内存
		// 子节点的值如果是一个常量， 则该值是一个 new 的内存， 如果是一个变量， 则该值是一个 clone 出现的对象
		Object * left = n1->value;
		Object * right = n2->value;

		if (left->getType() == NUMBER && right->getType() == NUMBER)
		{
			n->value = Allocator::allocateNumber(((Number*)left)->getDoubleValue() + ((Number*)right)->getDoubleValue());
		}
		else if (left != NULL && left->getType() == OBJECT) {
			langXObjectRef * ref1 = (langXObjectRef*)left;
			Function *func1 = ref1->getFunction("operator+");
			if (func1)
			{
				X3rdArgs _3rdArgs;
				memset(&_3rdArgs, 0, sizeof(X3rdArgs));
				_3rdArgs.args[0] = right;
				_3rdArgs.index = 1;
				n->value = callFunction(left, func1, &_3rdArgs);

				freeSubNodes(n);
				return;
			}
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
				else if (left->getType() == FUNCTION)
				{
					ss << "function@[" << left->characteristic();
				}
				else if (left->getType() == OBJECT)
				{
					//ss << "object";
					char tmp[2048] = { 0 };
					objToString(left, tmp, 0, 2048);
					ss << tmp;
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
					else if (right->getType() == FUNCTION)
					{
						ss << "function@[" << right->characteristic();
					}
					else if (right->getType() == OBJECT)
					{
						char tmp[2048] = { 0 };
						objToString(right, tmp, 0, 2048);
						ss << tmp;
					}
					else {
						printf("error type in do add opr! \n");
						return;
					}

					n->value = Allocator::allocateString(ss.str().c_str());
		}
		else {
			getState()->curThread()->throwException(newArithmeticException("args type error when do opr '+' .")->addRef());
		}

		freeSubNodes(n);
	}

	// +  
	// 操作结果， 会将结果存储在当前节点中 
	void __exec43(NodeLink *nodeLink) {
		Node *  n = nodeLink->node;
		if (nodeLink->index == 0) {
			doSubNodes(n);
			nodeLink->index = 1;
		}
		else {
			__realExec43(n);
			nodeLink->backAfterExec = true;
		}

	}

	// -
	void __exec45(NodeLink *nodeLink) {

		Node *n = nodeLink->node;
		if (nodeLink->index == 0) {
			doSubNodes(n);
			nodeLink->index = 1;
			return;
		}


		Node *n1 = n->opr_obj->op[0];
		Node *n2 = n->opr_obj->op[1];

		if (n1->value == NULL || n2->value == NULL)
		{
			getState()->curThread()->throwException(newArithmeticException("value is null on opr '-'!")->addRef());
			freeSubNodes(n);
			return;
		}

		Object * left = n1->value;
		Object * right = n2->value;
		if (left != NULL && left->getType() == OBJECT) {
			langXObjectRef * ref1 = (langXObjectRef*)left;
			Function *func1 = ref1->getFunction("operator-");
			if (func1)
			{
				X3rdArgs _3rdArgs;
				memset(&_3rdArgs, 0, sizeof(X3rdArgs));
				_3rdArgs.args[0] = right;
				_3rdArgs.index = 1;
				n->value = callFunction(left, func1, &_3rdArgs);

				freeSubNodes(n);
				return;
			}
		}
		if (n1->value->getType() != NUMBER || n2->value->getType() != NUMBER)
		{
			getState()->curThread()->throwException(newArithmeticException("type error on opr '-'!")->addRef());
			freeSubNodes(n);
			return;
		}

		n->value = Allocator::allocateNumber(((Number*)n1->value)->getDoubleValue() - ((Number*)n2->value)->getDoubleValue());
		freeSubNodes(n);
		nodeLink->backAfterExec = true;
	}

	// *
	void __exec42(NodeLink *nodeLink) {
		Node *n = nodeLink->node;
		if (nodeLink->index == 0) {
			doSubNodes(n);
			nodeLink->index = 1;
			return;
		}

		Node *n1 = n->opr_obj->op[0];
		Node *n2 = n->opr_obj->op[1];

		if (n1->value == NULL || n2->value == NULL)
		{
			getState()->curThread()->throwException(newArithmeticException("value is null on opr '*'!")->addRef());
			freeSubNodes(n);
			return;
		}

		Object * left = n1->value;
		Object * right = n2->value;
		if (left != NULL && left->getType() == OBJECT) {
			langXObjectRef * ref1 = (langXObjectRef*)left;
			Function *func1 = ref1->getFunction("operator*");
			if (func1)
			{
				X3rdArgs _3rdArgs;
				memset(&_3rdArgs, 0, sizeof(X3rdArgs));
				_3rdArgs.args[0] = right;
				_3rdArgs.index = 1;
				n->value = callFunction(left, func1, &_3rdArgs);

				freeSubNodes(n);
				return;
			}
		}

		if (n1->value->getType() != NUMBER || n2->value->getType() != NUMBER)
		{
			getState()->curThread()->throwException(newArithmeticException("type error on opr '*'!")->addRef());
			freeSubNodes(n);
			return;
		}

		n->value = Allocator::allocateNumber(((Number*)n1->value)->getDoubleValue() * ((Number*)n2->value)->getDoubleValue());
		freeSubNodes(n);
		nodeLink->backAfterExec = true;
	}

	// /
	void __exec47(NodeLink *nodeLink) {
		Node *n = nodeLink->node;
		if (nodeLink->index == 0) {
			doSubNodes(n);
			nodeLink->index = 1;
			return;
		}

		Node *n1 = n->opr_obj->op[0];
		Node *n2 = n->opr_obj->op[1];

		if (n1->value == NULL || n2->value == NULL)
		{
			getState()->curThread()->throwException(newArithmeticException("value is null on opr '/'!")->addRef());
			freeSubNodes(n);
			return;
		}

		Object * left = n1->value;
		Object * right = n2->value;
		if (left != NULL && left->getType() == OBJECT) {
			langXObjectRef * ref1 = (langXObjectRef*)left;
			Function *func1 = ref1->getFunction("operator/");
			if (func1)
			{
				X3rdArgs _3rdArgs;
				memset(&_3rdArgs, 0, sizeof(X3rdArgs));
				_3rdArgs.args[0] = right;
				_3rdArgs.index = 1;
				n->value = callFunction(left, func1, &_3rdArgs);

				freeSubNodes(n);
				return;
			}
		}

		if (n1->value->getType() != NUMBER || n2->value->getType() != NUMBER)
		{
			getState()->curThread()->throwException(newArithmeticException("type error on opr '/'!")->addRef());
			freeSubNodes(n);
			return;
		}

		double d2 = ((Number*)n2->value)->getDoubleValue();
		if (d2 == 0)
		{
			getState()->curThread()->throwException(newArithmeticException("/ by zero on opr '/'!")->addRef());
			freeSubNodes(n);
			return;
		}

		n->value = Allocator::allocateNumber(((Number*)n1->value)->getDoubleValue() / d2);
		freeSubNodes(n);
		nodeLink->backAfterExec = true;

	}

	// 按位或  |
	void __exec124(NodeLink *nodeLink) {

		Node *n = nodeLink->node;
		if (nodeLink->index == 0) {
			doSubNodes(n);
			nodeLink->index = 1;
			return;
		}

		Node *n1 = n->opr_obj->op[0];
		Node *n2 = n->opr_obj->op[1];

		if (n1->value == NULL || n2->value == NULL)
		{
			getState()->curThread()->throwException(newArithmeticException("value is null on opr '|'!")->addRef());
			freeSubNodes(n);
			return;
		}
		if (n1->value->getType() != NUMBER || n2->value->getType() != NUMBER)
		{
			getState()->curThread()->throwException(newArithmeticException("type error on opr '|'!")->addRef());
			freeSubNodes(n);
			return;
		}

		int i1 = ((Number*)n1->value)->getIntValue();
		int i2 = ((Number*)n2->value)->getIntValue();
		int i3 = i1 | i2;

		n->value = Allocator::allocateNumber(i3);
		freeSubNodes(n);
		nodeLink->backAfterExec = true;

	}

	// 按位与  &
	void __exec38(NodeLink *nodeLink) {
		Node *n = nodeLink->node;
		if (nodeLink->index == 0) {
			doSubNodes(n);
			nodeLink->index = 1;
			return;
		}

		Node *n1 = n->opr_obj->op[0];
		Node *n2 = n->opr_obj->op[1];

		if (n1->value == NULL || n2->value == NULL)
		{
			getState()->curThread()->throwException(newArithmeticException("value is null on opr '&'!")->addRef());
			freeSubNodes(n);
			return;
		}
		if (n1->value->getType() != NUMBER || n2->value->getType() != NUMBER)
		{
			getState()->curThread()->throwException(newArithmeticException("type error on opr '&'!")->addRef());
			freeSubNodes(n);
			return;
		}

		int i1 = ((Number*)n1->value)->getIntValue();
		int i2 = ((Number*)n2->value)->getIntValue();
		int i3 = i1 & i2;

		n->value = Allocator::allocateNumber(i3);
		freeSubNodes(n);
		nodeLink->backAfterExec = true;

	}

	// 按位异或  ^
	void __exec94(NodeLink *nodeLink) {
		Node *n = nodeLink->node;
		if (nodeLink->index == 0) {
			doSubNodes(n);
			nodeLink->index = 1;
			return;
		}

		Node *n1 = n->opr_obj->op[0];
		Node *n2 = n->opr_obj->op[1];

		if (n1->value == NULL || n2->value == NULL)
		{
			getState()->curThread()->throwException(newArithmeticException("value is null on opr '^'!")->addRef());
			freeSubNodes(n);
			return;
		}
		if (n1->value->getType() != NUMBER || n2->value->getType() != NUMBER)
		{
			getState()->curThread()->throwException(newArithmeticException("type error on opr '^'!")->addRef());
			freeSubNodes(n);
			return;
		}

		int i1 = ((Number*)n1->value)->getIntValue();
		int i2 = ((Number*)n2->value)->getIntValue();
		int i3 = i1 ^ i2;

		n->value = Allocator::allocateNumber(i3);
		freeSubNodes(n);
		nodeLink->backAfterExec = true;

	}

	// 按位取反  ~
	void __exec126(NodeLink *nodeLink) {

		Node *n = nodeLink->node;
		if (nodeLink->index == 0) {
			doSubNodes(n);
			nodeLink->index = 1;
			return;
		}

		Node *n1 = n->opr_obj->op[0];

		if (n1->value == NULL)
		{
			getState()->curThread()->throwException(newArithmeticException("value is null on opr '~'!")->addRef());
			freeSubNodes(n);
			return;
		}
		if (n1->value->getType() != NUMBER)
		{
			getState()->curThread()->throwException(newArithmeticException("type error on opr '~'!")->addRef());
			freeSubNodes(n);
			return;
		}

		int i1 = ((Number*)n1->value)->getIntValue();
		int i3 = ~i1;

		n->value = Allocator::allocateNumber(i3);
		freeSubNodes(n);
		nodeLink->backAfterExec = true;

	}

	// 向左移位
	void __execLEFT_SHIFT(NodeLink *nodeLink) {

		Node *n = nodeLink->node;
		if (nodeLink->index == 0) {
			doSubNodes(n);
			nodeLink->index = 1;
			return;
		}

		Node *n1 = n->opr_obj->op[0];
		Node *n2 = n->opr_obj->op[1];

		if (n1->value == NULL || n2->value == NULL)
		{
			getState()->curThread()->throwException(newArithmeticException("value is null on opr '<<'!")->addRef());
			freeSubNodes(n);
			return;
		}

		Object * left = n1->value;
		Object * right = n2->value;
		if (left != NULL && left->getType() == OBJECT) {
			langXObjectRef * ref1 = (langXObjectRef*)left;
			Function *func1 = ref1->getFunction("operator<<");
			if (func1)
			{
				X3rdArgs _3rdArgs;
				memset(&_3rdArgs, 0, sizeof(X3rdArgs));
				_3rdArgs.args[0] = right;
				_3rdArgs.index = 1;
				n->value = callFunction(left, func1, &_3rdArgs);

				freeSubNodes(n);
				return;
			}
		}

		if (n1->value->getType() != NUMBER || n2->value->getType() != NUMBER)
		{
			getState()->curThread()->throwException(newArithmeticException("type error on opr '<<'!")->addRef());
			freeSubNodes(n);
			return;
		}



		int i1 = ((Number*)n1->value)->getIntValue();
		int i2 = ((Number*)n2->value)->getIntValue();
		int i3 = i1 << i2;

		n->value = Allocator::allocateNumber(i3);
		freeSubNodes(n);
		nodeLink->backAfterExec = true;
	}

	// 向右移位
	void __execRIGHT_SHIFT(NodeLink *nodeLink) {

		Node *n = nodeLink->node;
		if (nodeLink->index == 0) {
			doSubNodes(n);
			nodeLink->index = 1;
			return;
		}

		Node *n1 = n->opr_obj->op[0];
		Node *n2 = n->opr_obj->op[1];

		if (n1->value == NULL || n2->value == NULL)
		{
			getState()->curThread()->throwException(newArithmeticException("value is null on opr '>>'!")->addRef());
			freeSubNodes(n);
			return;
		}

		Object * left = n1->value;
		Object * right = n2->value;
		if (left != NULL && left->getType() == OBJECT) {
			langXObjectRef * ref1 = (langXObjectRef*)left;
			Function *func1 = ref1->getFunction("operator>>");
			if (func1)
			{
				X3rdArgs _3rdArgs;
				memset(&_3rdArgs, 0, sizeof(X3rdArgs));
				_3rdArgs.args[0] = right;
				_3rdArgs.index = 1;
				n->value = callFunction(left, func1, &_3rdArgs);

				freeSubNodes(n);
				return;
			}
		}

		if (n1->value->getType() != NUMBER || n2->value->getType() != NUMBER)
		{
			getState()->curThread()->throwException(newArithmeticException("type error on opr '>>'!")->addRef());
			freeSubNodes(n);
			return;
		}

		int i1 = ((Number*)n1->value)->getIntValue();
		int i2 = ((Number*)n2->value)->getIntValue();
		int i3 = i1 >> i2;

		n->value = Allocator::allocateNumber(i3);
		freeSubNodes(n);
		nodeLink->backAfterExec = true;
	}

	//  取模运算 %
	void __exec37(NodeLink *nodeLink) {

		Node *n = nodeLink->node;
		if (nodeLink->index == 0) {
			doSubNodes(n);
			nodeLink->index = 1;
			return;
		}

		Node *n1 = n->opr_obj->op[0];
		Node *n2 = n->opr_obj->op[1];

		if (n1->value == NULL || n2->value == NULL)
		{
			getState()->curThread()->throwException(newArithmeticException("value is null on opr '%'!")->addRef());
			freeSubNodes(n);
			return;
		}

		Object * left = n1->value;
		Object * right = n2->value;
		if (left != NULL && left->getType() == OBJECT) {
			langXObjectRef * ref1 = (langXObjectRef*)left;
			Function *func1 = ref1->getFunction("operator%");
			if (func1)
			{
				X3rdArgs _3rdArgs;
				memset(&_3rdArgs, 0, sizeof(X3rdArgs));
				_3rdArgs.args[0] = right;
				_3rdArgs.index = 1;
				n->value = callFunction(left, func1, &_3rdArgs);

				freeSubNodes(n);
				return;
			}
		}

		if (n1->value->getType() != NUMBER || n2->value->getType() != NUMBER)
		{
			getState()->curThread()->throwException(newArithmeticException("type error on opr '%'!")->addRef());
			freeSubNodes(n);
			return;
		}

		int i1 = ((Number*)n1->value)->getIntValue();
		int i2 = ((Number*)n2->value)->getIntValue();
		int i3 = i1 % i2;

		n->value = Allocator::allocateNumber(i3);
		freeSubNodes(n);
		nodeLink->backAfterExec = true;
	}

	// 赋值操作 = 
	void __exec61(NodeLink *nodeLink, langXThread *thread) {
		Node *n = nodeLink->node;
		//printf("__exec61 start\n");
		Node *left = n->opr_obj->op[0];

		langXObjectRef *objectRef = NULL;
		ArrayInfo *arrayInfo = NULL;

		if (left->type == NODE_OPERATOR)
		{
			if (left->opr_obj->opr == CLAXX_MEMBER)
			{
				if (nodeLink->index == 0) {
					thread->beginExecute(left, true);
					nodeLink->index = 1;
					return;
				}
				else {
					objectRef = (langXObjectRef *)left->ptr_u;
					left->ptr_u = NULL;
				}
				
			}
			else if (left->opr_obj->opr == THIS)
			{
				if (nodeLink->index == 0) {
					thread->beginExecute(left, true);
					nodeLink->index = 1;
					return;
				}
			}
			else {
				//printf("left not the CLAXX_MEMBER! \n");
				getState()->curThread()->throwException(newException("left not the CLAXX_MEMBER!")->addRef());
				freeSubNodes(n);
				return;
			}
		}
		else if (left->type == NODE_ARRAY_ELE)
		{
			arrayInfo = left->arr_obj;
		}
		else {
			if (left->type != NODE_VARIABLE)
			{
				//printf("left not the NODE_VARIABLE\n");
				getState()->curThread()->throwException(newTypeErrorException("left not the NODE_VARIABLE")->addRef());
				freeSubNodes(n);
				return;
			} 

		}

		if (nodeLink->index == 0) {
			nodeLink->index = 1;
		}
			
		//printf("__exec61 left name: %s\n", left->var_obj->name);
		Node *right = n->opr_obj->op[1];
		//printf("right->value: %p\n", right->value);
		if (nodeLink->index == 1) {
			checkValue(right,thread);
			nodeLink->index = 2;
			return;
		}

		// 赋值操作的结果 为 右值的结果
		if (right->value == NULL)
		{
			// 判断是否是函数
			if (right->type == NODE_VARIABLE)
			{
				Function *func = thread->getFunction(right->var_obj->name);
				if (func != nullptr)
				{
					FunctionRef * f = Allocator::allocateFunctionRef(func);
					f->setEmergeEnv(thread->getCurrentEnv());
					right->value = f;
				}
			}

			if (right->value == NULL)
			{
				right->value = Allocator::allocate(NULLOBJECT);
			}
		}


		ObjectType rightType = right->value->getType();
		if (objectRef == NULL && arrayInfo == NULL)
		{
			checkVarValue(left, rightType);
			if (thread->isInException()) {
				return;
			}

			if (left->value->isConst())
			{
				char tmp[1024] = { 0 };
				sprintf(tmp, "cannot change %s value, because it is a const value.", left->value->getName());
				getState()->curThread()->throwException(newUnsupportedOperationException(tmp)->addRef());
				return;
			}

			left->value->update(right->value);

			// 释放右值的内存 
			Allocator::free(right->value);
			right->value = NULL;


			// 更新值到 Environment 
			setValueToEnv2(left->var_obj->name, left->value, left->value->getEmergeEnv());


			n->value = Allocator::copy(left->value);
			// 左值是指向 Environment 内的内存的复制， 需要释放
			Allocator::free(left->value);
			left->value = NULL;
		}
		else if (arrayInfo != NULL)
		{
			Object *obj = NULL;
			if (arrayInfo->name != NULL)
			{
				obj = getValue(arrayInfo->name);
			}
			else if (arrayInfo->objNode != NULL)
			{
				if (nodeLink->index == 2) {
					thread->beginExecute(arrayInfo->objNode, true);
					nodeLink->index = 3;
					return;
				}
				else {
					obj = arrayInfo->objNode->value;
				}
			}

			if (obj == NULL || obj->getType() != XARRAY)
			{
				getState()->curThread()->throwException(newUnsupportedOperationException("left value is not array with array operator!")->addRef());
				freeSubNodes(n);
				//printf("left value is not array with array operator!\n");
				return;
			}

			int index = arrayInfo->index;
			if (arrayInfo->indexNode != NULL)
			{
				Node *t = arrayInfo->indexNode;
				if (nodeLink->index == 3) {
					thread->beginExecute(t, true);
					nodeLink->index = 4;
					return;
				}

				if (t->value == NULL || t->value->getType() != NUMBER)
				{
					getState()->curThread()->throwException(newException("error array length!")->addRef());
					freeSubNodes(n);
					//printf("error array length !\n");
					return;
				}

				index = ((Number*)t->value)->getIntValue();
				Allocator::free(t->value);
				t->value = NULL;
			}

			XArrayRef *ref = (XArrayRef*)obj;
			ref->set(index, right->value);
			Allocator::free(right->value);
			right->value = NULL;

			n->value = Allocator::copy(right->value);
		}
		else {
			// 这里的Left 已经被执行过了   
			char * name = left->opr_obj->op[1]->var_obj->name;
			if (!objectRef->getClassInfo()->hasMember(name))
			{
				char tmp[100] = { 0 };
				sprintf(tmp, "cannot find member %s in class %s!", name, objectRef->getClassInfo()->getName());
				getState()->curThread()->throwException(newNoClassMemberException(tmp)->addRef());

			}
			else {
				if (left->value != NULL && left->value->isConst())
				{
					char tmp[1024] = { 0 };
					sprintf(tmp, "cannot change %s value, because it is a const value.", left->value->getName());
					getState()->curThread()->throwException(newUnsupportedOperationException(tmp)->addRef());
					return;
				}

				objectRef->setMember(name, right->value);
				n->value = Allocator::copy(right->value);
			}

			Allocator::free(right->value);
			right->value = NULL;

			delete objectRef;
			objectRef = NULL;
		}

		nodeLink->backAfterExec = true;
		doSuffixOperation(n);
	}

	void __execADD_EQ(NodeLink *nodeLink) {
		Node *n = nodeLink->node;
		if (nodeLink->index == 0) {
			doSubNodes(n);
			nodeLink->index = 1;
			return;
		}

		Node *n1 = n->opr_obj->op[0];
		Node *n2 = n->opr_obj->op[1];

		if (n1->value == NULL || n2->value == NULL)
		{
			getState()->curThread()->throwException(newArithmeticException("value is null on opr '+='!")->addRef());
			freeSubNodes(n);
			return;
		}
		if (n1->value->getType() != NUMBER || n2->value->getType() != NUMBER)
		{
			getState()->curThread()->throwException(newArithmeticException("type error on opr '+='!")->addRef());
			freeSubNodes(n);
			return;
		}

		n->value = Allocator::allocateNumber(((Number*)n1->value)->getDoubleValue() + ((Number*)n2->value)->getDoubleValue());

		setValueToEnv(n1->var_obj->name, n->value);
		freeSubNodes(n);
		nodeLink->backAfterExec = true;
	}

	void __execSUB_EQ(NodeLink *nodeLink) {
		Node *n = nodeLink->node;
		if (nodeLink->index == 0) {
			doSubNodes(n);
			nodeLink->index = 1;
			return;
		}

		Node *n1 = n->opr_obj->op[0];
		Node *n2 = n->opr_obj->op[1];

		if (n1->value == NULL || n2->value == NULL)
		{
			getState()->curThread()->throwException(newArithmeticException("value is null on opr '-='!")->addRef());
			freeSubNodes(n);
			return;
		}
		if (n1->value->getType() != NUMBER || n2->value->getType() != NUMBER)
		{
			getState()->curThread()->throwException(newArithmeticException("type error on opr '-='!")->addRef());
			freeSubNodes(n);
			return;
		}

		n->value = Allocator::allocateNumber(((Number*)n1->value)->getDoubleValue() - ((Number*)n2->value)->getDoubleValue());

		setValueToEnv(n1->var_obj->name, n->value);
		freeSubNodes(n);
		nodeLink->backAfterExec = true;
	}

	void __execMUL_EQ(NodeLink *nodeLink) {
		Node *n = nodeLink->node;
		if (nodeLink->index == 0) {
			doSubNodes(n);
			nodeLink->index = 1;
			return;
		}

		Node *n1 = n->opr_obj->op[0];
		Node *n2 = n->opr_obj->op[1];

		if (n1->value == NULL || n2->value == NULL)
		{
			getState()->curThread()->throwException(newArithmeticException("value is null on opr '*='!")->addRef());
			freeSubNodes(n);
			return;
		}
		if (n1->value->getType() != NUMBER || n2->value->getType() != NUMBER)
		{
			getState()->curThread()->throwException(newArithmeticException("type error on opr '*='!")->addRef());
			freeSubNodes(n);
			return;
		}

		n->value = Allocator::allocateNumber(((Number*)n1->value)->getDoubleValue() * ((Number*)n2->value)->getDoubleValue());

		setValueToEnv(n1->var_obj->name, n->value);

		freeSubNodes(n);
	}

	void __execDIV_EQ(NodeLink *nodeLink) {
		Node *n = nodeLink->node;
		if (nodeLink->index == 0) {
			doSubNodes(n);
			nodeLink->index = 1;
			return;
		}

		Node *n1 = n->opr_obj->op[0];
		Node *n2 = n->opr_obj->op[1];

		if (n1->value == NULL || n2->value == NULL)
		{
			getState()->curThread()->throwException(newArithmeticException("value is null on opr '/='!")->addRef());
			freeSubNodes(n);
			return;
		}
		if (n1->value->getType() != NUMBER || n2->value->getType() != NUMBER)
		{
			getState()->curThread()->throwException(newArithmeticException("type error on opr '/='!")->addRef());
			freeSubNodes(n);
			return;
		}

		double d2 = ((Number*)n2->value)->getDoubleValue();
		if (d2 == 0)
		{
			getState()->curThread()->throwException(newArithmeticException("/ by zero on opr '/='!")->addRef());
			freeSubNodes(n);
			return;
		}

		n->value = Allocator::allocateNumber(((Number*)n1->value)->getDoubleValue() / ((Number*)n2->value)->getDoubleValue());

		setValueToEnv(n1->var_obj->name, n->value);
		freeSubNodes(n);
		nodeLink->backAfterExec = true;
	}

	void __execMOD_EQ(NodeLink *nodeLink) {
		Node *n = nodeLink->node;
		if (nodeLink->index == 0) {
			doSubNodes(n);
			nodeLink->index = 1;
			return;
		}

		Node *n1 = n->opr_obj->op[0];
		Node *n2 = n->opr_obj->op[1];

		if (n1->value == NULL || n2->value == NULL)
		{
			getState()->curThread()->throwException(newArithmeticException("value is null on opr '%='!")->addRef());
			freeSubNodes(n);
			return;
		}
		if (n1->value->getType() != NUMBER || n2->value->getType() != NUMBER)
		{
			getState()->curThread()->throwException(newArithmeticException("type error on opr '%='!")->addRef());
			freeSubNodes(n);
			return;
		}

		int i1 = ((Number*)n1->value)->getIntValue();
		int i2 = ((Number*)n2->value)->getIntValue();
		int i3 = i1 % i2;

		n->value = Allocator::allocateNumber(i3);

		setValueToEnv(n1->var_obj->name, n->value);
		freeSubNodes(n);
		nodeLink->backAfterExec = true;
	}

	void __execBREAK(NodeLink *nodeLink, langXThread * thread) {
		
		if (!thread->isInLoop() && !thread->isInSwitch())
		{
			getState()->curThread()->throwException(newUnsupportedOperationException("invalid break stmt.")->addRef());
			//printf("无效的BREAK 语句 ");
			return;
		}

		do {
			if (nodeLink == nullptr) {
				break;
			}

			Node *n = nodeLink->node;
			nodeLink = nodeLink->previous;
			thread->endExecute();

			if (n->type == NodeType::NODE_OPERATOR) {
				int opr = n->opr_obj->opr;
				if (opr == WHILE || opr == FOR) {
					// 找到了该节点
					break;
				}
			}
		} while (true);
		
	}

	void __execRETURN(NodeLink *nodeLink, langXThread * thread) {
		Node *n = nodeLink->node;

		if (!thread->isInFunction())
		{
			getState()->curThread()->throwException(newUnsupportedOperationException("invalid return stmt.")->addRef());
			//printf("无效的 return 语句");
			return;
		}

		if (nodeLink->index == 0) {
			// 确定返回值
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
				}
				else {
					thread->beginExecute(a, true);
				}
			}

			nodeLink->index = 1;
			return;
		}
		
		Node * a = n->opr_obj->op[0];
		if (a == NULL)
		{
			n->value = NULL;
		}
		else {
			n->value = a->value->clone();
		}

		freeSubNodes(n);
		thread->setFunctionResult(n->value);

		// 回退节点
		do {
			if (nodeLink == nullptr) {
				break;
			}

			Node *n = nodeLink->node;
			
			if (n->type == NodeType::NODE_OPERATOR) {
				int opr = n->opr_obj->opr;
				if (opr == FUNC_CALL || opr == CLAXX_FUNC_CALL || opr == SCOPE_FUNC_CALL) {
					// 找到了该节点
					nodeLink->index = 1000;       // 函数已经获取到返回值
					break;
				}
			}

			nodeLink = nodeLink->previous;
			thread->endExecute();
		} while (true);
	}

	// 自增运算符 ++ 
	void __execINC_OP(NodeLink *nodeLink) {
		Node *n = nodeLink->node;
		if (nodeLink->index == 0) {
			doSubNodes(n);
			nodeLink->index = 1;
			return;
		}

		Node *n1 = n->opr_obj->op[0];

		if (n1 == NULL)
		{
			getState()->curThread()->throwException(newArithmeticException("node is null on opr '++'!")->addRef());
			freeSubNodes(n);
			return;
		}

		if (n1->value == NULL)
		{
			getState()->curThread()->throwException(newArithmeticException("value is null on opr '++'!")->addRef());
			freeSubNodes(n);
			return;
		}

		Object * left = n1->value;
		if (left != NULL && left->getType() == OBJECT) {
			langXObjectRef * ref1 = (langXObjectRef*)left;
			Function *func1 = ref1->getFunction("operator++");
			if (func1)
			{
				X3rdArgs _3rdArgs;
				memset(&_3rdArgs, 0, sizeof(X3rdArgs));
				_3rdArgs.index = 0;
				n->value = callFunction(left, func1, &_3rdArgs);

				freeSubNodes(n);
				return;
			}
		}

		if (n1->value->getType() != NUMBER)
		{
			getState()->curThread()->throwException(newArithmeticException("value is null on opr '++'!")->addRef());
			freeSubNodes(n);
			return;
		}

		if (!n->state.isSuffix)
		{
			// 前缀自增
			n->value = Allocator::allocateNumber(((Number*)n1->value)->getDoubleValue() + 1);
			n1->postposition = n->value->clone();
		}
		else {
			//  后缀自增
			n->value = n1->value->clone();
			n1->postposition = Allocator::allocateNumber(((Number*)n1->value)->getDoubleValue() + 1);
		}

		freeSubNodes(n);
		nodeLink->backAfterExec = true;
	}

	// 自减运算符 -- 
	void __execDEC_OP(NodeLink *nodeLink) {
		Node *n = nodeLink->node;
		if (nodeLink->index == 0) {
			doSubNodes(n);
			nodeLink->index = 1;
			return;
		}

		/*
		 * 后置值 被加到 变量身上， 而非 ++/-- 操作符身上了。
		 */

		Node *n1 = n->opr_obj->op[0];
		if (n1 == NULL)
		{
			getState()->curThread()->throwException(newArithmeticException("node is null on opr '--'!")->addRef());
			freeSubNodes(n);
			return;
		}

		if (n1->value == NULL)
		{
			getState()->curThread()->throwException(newArithmeticException("value is null on opr '--'!")->addRef());
			freeSubNodes(n);
			return;
		}

		Object * left = n1->value;
		if (left != NULL && left->getType() == OBJECT) {
			langXObjectRef * ref1 = (langXObjectRef*)left;
			Function *func1 = ref1->getFunction("operator--");
			if (func1)
			{
				X3rdArgs _3rdArgs;
				memset(&_3rdArgs, 0, sizeof(X3rdArgs));
				_3rdArgs.index = 0;
				n->value = callFunction(left, func1, &_3rdArgs);

				freeSubNodes(n);
				return;
			}
		}

		if (n1->value->getType() != NUMBER)
		{
			getState()->curThread()->throwException(newArithmeticException("value is null on opr '++'!")->addRef());
			freeSubNodes(n);
			return;
		}

		if (!n->state.isSuffix)
		{
			// 前缀自减
			n->value = Allocator::allocateNumber(((Number*)n1->value)->getDoubleValue() - 1);
			n1->postposition = n->value->clone();
		}
		else {
			//  后缀自减
			n->value = n1->value->clone();
			n1->postposition = Allocator::allocateNumber(((Number*)n1->value)->getDoubleValue() - 1);
		}

		freeSubNodes(n);
		nodeLink->backAfterExec = true;
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

		langXThread * thread = getState()->curThread();
		for (size_t i = 0; i < n->opr_obj->op_count; i++)
		{
			Node *run = n->opr_obj->op[i];
			if (run == NULL)
			{
				continue;
			}
			__execNode(run);

			if (getState()->curThread()->isInException())
			{
				freeSubNodes(n);
				return;
			}

			if (thread->isInContinue())
			{
				break;
			}
			if (thread->isInBreak())
			{
				break;
			}
			if (thread->isInReturn())
			{
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
	void __exec62(NodeLink *nodeLink) {
		Node *n = nodeLink->node;
		if (nodeLink->index == 0) {
			doSubNodes(n);
			nodeLink->index = 1;
			return;
		}

		Node *n1 = n->opr_obj->op[0];
		Node *n2 = n->opr_obj->op[1];

		if (n1->value == NULL || n2->value == NULL)
		{
			getState()->curThread()->throwException(newArithmeticException("value is null on opr '>'!")->addRef());
			freeSubNodes(n);
			return;
		}
		if (n1->value->getType() != NUMBER || n2->value->getType() != NUMBER)
		{
			getState()->curThread()->throwException(newArithmeticException("type error on opr '>'!")->addRef());
			freeSubNodes(n);
			return;
		}

		double a = ((Number*)n1->value)->getDoubleValue();
		double b = ((Number*)n2->value)->getDoubleValue();

		if (a > b)
		{
			n->value = Allocator::allocateNumber(1);
		}
		else {
			n->value = Allocator::allocateNumber(0);
		}

		doSuffixOperation(n);
		freeSubNodes(n);
		nodeLink->backAfterExec = true;
	}

	// 大于等于
	void __execGE_OP(NodeLink *nodeLink) {
		Node *n = nodeLink->node;
		if (nodeLink->index == 0) {
			doSubNodes(n);
			nodeLink->index = 1;
			return;
		}

		Node *n1 = n->opr_obj->op[0];
		Node *n2 = n->opr_obj->op[1];

		if (n1->value == NULL || n2->value == NULL)
		{
			getState()->curThread()->throwException(newArithmeticException("value is null on opr '>='!")->addRef());
			freeSubNodes(n);
			return;
		}
		if (n1->value->getType() != NUMBER || n2->value->getType() != NUMBER)
		{
			getState()->curThread()->throwException(newArithmeticException("type error on opr '>='!")->addRef());
			freeSubNodes(n);
			return;
		}

		double a = ((Number*)n1->value)->getDoubleValue();
		double b = ((Number*)n2->value)->getDoubleValue();

		if (a >= b)
		{
			n->value = Allocator::allocateNumber(1);
		}
		else {
			n->value = Allocator::allocateNumber(0);
		}

		doSuffixOperation(n);
		freeSubNodes(n);
		nodeLink->backAfterExec = true;
	}

	// 符号： <
	void __exec60(NodeLink *nodeLink) {
		Node *n = nodeLink->node;
		if (nodeLink->index == 0) {
			doSubNodes(n);
			nodeLink->index = 1;
			return;
		}

		Node *n1 = n->opr_obj->op[0];
		Node *n2 = n->opr_obj->op[1];

		if (n1->value == NULL || n2->value == NULL)
		{
			getState()->curThread()->throwException(newArithmeticException("value is null on opr '<'!")->addRef());
			freeSubNodes(n);
			return;
		}
		if (n1->value->getType() != NUMBER || n2->value->getType() != NUMBER)
		{
			getState()->curThread()->throwException(newArithmeticException("type error on opr '<'!")->addRef());
			freeSubNodes(n);
			return;
		}

		double a = ((Number*)n1->value)->getDoubleValue();
		double b = ((Number*)n2->value)->getDoubleValue();

		if (a < b)
		{
			n->value = Allocator::allocateNumber(1);
		}
		else {
			n->value = Allocator::allocateNumber(0);
		}

		doSuffixOperation(n);
		freeSubNodes(n);
		nodeLink->backAfterExec = true;
	}

	// 小于等于
	void __execLE_OP(NodeLink *nodeLink) {
		Node *n = nodeLink->node;
		if (nodeLink->index == 0) {
			doSubNodes(n);
			nodeLink->index = 1;
			return;
		}

		Node *n1 = n->opr_obj->op[0];
		Node *n2 = n->opr_obj->op[1];

		if (n1->value == NULL || n2->value == NULL)
		{
			getState()->curThread()->throwException(newArithmeticException("value is null on opr '<='!")->addRef());
			freeSubNodes(n);
			return;
		}
		if (n1->value->getType() != NUMBER || n2->value->getType() != NUMBER)
		{
			getState()->curThread()->throwException(newArithmeticException("type error on opr '<='!")->addRef());
			freeSubNodes(n);
			return;
		}

		double a = ((Number*)n1->value)->getDoubleValue();
		double b = ((Number*)n2->value)->getDoubleValue();

		if (a <= b)
		{
			n->value = Allocator::allocateNumber(1);
		}
		else {
			n->value = Allocator::allocateNumber(0);
		}

		doSuffixOperation(n);
		freeSubNodes(n);
		nodeLink->backAfterExec = true;
	}

	// 等于
	void __execEQ_OP(NodeLink *nodeLink) {
		Node *n = nodeLink->node;
		if (nodeLink->index == 0) {
			doSubNodes(n);
			nodeLink->index = 1;
			return;
		}

		Node *n1 = n->opr_obj->op[0];
		Node *n2 = n->opr_obj->op[1];

		if (n1->value == NULL || n2->value == NULL)
		{
			getState()->curThread()->throwException(newArithmeticException("value is null on opr '=='!")->addRef());
			freeSubNodes(n);
			return;
		}

		Object * left = n1->value;
		Object * right = n2->value;

		if (left->getType() == NULLOBJECT )
		{
			if (right->getType() == NULLOBJECT)
			{
				n->value = Allocator::allocateNumber(1);
			}else{
				n->value = Allocator::allocateNumber(0);
			}
			
		}
		else if (left->getType() == NUMBER )
		{
			if (n2->value->getType() == NUMBER)
			{
				double a = ((Number*)n1->value)->getDoubleValue();
				double b = ((Number*)n2->value)->getDoubleValue();

				if (a == b)
				{
					n->value = Allocator::allocateNumber(1);
				}
				else {
					n->value = Allocator::allocateNumber(0);
				}
			}else{
				n->value = Allocator::allocateNumber(0);
			}
			
		}
		else if (left->getType() == STRING )
		{
			if (n2->value->getType() == STRING)
			{
				// 字符串比较
				const char * a = ((String*)n1->value)->getValue();
				const char * b = ((String*)n2->value)->getValue();

				if (strcmp(a, b) == 0)
				{
					n->value = Allocator::allocateNumber(1);
				}
				else {
					n->value = Allocator::allocateNumber(0);
				}
			}else{
				n->value = Allocator::allocateNumber(0);
			}
		}
		else if (left->getType() == OBJECT) {
			langXObjectRef * ref1 = (langXObjectRef*)left;
			Function *func1 = ref1->getFunction("operator==");
			if (func1)
			{
				X3rdArgs _3rdArgs;
				memset(&_3rdArgs, 0, sizeof(X3rdArgs));
				_3rdArgs.args[0] = right;
				_3rdArgs.index = 1;
				n->value = callFunction(left, func1, &_3rdArgs);

				freeSubNodes(n);
				return;
			}

			// check 描述字符串
			if (right && right->getType() == OBJECT)
			{
				langXObjectRef * ref2 = (langXObjectRef*)right;
				if (strcmp(ref1->characteristic(), ref2->characteristic()) == 0)
				{
					n->value = Allocator::allocateNumber(1);
				}
				else {
					n->value = Allocator::allocateNumber(0);
				}

			}
			else if (right->getType() == NULLOBJECT || right->getType() == XARRAY)
			{
				n->value = Allocator::allocateNumber(0);
			}
			else {
				getState()->curThread()->throwException(newArithmeticException("type error on opr '=='! only can number or string!")->addRef());
				n->value = Allocator::allocateNumber(0);
			}

		}
		else if (left->getType() == XARRAY)
		{
			// 数组
			if (right && right->getType() == OBJECT)
			{
				n->value = Allocator::allocateNumber(0);
			}
			else if (right->getType() == NULLOBJECT)
			{
				n->value = Allocator::allocateNumber(0);
			}
			else if (right->getType() == XARRAY)
			{
				if (strcmp(left->characteristic(), right->characteristic()) == 0)
				{
					n->value = Allocator::allocateNumber(1);
				}
				else {
					n->value = Allocator::allocateNumber(0);
				}
			}
			else {
				getState()->curThread()->throwException(newArithmeticException("type error on opr '=='! only can number or string!")->addRef());
				n->value = Allocator::allocateNumber(0);
			}
		}
		else {
			//printf("类型不同，无法比较");
			getState()->curThread()->throwException(newArithmeticException("type error on opr '=='! only can number or string!")->addRef());
			n->value = Allocator::allocateNumber(0);
		}

		doSuffixOperation(n);
		freeSubNodes(n);
		nodeLink->backAfterExec = true;
	}

	// 不等于
	void __execNE_OP(NodeLink *nodeLink) {
		Node *n = nodeLink->node;
		if (nodeLink->index == 0) {
			doSubNodes(n);
			nodeLink->index = 1;
			return;
		}

		Node *n1 = n->opr_obj->op[0];
		Node *n2 = n->opr_obj->op[1];

		if (n1->value == NULL || n2->value == NULL)
		{
			getState()->curThread()->throwException(newArithmeticException("value is null on opr '!='!")->addRef());
			freeSubNodes(n);
			return;
		}


		Object * left = n1->value;
		Object * right = n2->value;

		if (left->getType() == NULLOBJECT)
		{
			if (right->getType() == NULLOBJECT)
			{
				n->value = Allocator::allocateNumber(0);
			}
			else {
				n->value = Allocator::allocateNumber(1);
			}

		}else
		if (left->getType() == NUMBER )
		{
			if (n2->value->getType() == NUMBER)
			{
				double a = ((Number*)n1->value)->getDoubleValue();
				double b = ((Number*)n2->value)->getDoubleValue();

				if (a != b)
				{
					n->value = Allocator::allocateNumber(1);
				}
				else {
					n->value = Allocator::allocateNumber(0);
				}
			}
			else {
				n->value = Allocator::allocateNumber(1);
			}
			
		}
		else if (left->getType() == STRING )
		{
			// 左侧类型为字符串
			if (n2->value->getType() == STRING)
			{
				// 如果右侧类型也为字符串

				// 字符串比较
				const char * a = ((String*)n1->value)->getValue();
				const char * b = ((String*)n2->value)->getValue();

				if (strcmp(a, b) != 0)
				{
					n->value = Allocator::allocateNumber(1);
				}
				else {
					n->value = Allocator::allocateNumber(0);
				}
			}
			else {

				n->value = Allocator::allocateNumber(1);
			}
		}
		else if (left->getType() == OBJECT) {
			langXObjectRef * ref1 = (langXObjectRef*)left;
			Function *func1 = ref1->getFunction("operator!=");
			if (func1)
			{
				X3rdArgs _3rdArgs;
				memset(&_3rdArgs, 0, sizeof(X3rdArgs));
				_3rdArgs.args[0] = right;
				_3rdArgs.index = 1;
				n->value = callFunction(left, func1, &_3rdArgs);

				freeSubNodes(n);
				return;
			}

			// check 描述字符串
			if (right && right->getType() == OBJECT)
			{
				langXObjectRef * ref2 = (langXObjectRef*)right;
				if (strcmp(ref1->characteristic(), ref2->characteristic()) == 0)
				{
					n->value = Allocator::allocateNumber(0);
				}
				else {
					n->value = Allocator::allocateNumber(1);
				}

			}
			else if (right->getType() == NULLOBJECT || right->getType() == XARRAY)
			{
				n->value = Allocator::allocateNumber(1);
			}
			else {
				getState()->curThread()->throwException(newArithmeticException("type error on opr '=='! only can number or string!")->addRef());
				n->value = Allocator::allocateNumber(0);
			}
		}
		else if (left->getType() == XARRAY)
		{
			// 数组
			if (right->getType() == OBJECT)
			{
				n->value = Allocator::allocateNumber(1);
			}
			else if (right->getType() == NULLOBJECT)
			{
				n->value = Allocator::allocateNumber(1);
			}
			else if (right->getType() == XARRAY)
			{
				if (strcmp(left->characteristic(), right->characteristic()) == 0)
				{
					n->value = Allocator::allocateNumber(0);
				}
				else {
					n->value = Allocator::allocateNumber(1);
				}
			}
			else {
				getState()->curThread()->throwException(newArithmeticException("type error on opr '=='! only can number or string!")->addRef());
				n->value = Allocator::allocateNumber(0);
			}
		}
		else {
			//printf("类型不同，无法比较");
			getState()->curThread()->throwException(newArithmeticException("type error on opr '!='! only can number or string!")->addRef());
			n->value = Allocator::allocateNumber(0);
		}

		doSuffixOperation(n);
		freeSubNodes(n);
		nodeLink->backAfterExec = true;
	}

	void __execOPAND(NodeLink *nodeLink) {
		Node *n = nodeLink->node;
		if (nodeLink->index == 0) {
			doSubNodes(n);
			nodeLink->index = 1;
			return;
		}

		stateExtends(n);
		bool f = __tryConvertToBool(n->opr_obj->op[0]);
		if (getState()->curThread()->isInException())
		{
			freeSubNodes(n);
			return;
		}
		if (f)
		{
			n->value = __tryConvertToBool(n->opr_obj->op[1]) ? n->value = Allocator::allocateNumber(1) : n->value = Allocator::allocateNumber(0);
		}
		else {
			n->value = Allocator::allocateNumber(0);
		}

		freeSubNodes(n);
		nodeLink->backAfterExec = true;
	}

	void __execOPOR(NodeLink *nodeLink) {
		Node *n = nodeLink->node;
		if (nodeLink->index == 0) {
			doSubNodes(n);
			nodeLink->index = 1;
			return;
		}

		stateExtends(n);
		bool f = __tryConvertToBool(n->opr_obj->op[0]);
		if (getState()->curThread()->isInException())
		{
			freeSubNodes(n);
			return;
		}

		if (f)
		{
			n->value = Allocator::allocateNumber(1);
		}
		else {
			n->value = __tryConvertToBool(n->opr_obj->op[1]) ? n->value = Allocator::allocateNumber(1) : n->value = Allocator::allocateNumber(0);
		}

		freeSubNodes(n);
		nodeLink->backAfterExec = true;
	}

	void __execIF(NodeLink *nodeLink, langXThread *thread) {

		Node *n = nodeLink->node;
		Node *n1 = n->opr_obj->op[0];
		if (nodeLink->index == 0) {
			thread->beginExecute(n1, true);
			nodeLink->index = 1;
			return;
		}
		else if (nodeLink->index == 1) {
			// 判断条件，确定 应该执行的点
			
			bool f = __tryConvertToBool(n1);

			if (f)
			{

				Node * a = n->opr_obj->op[1];
				if (a != NULL)
				{
					thread->beginExecute(a, true);
				}

			}
			else {
				if (n->opr_obj->op_count >= 3)
				{
					Node * a = n->opr_obj->op[2];
					if (a != NULL)
					{
						thread->beginExecute(a, true);
					}

				}
			}
			nodeLink->index = 2;
			return;
		}

		doSuffixOperation(n);
		// 清理掉 所有复制  值 占用的内存
		freeSubNodes(n);
		nodeLink->backAfterExec = true;
	}

	void __execWHILE(Node *n) {
		if (n == NULL || n->opr_obj == NULL || n->opr_obj->op_count != 2)
		{
			return;
		}

		// 先执行条件 节点 ,然后判断条件 节点的值， 然后释放条件 节点的内存
		// 循环执行结束 ， 释放掉  所有节点值 的内存
		langXThread * thread = getState()->curThread();
		thread->setInLoop(true);

		Node *conNode = n->opr_obj->op[0];
		while (__tryConvertToBool(conNode))
		{
			doSuffixOperation(conNode);
			Allocator::free(conNode->value);
			conNode->value = NULL;

			Node *run = n->opr_obj->op[1];
			if (run == NULL)
			{
				return;
			}
			__execNode(run);
			
			freeSubNodes(run);

			if (thread->isInBreak())
			{
				break;
			}
			if (thread->isInReturn())
			{
				if (run->value == NULL)
				{
					n->value = NULL;
				}
				else {
					n->value = run->value->clone();
				}

				break;
			}

			// 重置 run 节点以及其子节点的状态
			recursiveFreeNodeValue(run);

			// 如果当前环境为一个死亡环境， 则直接返回
			// TODO 清理内存
			if (getState()->curThread()->isInException())
			{
				return;
			}
		}

		// 清理条件节点的内容
		doSuffixOperation(conNode);
		Allocator::free(conNode->value);
		conNode->value = NULL;

		thread->setInLoop(false);
		doSuffixOperation(n);
		freeSubNodes(n);
	}

	void __execFOR(Node *n) {
		if (n == NULL || n->opr_obj == NULL || n->opr_obj->op_count != 4)
		{
			return;
		}

		langXThread * thread = getState()->curThread();
		thread->setInLoop(true);

		Node *conNode = n->opr_obj->op[1];
		// 后置节点
		Node *sNode = n->opr_obj->op[2];
		for (__execNode(n->opr_obj->op[0]); __tryConvertToBool(conNode);  )
		{
			doSuffixOperation(conNode);
			Allocator::free(conNode->value);
			conNode->value = NULL;

			Node *run = n->opr_obj->op[3];
			if (run == NULL)
			{
				continue;
			}
			__execNode(run);
			freeSubNodes(run);
			if (thread->isInBreak())
			{
				break;
			}
			if (thread->isInReturn())
			{
				if (run->value == NULL)
				{
					n->value = NULL;
				}
				else {
					n->value = run->value->clone();
				}
				break;
			}

			recursiveFreeNodeValue(run);

			// 如果当前环境为一个死亡环境， 则直接返回
			// TODO 清理内存
			if (getState()->curThread()->isInException())
			{
				return;
			}

			__execNode(sNode);
			doSuffixOperation(sNode);
			freeSubNodes(sNode);
			Allocator::free(sNode->value);
			sNode->value = nullptr;
		}

		// 清理条件节点的内容
		doSuffixOperation(conNode);
		Allocator::free(conNode->value);
		conNode->value = NULL;

		thread->setInLoop(false);
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
			getState()->curThread()->throwException(newUnsupportedOperationException("null condition value in switch()!")->addRef());
			return;
		}
		//printf("switch id_expr value: %f\n" , ((Number*)id_expr->value)->getDoubleValue());
	
		langXThread * thread = getState()->curThread();
		thread->setInLoop(true);
		Node * case_list = n->opr_obj->op[1];
		//printf("case_list op_count: %d\n", case_list->opr_obj->op_count);
		for (int i = 0; i < case_list->opr_obj->op_count; i++)
		{
			// 如果当前环境为一个死亡环境， 则直接返回
			// TODO 清理内存
			if (getState()->curThread()->isInException())
			{
				return;
			}

			Node * t = case_list->opr_obj->op[i];
			if (t == NULL)
			{
				continue;
			}

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

			if (thread->isInBreak() || thread->isInContinue())
			{
				break;
			}
			if (thread->isInReturn())
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

		thread->setInLoop(false);
		freeSubNodes(n);
	}

	void __execCASE_LIST(Node *n) {

		langXThread * thread = getState()->curThread();
		bool flag = true;
		for (int i = 0; i < n->opr_obj->op_count; i++)
		{
			// 如果当前环境为一个死亡环境， 则直接返回
			// TODO 清理内存
			if (getState()->curThread()->isInException())
			{
				return;
			}

			Node * t = n->opr_obj->op[i];
			if (t == NULL)
			{
				continue;
			}

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
			
			if (thread->isInBreak() || thread->isInContinue())
			{
				break;
			}
			if (thread->isInReturn())
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

		langXThread * thread = getState()->curThread();

		if (a == ((Number*)con->value)->getDoubleValue() || !thread->isInCaseNeedCon())
		{
			thread->setInCaseNeedCon(false);
			n->switch_info.isInCase = true;
			Node * t = n->opr_obj->op[1];
			if (t != NULL)
			{
				__execNode(t);

				if (thread->isInReturn())
				{
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

	void __execUMINUS(NodeLink *nodeLink) {
		Node *n = nodeLink->node;
		if (nodeLink->index == 0) {
			doSubNodes(n);
			nodeLink->index = 1;
			return;
		}

		Node *n1 = n->opr_obj->op[0];

		if (n1->value == NULL) {
			//printf("__execUMINUS n1->value is NULL\n");
			getState()->curThread()->throwException(newArithmeticException("value is null on opr '-'!")->addRef());
			freeSubNodes(n);
			return;
		}
		if (n1->value->getType() != NUMBER)
		{
			//printf("ERROR:  __execUMINUS is NOT NUMBER...  \n");
			getState()->curThread()->throwException(newArithmeticException("type error on opr '-'! only can number!")->addRef());
			freeSubNodes(n);
			return;
		}
		else {
			n->value = Allocator::allocateNumber(-((Number*)n1->value)->getDoubleValue());
		}

		freeSubNodes(n);
		nodeLink->backAfterExec = true;
		//printf("%.2f\n", ((Number*)n->value)->getDoubleValue());
	}

	// 执行一个函数
	void __execFUNC_CALL(NodeLink *nodeLink,langXThread *thread) {	
		Node *n = nodeLink->node;

		Node *n1 = n->opr_obj->op[0];
		if (nodeLink->index == 0) {
			thread->beginExecute(n1, true);
			nodeLink->index = 1;
			return;
		}
		

		std::string remark = fileInfoString(n->fileinfo);
		XArgsList *args = (XArgsList *)n->opr_obj->op[1]->ptr_u;
		char * name = n1->var_obj->name;
		bool flag = true;
		if (n1->value != NULL)
		{
			if (n1->value->getType() == FUNCTION)
			{
				FunctionRef *f = (FunctionRef*)n1->value;
				NodeLink *putNodeLink = nullptr;
				if (nodeLink->ptr_u == NULL) {
					// 第一次执行， 需要让函数确认所有的参数 
					putNodeLink = newNodeLink(nullptr, n );
					nodeLink->ptr_u = putNodeLink;
					f->call(args, remark.c_str(), putNodeLink);
					return;
				}
				else {
					putNodeLink = (NodeLink*)nodeLink->ptr_u;
					nodeLink->ptr_u = nullptr;
				}

				n->value = f->call(args, remark.c_str(), putNodeLink);
				freeNodeLink(putNodeLink);
				flag = false;
			}
			else if (n1->value->getType() == STRING)
			{
				std::string str = "call function ";
				String *n1Str = (String*)n1->value;
				str += n1Str->getValue();
				str += " by var ";
				str += name;
				str += " ";
				str += remark;
				n->value = call(n1Str->getValue(), args, str.c_str());
				flag = false;
			}
		}

		if (flag)
		{
			n->value = call(name, args, remark.c_str());
			//printf("func %s exec end\n" , name);
		}

		doSuffixOperationArgs(args);
		Allocator::free(n1->value);
		n1->value = NULL;
		nodeLink->backAfterExec = true;
	}

	void __execNEW(Node *n) {
		// new 一个对象
		char *className = n->opr_obj->op[0]->var_obj->name;
		ClassInfo *claxxInfo = getState()->getClass(className);
		if (claxxInfo == NULL)
		{
			getState()->curThread()->throwException(newClassNotFoundException(className)->addRef());
			return;
		}
		langXObject *object = claxxInfo->newObject();
		if (object == NULL)
		{
			getState()->curThread()->throwException(newClassNotFoundException(className)->addRef());
			return;
		}
		langXObjectRef * objectRef = object->addRef();
		objectRef->setEmergeEnv(getState()->curThread()->getCurrentEnv());


		//objectRef->setMembersEmergeEnv(env);
		//getState()->addEnvToList(env);

		Node *argNode = n->opr_obj->op[1];
		if (argNode != NULL)
		{
			XArgsList *args = (XArgsList *)argNode->ptr_u;
			object->callConstructor(args, fileInfoString(n->fileinfo).c_str());

			if (getState()->curThread()->isInException())
			{
				return;
			}
		}

		n->value = objectRef;
	}

	void __execCLAXX_BODY(NodeLink *nodeLink) {

		Node *n = nodeLink->node;
		if (nodeLink->index == 0) {
			doSubNodes(n);
			nodeLink->index = 1;
			return;
		}
		
		freeSubNodes(n);
		nodeLink->backAfterExec = true;
	}

	// 变量声明
	void __execVAR_DECLAR(Node *n) {

		// 都初始为 null
		// 数组要赋值
		Object *obj = Allocator::allocate(NULLOBJECT);
		obj->setEmergeEnv(getState()->curThread()->getCurrentEnv());
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
						getState()->curThread()->throwException(newException("Inner Error! delar array erorr!")->addRef());
						Allocator::free(obj);
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
							getState()->curThread()->throwException(newException("error array length !")->addRef());
							return;
						}

						len = ((Number*)t->value)->getIntValue();
						Allocator::free(t->value);
						t->value = nullptr;
					}
					XArray *array1 = Allocator::allocateArray(len);
					char *name = an->name;
					Object *arrayRef = array1->addRef();
					arrayRef->setEmergeEnv(getState()->curThread()->getCurrentEnv());
					setValueToEnv(name, arrayRef);

				}
				continue;
			}

			char *name = t->var_obj->name;
			setValueToEnv(name, obj);
		}

		Allocator::free(obj);
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
			getState()->curThread()->throwException(newTypeErrorException(tmp)->addRef());
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
				n->value = Allocator::allocateNumber(arrayRef->getLength());
			}
			else {
				char tmp[100] = { 0 };
				sprintf(tmp, "no member %s in array.", memberName);
				getState()->curThread()->throwException(newNoClassMemberException(tmp)->addRef());
			}

			freeSubNodes(n);
			return;
		}
		else if (n1->value->getType() == STRING) {

			String * str = (String*)n1->value;
			if (strcmp(memberName, "length") == 0)
			{
				// string.length.
				n->value = Allocator::allocateNumber(str->size());
			}
			else {
				char tmp[100] = { 0 };
				sprintf(tmp, "no member %s in string.", memberName);
				getState()->curThread()->throwException(newNoClassMemberException(tmp)->addRef());
			}

			freeSubNodes(n);
			return;
		}

		if (n1->value->getType() != OBJECT)
		{
			getState()->curThread()->throwException(newTypeErrorException("left value is not a object.")->addRef());
			//printf("left value %s is not class object or array  !\n", n1->var_obj->name);
			freeSubNodes(n);
			return;
		}

		langXObjectRef* objectRef = (langXObjectRef*)n1->value;

		Function *func1 = objectRef->getFunction("operator.");
		if (func1)
		{
			X3rdArgs _3rdArgs;
			memset(&_3rdArgs, 0, sizeof(X3rdArgs));
			String astr(memberName);
			_3rdArgs.args[0] = &astr;
			_3rdArgs.index = 1;
			n->value = callFunction(objectRef, func1, &_3rdArgs);

			freeSubNodes(n);
			return;
		}

		Object *t = objectRef->getMember(memberName);
		if (t == NULL || (t!=NULL && t->isLocal()))
		{
			// 变量未找到， 或者变量是一个local 

			// check 函数  回头再check 
			Function *func = objectRef->getFunction(memberName);
			if (func != nullptr)
			{
				FunctionRef *fr = Allocator::allocateFunctionRef(func);
				fr->setObj(objectRef->getRefObject());
				fr->setEmergeEnv(getState()->curThread()->getCurrentEnv());
				t = fr;
			}
			else {
				char tmp[100] = { 0 };
				sprintf(tmp, "no member %s in class %s.", memberName, objectRef->getClassInfo()->getName());
				getState()->curThread()->throwException(newNoClassMemberException(tmp)->addRef());
				freeSubNodes(n);
				return;
			}

		}
		n->value = t->clone();
		if (n->ptr_u != NULL)
		{
			delete ((langXObjectRef*)n->ptr_u);
			n->ptr_u = NULL;
		}
		n->ptr_u = objectRef->clone();

		freeSubNodes(n);
	}

	void __execCLAXX_FUNC_CALL(Node *n) {
		Node *n1 = n->opr_obj->op[0];
		__execNode(n1);

		if (n1->value == NULL)
		{
			getState()->curThread()->throwException(newTypeErrorException("left value is not class object !")->addRef());
			freeSubNodes(n);
			return;
		}

		if (n1->value->getType() == STRING)
		{
			// 
			n->value = callInnerFunc(n1->value, n->opr_obj->op[1]);
			return;
		}

		if (n1->value->getType() != OBJECT)
		{
			getState()->curThread()->throwException(newTypeErrorException("left value is not class object !")->addRef());
			freeSubNodes(n);
			return;
		}

		langXObjectRef* objectRef = (langXObjectRef*)n1->value;
		Environment *env = objectRef->getRefObject()->getObjectEnvironment();
		getState()->curThread()->newEnv2(env);

		// 根据语法解析文件可知， 第二个节点为一个函数调用节点
		Node *n2 = n->opr_obj->op[1];
		__execNode(n2);
		if (getState()->curThread()->isInException())
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

		getState()->curThread()->backEnv();

		freeSubNodes(n);
	}

	void __execRESTRICT(Node *n) {
		// 对当前环境进行限定， 限定后，不去搜索父级环境内容

		if (n->opr_obj->op_count <= 0)
		{
			getState()->curThread()->getCurrentEnv()->setRestrict(true);
		}
		else {

			getState()->curThread()->getCurrentEnv()->setRestrict(__tryConvertToBool(n->opr_obj->op[0]));

			freeSubNodes(n);
		}
	}

	// 执行 this.xxx
	void __execTHIS(Node *n) {

		Environment * env = getState()->curThread()->getNearestObjectEnv();
		if (!env)
		{
			//printf("cannot find the object on use this!\n");
			getState()->curThread()->throwException(newUnsupportedOperationException("invalid this stmt! cannot find the object on use this!")->addRef());
			return;
		}

		ObjectBridgeEnv *objEnv = (ObjectBridgeEnv*)env;
		if (n->opr_obj->op_count <= 0)
		{
			// no args.  获得自己就好了
			n->value = objEnv->getEnvObject()->addRef();
			return;
		}

		// 限定好像没什么卵用。。 
		//env->setRestrict(true);
		getState()->curThread()->newEnv2(env);

		langXObject *thisObj = objEnv->getEnvObject();
		Node *n1 = n->opr_obj->op[0];

		// 如果重复调用这个节点，则释放之前产生的内存 ， 以防内存泄漏
		if (n->var_obj != NULL)
		{
			if (n->var_obj->name != NULL)
			{
				free(n->var_obj->name);
				n->var_obj->name = NULL;
			}

			free(n->var_obj);
			n->var_obj = NULL;
		}

		//  产生变量的名字
		n->var_obj = (Variable*)calloc(1, sizeof(Variable));
		if (n1->type == NODE_VARIABLE)
		{
			n->var_obj->name = strdup(n1->var_obj->name);
			if (!thisObj->hasMember(n->var_obj->name))
			{
				// 没有那个成员
				char tmp[100] = { 0 };
				sprintf(tmp, "no class member %s in class %s!", n->var_obj->name, thisObj->getClassName());
				getState()->curThread()->throwException(newNoClassMemberException(tmp)->addRef());
				free(n->var_obj->name);
				free(n->var_obj);
				n->var_obj = NULL;
				return;
			}
		}
		else if (n1->type == NODE_OPERATOR)
		{
			// 语法解释器并没有实现这部分， 所以暂时先不管。
			n->var_obj->name = strdup(n1->opr_obj->op[1]->var_obj->name);
		}

		__execNode(n1);

		if (n1->value == NULL)
		{
			//printf("error in __execTHIS, n1->value == NULL");
			getState()->curThread()->throwException(newException("error in __execTHIS, n1->value == NULL")->addRef());
		}
		else {
			n->value = n1->value->clone();
		}

		getState()->curThread()->backEnv();
		freeSubNodes(n);
	}

	void __execSCOPE(Node *n) {

		if (n == NULL)
		{
			return;
		}

		char *className = n->opr_obj->op[0]->var_obj->name;
		ClassInfo *claxxInfo = getState()->getClass(className);
		if (claxxInfo == NULL)
		{
			getState()->curThread()->throwException(newClassNotFoundException(className)->addRef());
			return;
		}

		char *memberName = n->opr_obj->op[1]->var_obj->name;
		Object *t = claxxInfo->getMember(memberName);
		if (t == NULL || (t!=NULL &&t->isLocal()))
		{
			Function * tf = claxxInfo->getFunction(memberName);
			if (tf == NULL)
			{
				char tmp[100] = { 0 };
				sprintf(tmp, "no member %s in class %s.", memberName, className);
				getState()->curThread()->throwException(newNoClassMemberException(tmp)->addRef());
				return;
			}

			FunctionRef *fr = Allocator::allocateFunctionRef(tf);
			fr->setClaxx(claxxInfo);
			fr->setEmergeEnv(getState()->curThread()->getCurrentEnv());
			t = fr;
		}

		n->value = t->clone();
		//n->value->setEmergeEnv(getState()->curThread()->getCurrentEnv());
	}

	void __execSCOPE_FUNC_CALL(NodeLink *nodeLink) {

		Node *n = nodeLink->node;

		// 根据语法文件可知 n1 是一个SCOPE 类型
		Node *n1 = n->opr_obj->op[0];

		char *className = n1->opr_obj->op[0]->var_obj->name;
		ClassInfo *claxxInfo = getState()->getClass(className);
		if (claxxInfo == NULL)
		{
			getState()->curThread()->throwException(newClassNotFoundException(className)->addRef());
			return;
		}

		char *memberName = n1->opr_obj->op[1]->var_obj->name;
		Function *t = claxxInfo->getFunction(memberName);
		if (t == NULL)
		{
			char tmp[100] = { 0 };
			sprintf(tmp, "no function %s in class %s.", memberName, className);
			getState()->curThread()->throwException(newNoClassMemberException(tmp)->addRef());
			return;
		}

		ClassBridgeEnv *env = new ClassBridgeEnv(claxxInfo);
		getState()->curThread()->newEnv(env);

		// 根据语法解析文件得知， 第二个节点为参数节点
		XArgsList *args = (XArgsList *)n->opr_obj->op[1]->ptr_u;
		const char *remark = fileInfoString(n->fileinfo).c_str();
		n->value = callFunc(t, args, remark, nodeLink);

		doSuffixOperationArgs(args);
		//Allocator::free(n1->value);
		n1->value = NULL;

		getState()->curThread()->backEnv();
	}

	// 执行 try {}
	void __execXTRY(Node *n) {
		if (n == NULL)
		{
			return;
		}

		langXThread *thread = getState()->curThread();
		TryEnvironment * tryEnv = new TryEnvironment();
		//tryEnv->setCatchNode(n->opr_obj->op[1]);
		thread->newEnv(tryEnv);
		__execNode(n->opr_obj->op[0]);
		thread->backEnv();

		if (thread->isInException() )
		{
			// 发生了异常， 走 catch 节点
			thread->setInException(false);

			Environment *env = thread->newEnv();
			Node *cNode = n->opr_obj->op[1];
			env->putObject(cNode->opr_obj->op[0]->var_obj->name, thread->getThrownObj());
			// 执行catch 内的语句
			__execNode(cNode->opr_obj->op[1]);
			thread->backEnv();
		}

	}

	//  类型判断语句， 返回一个 true/false
	void __execXIS(Node *n) {

		Node *n1 = n->opr_obj->op[0];
		Node *n2 = n->opr_obj->op[1];

		__execNode(n1);
		if (getState()->curThread()->isInException())
		{
			freeSubNodes(n);
			return;
		}

		if (n1->value == NULL)
		{
			n->value = Allocator::allocateNumber(0);
		}
		else {
			//UNKNOWN=100, NUMBER , STRING, FUNCTION, OBJECT , NULLOBJECT ,XARRAY
			int i = 0;
			char *type = n2->var_obj->name;
			switch (n1->value->getType())
			{
			case NUMBER:
				if (strcmp(type, "Number") == 0)
				{
					i = 1;
				}
				break;
			case STRING:
				if (strcmp(type, "String") == 0)
				{
					i = 1;
				}
				break;
			case FUNCTION:
				if (strcmp(type, "Function") == 0)
				{
					i = 1;
				}
				break;
			case OBJECT:

				if (((langXObjectRef*)n1->value)->getClassInfo()->isInstanceOf(type))
				{
					i = 1;
				}
				break;
			case NULLOBJECT:
				if (strcmp(type, "Null") == 0)
				{
					i = 1;
				}
				break;
			case XARRAY:
				if (strcmp(type, "Array") == 0)
				{
					i = 1;
				}
				break;
			default:
				break;
			}

			n->value = Allocator::allocateNumber(i);
		}

		freeSubNodes(n);
	}


	// 包含其他文件
	void __execINCLUDE(Node *n) {
		if (n == NULL)
		{
			return;
		}

		char *tmp = n->opr_obj->op[0]->con_obj->sValue;

		char *filename = strndup(tmp + 1, strlen(tmp) - 2);

		char tmpMsg[1024] = { 0 };
		sprintf(tmpMsg, "require file %s  %s", filename, fileInfoString(n->fileinfo).c_str());
		getState()->curThread()->getStackTrace().newFrame(NULL, NULL, tmpMsg);

		//  把路径转换成绝对路径
		if (filename[0] != '/')
		{
			//  非绝对路径
			char tmpBuf[1024];
			const char *t1 = getState()->getParsingFile();
			if (realpath(t1, tmpBuf))
			{
				// ok 
				std::string a(tmpBuf);
				auto it = a.find_last_of('/');
				if (it != std::string::npos)
				{
					// 找到了最后一个 /
					a = a.substr(0, it + 1);
					a += filename;
					free(filename);
					filename = strdup(a.c_str());
				}
			}
		}


		getState()->includeFile(filename);

	}

	// 执行 require 其他文件
	void __execREQUIRE(Node *n) {
		if (n == NULL)
		{
			return;
		}

		char *tmp = n->opr_obj->op[0]->con_obj->sValue;

		char *filename = strndup(tmp + 1, strlen(tmp) - 2);

		char tmpMsg[1024] = { 0 };
		sprintf(tmpMsg, "require file %s  %s", filename, fileInfoString(n->fileinfo).c_str());
		getState()->curThread()->getStackTrace().newFrame(NULL, NULL, tmpMsg);

		//  把路径转换成绝对路径
		if (filename[0] != '/')
		{
			//  非绝对路径
			char tmpBuf[1024];
			const char *t1 = getState()->getParsingFile();
			if (realpath(t1, tmpBuf))
			{
				// ok 
				std::string a(tmpBuf);
				auto it = a.find_last_of('/');
				if (it != std::string::npos)
				{
					// 找到了最后一个 /
					a = a.substr(0, it + 1);
					a += filename;
					free(filename);
					filename = strdup(a.c_str());
				}
			}
		}


		getState()->requireFile(filename);

		// it's ok ?
	}

	void __execREQUIRE_ONCE(Node *n) {

		if (n == NULL)
		{
			return;
		}

		char *tmp = n->opr_obj->op[0]->con_obj->sValue;

		char *filename = strndup(tmp + 1, strlen(tmp) - 2);

		// 未执行过的文件
		char tmpMsg[1024] = { 0 };
		sprintf(tmpMsg, "require file %s  %s", filename, fileInfoString(n->fileinfo).c_str());
		getState()->curThread()->getStackTrace().newFrame(NULL, NULL, tmpMsg);

		//  把路径转换成绝对路径
		if (filename[0] != '/')
		{
			//  非绝对路径
			char tmpBuf[1024];
			if (realpath(getState()->getParsingFile(), tmpBuf))
			{
				// ok 
				std::string a(tmpBuf);
				auto it = a.find_last_of('/');
				if (it != std::string::npos)
				{
					// 找到了最后一个 /
					a = a.substr(0, it + 1);
					a += filename;
					free(filename);
					filename = strdup(a.c_str());
				}
			}
		}

		getState()->require_onceFile(filename);

		free(filename);

	}

	// 引入命名空间或者类
	void __execREF(Node *n) {

		//  深度为1 的环境为一个 脚本环境 或者命名空间环境。
		Environment *env = getState()->getScriptOrNSEnv();
		if (env == nullptr)
		{
			// error.
			getState()->curThread()->throwException(newUnsupportedOperationException("cannot ref operation now!")->addRef());
			return;
		}

		if (env->getType() != TScriptEnvironment)
		{
			getState()->curThread()->throwException(newUnsupportedOperationException("cannot ref not inner a script! check you are is a namespace?")->addRef());
			return;
		}

		ScriptEnvironment *scriptEnv = (ScriptEnvironment*)env;
		char *namespaceName = n->opr_obj->op[0]->con_obj->sValue;

		std::string str = std::string(namespaceName);
		XNameSpace *space = NULL;
		bool flag = true;

		auto dotIndex = str.find_first_of(".");

		while (dotIndex != std::string::npos)
		{
			std::string f = str.substr(0, dotIndex);
			str = str.substr(dotIndex + 1);
			dotIndex = str.find_first_of(".");

			// f is namespace name
			if (flag)
			{
				space = getState()->singleGetNameSpace(f.c_str());
				if (space == NULL)
				{
					break;
				}

				flag = false;
			}
			else {
				space = space->getNameSpace(f.c_str());
				if (space == NULL)
				{
					break;
				}
			}
		}

		if (flag)
		{
			space = getState()->singleGetNameSpace(str.c_str());
		}

		if (space == NULL)
		{
			//  error.  cannot find the namespace.
			char tmp[1024] = { 0 };
			sprintf(tmp, "cannot find namespace %s.", namespaceName);
			getState()->curThread()->throwException(newException(tmp)->addRef());
			return;
		}

		if (flag)
		{
			//  str 是用掉了已经
			scriptEnv->addNameSpace(space);
		}
		else {

			ClassInfo *c = space->getClass(str.c_str());
			if (c != NULL)
			{
				// 添加类
				scriptEnv->addClassInfo(c);
			}
			else {
				space = space->getNameSpace(str.c_str());

				if (space == NULL)
				{
					//  error.  cannot find the namespace.
					char tmp[1024] = { 0 };
					sprintf(tmp, "cannot find namespace %s.", namespaceName);
					getState()->curThread()->throwException(newException(tmp)->addRef());
					return;
				}
				scriptEnv->addNameSpace(space);
			}
		}


	}

	//  常量限制
	void __execCONST(Node *n) {
		if (!n) {
			return;
		}
		Object *obj = Allocator::allocate(NULLOBJECT);
		obj->setEmergeEnv(getState()->curThread()->getCurrentEnv());
		obj->setConst(true);
		for (int i = 0; i < n->opr_obj->op_count; i++)
		{
			Node *t = n->opr_obj->op[i];
			if (t == NULL)
			{
				continue;
			}
			if ( t->type != NODE_VARIABLE)
			{
				if (t->type == NODE_OPERATOR && t->opr_obj->opr == VAR_DECLAR)
				{
					__execCONST(t);
				}
				else 
				{
					// 抛出异常
					getState()->curThread()->throwException(newUnsupportedOperationException("invalid const stmt.")->addRef());
					return;
				}
				continue;
			}

			char *name = t->var_obj->name;
			Object *tmp = getState()->curThread()->getCurrentEnv()->getObjectSelf(name);
			if (tmp == NULL)
			{
				setValueToEnv(name, obj);
			}
			else {
				tmp->setConst(!tmp->isConst());
			}
			
		}

		Allocator::free(obj);

	}

	//  local 限制
	void __execLOCAL(Node *n) {
		if (!n) {
			return;
		}

		Object *obj = Allocator::allocate(NULLOBJECT);
		obj->setEmergeEnv(getState()->curThread()->getCurrentEnv());
		obj->setLocal(true);
		for (int i = 0; i < n->opr_obj->op_count; i++)
		{
			Node *t = n->opr_obj->op[i];
			if (t == NULL)
			{
				continue;
			}
			if (t->type != NODE_VARIABLE && t->type != NodeType::NODE_CLASS)
			{
				if (t->type == NODE_OPERATOR && t->opr_obj->opr == VAR_DECLAR)
				{
					__execLOCAL(t);
				}
				else
				{
					// 抛出异常
					getState()->curThread()->throwException(newUnsupportedOperationException("invalid local stmt.")->addRef());
					return;
				}
				continue;
			}

			if (t->type == NodeType::NODE_VARIABLE)
			{
				char *name = t->var_obj->name;
				Object *tmp = getState()->curThread()->getCurrentEnv()->getObjectSelf(name);
				if (tmp == NULL)
				{
					setValueToEnv(name, obj);
				}
				else {
					tmp->setLocal(!tmp->isLocal());
				}
			}
			else if (t->type == NodeType::NODE_CLASS)
			{
				// 类声明
				t->state.isLocal = true;
				__execNode(t);
			}
			
		}

		Allocator::free(obj);

	}

	//  continue 关键字
	void __execCONTINUE(Node *n) {
		if (!n) {
			return;
		}

		if (!getState()->curThread()->isInLoop() )
		{
			getState()->curThread()->throwException(newUnsupportedOperationException("invalid continue stmt.")->addRef());
			//printf("无效的CONTINUE 语句 ");
			return;
		}

		getState()->curThread()->setInContinue(true);
	}


	/*
	 * 执行节点，  节点的结果 将 放在  Node.value 上
	 * 这是一个 Object 类型的指针    07-24
	 * 由 void __execNode(Node *node)    修改为  __realExecNode()       2017年11月26日
	 */
	void __realExecNode(NodeLink *nodeLink, langXThread *thread) {
		if (nodeLink == NULL)
		{
			return;
		}

		Node *node = nodeLink->node;
		
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

					// find function.
					Function *func = getState()->curThread()->getFunction(node->var_obj->name);
					if (func != nullptr)
					{

						node->value = Allocator::allocateFunctionRef(func);
					}
					else {
						node->value = new NullObject();
					}

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
			node->value = Allocator::allocateNumber(node->con_obj->dValue);
			return;
		}
		else if (node->type == NODE_CONSTANT_STRING)
		{
			//printf("__execNode NODE_CONSTANT_STRING\n");
			//  因为匹配出的字符串是带有 双引号的， 现在要去掉这个双引号
			char *tmp = strndup(node->con_obj->sValue + 1, strlen(node->con_obj->sValue) - 2);
			node->value = Allocator::allocateString(tmp);
			free(tmp);

			return;
		}
		else if (node->type == NODE_CONSTANT_INTEGER)
		{
			node->value = Allocator::allocateNumber(node->con_obj->iValue);

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

			cinfo->setLocal(node->state.isLocal);

			if (node->state.classAuto == false)
			{
				if (getState()->curThread()->getCurrentEnv()->getClassSelf(cinfo->getName()) != NULL)
				{
					char tmp[100] = { 0 };
					sprintf(tmp, "class %s already declared.", cinfo->getName());
					getState()->curThread()->throwException(newRedeclarationException(tmp)->addRef());
					delete cinfo;
					node->ptr_u = NULL;
					return;
				}
			}
			else {
				//  自动填充
				ClassInfo *c1 = getState()->curThread()->getCurrentEnv()->getClass(cinfo->getName());
				if (c1 != NULL)
				{
					c1->expand(cinfo);
					delete cinfo;
					node->ptr_u = NULL;
					return;
				}

			}

			getState()->regClass(cinfo);
			node->ptr_u = NULL;
			return;
		}
		else if (node->type == NODE_FUNCTION)
		{
			// 函数
			if (node->ptr_u == NULL)
			{
				return;
			}
			Function *func = (Function*)node->ptr_u;
			if (!func->hasName())
			{
				// 匿名函数
				return;
			}
			if (getState()->curThread()->getCurrentEnv()->getFunctionSelf(func->getName()) != NULL)
			{
				char tmp[100] = { 0 };
				sprintf(tmp, "function %s already declared.", func->getName());
				getState()->curThread()->throwException(newRedeclarationException(tmp)->addRef());
				delete func;
				node->value = NULL;
				return;
			}

			//函数的产生环境可能在类内部
			//func->setEmergeEnv(getState()->curThread()->getCurrentEnv());
			Environment *env = getState()->getScriptOrNSEnv();
			if (env != NULL && env->getType() == EnvironmentType::TScriptEnvironment)
			{
				func->setScriptEnv( (ScriptEnvironment*)env );
			}
			getState()->curThread()->getCurrentEnv()->putFunction(func->getName(), func);
			return;
		}
		else if (node->type == NODE_NULL)
		{
			node->value = Allocator::allocate(NULLOBJECT);
			return;
		}
		else if (node->type == NODE_ARRAY_ELE)
		{
			ArrayInfo * arrayInfo = node->arr_obj;
			node->value = getValueFromArrayInfo(arrayInfo);
			freeArrayInfo(arrayInfo);
			return;
		}
		else if (node->type == NODE_CHANGE_NAMESPACE)
		{
			// 切换命名空间
			char* name = node->con_obj->sValue;
			std::string str = std::string(name);
			XNameSpace *space = NULL;

			auto dotIndex = str.find_first_of(".");

			while (dotIndex != std::string::npos)
			{
				std::string f = str.substr(0, dotIndex);
				str = str.substr(dotIndex + 1);
				dotIndex = str.find_first_of(".");

				// f is namespace name
				if (space == NULL)
				{
					space = getState()->singleGetNameSpace(f.c_str());
				}
				else {
					space = space->getNameSpace2(f.c_str());
				}
			}

			if (space == NULL)
			{
				space = getState()->singleGetNameSpace(str.c_str());
			}
			else {
				space = space->getNameSpace2(str.c_str());
			}

			getState()->changeNameSpace(space);
			return;
		}


		if (node->type != NODE_OPERATOR)
		{
			//printf("undeal type: %d\n", node->type);
			char tmp[100] = { 0 };
			sprintf(tmp, "undeal type: %d", node->type);
			getState()->curThread()->throwException(newException(tmp)->addRef());
			return;
		}


		//printf("exec operator node. opr is: %d\n", node->opr_obj->opr);
		switch (node->opr_obj->opr)
		{
		case '+':
			__exec43(nodeLink);
			break;
		case '-':
			__exec45(nodeLink);
			break;
		case '*':
			__exec42(nodeLink);
			break;
		case '/':
			__exec47(nodeLink);
			break;
		case '%':
			__exec37(nodeLink);
			break;
		case '=':
			__exec61(nodeLink, thread);
			break;
		case ';':
			__exec59(node);
			break;
		case '>':
			__exec62(nodeLink);
			break;
		case '<':
			__exec60(nodeLink);
			break;
		case '&':
			__exec38(nodeLink);
			break;
		case '|':
			__exec124(nodeLink);
			break;
		case '^':
			__exec94(nodeLink);
			break;
		case '~':
			__exec126(nodeLink);
			break;
		case UMINUS:
			__execUMINUS(nodeLink);
			break;
		case INC_OP:
			__execINC_OP(nodeLink);
			break;
		case DEC_OP:
			__execDEC_OP(nodeLink);
			break;
		case ADD_EQ:
			__execADD_EQ(nodeLink);
			break;
		case SUB_EQ:
			__execSUB_EQ(nodeLink);
			break;
		case MUL_EQ:
			__execMUL_EQ(nodeLink);
			break;
		case DIV_EQ:
			__execDIV_EQ(nodeLink);
			break;
		case MOD_EQ:
			__execMOD_EQ(nodeLink);
			break;
		case LE_OP:
			__execLE_OP(nodeLink);
			break;
		case GE_OP:
			__execGE_OP(nodeLink);
			break;
		case EQ_OP:
			__execEQ_OP(nodeLink);
			break;
		case NE_OP:
			__execNE_OP(nodeLink);
			break;
		case AND_OP:
			__execOPAND(nodeLink);
			break;
		case OR_OP:
			__execOPOR(nodeLink);
			break;
		case IF:
			__execIF(nodeLink, thread);
			break;
		case WHILE:
			__execWHILE(node);
			break;
		case FOR:
			__execFOR(node);
			break;
		case FUNC_CALL:
			__execFUNC_CALL(nodeLink, thread);
			break;
		case BREAK:
			__execBREAK(nodeLink, thread);
			break;
		case RETURN:
			__execRETURN(nodeLink, thread);
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
			__execCLAXX_BODY(nodeLink);
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
		case LEFT_SHIFT:
			__execLEFT_SHIFT(nodeLink);
			break;
		case RIGHT_SHIFT:
			__execRIGHT_SHIFT(nodeLink);
			break;
		case XIS:
			__execXIS(node);
			break;
		case SCOPE:
			__execSCOPE(node);
			break;
		case SCOPE_FUNC_CALL:
			__execSCOPE_FUNC_CALL(nodeLink);
			break;
		case REQUIRE:
			__execREQUIRE(node);
			break;
		case  REQUIRE_ONCE:
			__execREQUIRE_ONCE(node);
			break;
		case XINCLUDE:
			__execINCLUDE(node);
			break;
		case REF:
			__execREF(node);
			break;
		case XCONST:
			__execCONST(node);
			break ;
		case XCONTINUE :
			__execCONTINUE(node);
			break;
		case XLOCAL:
			__execLOCAL(node);
			break;
		default:
			break;
		}

	}


	void __execNode(Node *node) {
		if (node == NULL)
		{
			return;
		}

		langXThread * thread = getState()->curThread();
		thread->initRootNode(node);

		NodeLink *curLink = NULL;
		while ((curLink = thread->getCurrentExecute()) != NULL) {
			//  程序没还有结束

			__realExecNode(curLink, thread);     // 将原来的内容丢到一个新的方法里面
			if (curLink->next == nullptr && curLink->backAfterExec) {
				thread->endExecute();
			}
		}

	}

}

