#include <stdio.h>
#include "../include/ExecNode.h"
#include "../include/YLlangX.h"
#include "../include/Object.h"
#include "../include/Number.h"
#include "../include/String.h"
#include "../extern/y.tab.h"

namespace langX {

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

	int __readRealNumber(Object *obj, double* v) {
		if (obj == NULL)
		{
			return -1;
		}

		//printf("__readRealNumber1\n");
		if (obj->getType() != NUMBER)
		{
			return -1;
		}
		//printf("__readRealNumber2\n");

		Number * a = (Number*)obj;
		*v = a->getDoubleValue();
		//printf("__readRealNumber: %.2f\n" , (*v));
		return 0;
	}

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

	int __getNumberValue(Node*n, double *v) {
		//printf("__getNumberValue00   \n");
		if (n == NULL || v == NULL)
		{
			return -1;
		}

		checkValue(n);
		return __readRealNumber(n->value, v);
	}

	// +  
	// 操作结果， 会将结果存储在当前节点中 
	void __exec43(Node *n) {
		//printf("__exec43 n addr: %p\n", n);
		//printf("op_count: %d\n" , n->opr_obj->op_count);
		double a = 0;
		__getNumberValue(n->opr_obj->op[0], &a);
		double b = 0;
		__getNumberValue(n->opr_obj->op[1], &b);

		n->value = new Number(a + b);
		printf("%.2f\n", a + b);
	}

	// -
	void __exec45(Node *n) {
		double a = 0;
		__getNumberValue(n->opr_obj->op[0], &a);
		double b = 0;
		__getNumberValue(n->opr_obj->op[1], &b);

		n->value = new Number(a - b);
		printf("%.2f\n", a - b);
	}

	// *
	void __exec42(Node *n) {

		double a = 0;
		__getNumberValue(n->opr_obj->op[0], &a);
		double b = 0;
		__getNumberValue(n->opr_obj->op[1], &b);

		n->value = new Number(a*b);
		printf("%.2f\n", a*b);

	}

	// /
	void __exec47(Node *n) {

		double a = 0;
		__getNumberValue(n->opr_obj->op[0], &a);
		double b = 0;
		__getNumberValue(n->opr_obj->op[1], &b);

		n->value = new Number(a / b);
		printf("%.2f\n", a / b);
	}

	// 赋值操作 = 
	void __exec61(Node *n) {
		printf("__exec61 start\n");
		Node *left = n->opr_obj->op[0];
		if (left->type != NODE_VARIABLE)
		{
			printf("left not the NODE_VARIABLE\n");
			return;
		}

		printf("__exec61 left name: %s\n", left->var_obj->name);
		Node *right = n->opr_obj->op[1];
		checkValue(right);
		// 赋值操作的结果 为 右值的结果
		if (right->value == NULL)
		{
			n->value = NULL;
		}
		else {
			n->value = right->value->clone();
		}

		assignment(left->var_obj->name, n->value);
	}

	void __execADD_EQ(Node *n) {
		printf("__execADD_EQ\n");
		Node *left = n->opr_obj->op[0];
		if (left->type != NODE_VARIABLE)
		{
			printf("left not the NODE_VARIABLE: %d\n",left->type);
			return;
		}
		double a = 0;
		__getNumberValue(left, &a);
		double b = 0;
		__getNumberValue(n->opr_obj->op[1], &b);
		n->value = new Number(a + b);
		assignment(left->var_obj->name, n->value);

		printf("__execADD_EQ END \n");
	}

	void __execSUB_EQ(Node *n) {
		printf("__execSUB_EQ\n");
	}

	void __execMUL_EQ(Node *n) {
		printf("__execMUL_EQ\n");
	}

