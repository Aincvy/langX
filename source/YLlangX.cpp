#include <stdio.h>
#include <string.h>
#include <stdarg.h>
#include <sstream>
#include "../include/YLlangX.h"
#include "../include/langX.h"
#include "../include/Object.h"
#include "../include/Number.h"
#include "../include/ExecNode.h"
#include "../include/RegFunctions.h"
#include "../include/Environment.h"
#include "../include/Allocator.h"
#include "../include/ClassInfo.h"
#include "../include/StackTrace.h"


extern int yyget_lineno(void);
extern const char * parseFileName;

using namespace langX;

static langXState* state = NULL;

void initLangX()
{
	if (state == NULL)
	{
		printf("initLangX\n");
		state = new langXState();

		regFunctions(state);
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

void assignment(const char *n, langX::Object * obj)
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
		printf("var %s not found.\n", n);
		return 0;
	}
	if (p->getType() == NUMBER)
	{
		return *(Number*)p;
	}
	return 0;
}

void deal_state(NodeState * state) {
	state->isBreak = false;
	state->isReturn = false;
	state->in_func = false;
	state->in_loop = false;
	state->in_switch = false;
	state->isCaseNeedCon = true;
	state->isSuffix = false;
}

void deal_switch_info(SwitchInfo *si) {
	si->defaultNode = NULL;
	si->isDefault = false;
	si->isInCase = false;
	si->doDefault = false;
}

void deal_fileinfo(NodeFileInfo *f) {
	f->lineno = yyget_lineno();
	f->filename = parseFileName;
}

std::string fileInfoString(const NodeFileInfo & f) {
	std::stringstream ss;
	ss << "at ";
	if (f.filename)
	{
		ss << f.filename;
	}
	else {
		ss << "<NoFile>";
	}

	ss << ":";
	ss << f.lineno;

	return std::string(ss.str());
}

XNode * string(char *v)
{
	XNode * node = (XNode*)calloc(1,sizeof(XNode) * 1);
	node->con_obj = (langX::Constant*) calloc(1,sizeof(langX::Constant) * 1);

	node->freeOnExeced = true;
	deal_fileinfo(&node->fileinfo);
	deal_state(&node->state);
	deal_switch_info(&node->switch_info);
	node->value = NULL;
	node->postposition = NULL;
	node->type = NODE_CONSTANT_STRING;
	// v 是已经申请过的内存 ， 直接赋值就OK
	node->con_obj->sValue = v;
	//printf("createStringNode: %d\n",i);
	return node;
}

XNode * number(double a)
{
	XNode * node = (XNode*)calloc(1,sizeof(XNode) * 1);
	node->con_obj = (langX::Constant*) calloc(1,sizeof(langX::Constant) * 1);

	deal_fileinfo(&node->fileinfo);
	deal_state(&node->state);
	deal_switch_info(&node->switch_info);
	node->type = NODE_CONSTANT_NUMBER;
	node->value = NULL;
	node->postposition = NULL;
	node->freeOnExeced = true;
	node->con_obj->dValue = a;
	node->con_obj->sValue = NULL;
	//printf("createNumberNode: %.5f\n", a);
	return node;
}

XNode * var(char *name)
{
	XNode * node = (XNode*)calloc(1,sizeof(XNode) * 1);
	node->var_obj = (langX::Variable*) calloc(1,sizeof(langX::Variable) * 1);

	deal_fileinfo(&node->fileinfo);
	deal_state(&node->state);
	deal_switch_info(&node->switch_info);
	node->type = NODE_VARIABLE;
	node->freeOnExeced = true;
	node->value = NULL;
	node->postposition = NULL;
	node->var_obj->name = name;

	//printf("createVarNode: %s\n", name);
	//printf("addr: %p\n" , node);
	return node;
}

