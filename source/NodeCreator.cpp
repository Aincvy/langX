#include <stdio.h>
#include <string.h>
#include <stdarg.h>
#include <sstream>
#include <iostream>
#include "../include/NodeCreator.h"
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
#include "../include/langXObjectRef.h"
#include "../include/NullObject.h"
#include "../include/StringType.h"
#include "../extern/y.tab.h"
#include "../include/LogManager.h"
#include "../include/RegObjects.h"
#include "../include/langXCommon.h"
#include "langXThread.h"


using namespace langX;

// 获取当前解析的是第几行
extern int getParseLineNo();
// lex 的 文件结束 工作
extern void lexEOFWork();


static langXState* state = nullptr;

void initLangX(int argc, char *argv[])
{
	if (state == nullptr)
	{
		state = new langXState();
		state->setStartArg(argc, argv);
		logger->debug("initLangX");

		regFunctions(state);
		regExceptions();
		regObjects(state);

		state->loadConfig("/etc/langX/langX.properties");
	}
}

void closeLangX()
{
	if (state != NULL)
	{
		logger->debug("closeLangX");
		delete state;
		state = NULL;
	}
}

Object * getValue(const char *n)
{
	return state->curThread()->getObject(n);
}

langX::langXState * getState()
{
	return state;
}

double getNumberValue(const char *n)
{

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
	state->isSuffix = false;
	state->classAuto = false;
	state->isLocal = false;
}

// 这里是给节点的文件信息赋值
void deal_fileInfo(NodeFileInfo *f) {
	f->lineno = getParseLineNo();

	auto filepath = state->getParsingFile();
    if (filepath == nullptr) {
        logger->debug("state file path is null .. ? ");
    } else{
        f->filename = filepath;
    }

}

XNode *newNode() {
	// 节点的文件信息里面存在了一个 std::string
	// 如果再用下面的方式进行申请内存，则会在centos 下有问题
	// 需要改成使用 new 的方式
	// XNode * node = (XNode*)calloc(1, sizeof(XNode) * 1);
	XNode * node = new XNode();
	node->con_obj = NULL;
	node->var_obj = NULL;
	node->arr_obj = NULL;
	node->opr_obj = NULL;

	node->freeOnExecuted = true;
    deal_fileInfo(&node->fileinfo);
	deal_state(&node->state);
	node->value = NULL;
	node->postposition = NULL;
	node->ptr_u = NULL;

	return node;
}