	void __execDIV_EQ(Node *n) {
		printf("__execDIV_EQ\n");
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
			__execNode(n->opr_obj->op[i]);
		}
	}

	// 逗号表达式
	void __exec44(Node *n) {
		// 操作和 分号表达式差不多应该， 这样应该就OK了。 
		__exec59(n);
	}

	// 符号： >
	void __exec62(Node *n) {
		double a = 0;
		__getNumberValue(n->opr_obj->op[0], &a);
		double b = 0;
		__getNumberValue(n->opr_obj->op[1], &b);

		if (a > b)
		{
			n->opr_obj->bool_value = true;
		}
		else {
			n->opr_obj->bool_value = false;
		}

	}

	// 大于等于
	void __execGE_OP(Node *n) {
		double a = 0;
		__getNumberValue(n->opr_obj->op[0], &a);
		double b = 0;
		__getNumberValue(n->opr_obj->op[1], &b);

		if (a >= b)
		{
			n->opr_obj->bool_value = true;
		}
		else {
			n->opr_obj->bool_value = false;
		}

	}

	// 符号： <
	void __exec60(Node *n) {
		double a = 0;
		__getNumberValue(n->opr_obj->op[0], &a);
		double b = 0;
		__getNumberValue(n->opr_obj->op[1], &b);

		if (a < b)
		{
			n->opr_obj->bool_value = true;
		}
		else {
			n->opr_obj->bool_value = false;
		}
	}

	// 小于等于
	void __execLE_OP(Node *n) {
		double a = 0;
		__getNumberValue(n->opr_obj->op[0], &a);
		double b = 0;
		__getNumberValue(n->opr_obj->op[1], &b);

		if (a <= b)
		{
			n->opr_obj->bool_value = true;
		}
		else {
			n->opr_obj->bool_value = false;
		}
	}

	// 等于
	void __execEQ_OP(Node *n) {
		double a = 0;
		__getNumberValue(n->opr_obj->op[0], &a);
		double b = 0;
		__getNumberValue(n->opr_obj->op[1], &b);

		if (a == b)
		{
			n->opr_obj->bool_value = true;
		}
		else {
			n->opr_obj->bool_value = false;
		}
	}

	// 不等于
	void __execNE_OP(Node *n) {
		double a = 0;
		__getNumberValue(n->opr_obj->op[0], &a);
		double b = 0;
		__getNumberValue(n->opr_obj->op[1], &b);

		if (a != b)
		{
			n->opr_obj->bool_value = true;
		}
		else {
			n->opr_obj->bool_value = false;
		}
	}

	void __execOPAND(Node *n) {
		if (n == NULL)
		{
			return;
		}

		if (__tryConvertToBool(n->opr_obj->op[0]))
		{
			n->opr_obj->bool_value = __tryConvertToBool(n->opr_obj->op[1]);
			//__execNode(n->opr_obj->op[1]);
		}
		else {
			n->opr_obj->bool_value = false;
		}
	}

	void __execOPOR(Node *n) {
		if (n == NULL)
		{
			return;
		}

		if (__tryConvertToBool(n->opr_obj->op[0]))
		{
			n->opr_obj->bool_value = true;
		}
		else {
			n->opr_obj->bool_value = __tryConvertToBool(n->opr_obj->op[1]);
		}
	}

	void __execIF(Node *n) {
		if (n == NULL)
		{
			return;
		}

		if (__tryConvertToBool(n->opr_obj->op[0]))
		{
			__execNode(n->opr_obj->op[1]);
		}
		else {
			if (n->opr_obj->op_count >= 3)
			{
				__execNode(n->opr_obj->op[2]);
			}
		}
	}

	void __execWHILE(Node *n) {
		if (n == NULL || n->opr_obj == NULL || n->opr_obj->op_count != 2)
		{
			return;
		}

		while (__tryConvertToBool(n->opr_obj->op[0]))
		{
			__execNode(n->opr_obj->op[1]);
		}
	}

	void __execFOR(Node *n) {
		if (n == NULL || n->opr_obj == NULL || n->opr_obj->op_count != 4)
		{
			return;
		}

		for (__execNode(n->opr_obj->op[0]); __tryConvertToBool(n->opr_obj->op[1]); __execNode(n->opr_obj->op[2]))
		{
			__execNode(n->opr_obj->op[3]);
		}
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

		//printf("__execNode 01x\n");
		//printf("node addr: %p\n",node);
		if (node->type == NODE_VARIABLE)
		{
			printf("__execNode NODE_VARIABLE\n");
			// 协调程序， 使变量的 obj 处于赋值状态
			if (node->value == NULL)
			{
				//printf("__execNode 01\n");
				Object *obj = getValue(node->var_obj->name);

				if (obj == NULL)
				{
					printf("var %s=null \n", node->var_obj->name);
					node->value = NULL;
				}
				else {
					if (obj->getType() == NUMBER)
					{
						Number * number = (Number*)obj;
						printf("var %s=%.2f \n", node->var_obj->name, number->getDoubleValue());
					}

					node->value = obj;
				}

			}

			return;
		}
		else if (node->type == NODE_CONSTANT_NUMBER)
		{
			printf("__execNode NODE_CONSTANT_NUMBER\n");
			node->value = new Number(node->con_obj->dValue);
			return;
		}
		else if (node->type == NODE_CONSTANT_STRING)
		{
			printf("__execNode NODE_CONSTANT_STRING\n");
			return;
		}


		printf("exec operator node. opr is: %d\n", node->opr_obj->opr);
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
		case FOR:
			__execFOR(node);
		default:
			break;
		}

	}

}

