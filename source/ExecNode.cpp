#include <stdio.h>
#include "../include/ExecNode.h"
#include "../include/YLlangX.h"
#include "../include/Object.h"
#include "../include/Number.h"
#include "../include/String.h"
#include "../extern/y.tab.h"

namespace langX {

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

		if (n->type == NODE_CONSTANT_NUMBER)
		{
			if (n->con_obj->dValue == 0)
			{
				return false;
			}
			return true;
		}
		else if (n->type == NODE_CONSTANT_STRING)
		{
			return true;
		}
		else if (n->type == NODE_VARIABLE)
		{
			__execNode(n);
			Object *obj = n->var_obj->obj;
			if (obj == NULL)
			{
				return false;
			}
			return obj->isTrue();
		}
		else {
			__execNode(n);
			Object *obj = n->opr_obj->obj;
			if (obj == NULL)
			{
				return n->opr_obj->bool_value;
			}
			return obj->isTrue();
		}
	}

	int __getNumberValue(Node*n, double *v) {
		//printf("__getNumberValue00   \n");
		if (n == NULL || v == NULL)
		{
			return -1;
		}


		//printf("n type: %d\n", n->type);
		//printf("n addr: %p\n" , n);

		if (n->type == NODE_CONSTANT_STRING)
		{
			return -1;
		}

		if (n->type == NODE_CONSTANT_NUMBER)
		{
			//printf("__getNumberValue01  \n");
			*v = n->con_obj->dValue;
		}
		else if (n->type == NODE_VARIABLE)
		{
			//printf("__getNumberValue::  NODE_VARIABLE");
			__execNode(n);
			__readRealNumber(n->var_obj->obj, v);
		}
		else {
			//printf("__getNumberValue::  else");

			__execNode(n);
			__readRealNumber(n->opr_obj->obj, v);
		}
		

		return 0;
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

		n->opr_obj->obj = new Number(a+b);
		printf("%.2f\n", a+b);
	}

	// -
	void __exec45(Node *n) {
		double a = 0;
		__getNumberValue(n->opr_obj->op[0], &a);
		double b = 0;
		__getNumberValue(n->opr_obj->op[1], &b);

		n->opr_obj->obj = new Number(a-b);
		printf("%.2f\n", a-b );
	}

	// *
	void __exec42(Node *n) {

		double a = 0;
		__getNumberValue(n->opr_obj->op[0], &a);
		double b = 0;
		__getNumberValue(n->opr_obj->op[1], &b);

		n->opr_obj->obj = new Number(a*b);
		printf("%.2f\n", a*b);

	}

	// /
	void __exec47(Node *n) {

		double a = 0;
		__getNumberValue(n->opr_obj->op[0], &a);
		double b = 0;
		__getNumberValue(n->opr_obj->op[1], &b);

		n->opr_obj->obj = new Number(a/b);
		printf("%.2f\n", a/b);

		for (size_t i = 0; i < 10; i++)
		{

		}
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

		printf("__exec61 left name: %s\n" , left->var_obj->name);
		Node *right = n->opr_obj->op[1];
		if (right->type == NODE_CONSTANT_NUMBER)
		{
			n->opr_obj->obj = new Number(right->con_obj->dValue);
		}
		else if (right->type == NODE_CONSTANT_STRING)
		{
			n->opr_obj->obj = new String(right->con_obj->sValue);
			//assignment(left->var_obj->name, new String(right->con_obj->sValue));
		}
		else if (right->type == NODE_VARIABLE)
		{
			__execNode(right);
			n->opr_obj->obj = right->var_obj->obj;
			//assignment(left->var_obj->name, right->var_obj->obj);
		}
		else if (right->type == NODE_OPERATOR)
		{
			__execNode(right);
			n->opr_obj->obj = right->opr_obj->obj;
			//assignment(left->var_obj->name, right->opr_obj->obj);
		}

		assignment(left->var_obj->name, n->opr_obj->obj);
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
		}else{
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


	void __execIF(Node *n) {
		if (n == NULL)
		{
			return;
		}

		if (__tryConvertToBool(n->opr_obj->op[0]))
		{
			__execNode(n->opr_obj->op[1]);
		}
	}

	void __execWHILE(Node *n) {
		if (n == NULL || n->opr_obj  == NULL || n->opr_obj->op_count != 2)
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

		for (__execNode(n->opr_obj->op[0]);  __tryConvertToBool(n->opr_obj->op[1]) ; __execNode(n->opr_obj->op[2]))
		{
			__execNode(n->opr_obj->op[3]);
		}
	}

	void __execNode(Node *node) {
		if (node == NULL)
		{
			return;
		}

		//printf("__execNode 01x\n");
		//printf("node addr: %p\n",node);
		if (node->type == NODE_VARIABLE)
		{
			//printf("__execNode 01y");
			// 协调程序， 使变量的 obj 处于赋值状态
			if (node->var_obj->obj == NULL)
			{
				printf("__execNode 01\n");
				Object *obj = getValue(node->var_obj->name);

				if (obj  == NULL)
				{
					printf("var %s=null \n", node->var_obj->name);
					node->var_obj->obj = NULL;
				}
				else {
					if (obj->getType() == NUMBER)
					{
						Number * number = (Number*)obj;
						printf("var %s=%.2f \n", node->var_obj->name, number->getDoubleValue());
					}

					node->var_obj->obj = obj;
				}

			}

			//printf("__execNode 02");
			/*if (node->var_obj->obj == NULL)
			{
				printf("var %s=null \n" , node->var_obj->name);
			}
			else {
				if (node->var_obj->obj->getType() == NUMBER)
				{
					printf("var %s=%.2f", node->var_obj->name, (double)(*dynamic_cast<Number*>(node->var_obj->obj)));
				}
			}*/


			return;
		}

		if (node->type != NODE_OPERATOR)
		{
			return;
		}

		printf("exec operator node. opr is: %d\n" , node->opr_obj->opr);
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

