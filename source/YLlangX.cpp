#include <stdio.h>
#include <string.h>
#include <stdarg.h>
#include "../include/YLlangX.h"
#include "../include/langX.h"
#include "../include/Object.h"
#include "../include/Number.h"
#include "../include/ExecNode.h"

using namespace langX;

static langXState* state = NULL;

void initLangX()
{
	if (state == NULL)
	{
		printf("initLangX\n");
		state = new langXState();
	}
}

void closeLangX()
{
	if (state != NULL)
	{
		printf("closeLangX\n");
		delete state;
		state = NULL;
	}
}

void assignment(const char *n,langX::Object * obj)
{
	state->putObject(n, obj);
}


Object * getValue(const char *n)
{
	return state->getObject(n);
}

langX::langXState * getState()
{
	return state;
}

double getNumberValue(const char *n)
{
	//printf("getNumberValue length: %d\n" , strlen(n));
	
	Object*p = getValue(n);
	if (p == NULL)
	{
		printf("var %s not found.\n" , n );
		return 0;
	}
	if (p->getType() == NUMBER)
	{
		return *(Number*)p;
	}
	return 0;
}

XNode * string(char *v)
{
	XNode * node = (XNode*)malloc(sizeof(XNode) * 1);
	node->con_obj = (langX::Constant*) malloc(sizeof(langX::Constant) * 1);

	node->type = NODE_CONSTANT_STRING;
	// v 是已经申请过的内存 ， 直接复制就OK
	node->con_obj->sValue = v;
	//printf("createNumberNode: %d\n",i);
	return node;
}

XNode * number(double a)
{
	XNode * node = (XNode*)malloc(sizeof(XNode) * 1);
	node->con_obj = (langX::Constant*) malloc(sizeof(langX::Constant) * 1);

	node->type = NODE_CONSTANT_NUMBER;
	node->freeOnExeced = true;
	node->con_obj->dValue = a;
	node->con_obj->sValue = NULL;
	//printf("createNumberNode: %.5f\n",a);
	return node;
}

XNode * var(char *name)
{
	XNode * node = (XNode*)malloc(sizeof(XNode) * 1);
	node->var_obj = (langX::Variable*) malloc(sizeof(langX::Variable) * 1);

	node->type = NODE_VARIABLE;
	node->freeOnExeced = true;
	node->value = NULL;
	node->var_obj->name = name;

	printf("createVarNode: %s\n", name);
	//printf("addr: %p\n" , node);
	return node;
}

XNode * opr(int opr, int npos, ...)
{
	va_list ap;

	XNode * node = (XNode*)malloc(sizeof(XNode) * 1);
	node->opr_obj = (langX::Operator*) malloc(sizeof(langX::Operator) * 1);
	node->opr_obj->op = (XNode**)malloc(sizeof(XNode*) * npos);
	
	node->value = NULL;
	node->type = NODE_OPERATOR;
	node->freeOnExeced = true;
	node->opr_obj->bool_value = false;
	node->opr_obj->opr = opr;
	node->opr_obj->op_count = npos;

	va_start(ap, npos);
	for (size_t i = 0; i < npos; i++)
	{
		node->opr_obj->op[i] = va_arg(ap, XNode*);
	}
	va_end(ap);
	
	//printf("new opr node, opr is: %d\n" , opr);
	//printf("opr npos: %d\n", npos);
	//printf("node npos: %d\n", node->opr_obj->op_count);
	//printf("createOperatorNode: %p\n",node);
	return node;
}

XNode * func(char *name, XArgsList *args, XNode *node)
{
	node->freeOnExeced = false;
	Function *func = new Function(name,node);
	getState()->getCurrentEnv()->putFunction(name, func);
	return nullptr;
}

XNode * call(char *name)
{
	Function *function = getState()->getCurrentEnv()->getFunction(name);
	if (function == NULL)
	{
		printf("cannot find function %s\n",name);
		return NULL;
	}
	function->call();
	return nullptr;
}

void freeNode(XNode * n) {
	if (n == NULL)
	{
		return;
	}
	if (!n->freeOnExeced)
	{
		return ;
	}

	//printf("free node\n");
	if (n->type == NODE_CONSTANT_NUMBER)
	{
		free(n->con_obj);
		if (n->value != NULL)
		{
			delete n->value;
			n->value = NULL;
		}
		free(n);
	}
	else if (n->type == NODE_VARIABLE)
	{
		//printf("00000\n");
		if (n->var_obj->name != NULL)
		{
			free(n->var_obj->name);
			n->var_obj->name = NULL;
		}

		free(n->var_obj);
		free(n);
	}
	else if (n->type == NODE_OPERATOR)
	{
		//printf("00001\n");
		for (size_t i = 0; i < n->opr_obj->op_count; i++)
		{
			freeNode(n->opr_obj->op[i]);
		}

		free(n->opr_obj->op);
		free(n->opr_obj);
		free(n);
	}
}

void execNode(XNode *n) {
	langX::__execNode(n);
}

void execAndFreeNode(XNode *n) {
	execNode(n);
	freeNode(n);
}