XNode * opr(int opr, int npos, ...)
{
	va_list ap;

	XNode * node = (XNode*)calloc(1,sizeof(XNode) * 1);
	node->opr_obj = (langX::Operator*) calloc(1,sizeof(langX::Operator) * 1);
	node->opr_obj->op = (XNode**)calloc(1,sizeof(XNode*) * npos);

	deal_fileinfo(&node->fileinfo);
	deal_state(&node->state);
	deal_switch_info(&node->switch_info);
	node->value = NULL;
	node->postposition = NULL;
	node->type = NODE_OPERATOR;
	node->freeOnExeced = true;
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

XNode * sopr(int opr, int npos, ...)
{
	//printf("sopr: %d\n" ,opr);
	va_list ap;

	XNode * node = (XNode*)calloc(1,sizeof(XNode) * 1);
	node->opr_obj = (langX::Operator*) calloc(1,sizeof(langX::Operator) * 1);
	node->opr_obj->op = (XNode**)calloc(1,sizeof(XNode*) * npos);

	deal_fileinfo(&node->fileinfo);
	deal_state(&node->state);
	deal_switch_info(&node->switch_info);
	node->state.isSuffix = true;
	node->value = NULL;
	node->postposition = NULL;
	node->type = NODE_OPERATOR;
	node->freeOnExeced = true;
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

XNode * func(char *name, XParamsList *params, XNode *node)
{
	if (node != NULL)
	{
		node->freeOnExeced = false;
	}
	//printf("create Func: %s\n" , name);

	Function *func = new Function(name, node);
	func->setParamsList(params);
	//  在执行他的时候再把它放入环境中
	//getState()->getCurrentEnv()->putFunction(name, func);
	free(name);
	XNode * nodeF = (XNode*)calloc(1,sizeof(XNode) * 1);
	nodeF->type = NODE_FUNCTION;
	deal_fileinfo(&node->fileinfo);
	deal_state(&nodeF->state);
	deal_switch_info(&nodeF->switch_info);
	nodeF->value = func;
	return nodeF;
}

XNode * xnull()
{
	XNode * node = (XNode*)calloc(1,sizeof(XNode) * 1);

	deal_fileinfo(&node->fileinfo);
	deal_state(&node->state);
	deal_switch_info(&node->switch_info);
	node->type = NODE_NULL;
	node->freeOnExeced = true;
	node->value = NULL;
	node->postposition = NULL;

	return node;
}

XNode * claxx(char *name , char *parent, XNode * node) {

	ClassInfo *pclass = NULL;
	if (parent != NULL)
	{
		pclass = getState()->getGlobalEnv()->getClass(parent);
		if (pclass == NULL)
		{
			printf("error! cannot find class %s on extends!" , parent);
		}
		free(parent);
	}

	ClassInfo *claxxInfo = new ClassInfo(name);
	claxxInfo->setParent(pclass);
	free(name);

	if (node != NULL)
	{
		ClassBridgeEnv *env = new ClassBridgeEnv(claxxInfo);
		state->newEnv(env);
		__execNode(node);
		state->backEnv(false);
		// 把环境添加到List ，等langXState 析构的时候会析构这个变量
		state->addEnvToList(env);
	}
	
	XNode * nodeC = (XNode*)calloc(1, sizeof(XNode) * 1);
	nodeC->type = NODE_CLASS;
	deal_fileinfo(&node->fileinfo);
	deal_state(&nodeC->state);
	deal_switch_info(&nodeC->switch_info);
	nodeC->ptr_u = claxxInfo;

	return nodeC;
}

XObject * call(char *name, XArgsList* args , const char *remark)
{
	Function *function = getState()->getCurrentEnv()->getFunction(name);
	if (function == NULL)
	{
		printf("cannot find function %s\n", name);
		return NULL;
	}

	return callFunc(function, args, remark);
}

XObject * callFunc(XFunction* function, XArgsList *args, const char *remark) {
	if (function == NULL)
	{
		return NULL;
	}


	getState()->getStackTrace().newFrame(function->getClassInfo(), function, remark);

	if (function->is3rd())
	{
		// 第三方函数 
		X3rdFunction *x3rdfunc = (X3rdFunction*)function;
		X3rdArgs _3rdArgs;
		if (args != NULL)
		{
			for (int i = 0; i < args->index; i++)
			{
				if (args->args[i] == NULL)
				{
					_3rdArgs.args[i] = NULL;
					continue;
				}
				execNode(args->args[i]);
				_3rdArgs.args[i] = args->args[i]->value;
			}
			_3rdArgs.index = args->index;
		}
		
		Object * ret1 = x3rdfunc->call(_3rdArgs);
		getState()->getStackTrace().popFrame();
		return ret1;
	}

	Environment * env = getState()->newEnv();
	Object * ret = NULL;
	if (args != NULL)
	{
		XParamsList *params = function->getParamsList();
		for (int i = 0; i < args->index; i++)
		{
			if (i >= params->index)
			{
				break;
			}

			if (args->args[i] != NULL)
			{
				execNode(args->args[i]);
				env->putObject(params->args[i], args->args[i]->value->clone());
				//printf("put object: %s\n", params->args[i]);
			}
		}

		ret = function->call();

	}
	else {
		ret = function->call();
	}
	getState()->getStackTrace().popFrame();
	getState()->backEnv();

	return ret;
}

XNode * argsNode(XArgsList * args) {
	XNode * node = (XNode*)calloc(1,sizeof(XNode) * 1);
	node->type = NODE_ARGS;
	node->value = NULL;
	node->postposition = NULL;
	node->ptr_u = args;
	deal_fileinfo(&node->fileinfo);
	deal_state(&node->state);
	deal_switch_info(&node->switch_info);

	return node;
}

XParamsList * params(XParamsList *args, char *name)
{
	XParamsList * list = NULL;
	if (args == NULL)
	{
		list = (XParamsList* )calloc(1, sizeof(XParamsList));
		list->index = 0;
	}
	else {
		list = args;
	}

	// name 的内存是申请过的， 现在直接使用， 等不用的时候释放掉就OK了
	//printf("第 %d 个参数，名字: %s\n",list->index,name);
	list->args[list->index] = name;
	list->index++;

	return	list;
}

XArgsList * xArgs(XArgsList *args, XNode *node) {
	XArgsList *list = NULL;
	if (args == NULL)
	{
		list = (XArgsList*)calloc(1, sizeof(XArgsList));
		list->index = 0;
	}
	else {
		list = args;
	}

	list->args[list->index] = node;
	list->index++;

	return list;
}

void freeArgsList(XArgsList *alist) {
	if (alist->args != NULL)
	{
		for (int i = 0; i < alist->index; i++)
		{
			if (alist->args[i] != NULL)
			{
				freeNode(alist->args[i]);
				alist->args[i] = NULL;
			}
		}
	}

	free(alist);
}

void freeNode(XNode * n) {
	if (n == NULL)
	{
		return;
	}
	if (!n->freeOnExeced)
	{
		return;
	}
	// 如果是一个函数节点， 直接FREE节点内存就好了
	if (n->type == NODE_FUNCTION)
	{
		free(n);
		return;
	}

	if (n->value != NULL)
	{
		getState()->getAllocator().free(n->value);
		n->value = NULL;
	}

	//printf("free node\n");
	if (n->type == NODE_CONSTANT_NUMBER)
	{
		free(n->con_obj);
		free(n);
	}
	else if (n->type == NODE_CONSTANT_STRING)
	{
		if (n->con_obj->sValue != NULL)
		{
			free(n->con_obj->sValue);
		}
		free(n->con_obj);
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