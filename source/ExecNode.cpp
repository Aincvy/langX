#include <stdio.h>
#include "../include/ExecNode.h"
#include "../include/YLlangX.h"
#include "../include/Object.h"
#include "../include/Number.h"
#include "../extern/y.tab.h"

namespace langX {

	int __readRealNumber(Object *obj, double* v) {
		if (obj == NULL)
		{
			return -1;
		}

		if (obj->getType() != NUMBER)
		{
			return -1;
		}

		Number * a = (Number*)obj;
		*v = a->getDoubleValue();
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
				return false;
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
			__execNode(n);
			__readRealNumber(n->var_obj->obj, v);
		}
		else {
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
			assignment(left->var_obj->name, new Number(right->con_obj->dValue));
		}
		else if (right->type == NODE_VARIABLE)
		{
			__execNode(right);
			assignment(left->var_obj->name, right->var_obj->obj);
		}
		else if (right->type == NODE_OPERATOR)
		{
			__execNode(right);
			assignment(left->var_obj->name, right->opr_obj->obj);
		}

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
		case IF:
			__execIF(node);
			break;
		default:
			break;
		}

	}

}

