#include <stdio.h>
#include <string.h>
#include <stdarg.h>
#include <sstream>
#include <iostream>
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
#include "../include/langXObjectRef.h"
#include "../include/NullObject.h"
#include "../include/String.h"
#include "../extern/y.tab.h"
#include "../include/langXThread.h"
#include "../include/LogManager.h"

extern int getParseLineNo();

using namespace langX;

static langXState* state = NULL;

void initLangX()
{
	if (state == NULL)
	{
		state = new langXState();
		logger->debug("initLangX");

		regFunctions(state);
		regExceptions();

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

void assignment(const char *n, langX::Object * obj)
{
	state->curThread()->putObject(n, obj);
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
	state->isSuffix = false;
	state->classAuto = false;
	state->isLocal = false;
}

// 这里是给节点的文件信息赋值
void deal_fileinfo(NodeFileInfo *f) {
	f->lineno = getParseLineNo();
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
	node->value = NULL;
	node->postposition = NULL;
	node->ptr_u = NULL;

	return node;

}

std::string fileInfoString(const NodeFileInfo & f) {
	std::stringstream ss;
	ss << "at ";
	//if (f.filename)
	//{
	//	ss << f.filename;
	//}
	//else {
	//	ss << "<NoFile>";
	//}
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
		FunctionRef aref(func1);
		aref.setObj(ref1->getRefObject());
		NodeLink tmpNodeLink;
		memset(&tmpNodeLink, 0, sizeof(NodeLink));
		//  因为本参数无参，所以只修改 index为1， 这样的话，一次就可以获取到结果
		tmpNodeLink.index = 1;
		Object *retObj = aref.call(nullptr, "<call toString()>", &tmpNodeLink);
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
	
	memcpy(p+offset, str.c_str(), size);

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

	node->arr_obj->objNode = NULL;
	node->arr_obj->name = name;
	node->arr_obj->index = index;
	node->arr_obj->indexNode = indexNode;

	return node;

}

XNode * arr2(XNode *objNode, int index, XNode *indexNode)
{
	XNode * node = newNode();
	node->arr_obj = (langX::ArrayInfo*) calloc(1, sizeof(langX::ArrayInfo) * 1);
	node->type = NODE_ARRAY_ELE;

	node->arr_obj->objNode = objNode;
	node->arr_obj->name = NULL;
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

XNode * dtrt(char *name, XParamsList *params, XNode *node)
{
	if (node != NULL)
	{
		node->freeOnExeced = false;
	}

	std::string str("~");
	str += name;
	Function *func = new Function(str.c_str(), node);
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
		state->curThread()->newEnv(env);
		__execNode(node, node);         // 立即处理掉这个节点，但是也仅仅只是处理到这个节点
		state->curThread()->backEnv(false);
	}

	XNode * nodeC = newNode();
	nodeC->type = NODE_CLASS;
	nodeC->ptr_u = claxxInfo;
	nodeC->state.classAuto = flag;

	return nodeC;
}

XObject * call(const char *name, XArgsList* args, const char *remark, NodeLink *nodeLink)
{
	Function *function = getState()->curThread()->getFunction(name);
	if (function == NULL)
	{
		char tmp[100] = { 0 };
		sprintf(tmp, "cannot find function %s", name);
		getState()->curThread()->throwException(newFunctionNotFoundException(tmp)->addRef());
		//printf("cannot find function %s\n", name);
		return NULL;
	}

	return callFunc(function, args, remark, nodeLink);
}


// 调用第三方函数
XObject *call3rdFunc(X3rdFunction *x3rdfunc, langXThread * thread,XArgsList *args, NodeLink* nodeLink) {

	X3rdArgs _3rdArgs;
	memset(&_3rdArgs, 0, sizeof(X3rdArgs));
	if (args != NULL)
	{
		// 计算出参数节点的值。 然后克隆一份给 传参的那个数据结构。 然后再释放掉参数节点的值。 
		if (nodeLink->index == 0) {
			for (int i = 0; i < args->index; i++)
			{
				if (args->args[i] != NULL) {
					thread->beginExecute(args->args[i]);
				}
			}
			nodeLink->index = 1;
			return nullptr;
		}
		else {
			for (int i = 0; i < args->index; i++)
			{
				if (args->args[i] == NULL)
				{
					_3rdArgs.args[i] = NULL;
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
				args->args[i]->value = NULL;
			}
		}

		_3rdArgs.index = args->index;
	}

	// 确保 这个函数执行第二遍的时候才会获取到结果
	if (nodeLink->index == 0) {
		nodeLink->index = 1;
		return nullptr;
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
	Object * ret1 = x3rdfunc->call(_3rdArgs);
	thread->getStackTrace().popFrame();
	thread->setInFunction(false);

	for (size_t i = 0; i < _3rdArgs.index; i++)
	{
		Allocator::free(_3rdArgs.args[i]);
	}
	
	return ret1;

}

XObject * callFunc(XFunction* function, XArgsList *args, const char *remark, NodeLink* nodeLink) {
	
#ifdef SHOW_DETAILS
	//printf("callFunc %s %s\n" , function->getName(), remark );
#endif

	langXThread * thread = getState()->curThread();
	if (function == NULL)
	{
		thread->throwException(newException("function is null when call function.")->addRef());
		return NULL;
	}

	if (function->is3rd())
	{
		if (nodeLink->index == 0) {
			thread->getStackTrace().newFrame(function->getClassInfo(), function, remark);
		}
		// 第三方函数 
		X3rdFunction *x3rdfunc = (X3rdFunction*)function;
		return call3rdFunc(x3rdfunc, thread, args, nodeLink);
	}

	if (nodeLink->index == 0)
	{
		// 
		thread->getStackTrace().newFrame(function->getClassInfo(), function, remark);

		// 计算参数的值
		if (args != NULL )
		{
			XParamsList *params = function->getParamsList();
			NullObject nullobj;
			for (int i = 0; i < args->index; i++)
			{
				// 如果给出的参数个数大于需要的参数个数， 则无视剩余给出的参数
				if (i >= params->index)
				{
					break;
				}

				if (args->args[i] != NULL)
				{
					// 最初的时候， 参数的值应该是一个NULL 。 然后执行参数节点， 产生一个结果
					thread->beginExecute(args->args[i], true);

				}
			}
		}
		
		nodeLink->index = 1;
		return nullptr;
	}

	// 如果当前环境是一个对象环境， 则暂存他
	Environment *abcEnv = NULL;
	Environment *currEnv1 = thread->getCurrentEnv();
	if (currEnv1->isObjectEnvironment())
	{
		abcEnv = currEnv1;
		thread->backEnv(false);
	}

	Environment * env = new DefaultEnvironment();
	Object * ret = NULL;


	if (args != NULL)
	{
		XParamsList *params = function->getParamsList();
		NullObject nullobj;
		for (int i = 0; i < args->index; i++)
		{
			// 如果给出的参数个数大于需要的参数个数， 则无视剩余给出的参数
			if (i >= params->index)
			{
				break;
			}

			if (args->args[i] != NULL)
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
				args->args[i]->value = NULL;

				//printf("put param %s object: %d.on env: %p. number value: %f. \n", params->args[i] , t ,env, t == NUMBER ? ((Number*)args->args[i]->value)->getDoubleValue() : -1 );
			}
			else {
				// 没给出的参数 给个NULL 
				env->putObject(params->args[i], &nullobj);
			}
		}

	}

	if (abcEnv != NULL)
	{
		thread->newEnv(abcEnv);
		abcEnv = NULL;
	}

	// 如果这个函数属于某个脚本， 先用该函数的脚本环境覆盖
	ScriptEnvironment *fsenv =  function->getScriptEnv();
	bool flagfsenv = false;
	if (fsenv != nullptr)
	{
		flagfsenv = true;
		thread->newEnv2(fsenv);
	}

	thread->newEnv(env);
	ret = function->call();
	thread->backEnv();

	if (flagfsenv)
	{
		thread->backEnv();
	}

	thread->getStackTrace().popFrame();

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

// 预处理case list
void pretreatCaseList(XNode *node,SwitchInfo *switchInfo) {
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
	else if (opr == CASE) {
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
	else if (opr == DEFAULT) {
		switchInfo->defaultNode = node;
	}

}

void pretreatSwitch(XNode *node) {
	if (node->type != NodeType::NODE_OPERATOR) {
		return;
	}
	
	if (node->opr_obj->opr != SWITCH) {
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

void freeNode(XNode * n) {
	if (n == NULL)
	{
		return;
	}
	if (!n->freeOnExeced)
	{
		return;
	}

	if (n->value != NULL)
	{
		Allocator::free(n->value);
		n->value = NULL;
	}

	// 如果是一个函数节点， 还需要释放它的参数列表
	if (n->type == NODE_FUNCTION)
	{
		freeAllArgList(n);
		//free(n);
		//return;
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
		else if (n->opr_obj->opr == SWITCH)
		{
			SwitchInfo *switchInfo = (SwitchInfo *)n->ptr_u;
			if (switchInfo != NULL)
			{
				delete switchInfo;
				n->ptr_u = NULL;
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

	execNode(n);

	// 判断一下执行后程序有没有异常
	if (thread->isInException())
	{
		gTryCatchCB(thread->getThrownObj());
	}

	freeNode(n);
}
