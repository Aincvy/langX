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
#include "../include/LogManager.h"

namespace langX {

	// 根据数组信息获得结果， 返回的结果为一个 nullptr 或者复制好的结果
	Object * getValueFromArrayInfo(ArrayInfo *arrayInfo, NodeLink *nodeLink, langXThread *thread) {
		if (nodeLink->index == 0) {
			nodeLink->index = 1;
			bool flag = false;
			if (arrayInfo->objNode != NULL)
			{
				thread->beginExecute(arrayInfo->objNode, true);
				flag = true;
			}
			//  计算数组的 索引节点
			if (arrayInfo->indexNode != NULL)
			{
				Node *t = arrayInfo->indexNode;
				thread->beginExecute(t, true);
				flag = true;
			}

			if (flag) {
				nodeLink->backAfterExec = false;
				return nullptr;
			}
		}

		Object *obj = NULL;
		if (arrayInfo->name != NULL)
		{
			obj = getValue(arrayInfo->name);
		}
		else if (arrayInfo->objNode != NULL)
		{
			obj = arrayInfo->objNode->value;
		}

		if (obj == NULL)
		{
			thread->throwException(newUnsupportedOperationException("left value is not array with array operator!")->addRef());
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
					if (t->value == nullptr)
					{
						thread->throwException(newException("error index !")->addRef());
						return nullptr;
					}
					arg1 = t->value;
				}
				else {
					// use arrayInfo's index
					num1.setValue(arrayInfo->index);
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
			thread->throwException(newUnsupportedOperationException("left value is not array with array operator!")->addRef());
			return nullptr;
		}

		int index = arrayInfo->index;
		if (arrayInfo->indexNode != NULL)
		{
			Node *t = arrayInfo->indexNode;

			if (t->value == NULL || t->value->getType() != NUMBER)
			{
				thread->throwException(newException("error array length !")->addRef());
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
			thread->throwException(newIndexOutOfBoundsException(tmp)->addRef());
			return nullptr;
		}

		Object * ret = ref->at(index);
		if (ret == nullptr)
		{
			// 内部异常
			thread->throwException(newInnerException(" array element is null... ")->addRef());
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
		else if ((left != NULL && left->getType() == STRING) || (right != NULL && right->getType() == STRING))
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

		nodeLink->backAfterExec = true;

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
	}

	// ! 取反
	void __exec33(NodeLink *nodeLink) {
		Node *n = nodeLink->node;
		if (nodeLink->index == 0) {
			doSubNodes(n);
			nodeLink->index = 1;
			return;
		}

		Node *n1 = n->opr_obj->op[0];
		if (n1->value == NULL)
		{
			getState()->curThread()->throwException(newArithmeticException("value is null on opr '-'!")->addRef());
			freeSubNodes(n);
			return;
		}

		Object * value = n1->value;
		n->value = Allocator::allocateNumber(value->isTrue() ? 0 : 1);

		freeSubNodes(n);
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

		nodeLink->backAfterExec = true;

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

		nodeLink->backAfterExec = true;

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

		nodeLink->backAfterExec = true;

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

		nodeLink->backAfterExec = true;

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

		nodeLink->backAfterExec = true;

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

		Node *right = n->opr_obj->op[1];
		//   要把右侧的值检出， 然后对比类型，更新左侧的值
		if (nodeLink->index == 1) {
			checkValue(right, thread);
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

		// 尝试获取下左值是否是一个对象
		if (left->type == NODE_OPERATOR)
		{
			if (left->opr_obj->opr == CLAXX_MEMBER)
			{
				objectRef = (langXObjectRef *)left->ptr_u;
				left->ptr_u = NULL;
			}
		}

		ObjectType rightType = right->value->getType();
		if (objectRef == NULL && arrayInfo == NULL)
		{
			checkVarValue(left, rightType);

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
				return;
			}

			// 强制更新index的值
			if (nodeLink->index == 2) {
				nodeLink->index = 3;
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

			do {
				// 判定一下操作符 = 是否进行重载了
				// 操作符= 重载的结果是 属性赋值， 而非当前对象
				Function *func1 = objectRef->getFunction("operator=");
				if (func1)
				{
					X3rdArgs _3rdArgs;
					memset(&_3rdArgs, 0, sizeof(X3rdArgs));
					langX::String str1(name);
					_3rdArgs.args[0] = &str1;
					_3rdArgs.args[1] = right->value;
					_3rdArgs.index = 2;
					n->value = callFunction(objectRef, func1, &_3rdArgs);

					freeSubNodes(n);
					break;
				}

				// 属性的正常赋值
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
			} while (false);

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

		// 字符串的 += 操作
		if (n1->value->getType() == STRING)
		{
			// 追加到一起去
			String *str1 = (String*)n1->value;
			std::string str2(str1->getStrValue());
			Object* obj = n2->value;
			if (obj->getType() == ObjectType::STRING) {
				str2.append(((String*)obj)->getStrValue());
			}
			else {
				char tmp[4096] = { 0 };
				getObjStringDesc(obj, tmp, 4096);
				str2.append(tmp);
			}
			n->value = Allocator::allocateString(str2.c_str());
		}
		else
		{
			if (n1->value->getType() != NUMBER || n2->value->getType() != NUMBER)
			{
				getState()->curThread()->throwException(newArithmeticException("type error on opr '+='!")->addRef());
				freeSubNodes(n);
				return;
			}

			n->value = Allocator::allocateNumber(
				((Number*)n1->value)->getDoubleValue() + ((Number*)n2->value)->getDoubleValue());
		}

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
			freeSubNodes(n);      //  释放节点的值的内存
			nodeLink = nodeLink->previous;
			thread->endExecute();

			if (n->type == NodeType::NODE_OPERATOR) {
				int opr = n->opr_obj->opr;
				if (opr == WHILE || opr == FOR || opr == SWITCH) {
					// 找到了该节点
					break;
				}
			}
		} while (true);

		thread->setBackInExec(true);
		if (thread->isInLoop()) {
			thread->setInLoop(false);
		}
		else {
			thread->setInSwitch(false);
		}
	}

	void __execRETURN(NodeLink *nodeLink, langXThread * thread) {
		Node *n = nodeLink->node;
		//printf("call return %p\n", n);
		nodeLink->backAfterExec = false;

		if (nodeLink->index == 0) {
			if (!thread->isInFunction())
			{
				getState()->curThread()->throwException(newUnsupportedOperationException("invalid return stmt.")->addRef());
				return;
			}

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

		//printf("return %p\n",n->value);
		freeSubNodes(n);
		thread->setFunctionResult(n->value);
		Allocator::free(n->value);
		n->value = nullptr;
		thread->setBackInExec(true);
		nodeLink->backAfterExec = true;

		// 回退节点
		Node *funcRootNode = thread->getFuncRootNode();
		do {
			if (nodeLink == nullptr) {
				break;
			}

			Node *n = nodeLink->node;
			freeSubNodes(n);
			if (funcRootNode == n) {
				// 找到了该节点
				nodeLink->index = 1000;       // 函数已经获取到返回值
				break;
			}

			nodeLink = nodeLink->previous;
			thread->endExecute();
		} while (true);

#ifdef SHOW_DETAILS
		//printf("want back to %p,cmd %d \n", funcRootNode, funcRootNode == nullptr ? -1 : funcRootNode->opr_obj->opr);
		//if (nodeLink == nullptr)
		//{
		//	printf("after return back. nodeLink is null.\n");
		//}
		//else {
		//	Node *tmpNode1 = nodeLink->node;
		//	printf("after return back. on node %p cmd %d\n", tmpNode1, tmpNode1->type == NodeType::NODE_OPERATOR ? tmpNode1->opr_obj->opr : -1);
		//}
#endif
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

		nodeLink->backAfterExec = true;

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

		nodeLink->backAfterExec = true;

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
	}

	// 分号 ;
	void __exec59(NodeLink *nodeLink, langXThread * thread) {
		Node *n = nodeLink->node;

		nodeLink->backAfterExec = false;      //  这是一个复合性质的节点， 自己管理这个状态就好了
		int oprCount = n->opr_obj->op_count;
		if (nodeLink->index < oprCount) {
			// 遍历节点
			Node *run = n->opr_obj->op[nodeLink->index];
			nodeLink->index++;
			if (run != NULL) {
				thread->beginExecute(run, true);
			}
			return;
		}

		doSuffixOperation(n);
		freeSubNodes(n);
		nodeLink->backAfterExec = true;
	}

	// 逗号表达式
	void __exec44(NodeLink *nodeLink, langXThread * thread) {
		// 操作和 分号表达式差不多应该， 这样应该就OK了。
		__exec59(nodeLink, thread);
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

		if (left->getType() == NULLOBJECT)
		{
			if (right->getType() == NULLOBJECT)
			{
				n->value = Allocator::allocateNumber(1);
			}
			else {
				n->value = Allocator::allocateNumber(0);
			}
		}
		else if (left->getType() == NUMBER)
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
			}
			else {
				n->value = Allocator::allocateNumber(0);
			}
		}
		else if (left->getType() == STRING)
		{
			if (n2->value->getType() == STRING)
			{
				// 字符串比较
				const char * a = ((String*)n1->value)->getValue();
				const char * b = ((String*)n2->value)->getValue();
				// logger->debug("a: %s,b: %s",a,b);

				if (strcmp(a, b) == 0)
				{
					n->value = Allocator::allocateNumber(1);
				}
				else {
					n->value = Allocator::allocateNumber(0);
				}
			}
			else {
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
				nodeLink->backAfterExec = true;
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
		}
		else
			if (left->getType() == NUMBER)
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
			else if (left->getType() == STRING)
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
					nodeLink->backAfterExec = true;
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

	void __execWHILE(NodeLink *nodeLink, langXThread *thread) {
		Node *n = nodeLink->node;
		nodeLink->backAfterExec = false;

		// 先执行条件 节点 ,然后判断条件 节点的值， 然后释放条件 节点的内存
		// 循环执行结束 ， 释放掉  所有节点值 的内存
		Node *conNode = n->opr_obj->op[0];
		Node *run = n->opr_obj->op[1];
		if (!nodeLink->flag) {
			thread->setInLoop(true);
			nodeLink->flag = true;
		}
		if (nodeLink->index == 0) {
			// 需要计算条件节点
			thread->beginExecute(conNode, true);
			nodeLink->index = 1;
			return;
		}
		else if (nodeLink->index == 1) {
			// 已经计算了条件节点
			if (__tryConvertToBool(conNode)) {
				doSuffixOperation(conNode);
				thread->beginExecute(run, true);
				nodeLink->index = 2;
			}
			else {
				doSuffixOperation(conNode);
				thread->setInLoop(false);
				nodeLink->backAfterExec = true;
				freeSubNodes(n);
			}

			// 重置条件节点的值
			Allocator::free(conNode->value);
			conNode->value = NULL;
		}
		else if (nodeLink->index == 2) {
			// 循环内部的节点已经执行完毕， 现在做一些后续操作
			freeSubNodes(run);
			recursiveFreeNodeValue(run);
			nodeLink->index = 0;    //
		}
	}

	void __execFOR(NodeLink *nodeLink, langXThread *thread) {
		nodeLink->backAfterExec = false;

		Node *n = nodeLink->node;
		if (!nodeLink->flag) {
			thread->setInLoop(true);
			nodeLink->flag = true;
		}

		Node *conNode = n->opr_obj->op[1];
		// 后置节点
		Node *sNode = n->opr_obj->op[2];
		// 要执行的节点
		Node *run = n->opr_obj->op[3];
		if (nodeLink->index == 0) {
			// 要求计算初始节点的值
			thread->beginExecute(n->opr_obj->op[0], true);
			nodeLink->index = 1;
		}
		else if (nodeLink->index == 1) {
			thread->beginExecute(conNode, true);    // 执行条件节点
			nodeLink->index = 2;
		}
		else if (nodeLink->index == 2)
		{
			// 判定条件
			doSuffixOperation(conNode);
			if (__tryConvertToBool(conNode))
			{
				// 满足条件，执行后续的节点
				thread->beginExecute(run, true);
				nodeLink->index = 3;
			}
			else {
				// 不满足条件， 退出循环
				thread->setInLoop(false);
				nodeLink->backAfterExec = true;
				freeSubNodes(n);
			}
			Allocator::free(conNode->value);
			conNode->value = NULL;
		}
		else if (nodeLink->index == 3)
		{
			// 重置run节点的状态
			recursiveFreeNodeValue(run);

			// 执行后置节点
			thread->beginExecute(sNode, true);
			nodeLink->index = 4;
		}
		else if (nodeLink->index == 4)
		{
			// 对后置节点进行收尾，然后准备执行条件判定节点
			doSuffixOperation(sNode);
			freeSubNodes(sNode);
			Allocator::free(sNode->value);
			sNode->value = nullptr;

			nodeLink->index = 1;
		}
	}

	void __execSWITCH(NodeLink *nodeLink, langXThread *thread) {
		Node* n = nodeLink->node;

		nodeLink->backAfterExec = false;

		Node * id_expr = n->opr_obj->op[0];
		if (nodeLink->index == 0) {
			// 运算id表达式
			thread->beginExecute(id_expr, true);
			nodeLink->index = 1;
			return;
		}

		if (id_expr->value == NULL)
		{
			thread->throwException(newUnsupportedOperationException("null condition value in switch()!")->addRef());
			return;
		}

		if (!nodeLink->flag) {
			thread->setInSwitch(true);
			nodeLink->flag = true;
		}

		if (nodeLink->index == 1) {
			nodeLink->index = 2;

			char tmp[1024] = { 0 };
			Object *obj = id_expr->value;
			if (obj->getType() == ObjectType::NUMBER) {
				Number  *number = (Number*)obj;
				if (number->isInteger()) {
					// 正数
					sprintf(tmp, "%d", number->getIntValue());
				}
				else {
					sprintf(tmp, "%f", number->getDoubleValue());
				}
			}
			else if (obj->getType() == ObjectType::STRING) {
				String *str = (String*)obj;
				sprintf(tmp, "%s", str->getValue());
			}

			SwitchInfo *switchInfo = (SwitchInfo *)n->ptr_u;
			auto it = switchInfo->keyIndexMap.find(tmp);
			if (it == switchInfo->keyIndexMap.end()) {
				// 未找到  执行default
				thread->beginExecute(switchInfo->defaultNode, true);
			}
			else {
				// 找到
				thread->beginExecute(switchInfo->caseList[it->second], true);
			}

			return;
		}

		thread->setInSwitch(false);
		nodeLink->backAfterExec = true;
	}

	void __execCASE_LIST(NodeLink *nodeLink, langXThread *thread) {
		// 2017年12月8日  switch 内处理这些事情
		nodeLink->backAfterExec = true;
	}

	void __execCASE(NodeLink *nodeLink, langXThread *thread) {
		// 2017年12月8日  switch 内处理这些事情
		nodeLink->backAfterExec = true;
	}

	void __execDeafult(NodeLink *nodeLink, langXThread *thread) {
		Node *n = nodeLink->node;

		if (nodeLink->index == 0) {
			thread->beginExecute(n->opr_obj->op[0], true);
			nodeLink->index = 1;
		}
		else {
			freeSubNodes(n);
		}
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
			getState()->curThread()->throwException(newArithmeticException("value is null on opr '-'!")->addRef());
			freeSubNodes(n);
			return;
		}
		if (n1->value->getType() != NUMBER)
		{
			getState()->curThread()->throwException(newArithmeticException("type error on opr '-'! only can number!")->addRef());
			freeSubNodes(n);
			return;
		}
		else {
			n->value = Allocator::allocateNumber(-((Number*)n1->value)->getDoubleValue());
		}

		freeSubNodes(n);
		nodeLink->backAfterExec = true;
	}

	// 执行一个函数
	void __execFUNC_CALL(NodeLink *nodeLink, langXThread *thread) {
		Node *n = nodeLink->node;

		Node *n1 = n->opr_obj->op[0];
		if (nodeLink->index == 0) {
			thread->beginExecute(n1, true);
			nodeLink->index = 1;
			return;
		}

		nodeLink->backAfterExec = false;     // 强制更新状态为执行结束后不释放节点， 因为函数执行需要2次

		std::string remark = fileInfoString(n->fileinfo);
		XArgsList *args = (XArgsList *)n->opr_obj->op[1]->ptr_u;
		bool flag = true;
		if (n1->value != NULL)
		{
			if (n1->value->getType() == FUNCTION)
			{
				FunctionRef *f = (FunctionRef*)n1->value;
				NodeLink *putNodeLink = nullptr;
				if (nodeLink->ptr_u == NULL) {
					// 第一次执行， 需要让函数确认所有的参数
					putNodeLink = newNodeLink(nullptr, n);
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
				if (n1->var_obj)
				{
					str += n1->var_obj->name;;
				}
				else {
					str += " [array,do not know name]";
				}
				str += " ";
				str += remark;

				NodeLink *putNodeLink = nullptr;
				if (nodeLink->ptr_u == NULL) {
					// 第一次执行， 需要让函数确认所有的参数
					putNodeLink = newNodeLink(nullptr, n);
					nodeLink->ptr_u = putNodeLink;
					call(n1Str->getValue(), args, str.c_str(), putNodeLink);
					return;
				}
				else {
					putNodeLink = (NodeLink*)nodeLink->ptr_u;
					nodeLink->ptr_u = nullptr;
				}
				n->value = call(n1Str->getValue(), args, str.c_str(), putNodeLink);
				flag = false;
			}
		}

		if (flag)
		{
			char * name = n1->var_obj->name;
			NodeLink *putNodeLink = nullptr;
			if (nodeLink->ptr_u == NULL) {
				// 第一次执行， 需要让函数确认所有的参数
				putNodeLink = newNodeLink(nullptr, n);
				nodeLink->ptr_u = putNodeLink;
				call(name, args, remark.c_str(), putNodeLink);
				return;
			}
			else {
				putNodeLink = (NodeLink*)nodeLink->ptr_u;
				nodeLink->ptr_u = nullptr;
			}
			n->value = call(name, args, remark.c_str(), putNodeLink);
			//printf("func %s exec end\n" , name);
		}

		doSuffixOperationArgs(args);
		Allocator::free(n1->value);
		n1->value = NULL;
		nodeLink->backAfterExec = true;
	}

	void __execNEW(NodeLink *nodeLink, langXThread *thread) {
		Node *n = nodeLink->node;
		// new 一个对象
		nodeLink->backAfterExec = false;
		Node *argNode = n->opr_obj->op[1];
		if (nodeLink->index == 0) {
			nodeLink->index = 1;

			char *className = n->opr_obj->op[0]->var_obj->name;
			ClassInfo *claxxInfo = getState()->getClass(className);
			if (claxxInfo == NULL)
			{
				thread->throwException(newClassNotFoundException(className)->addRef());
				return;
			}
			langXObject *object = claxxInfo->newObject();
			if (object == NULL)
			{
				thread->throwException(newClassNotFoundException(className)->addRef());
				return;
			}
			langXObjectRef * objectRef = object->addRef();
			objectRef->setEmergeEnv(thread->getCurrentEnv());
			n->value = objectRef;

			if (argNode != NULL)
			{
				XArgsList *args = (XArgsList *)argNode->ptr_u;
				object->callConstructor(args, fileInfoString(n->fileinfo).c_str(), nodeLink, thread);
			}
			else {
				object->callConstructor(nullptr, fileInfoString(n->fileinfo).c_str(), nodeLink, thread);
			}

			return;        // 先出去运算参数
		}
		else {
			langXObjectRef * objectRef = (langXObjectRef *)n->value;
			langXObject *object = objectRef->getRefObject();
			if (argNode != NULL)
			{
				XArgsList *args = (XArgsList *)argNode->ptr_u;
				object->callConstructor(args, fileInfoString(n->fileinfo).c_str(), nodeLink, thread);
			}
			else {
				object->callConstructor(nullptr, fileInfoString(n->fileinfo).c_str(), nodeLink, thread);
			}
		}

		nodeLink->backAfterExec = true;
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

	void __realExecVAR_DECLAR(Node *n, langXThread *thread) {
		// 都初始为 null
		// 数组要赋值
		Object *obj = Allocator::allocate(NULLOBJECT);
		obj->setEmergeEnv(thread->getCurrentEnv());
		for (int i = 0; i < n->opr_obj->op_count; i++)
		{
			Node *t = n->opr_obj->op[i];
			if (t == NULL || t->type != NODE_VARIABLE)
			{
				if (t->type == NODE_OPERATOR && t->opr_obj->opr == VAR_DECLAR)
				{
					__realExecVAR_DECLAR(t, thread);
				}
				else if (t->type == NODE_ARRAY)
				{
					if (t->ptr_u == NULL)
					{
						//printf("delar array erorr!\n");
						thread->throwException(newException("Inner Error! delar array erorr!")->addRef());
						Allocator::free(obj);
						return;
					}

					XArrayNode *an = (XArrayNode *)t->ptr_u;
					int len = an->length;
					if (an->lengthNode != NULL)
					{
						Node *t = an->lengthNode;

						if (t->value == NULL || t->value->getType() != NUMBER)
						{
							//printf("error array length !\n");
							thread->throwException(newException("error array length !")->addRef());
							return;
						}

						len = ((Number*)t->value)->getIntValue();
						Allocator::free(t->value);
						t->value = nullptr;
					}
					XArray *array1 = Allocator::allocateArray(len);
					char *name = an->name;
					Object *arrayRef = array1->addRef();
					arrayRef->setEmergeEnv(thread->getCurrentEnv());
					setValueToEnv(name, arrayRef);
				}
				continue;
			}

			char *name = t->var_obj->name;
			setValueToEnv(name, obj);
		}

		Allocator::free(obj);
	}

	// 确保变量声明里的数组 节点的值都运算出来
	void __execVAR_DECLAR_CheckValue(Node *n, langXThread *thread) {
		for (int i = 0; i < n->opr_obj->op_count; i++)
		{
			Node *t = n->opr_obj->op[i];
			if (t == NULL || t->type != NODE_VARIABLE)
			{
				if (t->type == NODE_OPERATOR && t->opr_obj->opr == VAR_DECLAR)
				{
					__execVAR_DECLAR_CheckValue(t, thread);
				}
				else if (t->type == NODE_ARRAY)
				{
					if (t->ptr_u == NULL)
					{
						//printf("delar array erorr!\n");
						thread->throwException(newException("Inner Error! delar array erorr!")->addRef());
						return;
					}

					XArrayNode *an = (XArrayNode *)t->ptr_u;
					int len = an->length;
					if (an->lengthNode != NULL)
					{
						Node *t = an->lengthNode;
						thread->beginExecute(t, true);
					}
				}
				continue;
			}
		}
	}

	// 变量声明
	void __execVAR_DECLAR(NodeLink *nodeLink, langXThread *thread) {
		Node *n = nodeLink->node;
		nodeLink->backAfterExec = false;
		if (nodeLink->index == 0) {
			// 检测数组节点，都给赋值了
			__execVAR_DECLAR_CheckValue(n, thread);
			nodeLink->index = 1;
		}
		else {
			// 真正的声明变量
			__realExecVAR_DECLAR(n, thread);
			nodeLink->backAfterExec = true;
		}
	}

	void __execCLAXX_MEMBER(NodeLink *nodeLink, langXThread *thread) {
		Node *n = nodeLink->node;
		Node *n1 = n->opr_obj->op[0];
		nodeLink->backAfterExec = false;
		if (nodeLink->index == 0) {
			//  执行节点1， 获得 类对象
			thread->beginExecute(n1, true);
			nodeLink->index = 1;
			return;
		}

		if (n1->value == NULL)
		{
			//printf("left value %s is not class object or array  !\n", n1->var_obj->name);
			char tmp[100] = { 0 };
			sprintf(tmp, "left value %s is not class object or array  !\n", n1->var_obj->name);
			thread->throwException(newTypeErrorException(tmp)->addRef());
			freeSubNodes(n);
			return;
		}

		char *memberName = n->opr_obj->op[1]->var_obj->name;

		nodeLink->backAfterExec = true;
		//    先处理数组和字符串的情况
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
				thread->throwException(newNoClassMemberException(tmp)->addRef());
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
				thread->throwException(newNoClassMemberException(tmp)->addRef());
			}

			freeSubNodes(n);
			return;
		}

		//  处理 object 的情况
		if (n1->value->getType() != OBJECT)
		{
			thread->throwException(newTypeErrorException("left value is not a object.")->addRef());
			freeSubNodes(n);
			return;
		}

		langXObjectRef* objectRef = (langXObjectRef*)n1->value;

		// set ptr_u first,  等号的处理部分会用这个属性
		if (n->ptr_u != NULL)
		{
			delete ((langXObjectRef*)n->ptr_u);
			n->ptr_u = NULL;
		}
		n->ptr_u = objectRef->clone();

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
		if (t == NULL || (t != NULL && t->isLocal()))
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
				thread->throwException(newNoClassMemberException(tmp)->addRef());
				freeSubNodes(n);
				return;
			}
		}
		n->value = t->clone();

		freeSubNodes(n);
	}

	void __execCLAXX_FUNC_CALL(NodeLink *nodeLink, langXThread *thread) {
		Node *n = nodeLink->node;
		Node *n1 = n->opr_obj->op[0];
		if (nodeLink->index == 0) {
			thread->beginExecute(n1, true);
			nodeLink->index = 1;
			return;
		}

		if (n1->value == NULL)
		{
			thread->throwException(newTypeErrorException("left value is not class object !")->addRef());
			freeSubNodes(n);
			return;
		}

		if (n1->value->getType() == STRING)
		{
			// 从语法解析文件可知 此节点是一个函数调用节点
			Node *n2 = n->opr_obj->op[1];
			XArgsList *args = (XArgsList *)n2->opr_obj->op[1]->ptr_u;
			if (nodeLink->index == 1)
			{
				nodeLink->index = 2;
				if (args) {
					for (int i = 0; i < args->index; i++)
					{
						if (args->args[i] == NULL)
						{
							continue;
						}

						thread->beginExecute(args->args[i], true);
					}
					return;
				}
			}
			//  上面的写法是为了确保 无论如何到这个地方 index都是2
			n->value = callInnerFunc(n1->value, n2);
			return;
		}

		if (n1->value->getType() != OBJECT)
		{
			thread->throwException(newTypeErrorException("left value is not class object !")->addRef());
			freeSubNodes(n);
			return;
		}

		// 2017年12月3日   首次执行到这里的时候 把当前object的环境丢进去
		if (!nodeLink->flag) {
			nodeLink->flag = true;

			langXObjectRef* objectRef = (langXObjectRef*)n1->value;
			Environment *env = objectRef->getRefObject()->getObjectEnvironment();
            thread->newEnvByBridge(env);
		}

		// 根据语法解析文件可知， 第二个节点为一个函数调用节点
		Node *n2 = n->opr_obj->op[1];
		if (nodeLink->index == 1) {
			thread->beginExecute(n2, true);
			nodeLink->index = 2;
			return;
		}

		if (n2->value != NULL)
		{
			n->value = n2->value->clone();
		}
		else {
			n->value = NULL;
		}

		thread->backEnv();
		freeSubNodes(n);
		nodeLink->backAfterExec = true;
	}

	void __execRESTRICT(NodeLink *nodeLink, langXThread * thread) {
		Node *n = nodeLink->node;
		// 对当前环境进行限定， 限定后，不去搜索父级环境内容

		if (n->opr_obj->op_count <= 0)
		{
			thread->getCurrentEnv()->setRestrict(true);
			thread->getCurrentEnv()->setClose(true);
		}
		else {
			Node *n1 = n->opr_obj->op[0];
			if (nodeLink->index == 0) {
				thread->beginExecute(n1, true);
				nodeLink->index = 1;
				return;
			}
			else {
				bool f = __tryConvertToBool(n1);
				thread->getCurrentEnv()->setRestrict(f);
				thread->getCurrentEnv()->setClose(f);
			}

			freeSubNodes(n);
		}

		nodeLink->backAfterExec = true;
	}

	// 执行 this.xxx
	void __execTHIS(NodeLink *nodeLink, langXThread *thread) {
		Node *n = nodeLink->node;
		Node *n1 = n->opr_obj->op[0];
		nodeLink->backAfterExec = false;

		if (nodeLink->index == 0) {
			Environment * env = thread->getNearestObjectEnv();
			if (!env)
			{
				thread->throwException(newUnsupportedOperationException("invalid this stmt! cannot find the object on use this!")->addRef());
				return;
			}

			ObjectBridgeEnv *objEnv = (ObjectBridgeEnv*)env;
			if (n->opr_obj->op_count <= 0)
			{
				// no args.  获得自己就好了
				n->value = objEnv->getEnvObject()->addRef();
				nodeLink->backAfterExec = true;
				return;
			}

            thread->newEnvByBridge(env);

			langXObject *thisObj = objEnv->getEnvObject();

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
					thread->throwException(newNoClassMemberException(tmp)->addRef());
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

			thread->beginExecute(n1, true);
			nodeLink->index = 1;
			return;
		}

		if (n1->value == NULL)
		{
			//printf("error in __execTHIS, n1->value == NULL");
			thread->throwException(newException("error in __execTHIS, n1->value == NULL")->addRef());
		}
		else {
			n->value = n1->value->clone();
		}

		thread->backEnv();
		freeSubNodes(n);
		nodeLink->backAfterExec = true;
	}

	void __execSCOPE(NodeLink *nodeLink, langXThread *thread) {
		Node *n = nodeLink->node;

		char *className = n->opr_obj->op[0]->var_obj->name;
		ClassInfo *claxxInfo = getState()->getClass(className);
		if (claxxInfo == NULL)
		{
			thread->throwException(newClassNotFoundException(className)->addRef());
			return;
		}

		char *memberName = n->opr_obj->op[1]->var_obj->name;
		Object *t = claxxInfo->getMember(memberName);
		if (t == NULL || (t != NULL && t->isLocal()))
		{
			Function * tf = claxxInfo->getFunction(memberName);
			if (tf == NULL)
			{
				char tmp[100] = { 0 };
				sprintf(tmp, "no member %s in class %s.", memberName, className);
				thread->throwException(newNoClassMemberException(tmp)->addRef());
				return;
			}

			FunctionRef *fr = Allocator::allocateFunctionRef(tf);
			fr->setClaxx(claxxInfo);
			fr->setEmergeEnv(getState()->curThread()->getCurrentEnv());
			t = fr;
		}

		n->value = t->clone();
		nodeLink->backAfterExec = true;
	}

	void __execSCOPE_FUNC_CALL(NodeLink *nodeLink, langXThread *thread) {
		Node *n = nodeLink->node;

		nodeLink->backAfterExec = false;      // 函数需要执行两次 才会获取到结果

		// 根据语法文件可知 n1 是一个SCOPE 类型
		Node *n1 = n->opr_obj->op[0];
		ClassInfo *claxxInfo = nullptr;
		char *className = n1->opr_obj->op[0]->var_obj->name;
		char *memberName = n1->opr_obj->op[1]->var_obj->name;
		NodeLink *putNodeLink = nullptr;
		const char *remark = fileInfoString(n->fileinfo).c_str();

		if (nodeLink->index == 0) {
			// 进行一些检测和处理参数
			nodeLink->index = 1;
			putNodeLink = newNodeLink(nullptr, n);
			nodeLink->ptr_u = putNodeLink;

			claxxInfo = getState()->getClass(className);
			if (claxxInfo == NULL)
			{
				thread->throwException(newClassNotFoundException(className)->addRef());
				return;
			}

			Function *t = claxxInfo->getFunction(memberName);
			if (t == NULL)
			{
				char tmp[100] = { 0 };
				sprintf(tmp, "no function %s in class %s.", memberName, className);
				thread->throwException(newNoClassMemberException(tmp)->addRef());
				return;
			}

			ClassBridgeEnv *env = new ClassBridgeEnv(claxxInfo);
			getState()->curThread()->newEnv(env);

			// 根据语法解析文件得知， 第二个节点为参数节点
			XArgsList *args = (XArgsList *)n->opr_obj->op[1]->ptr_u;
			callFunc(t, args, remark, putNodeLink);        // 首次执行 确定参数
			return;
		}
		else {
			putNodeLink = (NodeLink*)nodeLink->ptr_u;
		}

		claxxInfo = getState()->getClass(className);
		Function *t = claxxInfo->getFunction(memberName);

		// 根据语法解析文件得知， 第二个节点为参数节点
		XArgsList *args = (XArgsList *)n->opr_obj->op[1]->ptr_u;
		n->value = callFunc(t, args, remark, putNodeLink);

		doSuffixOperationArgs(args);
		n1->value = NULL;

		getState()->curThread()->backEnv();
		nodeLink->backAfterExec = true;
	}

	// 执行 try {}
	void __execXTRY(NodeLink *nodeLink, langXThread *thread) {
		Node *n = nodeLink->node;

		if (nodeLink->index == 0) {
			nodeLink->index = 1;
			TryEnvironment * tryEnv = new TryEnvironment();
			tryEnv->setCatchNode(n->opr_obj->op[1]);    // 设置catch 节点
			thread->newEnv(tryEnv);
			thread->beginExecute(n->opr_obj->op[0], true);
			nodeLink->tryEnv = tryEnv;     // 设置环境到节点是上
			return;
		}

		if (nodeLink->index == 1) {
			thread->backEnv();
		}

		nodeLink->backAfterExec = true;
	}

	//  类型判断语句， 返回一个 true/false
	void __execXIS(NodeLink *nodeLink, langXThread *thread) {
		Node *n = nodeLink->node;
		Node *n1 = n->opr_obj->op[0];
		Node *n2 = n->opr_obj->op[1];

		if (nodeLink->index == 0) {
			thread->beginExecute(n1, true);
			nodeLink->index = 1;
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
		nodeLink->backAfterExec = true;
	}

	// 包含其他文件
	void __execINCLUDE(NodeLink *nodeLink) {
		Node *n = nodeLink->node;

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
		nodeLink->backAfterExec = true;
	}

	// 执行 require 其他文件
	void __execREQUIRE(NodeLink *nodeLink) {
		Node *n = nodeLink->node;

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

		nodeLink->backAfterExec = true;
		// it's ok ?
	}

	void __execREQUIRE_ONCE(NodeLink *nodeLink) {
		Node *n = nodeLink->node;

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
		nodeLink->backAfterExec = true;
	}

	// 引入命名空间或者类
	void __execREF(NodeLink *nodeLink) {
		Node *n = nodeLink->node;

		//  深度为1 的环境为一个 脚本环境 或者命名空间环境。
		Environment *env = getState()->getScriptOrNSEnv();
		if (env == nullptr)
		{
			// error.
			getState()->curThread()->throwException(newUnsupportedOperationException("cannot ref operation now!")->addRef());
			return;
		}

		EnvironmentType eType = env->getType();
		if (eType != TScriptEnvironment
				&& eType != TXNameSpaceEnvironment)
		{
			getState()->curThread()->throwException(newUnsupportedOperationException("cannot ref not inner a script or namespace! check are you ok?")->addRef());
			return;
		}

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

		XNameSpace *retSpace = nullptr;
		ClassInfo *retClass = nullptr;
	
		if (flag)
		{
			//  str 是用掉了已经
			
			retSpace = space;
		}
		else {
			ClassInfo *c = space->getClass(str.c_str());
			if (c != NULL)
			{
				// 添加类
				retClass = c;
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
				retSpace = space;
			}
		}

		if (eType == TScriptEnvironment)
		{
			ScriptEnvironment *scriptEnv = (ScriptEnvironment*)env;
			if (retSpace != nullptr)
			{
				scriptEnv->addNameSpace(retSpace);
			}
			if (retClass != nullptr)
			{
				scriptEnv->addClassInfo(retClass);
			}

		}
		else if (eType == TXNameSpaceEnvironment)
		{
			XNameSpaceEnvironment *nsEnv = (XNameSpaceEnvironment*)env;
			if (retSpace != nullptr)
			{
				nsEnv->getNameSpace()->addRefNamespace(retSpace);
			}
			if (retClass != nullptr)
			{
				nsEnv->putClass(retClass->getName(), retClass);
			}
		}
		
		nodeLink->backAfterExec = true;
	}

	void __realExecCONST(Node *n, langXThread *thread) {
		if (!n) {
			return;
		}
		Object *obj = Allocator::allocate(NULLOBJECT);
		obj->setEmergeEnv(thread->getCurrentEnv());
		obj->setConst(true);
		for (int i = 0; i < n->opr_obj->op_count; i++)
		{
			Node *t = n->opr_obj->op[i];
			if (t == NULL)
			{
				continue;
			}
			if (t->type != NODE_VARIABLE)
			{
				if (t->type == NODE_OPERATOR && t->opr_obj->opr == VAR_DECLAR)
				{
					__realExecCONST(t, thread);
				}
				else
				{
					// 抛出异常
					thread->throwException(newUnsupportedOperationException("invalid const stmt.")->addRef());
					return;
				}
				continue;
			}

			char *name = t->var_obj->name;
			Object *tmp = thread->getCurrentEnv()->getObjectSelf(name);
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

	//  常量限制
	void __execCONST(NodeLink *nodeLink, langXThread *thread) {
		Node *n = nodeLink->node;
		__realExecCONST(n, thread);
		nodeLink->backAfterExec = true;
	}

	//  local 限制
	void __realExecLOCAL(Node *n, langXThread *thread) {
		if (!n) {
			return;
		}

		Object *obj = Allocator::allocate(NULLOBJECT);
		obj->setEmergeEnv(thread->getCurrentEnv());
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
					__realExecLOCAL(t, thread);
				}
				else
				{
					// 抛出异常
					thread->throwException(newUnsupportedOperationException("invalid local stmt.")->addRef());
					return;
				}
				continue;
			}

			if (t->type == NodeType::NODE_VARIABLE)
			{
				char *name = t->var_obj->name;
				Object *tmp = thread->getCurrentEnv()->getObjectSelf(name);
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
				NodeLink tmpNodeLink;
				memset(&tmpNodeLink, 0, sizeof(NodeLink));
				tmpNodeLink.node = t;
				__realExecNode(&tmpNodeLink, thread);
			}
		}

		Allocator::free(obj);
	}

	void __execLOCAL(NodeLink* nodeLink, langXThread *thread) {
		Node *n = nodeLink->node;
		__realExecLOCAL(n, thread);
		nodeLink->backAfterExec = true;
	}

	//  continue 关键字
	void __execCONTINUE(NodeLink *nodeLink, langXThread* thread) {
		Node *n = nodeLink->node;

		if (!thread->isInLoop())
		{
			getState()->curThread()->throwException(newUnsupportedOperationException("invalid continue stmt.")->addRef());
			//printf("无效的CONTINUE 语句 ");
			return;
		}

		//
		do {
			if (nodeLink == nullptr) {
				break;
			}

			Node *n = nodeLink->node;
			freeSubNodes(n);
			if (n->type == NodeType::NODE_OPERATOR) {
				int opr = n->opr_obj->opr;
				if (opr == WHILE || opr == FOR) {
					// 找到了该节点
					if (opr == WHILE) {
						// 跳到判定条件的地方
						nodeLink->index = 2;
					}
					else if (opr == FOR) {
						// 跳到后置节点的地方
						nodeLink->index = 3;
					}
					break;
				}
			}

			nodeLink = nodeLink->previous;
			thread->endExecute();
		} while (true);

		thread->setBackInExec(true);
	}

	/*
	 * 执行节点，  节点的结果 将 放在  Node.value 上
	 * 这是一个 Object 类型的指针    07-24
	 * 由 void __execNode(Node *node)    修改为  __realExecNode()       2017年11月26日
	 */
	void __realExecNode(NodeLink *nodeLink, langXThread *thread) {
		if (nodeLink == NULL || nodeLink->node == NULL)
		{
			return;
		}

		//  设置当前节点在执行结束后  会回收， 下面的 switch  开始前会重置状态
		bool nodeLinkBackAfterExec = nodeLink->backAfterExec;
		nodeLink->backAfterExec = true;

		Node *node = nodeLink->node;

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
				// 匿名函数    ...  wtf ???  当初匿名函数到底是怎么进行处理的- -
				//  2017年12月3日   当运算一个匿名函数的时候， 就把改该节点的值 做成一个函数指针指向这个匿名函数
				node->value = Allocator::allocateFunctionRef(func);
				return;
			}
			if (thread->getCurrentEnv()->getFunctionSelf(func->getName()) != NULL)
			{
				char tmp[100] = { 0 };
				sprintf(tmp, "function %s already declared.", func->getName());
				thread->throwException(newRedeclarationException(tmp)->addRef());
				delete func;
				node->value = NULL;
				return;
			}

			//函数的产生环境可能在类内部
			//func->setEmergeEnv(getState()->curThread()->getCurrentEnv());
			Environment *env = getState()->getScriptOrNSEnv();
			if (env != NULL && env->getType() == EnvironmentType::TScriptEnvironment)
			{
				func->setScriptEnv((ScriptEnvironment*)env);
			}
			thread->getCurrentEnv()->putFunction(func->getName(), func);

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
			if (nodeLink->index == 0) {
				// 获取一些参数值
				Object *tmpValue = getValueFromArrayInfo(arrayInfo, nodeLink, thread);
				if (tmpValue != nullptr) {
					// 可能上面的执行中没需要参数，一次就成功了，直接将值处理了就好
					node->value = tmpValue;
					freeArrayInfo(arrayInfo);
				}
			}
			else {
				node->value = getValueFromArrayInfo(arrayInfo, nodeLink, thread);
				freeArrayInfo(arrayInfo);
			}
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

		nodeLink->backAfterExec = nodeLinkBackAfterExec;

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
			__exec59(nodeLink, thread);
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
		case '!':
			__exec33(nodeLink);
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
			__execWHILE(nodeLink, thread);
			break;
		case FOR:
			__execFOR(nodeLink, thread);
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
			__execSWITCH(nodeLink, thread);
			break;
		case CASE_LIST:
			__execCASE_LIST(nodeLink, thread);
			break;
		case CASE:
			__execCASE(nodeLink, thread);
			break;
		case DEFAULT:
			__execDeafult(nodeLink, thread);
			break;
		case NEW:
			__execNEW(nodeLink, thread);
			break;
		case CLAXX_BODY:
			__execCLAXX_BODY(nodeLink);
			break;
		case CLAXX_MEMBER:
			__execCLAXX_MEMBER(nodeLink, thread);
			break;
		case CLAXX_FUNC_CALL:
			__execCLAXX_FUNC_CALL(nodeLink, thread);
			break;
		case VAR_DECLAR:
			__execVAR_DECLAR(nodeLink, thread);
			break;
		case RESTRICT:
			__execRESTRICT(nodeLink, thread);
			break;
		case THIS:
			__execTHIS(nodeLink, thread);
			break;
		case XTRY:
			__execXTRY(nodeLink, thread);
			break;
		case LEFT_SHIFT:
			__execLEFT_SHIFT(nodeLink);
			break;
		case RIGHT_SHIFT:
			__execRIGHT_SHIFT(nodeLink);
			break;
		case XIS:
			__execXIS(nodeLink, thread);
			break;
		case SCOPE:
			__execSCOPE(nodeLink, thread);
			break;
		case SCOPE_FUNC_CALL:
			__execSCOPE_FUNC_CALL(nodeLink, thread);
			break;
		case REQUIRE:
			__execREQUIRE(nodeLink);
			break;
		case  REQUIRE_ONCE:
			__execREQUIRE_ONCE(nodeLink);
			break;
		case XINCLUDE:
			__execINCLUDE(nodeLink);
			break;
		case REF:
			__execREF(nodeLink);
			break;
		case XCONST:
			__execCONST(nodeLink, thread);
			break;
		case XCONTINUE:
			__execCONTINUE(nodeLink, thread);
			break;
		case XLOCAL:
			__execLOCAL(nodeLink, thread);
			break;
		default:
			break;
		}
	}

	void __execNode(Node *node) {
		__execNode(node, nullptr);
	}

	void __execNode(Node *node, Node *limitNode) {
		langXThread * thread = getState()->curThread();
		if (node != NULL)
		{
			// 如果没给参数， 就暂时进入一个循环做一些事情
			thread->initRootNode(node);
		}

		Node *lastExecNode = NULL;
		NodeLink *curLink = NULL;
		while ((curLink = thread->getCurrentExecute()) != NULL) {
			//  程序没还有结束
			lastExecNode = curLink->node;

			int cmd = -1;
			if (curLink->node->type == NodeType::NODE_OPERATOR)
			{
				cmd = curLink->node->opr_obj->opr;
			}
			// printf("curLink: %d\n", cmd);
			__realExecNode(curLink, thread);     // 将原来的内容丢到一个新的方法里面
			if (thread->isBackInExec()) {
				// 上面方法可能会将  curLink 指向的位置内存被删除， 判定下两个值是否一致， 不一致则重新执行
				thread->setBackInExec(false);
				NodeLink *tmpNodeLink = thread->getCurrentExecute();
				if (tmpNodeLink == nullptr) {
					break;            // 栈顶已经没有元素
				}
				if (tmpNodeLink != curLink) {
					// tmpNodeLink 是最新的数据
					if (tmpNodeLink->node == limitNode) {
						// 强制跳跃到 限制节点了， 直接退出循环
						thread->endExecute();
						break;
					}

					continue;
				}
			}

			if (curLink->next == nullptr && curLink->backAfterExec) {
				// will end execute .
				Node *tmpNode = curLink->node;
				thread->endExecute();

				if (tmpNode == limitNode) {
					break;
				}
			}
		}

		// 处理下一些后续的操作
		if (lastExecNode)
		{
			doSuffixOperation(lastExecNode);
			lastExecNode = nullptr;
		}
		// printf("one round end\n");
	}
}