std::string fileInfoString(const NodeFileInfo & f) {
	std::stringstream ss;
	ss << "at ";
	ss << f.filename;

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

void getObjStringDesc(langX::Object * obj, char *tmp, int maxSize)
{
	if (!obj) {
		return;
	}

	langX::ObjectType type = obj->getType();
	switch (type)
	{
	case NUMBER:
		snprintf(tmp, maxSize, "%f", ((Number*)obj)->getDoubleValue());
		break;
	case STRING:
		snprintf(tmp, maxSize, "%s", ((String*)obj)->getValue());
		break;
	case NULLOBJECT:
		snprintf(tmp, maxSize, "%s", "null");
		break;
	case FUNCTION:
		snprintf(tmp, maxSize, "function@[%s", obj->characteristic());
		break;
	default:
		break;
	}
}

void objToString(langX::Object * obj, char *p, int offset, int maxSize)
{
	std::stringstream ss;
	langXObjectRef *ref1 = (langXObjectRef*)obj;
	Function *func1 = ref1->getFunction("toString");
	if (func1 == nullptr)
	{
		ss << "|[" << obj->characteristic();
	}
	else {
		//
		FunctionRef funcRef(func1);
		funcRef.setObj(ref1->getRefObject());

		Object *retObj = funcRef.call(nullptr, "<call toString()>" );
		if (retObj->getType() == STRING)
		{
			ss << ((String*)retObj)->getValue();
		}
		Allocator::free(retObj);
		retObj = nullptr;
	}

	std::string str = ss.str();
	int size = maxSize;
	if (str.size() < size)
	{
		size = str.size();
	}

	memcpy(p + offset, str.c_str(), size);
}

XNode * string(char *v)
{
	XNode * node = newNode();
	node->con_obj = (langX::Constant*) calloc(1, sizeof(langX::Constant) * 1);

	node->type = NODE_CONSTANT_STRING;
	// v 是已经申请过的内存 ， 直接赋值就OK
	node->con_obj->sValue = v;

	return node;
}

XNode * number(double a)
{
	XNode * node = newNode();
	node->con_obj = (langX::Constant*) calloc(1, sizeof(langX::Constant) * 1);
	node->type = NODE_CONSTANT_NUMBER;
	node->con_obj->dValue = a;
	node->con_obj->sValue = NULL;

	return node;
}

XNode * var(char *name)
{
	XNode * node = newNode();
	node->var_obj = (langX::Variable*) calloc(1, sizeof(langX::Variable) * 1);
	node->type = NODE_VARIABLE;
	node->var_obj->name = name;

	// logger->debug("createVarNode: %s", name);

	return node;
}


// 数组元素节点
// 如果使用的变量， 则值放在 第三个参数lengthNode 上
XNode *arrayElementNode(char *name,  XNode * indexNode) {
	XNode * node = newNode();
	node->arr_obj = (langX::ArrayInfo*) calloc(1, sizeof(langX::ArrayInfo) * 1);
	node->type = NODE_ARRAY_ELE;

	node->arr_obj->objNode = nullptr;
	node->arr_obj->name = name;
	node->arr_obj->indexNode = indexNode;

	return node;
}

XNode * objectArrayElementNode(XNode *objNode, XNode *indexNode)
{
	XNode * node = newNode();
	node->arr_obj = (langX::ArrayInfo*) calloc(1, sizeof(langX::ArrayInfo) * 1);
	node->type = NODE_ARRAY_ELE;

	node->arr_obj->objNode = objNode;
	node->arr_obj->name = nullptr;
	node->arr_obj->indexNode = indexNode;

	return node;
}

XNode * intNode(int i)
{
	XNode * node = newNode();
	node->con_obj = (langX::Constant*) calloc(1, sizeof(langX::Constant) * 1);
	node->type = NODE_CONSTANT_INTEGER;
	node->con_obj->iValue = i;
	node->con_obj->sValue = NULL;

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

	//logger->debug("new opr node, opr is: %d" , opr);
	//logger->debug(("opr npos: %d", npos);
	//logger->debug(("node npos: %d", node->opr_obj->op_count);
	//logger->debug(("createOperatorNode: %p",node);
	return node;
}

XNode * sopr(int opr, int npos, ...)
{
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

	return node;
}

XNode * func(char *name, XParamsList *params, XNode *node)
{

	if (node != NULL)
	{
		node->freeOnExecuted = false;
	}

	Function *func = new Function(name, node);
	func->setParamsList(params);
	free(name);
	XNode * nodeF = newNode();
	nodeF->type = NODE_FUNCTION;
	nodeF->ptr_u = func;
	return nodeF;
}

XNode * xnull()
{
	XNode * node = newNode();
	node->type = NODE_NULL;

	return node;
}

// 根据名字调用一个函数
XObject * call(const char *name, XArgsList* args, const char *remark )
{
    auto thread = getState()->curThread();
	Function *function = thread->getFunction(name);
	if (function == NULL)
	{
		char tmp[100] = { 0 };
		sprintf(tmp, "cannot find function %s", name);
        thread->throwException(newFunctionNotFoundException(tmp)->addRef());
		return NULL;
	}

	// auto env = thread->getCurrentEnv();
	auto object = callFunc(function, args, remark );
    // env->putObject(FE_KEY_PREV_RESULT, object);
    return object;
}

// 调用第三方函数
XObject *call3rdFunc(X3rdFunction *x3rdFunc, langXThread * thread, XArgsList *args ) {
	X3rdArgs _3rdArgs;
	memset(&_3rdArgs, 0, sizeof(X3rdArgs));
	if (args != nullptr)
	{
        for (int i = 0; i < args->index; i++)
        {
            if (args->args[i] == nullptr)
            {
                _3rdArgs.args[i] = nullptr;
                continue;
            }

            Object * tmp1 = args->args[i]->value;
            if (tmp1)
            {
                _3rdArgs.args[i] = tmp1->clone();
            }
            else {
                _3rdArgs.args[i] = Allocator::allocate(NULLOBJECT);
            }

            // 释放这个参数节点的值
            Allocator::free(args->args[i]->value);
            args->args[i]->value = nullptr;
        }

		_3rdArgs.index = args->index;
	}

	Environment *currEnv1 = thread->getCurrentEnv();
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

	thread->setInFunction(true);
	Object * ret1 = x3rdFunc->call(_3rdArgs);
	thread->getStackTrace().popFrame();
	thread->setInFunction(false);

	for (size_t i = 0; i < _3rdArgs.index; i++)
	{
		Allocator::free(_3rdArgs.args[i]);
	}

	thread->setFunctionResult(ret1);
	return ret1;
}

// 执行 函数节点的 第一阶段，  参数值的运算阶段
void callFuncNodeLink0(XFunction *function, const XArgsList *args, const char *remark, NodeLink *nodeLink,
                       langXThread *thread) {
    // add stackTrace
    thread->getStackTrace().newFrame(function->getClassInfo(), function, remark);

    // 计算参数的值
    if (args != nullptr)
    {
        for (int i = 0; i < args->index; i++)
        {
            if (args->args[i] != nullptr)
            {
                // 最初的时候， 参数的值应该是一个NULL 。 然后执行参数节点， 产生一个结果
                thread->beginExecute(args->args[i], true);
            }
        }
    }

    nodeLink->index = 1;
}

// 添加函数的拓展变量到 函数内部 | $_, $1,$2 等
void addFunctionExtendsVar(Environment* env, XArgsList* args){
    if (!env->hasObject(FE_KEY_VARIABLE_COUNT)){
        auto functionArgsCount = args == nullptr ? 0 : args->index;
        env->putObject(FE_KEY_VARIABLE_COUNT , Allocator::allocateNumber(functionArgsCount));

//         赋值给 $1,$2..
        for (int i = 0; i < functionArgsCount; ++i) {
            std::stringstream  ss;
            ss << FE_KEY_VARIABLE_PREFIX;
            ss << (i + 1);
            const std::string & tmpVarName = ss.str();

            if (!env->hasObject(tmpVarName)){
                // 不包含这个变量， 则赋值
                env->putObject(tmpVarName, args->args[i]->value);
            }
        }
    }

}

XObject * callFunc(XFunction* function, XArgsList* args, const char* remark) {
#ifdef SHOW_DETAILS
	// logger->debug("callFunc %s %s\n" , function->getName(), remark );
#endif

	langXThread * thread = getState()->curThread();
	if (function == nullptr)
	{
		thread->throwException(newException("function is null when call function.")->addRef());
		return nullptr;
	}

	if (function->is3rd())
	{
		// 第三方函数
        thread->getStackTrace().newFrame(function->getClassInfo(), function, remark);
		X3rdFunction *x3rdFunc = (X3rdFunction*)function;
		return call3rdFunc(x3rdFunc, thread, args );
	}

	// 函数环境
	DefaultEnvironment defaultEnvironment;
	Environment * env = &defaultEnvironment;

	// 赋值参数列表
    XParamsList *params = function->getParamsList();
	if (args != nullptr && params != nullptr)
	{

		NullObject nullobj;

		// put real args value
		for (int i = 0; i < args->index; i++)
		{
			// 如果给出的参数个数大于需要的参数个数， 则无视剩余给出的参数
			if (i >= params->index)
			{
				break;
			}

			if (args->args[i] != nullptr)
			{
				if (args->args[i]->value)
				{
					env->putObject(params->args[i], args->args[i]->value);
				}
				else {
					env->putObject(params->args[i], &nullobj);
				}

				// 上面的做法是把参数的值 复制到环境内。
				// Environment.putObject   内都是保留的一个副本。
				// 这片代码的本意是吧参数节点的值算出来，然后丢给函数。 现在任务已经完成了。 可以把参数节点的值给释放掉了

				// 释放这个参数节点的值
				Allocator::free(args->args[i]->value);
				args->args[i]->value = nullptr;

			}
			else {
				// 没给出的参数 给个NULL
				env->putObject(params->args[i], &nullobj);
			}
		}
	}

    // put function extends var ...
    addFunctionExtendsVar(env, args);

    // 附加函数所属环境， 然后调用函数， 之后撤销环境
    thread->newEnv(env);
	auto ret = function->call();
	thread->backEnv(false);

	thread->getStackTrace().popFrame();

	return ret;
}


XNode * argsNode(XArgsList * args) {
	XNode * node = new XNode();
	node->type = NODE_ARGS;
	node->value = NULL;
	node->postposition = NULL;
	node->ptr_u = args;
    deal_fileInfo(&node->fileinfo);
	deal_state(&node->state);

	return node;
}

// 预处理case list
void pretreatCaseList(XNode *node, SwitchInfo *switchInfo) {
	if (node == nullptr || node->type != NodeType::NODE_OPERATOR) {
		return;
	}

	std::list<std::string> *list = (std::list<std::string>*)switchInfo->list_ptr;
	int opr = node->opr_obj->opr;
	if (opr == CASE_LIST) {
		for (size_t i = 0; i < node->opr_obj->op_count; i++)
		{
			pretreatCaseList(node->opr_obj->op[i], switchInfo);
		}
	}
	else if (opr == KEY_CASE) {
		// case 节点
		int index = switchInfo->nowIndex++;
		NodeLink nodeLink;
		memset(&nodeLink, 0, sizeof(NodeLink));
		Node *checkValueNode = node->opr_obj->op[0];    // 从语法解析文件可知， 此值是一个判定值
		Node *execNode = node->opr_obj->op[1];    // 从语法解析文件可知， 此值是一个具体的执行值

		nodeLink.node = checkValueNode;
		__realExecNode(&nodeLink, getState()->curThread());

		if (execNode != nullptr) {
			switchInfo->caseList[index] = execNode;

			if (!list->empty()) {
				for (auto i = list->begin(); i != list->end(); i++)
				{
					switchInfo->keyIndexMap.insert(std::pair<std::string, int>((*i), index));
				}
			}
		}

		// 释放值
		Object *obj = checkValueNode->value;
		if (obj->getType() == ObjectType::NUMBER) {
			Number  *number = (Number*)obj;
			char tmp[1024] = { 0 };
			if (number->isInteger()) {
				// 正数
				sprintf(tmp, "%d", number->getIntValue());
			}
			else {
				sprintf(tmp, "%f", number->getDoubleValue());
			}
			//printf("index: %d, check value: %s\n", index, tmp);
			std::string key(tmp);
			if (execNode == nullptr) {
				list->push_back(key);
			}
			else {
				switchInfo->keyIndexMap.insert(std::pair<std::string, int>(key, index));
			}
		}
		else if (obj->getType() == ObjectType::STRING) {
			String *str = (String*)obj;
			std::string key(str->getStrValue());
			if (execNode == nullptr) {
				list->push_back(key);
			}
			else {
				switchInfo->keyIndexMap[key] = index;
			}
		}
		else {
			// error value
			printf("error object type in switch. \n");
			exit(1);
		}

		Allocator::free(obj);
		checkValueNode->value = nullptr;
	}
	else if (opr == KEY_DEFAULT) {
		switchInfo->defaultNode = node;
	}
}

void pretreatSwitch(XNode *node) {
	if (node->type != NodeType::NODE_OPERATOR) {
		return;
	}

	if (node->opr_obj->opr != KEY_SWITCH) {
		return;
	}

	SwitchInfo* switchInfo = new SwitchInfo();
	switchInfo->nowIndex = 0;
	XNode *nodes[235] = { NULL };
	switchInfo->caseList = nodes;
	node->ptr_u = switchInfo;
	std::list<std::string> list;
	switchInfo->list_ptr = &list;
	for (size_t i = 0; i < node->opr_obj->op_count; i++)
	{
		pretreatCaseList(node->opr_obj->op[i], switchInfo);
	}

	// 重做 caseList
	int memSize = switchInfo->nowIndex * sizeof(XNode*);
	XNode **caseList = (XNode **)calloc(1, memSize);
	memcpy(caseList, nodes, memSize);
	switchInfo->caseList = caseList;
}

void freeArgsList(XArgsList *alist) {
	if (alist != nullptr && alist->index > 0)
	{
		for (int i = 0; i < alist->index; i++)
		{
			if (alist->args[i] != nullptr)
			{
				freeNode(alist->args[i]);
				alist->args[i] = nullptr;
			}
		}
	}

	free(alist);
}

//  释放 n 及 n 下的所有节点的参数列表内存
void freeAllArgList(Node *n) {
	if (!n)
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

// 释放 数组元素的内存
void freeArrayInfo(ArrayInfo *arrayInfo){
    // 释放依赖
    freeNode(arrayInfo->objNode);
    freeNode(arrayInfo->indexNode);
    free(arrayInfo);
}

void freeNode(XNode * node) {

	if (node == nullptr)
	{
		return;
	}
	if (!node->freeOnExecuted)
	{
		return;
	}

	// 释放值的内存
	if (node->value != nullptr)
	{
		Allocator::free(node->value);
        node->value = nullptr;
	}

	// 如果是一个函数节点， 还需要释放它的参数列表
	if (node->type == NODE_FUNCTION)
	{
		freeAllArgList(node);
	}

    // 根据类型释放不同内存的内容
	if (node->type == NODE_VARIABLE)
	{
		if (node->var_obj->name != nullptr)
		{
			free(node->var_obj->name);
            node->var_obj->name = nullptr;
		}

		free(node->var_obj);
        node->var_obj = nullptr;
	} else if (node->type == NODE_CONSTANT_NUMBER || node->type == NODE_CONSTANT_INTEGER )
	{
		if (node->con_obj->sValue != NULL)
		{
			free(node->con_obj->sValue);
            node->con_obj->sValue = NULL;
		}
		free(node->con_obj);
	}
	else if (node->type == NODE_CONSTANT_STRING)
	{
		if (node->con_obj->sValue != NULL)
		{
			free(node->con_obj->sValue);
		}
		free(node->con_obj);
	}
	else if (node->type == NODE_OPERATOR)
	{
		if (node->opr_obj->opr == KEY_THIS)
		{
			if (node->var_obj != NULL)
			{
				free(node->var_obj);
                node->var_obj = NULL;
			}
		}
		else if (node->opr_obj->opr == KEY_SWITCH)
		{
			SwitchInfo *switchInfo = (SwitchInfo *)node->ptr_u;
			if (switchInfo != NULL)
			{
				delete switchInfo;
                node->ptr_u = NULL;
			}
		}

		for (size_t i = 0; i < node->opr_obj->op_count; i++)
		{
			freeNode(node->opr_obj->op[i]);
		}

		free(node->opr_obj->op);
		free(node->opr_obj);
	}
	else if (node->type == NODE_ARRAY_ELE)
	{
		freeArrayInfo(node->arr_obj);
        node->arr_obj = nullptr;
	}

    free(node);
}

void popStateFrame()
{
	state->curThread()->getStackTrace().popFrame();
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

void yyParseStopped()
{
	state->setYYParsing(false);
}

void endOfFileFlag() {
    state->curThread()->getStackTraceTopStatus().endOfFile = true;
}


void execNodeButLimit(XNode *n, XNode *limit) {
	langX::__execNode(n, limit);
}

void execNode(XNode *n) {
	langX::__execNode(n);
}

void execAndFreeNode(XNode *n) {
	langXThread * thread = getState()->curThread();
	if (thread->isInException())
	{
		// 当前在异常中， 不执行节点了
		return;
	}

	nodeLogger->debug("try exec node at %s:%d", getParsingFilename(), getParseLineNo());

	execNode(n);

	// 判断一下执行后程序有没有异常
	if (thread->isInException())
	{
		gTryCatchCB(thread->getThrownObj());
	}

	freeNode(n);

	// 判断文件是否结束了
	auto & status = thread->getStackTraceTopStatus();
    if (status.endOfFile) {
        status.endOfFile = false;

        lexEOFWork();
    }

}

