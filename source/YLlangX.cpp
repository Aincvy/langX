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
#include "../include/Exception.h"
#include "../include/langXObject.h"
#include "../extern/y.tab.h"

extern int yyget_lineno(void);

using namespace langX;

static langXState* state = NULL;
static Node *currentNode = NULL;
static bool inException = false;

void initLangX()
{
	if (state == NULL)
	{
		printf("initLangX\n");
		state = new langXState();

		regFunctions(state);
		regExceptions();
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
	state->classAuto = false;
}

void deal_switch_info(SwitchInfo *si) {
	si->defaultNode = NULL;
	si->isDefault = false;
	si->isInCase = false;
	si->doDefault = false;
}

void deal_fileinfo(NodeFileInfo *f) {
	f->lineno = yyget_lineno();
	f->filename = state->getParsingFile();
}

XNode *newNode() {

	XNode * node = (XNode*)calloc(1, sizeof(XNode) * 1);
	node->con_obj = NULL;
	node->var_obj = NULL;
	node->arr_obj = NULL;
	node->opr_obj = NULL;

	node->freeOnExeced = true;
	deal_fileinfo(&node->fileinfo);
	deal_state(&node->state);
	deal_switch_info(&node->switch_info);
	node->value = NULL;
	node->postposition = NULL;
	node->ptr_u = NULL;

	return node;

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

XFunction * create3rdFunc(const char *name, langX::X3rdFuncWorker worker)
{
	X3rdFunction *func = new X3rdFunction();
	func->setName(name);
	func->setWorker(worker);
	func->setParamsList(NULL);
	func->setLangX(state);

	return func;
}

NodeFileInfo getCurrentNodeFileInfo()
{
	if (currentNode == NULL)
	{
		NodeFileInfo f;
		deal_fileinfo(&f);
		return (f);
	}
	return currentNode->fileinfo;
}

void setExecNode(XNode *n) {
	currentNode = n;
}

XNode * getExecNode()
{
	return currentNode;
}

void setInException(bool f)
{
	inException = f;
}

bool getInException()
{
	return inException;
}

XNode * string(char *v)
{
	XNode * node = newNode();
	node->con_obj = (langX::Constant*) calloc(1, sizeof(langX::Constant) * 1);

	node->type = NODE_CONSTANT_STRING;
	// v 是已经申请过的内存 ， 直接赋值就OK
	node->con_obj->sValue = v;
	//printf("createStringNode: %d\n",i);
	return node;
}

XNode * number(double a)
{
	XNode * node = newNode();
	node->con_obj = (langX::Constant*) calloc(1, sizeof(langX::Constant) * 1);
	node->type = NODE_CONSTANT_NUMBER;
	node->con_obj->dValue = a;
	node->con_obj->sValue = NULL;
	//printf("createNumberNode: %.5f\n", a);
	return node;
}

XNode * var(char *name)
{
	XNode * node = newNode();
	node->var_obj = (langX::Variable*) calloc(1, sizeof(langX::Variable) * 1);
	node->type = NODE_VARIABLE;
	node->var_obj->name = name;

	//printf("createVarNode: %s\n", name);
	//printf("addr: %p\n" , node);
	return node;
}

// 数组元素节点 
// 如果使用的变量， 则值放在 第三个参数lengthNode 上
XNode *arr(char *name, int index, XNode *indexNode) {

	XNode * node = newNode();
	node->arr_obj = (langX::ArrayInfo*) calloc(1, sizeof(langX::ArrayInfo) * 1);
	node->type = NODE_ARRAY_ELE;

	node->arr_obj->name = name;
	node->arr_obj->index = index;
	node->arr_obj->indexNode = indexNode;

	return node;

}

XNode * xint(int i)
{
	XNode * node = newNode();
	node->con_obj = (langX::Constant*) calloc(1, sizeof(langX::Constant) * 1);
	node->type = NODE_CONSTANT_INTEGER;
	node->con_obj->iValue = i;
	node->con_obj->sValue = NULL;
	//printf("createNumberNode: %.5f\n", a);
	return node;
}

XNode * changeNameSpace(char * name)
{
	//printf("node will change space to: %s\n" ,name);
	XNode * node = (XNode*)calloc(1, sizeof(XNode) * 1);
	node->con_obj = (langX::Constant*) calloc(1, sizeof(langX::Constant) * 1);
	node->type = NODE_CHANGE_NAMESPACE;
	node->con_obj->sValue = name;
	//printf("createNumberNode: %.5f\n", a);
	return node;
}

XNode * opr(int opr, int npos, ...)
{
	va_list ap;

	XNode * node = newNode();
	node->opr_obj = (langX::Operator*) calloc(1, sizeof(langX::Operator) * 1);
	node->opr_obj->op = (XNode**)calloc(1, sizeof(XNode*) * npos);
	node->type = NODE_OPERATOR;
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

	XNode * node = newNode();
	node->opr_obj = (langX::Operator*) calloc(1, sizeof(langX::Operator) * 1);
	node->opr_obj->op = (XNode**)calloc(1, sizeof(XNode*) * npos);

	node->state.isSuffix = true;
	node->type = NODE_OPERATOR;
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
	//printf("create Func: %s\n" , name);
	if (node != NULL)
	{
		node->freeOnExeced = false;
	}

	Function *func = new Function(name, node);
	func->setParamsList(params);
	//  在执行他的时候再把它放入环境中
	//getState()->getCurrentEnv()->putFunction(name, func);
	free(name);
	XNode * nodeF = newNode();
	nodeF->type = NODE_FUNCTION;
	nodeF->ptr_u = func;
	return nodeF;
}

XNode *lambda(XParamsList *params, XNode *node) {

	Function *func = new Function("", node);
	func->setParamsList(params);

	XNode * nodeF = newNode();
	nodeF->type = NODE_FUNCTION;
	nodeF->ptr_u = func;
	return nodeF;
}

XNode * arrayNode(char *name, int length, XNode *lengthNode)
{
	XNode * node = newNode();
	node->type = NODE_ARRAY;

	XArrayNode *an = (XArrayNode*)calloc(1, sizeof(XArrayNode) * 1);
	an->name = name;
	an->length = length;
	an->lengthNode = lengthNode;
	node->ptr_u = an;

	return node;
}

XNode * xnull()
{
	XNode * node = newNode();
	node->type = NODE_NULL;

	return node;
}

XNode * claxx(char *name, char *parent, XNode * node, bool flag) {

	ClassInfo *pclass = NULL;
	if (parent != NULL)
	{
		pclass = getState()->getClass(parent);
		if (pclass == NULL)
		{
			printf("error! cannot find class %s on extends!", parent);
		}
		free(parent);
	}

	ClassInfo *claxxInfo = new ClassInfo(name);
	claxxInfo->setParent(pclass);
	free(name);

	if (node != NULL)
	{
		ClassBridgeEnv *env = claxxInfo->getClassEnv();
		state->newEnv(env);
		__execNode(node);
		state->backEnv(false);
	}

	XNode * nodeC = newNode();
	nodeC->type = NODE_CLASS;
	nodeC->ptr_u = claxxInfo;
	nodeC->state.classAuto = flag;

	return nodeC;
}

XObject * call(const char *name, XArgsList* args, const char *remark)
{
	Function *function = getState()->getCurrentEnv()->getFunction(name);
	if (function == NULL)
	{
		char tmp[100] = { 0 };
		sprintf(tmp, "cannot find function %s", name);
		getState()->throwException(newFunctionNotFoundException(tmp)->addRef());
		//printf("cannot find function %s\n", name);
		return NULL;
	}

	return callFunc(function, args, remark);
}

XObject * callFunc(XFunction* function, XArgsList *args, const char *remark) {
	if (function == NULL)
	{
		getState()->throwException(newException("function is null when call function.")->addRef());
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

				// 释放这个参数节点的值先
				getState()->getAllocator().free(args->args[i]->value);

				execNode(args->args[i]);

				if (getState()->getCurrentEnv()->isDead())
				{
					return NULL;
				}

				_3rdArgs.args[i] = args->args[i]->value;
			}
			_3rdArgs.index = args->index;
		}
		Environment *currEnv1 = getState()->getCurrentEnv();
		if (currEnv1->isObjectEnvironment())
		{
			if (currEnv1->isEnvEnvironment())
			{
				_3rdArgs.object = ((ObjectBridgeEnv*)((EnvironmentBridgeEnv*)currEnv1)->getBridgeEnv())->getEnvObject();
			}
			else {
				_3rdArgs.object = ((ObjectBridgeEnv*)currEnv1)->getEnvObject();
			}


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
				// 释放这个参数节点的值先
				getState()->getAllocator().free(args->args[i]->value);
				args->args[i]->value = NULL;

				execNode(args->args[i]);

				if (getState()->getCurrentEnv()->isDead())
				{
					return NULL;
				}

				ObjectType t = NULLOBJECT;
				if (args->args[i]->value)
				{
					t = args->args[i]->value->getType();
				}

				env->putObject(params->args[i], args->args[i]->value);
				//printf("put param %s object: %d.on env: %p. number value: %f. \n", params->args[i] , t ,env, t == NUMBER ? ((Number*)args->args[i]->value)->getDoubleValue() : -1 );
			}
		}

		ret = function->call();

	}
	else {
		ret = function->call();
	}
	getState()->getStackTrace().popFrame();
	if (getState()->getCurrentEnv()->isDead())
	{
		return NULL;
	}
	getState()->backEnv();

	return ret;
}

