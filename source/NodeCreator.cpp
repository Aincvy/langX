#include <stdio.h>
#include <string.h>
#include <stdarg.h>
#include <sstream>
#include <iostream>
#include "NodeCreator.h"
#include "langX.h"
#include "Object.h"
#include "Number.h"
#include "ExecNode.h"
#include "RegFunctions.h"
#include "Environment.h"
#include "Allocator.h"
#include "ClassInfo.h"
#include "StackTrace.h"
#include "Exception.h"
#include "langXObject.h"
#include "NullObject.h"
#include "StringType.h"
#include "../extern/y.tab.h"
#include "LogManager.h"
#include "RegObjects.h"
#include "langXCommon.h"
#include "langXThread.h"
#include "Utils.h"


using namespace langX;

// 获取当前解析的是第几行
extern int getParseLineNo();


static langXState* state = nullptr;

void initLangX(int argc, char **argv, const langXStateConfig &stateConfig)
{
	if (state == nullptr)
	{
		state = new langXState();
		state->setStartArg(argc, argv);
		logger->debug("initLangX");

		regFunctions(state);
		regExceptions();
		regObjects(state);

        state->loadConfig("/etc/langX/langX.properties", stateConfig);
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

    //auto a = fileInfoString(*f);
    //logger->debug("after deal_fileInfo: %s", a.c_str());
}

XNode *newNode() {
	// 节点的文件信息里面存在了一个 std::string
	// 如果再用下面的方式进行申请内存，则会在centos 下有问题
	// 需要改成使用 new 的方式
	// XNode * node = (XNode*)calloc(1, sizeof(XNode) * 1);
	XNode * node = new XNode();
	node->con_obj = nullptr;
	node->var_obj = nullptr;
	node->arr_obj = nullptr;
	node->opr_obj = nullptr;

	node->freeOnExecuted = true;
    deal_fileInfo(&node->fileinfo);
	deal_state(&node->state);
	node->value = nullptr;
	node->postposition = nullptr;
	node->ptr_u = nullptr;

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

XNode * string(char *str)
{

    // 对 str 进行转义
    auto size = strlen(str) + 1;
    auto tmpBuf = (char*) calloc(size, sizeof(char ));
    workEscapeStr(str, tmpBuf, size);

    // str 已经使用完了，释放内存
    free(str);

	XNode * node = newNode();
	node->con_obj = (langX::Constant*) calloc(1, sizeof(langX::Constant) * 1);

	node->type = NODE_CONSTANT_STRING;
	// sValue 将会使用新申请得内存
	node->con_obj->sValue = strdup(tmpBuf);

	// 释放 tmpBuf 得内存。  因为转义之后得字符串可能比原来得字符串小， 所以这样操作
	free(tmpBuf);

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

XNode *boolNode(int i) {

    XNode * node = intNode(i);
    node->con_obj->flagBool = true;
    return node;
}

XNode * opr(int opr, int size, ...)
{
	va_list ap;

	XNode * node = newNode();
	node->opr_obj = (langX::Operator*) calloc(1, sizeof(langX::Operator) * 1);
	node->opr_obj->op = (XNode**)calloc(1, sizeof(XNode*) * size);
	node->type = NODE_OPERATOR;
	node->opr_obj->opr = opr;
	node->opr_obj->op_count = size;

	va_start(ap, size);
	for (size_t i = 0; i < size; i++)
	{
		node->opr_obj->op[i] = va_arg(ap, XNode*);
	}
	va_end(ap);

	//logger->debug("new opr node, opr is: %d" , opr);
	//logger->debug(("opr size: %d", size);
	//logger->debug(("node size: %d", node->opr_obj->op_count);
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

XNode * xnull()
{
	XNode * node = newNode();
	node->type = NODE_NULL;

	return node;
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

    logger->debug("eof flag of %s", getParsingFilename());
}


void execNodeButLimit(XNode *n, XNode *limit) {
	langX::__execNode(n, limit);
}

void execNode(XNode *n) {
	langX::__execNode(n);
}

void execAndFreeNode(XNode *n) {
    // 如果传来得参数是空指针， 则跳过执行
    if (!n) {
        return;
    }

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

    getState()->checkEndOfFile(thread);
}