XNode * argsNode(XArgsList * args) {
	XNode * node = (XNode*)calloc(1, sizeof(XNode) * 1);
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
		list = (XParamsList*)calloc(1, sizeof(XParamsList));
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

XParamsList * params2(char *name1, char *name2)
{
	XParamsList * list = (XParamsList*)calloc(1, sizeof(XParamsList));

	// name 的内存是申请过的， 现在直接使用， 等不用的时候释放掉就OK了
	//printf("第 %d 个参数，名字: %s\n",list->index,name);
	list->args[list->index] = name1;
	list->index++;
	list->args[list->index] = name2;
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

	if (n->var_obj != NULL)
	{
		if (n->var_obj->name != NULL)
		{
			free(n->var_obj->name);
			n->var_obj->name = NULL;
		}

		free(n->var_obj);
		n->var_obj = NULL;
		free(n);
	}

	//printf("free node\n");
	if (n->type == NODE_CONSTANT_NUMBER || n->type == NODE_CONSTANT_INTEGER || n->type == NODE_CHANGE_NAMESPACE)
	{
		if (n->con_obj->sValue != NULL)
		{
			free(n->con_obj->sValue);
			n->con_obj->sValue = NULL;
		}
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
	else if (n->type == NODE_OPERATOR)
	{
		if (n->opr_obj->opr == THIS)
		{
			if (n->var_obj != NULL)
			{
				free(n->var_obj);
				n->var_obj = NULL;
			}
		}
		//printf("00001\n");
		for (size_t i = 0; i < n->opr_obj->op_count; i++)
		{
			freeNode(n->opr_obj->op[i]);
		}

		free(n->opr_obj->op);
		free(n->opr_obj);
		free(n);
	}
	else if (n->type == NODE_ARRAY_ELE)
	{
		free(n->arr_obj);
		n->arr_obj = NULL;
		free(n);
	}
}

void popStateFrame()
{
	state->getStackTrace().popFrame();
}

void fileEOF()
{
	state->fileEOF();
}

const char* getParsingFilename()
{
	return state->getParsingFile();
}

void doFile(const char *f)
{
	state->doFile(f);
}

void execNode(XNode *n) {
	langX::__execNode(n);
}

void execAndFreeNode(XNode *n) {
	execNode(n);
	freeNode(n);
}