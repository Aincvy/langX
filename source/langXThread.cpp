#include "../include/langXThread.h"
#include "../include/Environment.h"
#include "../include/Function.h"
#include "../include/ExecNode.h"
#include "../include/Allocator.h"
#include "../include/langX.h"
#include "../include/YLlangX.h"
#include "../include/Object.h"
#include "../include/langXObject.h"
#include "../include/langXObjectRef.h"
#include "../include/Function.h"


#ifdef WIN32
// win32的库
#else
// linux 库
#include <pthread.h>
#include <thread>
#include <unistd.h>
#endif

#ifdef SHOW_DETAILS
#include <iostream>
#include <stdio.h>
#endif

extern "C" {
	extern void yyerror(char *msg);
}

// 释放环境内存
void freeEnv(langX::Environment **env) {

	if (env == NULL || (*env) == NULL)
	{
		return;
	}
	
	langX::Environment *p = (*env);
	switch (p->getType())
	{
	case langX::TDefaultEnvironment:
		delete (langX::DefaultEnvironment*) p;
		break;
	case	langX::TGlobalEnvironment:
		delete (langX::GlobalEnvironment*) p;
		break;
	case	langX::TScriptEnvironment:
		delete (langX::ScriptEnvironment*) p;
		break;
	case	langX::TXNameSpaceEnvironment:
		delete (langX::XNameSpaceEnvironment*) p;
		break;
	case	langX::TClassBridgeEnv:
		delete (langX::ClassBridgeEnv*) p;
		break;
	case	langX::TObjectBridgeEnv:
		delete (langX::ObjectBridgeEnv*) p;
		break;
	case	langX::TTryEnvironment:
		delete (langX::TryEnvironment*) p;
		break;
	case	langX::TEnvironmentBridgeEnv:
		delete (langX::EnvironmentBridgeEnv*) p;
		break;
	default:
		break;
	}

	*env = NULL;
}

namespace langX {

	void  gTryCatchCB(langXObjectRef *obj) {
		Function *func = obj->getFunction("printStackTrace");
		if (func != NULL)
		{
			if (func->is3rd())
			{
				X3rdArgs _3rdArgs;
				_3rdArgs.object = obj->getRefObject();
				_3rdArgs.index = 0;
				_3rdArgs.arrayRef = NULL;
				X3rdFunction *f = (X3rdFunction*)func;
				f->call(_3rdArgs);
			}
			else {
				func->call();
			}
		}
	}

	langXThread::langXThread(int id) : m_thread_id(id)
	{
		this->m_name = "thread";
		this->m_name += id;
		this->m_exec_status.inFunction = 0;
		this->m_exec_status.inLoop = 0;
		this->m_exec_status.inSwitch = 0;

		this->m_current_env = nullptr;
		this->m_current_deep = 0;
	}

	langXThread::~langXThread()
	{
		freeThrownObj();

		// 清理掉环境 

		while (this->m_current_env != NULL && this->m_current_env->getParent() != NULL)
		{
			backEnv();
		}

		if (this->m_current_env != nullptr)
		{
			freeEnv(&this->m_current_env);
		}

	}

	StackTrace & langXThread::getStackTrace()
	{
		return this->m_stacktrace;
	}

	const char * langXThread::getName() const
	{
		return this->m_name.c_str();;
	}

	void langXThread::setName(const char *name)
	{
		this->m_name = std::string(name);
	}

	langXThreadStatus langXThread::getStatus() const
	{
		return this->m_thread_status;
	}

	void langXThread::setStatus(langXThreadStatus status)
	{
		this->m_thread_status = status;
	}

	void langXThread::setInLoop(bool flag)
	{
		if (flag)
		{
			m_exec_status.inLoop++;
		}else{
			if (m_exec_status.inLoop > 0)
			{
				m_exec_status.inLoop--;
			}
		}
	}

	bool langXThread::isInLoop()
	{
		return m_exec_status.inLoop > 0;
	}

	void langXThread::setInFunction(bool flag)
	{
		if (flag)
		{
			m_exec_status.inFunction++;
		}
		else {
			if (m_exec_status.inFunction > 0)
			{
				m_exec_status.inFunction--;
			}
		}
	}

	bool langXThread::isInFunction()
	{
		return m_exec_status.inFunction > 0;
	}

	void langXThread::setInSwitch(bool flag)
	{
		if (flag)
		{
			m_exec_status.inSwitch++;
		}
		else {
			if (m_exec_status.inSwitch > 0)
			{
				m_exec_status.inSwitch--;
			}
		}
	}

	bool langXThread::isInSwitch()
	{
		return m_exec_status.inSwitch > 0;
	}

	void langXThread::setInException(bool flag)
	{
		if (flag)
		{
			m_exec_status.inException++;
		}
		else {
			if (m_exec_status.inException > 0)
			{
				m_exec_status.inException--;
			}
		}
	}

	bool langXThread::isInException()
	{
		return m_exec_status.inException > 0;
	}

	void langXThread::setInBreak(bool flag)
	{
		if (flag)
		{
			m_exec_status.inBreak++;
		}
		else {
			if (m_exec_status.inBreak > 0)
			{
				m_exec_status.inBreak--;
			}
		}
	}

	bool langXThread::isInBreak()
	{
		return m_exec_status.inBreak > 0;
	}

	void langXThread::setInReturn(bool flag)
	{
		if (flag)
		{
			m_exec_status.inReturn++;
		}
		else {
			if (m_exec_status.inReturn > 0)
			{
				m_exec_status.inReturn--;
			}
		}
	}

	bool langXThread::isInReturn()
	{
		return m_exec_status.inReturn > 0;
	}

	void langXThread::setInContinue(bool flag)
	{
		if (flag)
		{
			m_exec_status.inContinue++;
		}
		else {
			if (m_exec_status.inContinue > 0)
			{
				m_exec_status.inContinue--;
			}
		}
	}

	bool langXThread::isInContinue()
	{
		return m_exec_status.inContinue > 0;
	}

	void langXThread::setInCaseNeedCon(bool flag)
	{
		if (flag)
		{
			m_exec_status.inCaseNeedCon++;
		}
		else {
			if (m_exec_status.inCaseNeedCon > 0)
			{
				m_exec_status.inCaseNeedCon--;
			}
		}
	}

	bool langXThread::isInCaseNeedCon()
	{
		return m_exec_status.inCaseNeedCon > 0;
	}

	Environment * langXThread::getCurrentEnv() const
	{
		if (this->m_current_deep == 0)
		{
			return getState()->getScriptOrNSEnv();
		}
		return this->m_current_env;
	}

	void langXThread::printStackTrace() const
	{
		StrackTraceFrameArray array1 = this->m_stacktrace.frames();

		// 不打印自己这个函数
		for (int i = array1.length - 2; i >= 0; i--)
		{
			printf("%s\n", array1.frame[i]->getInfo());
		}

		free(array1.frame);
	}

	Environment * langXThread::newEnv()
	{
		Environment *env = new DefaultEnvironment();
		env->setParent(this->m_current_env);
		env->setDeep((++this->m_current_deep));
		this->m_current_env = env;
		return env;
	}

	Environment * langXThread::newEnv(Environment *env)
	{
		if (env == NULL)
		{
			return NULL;
		}

		//printf("newEnv %p , type: %d\n" , env,env->getType());
		env->setParent(this->m_current_env);
		env->setDeep((++this->m_current_deep));
		this->m_current_env = env;
		return env;
	}

	Environment * langXThread::newEnv2(Environment *env)
	{
		if (env == NULL)
		{
			return NULL;
		}

		//printf("newEnv2 %p , type: %d\n", env, env->getType());
		EnvironmentBridgeEnv *bEnv = new EnvironmentBridgeEnv(env);
		bEnv->setParent(this->m_current_env);
		bEnv->setDeep((++this->m_current_deep));
		this->m_current_env = bEnv;
		return bEnv;
	}

	void langXThread::throwException(langXObjectRef *obj)
	{
		// 丢出一个异常
		this->setInException(true);

		this->m_thrown_obj = obj;

		// 找到一个存在tryEnv 的执行链节点
		NodeLink *nodeLink = nullptr;
		do {
			nodeLink = this->currentExecute;
			if (nodeLink == NULL || nodeLink->tryEnv != NULL) {
				break;
			}

			this->endExecute();
		} while (true);

		if (nodeLink == NULL) {
			// 没有找到一个try 节点
			//gTryCatchCB(this->m_thrown_obj);

			yyerror("Execption Get , end parse.");
			printf("!!! [DEBUG] gTryCatchCB \n");
		}
		else {
			// 找到了try 节点
			TryEnvironment * tryEnv = (TryEnvironment *)nodeLink->tryEnv;
			
			// check call back first.
			CBCatch c = tryEnv->getCatchCB();
			if (c != NULL)
			{
				// 调用回调 
				c(obj);
			}
			else {
				// 将异常赋值
				// 进入catch 环境
				Environment* env = newEnv();
				Node *cNode = tryEnv->getCatchNode();
				env->putObject(cNode->opr_obj->op[0]->var_obj->name, obj);

				// 执行 catch 块的语句
				//__execNode(cNode->opr_obj->op[1]);

				
				backEnv();
			}
			
		}

		printf("!!! [DEBUG] delete object and ref. \n");
		// 删除对象
		delete obj->getRefObject();
		freeThrownObj();
		this->setInException(false);
	}

	Environment * langXThread::getNearestObjectEnv() const
	{
		Environment *env = this->m_current_env;

		while (env != NULL)
		{
			if (env->isObjectEnvironment())
			{
				if (env->isEnvEnvironment())
				{
					return ((EnvironmentBridgeEnv*)env)->getBridgeEnv();
				}
				return env;
			}

			env = env->getParent();
		}

		return nullptr;
	}

	void langXThread::putObject(const char * name, Object *obj)
	{
		if (this->m_current_deep > 0)
		{
			this->m_current_env->putObject(name, obj);
		}else{
			getState()->getScriptOrNSEnv()->putObject(name, obj);
		}
		
	}

	void langXThread::putObject(const std::string &name, Object *obj)
	{
		if (this->m_current_deep > 0)
		{
			this->m_current_env->putObject(name, obj);
		}
		else {
			getState()->getScriptOrNSEnv()->putObject(name, obj);
		}
	}

	Object * langXThread::getObject(const std::string &name)
	{
		Object * obj = nullptr;

		if (this->m_current_deep > 0)
		{
			obj = this->m_current_env->getObject(name);
		}

		if (obj == nullptr)
		{
			obj = getState()->getScriptOrNSEnv()->getObject(name);
		}

		return obj;
	}

	Function * langXThread::getFunction(const std::string & name)
	{
		Function * func = nullptr;
		if (this->m_current_deep > 0)
		{
			func = this->m_current_env->getFunction(name);
		}

		if (func == nullptr)
		{
			func = getState()->getScriptOrNSEnv()->getFunction(name);
		}
		return func;
	}

	Object * langXThread::getFunctionResult()
	{
		return this->m_function_result;
	}

	void langXThread::setFunctionResult(Object *obj)
	{
		if (this->m_function_result)
		{
			Allocator::free(this->m_function_result);
			this->m_function_result = nullptr;
		}

		if (!obj)
		{
			this->m_function_result = nullptr;
		}
		else {
			this->m_function_result = obj->clone();
		}
	}


	NodeFileInfo langXThread::getCurrentNodeFileInfo()
	{
		if (this->currentExecute == NULL)
		{
			NodeFileInfo f;
			f.lineno = -1;
			f.filename = "No Current Node Info... ";
			return (f);
		}
		return this->currentExecute->node->fileinfo;
	}

	langXObjectRef * langXThread::getThrownObj()
	{
		return this->m_thrown_obj;
	}

	bool langXThread::isMainThread()
	{
		return this->m_is_main_thread;
	}

	void langXThread::setMainThread(bool flag)
	{
		this->m_is_main_thread = flag;
	}

	void langXThread::kill()
	{
		// 暂不实现

	}

	NodeLink * langXThread::beginExecute(Node *node)
	{
		this->currentExecute = newNodeLink(this->currentExecute, node);
		return this->currentExecute;
	}

	NodeLink * langXThread::beginExecute(Node *node, bool flag)
	{
		NodeLink * nl = this->beginExecute(node);
		nl->backAfterExec = flag;
		return nl;
	}

	void langXThread::endExecute()
	{
		if (this->currentExecute == NULL) {
			return;
		}

		NodeLink * nodeLink = this->currentExecute;
		this->currentExecute = this->currentExecute->previous;
		freeNodeLink(nodeLink);
	}

	NodeLink * langXThread::initRootNode(Node *node)
	{
		this->executeRoot = newNodeLink(NULL, node);
		this->currentExecute = this->executeRoot;
		return this->executeRoot;
	}

	NodeLink * langXThread::getCurrentExecute()
	{
		return this->currentExecute;
	}

	void langXThread::freeThrownObj()
	{
		if (m_thrown_obj != nullptr)
		{
			Allocator::free(m_thrown_obj);
			m_thrown_obj = nullptr;
		}
	}

	void langXThread::backEnv()
	{
		backEnv(true);
	}

	void langXThread::backEnv(bool flag)
	{
		Environment *env = this->m_current_env->getParent();
		//if (env == NULL)
		//{
		//	return;
		//}
		//printf("backEnv %p,type: %d\n", m_current_env, m_current_env->getType());
		if (flag)
		{
			//  子类
			freeEnv(&this->m_current_env);
			//this->m_current_env = NULL;
		}
		this->m_current_deep--;
		this->m_current_env = env;
	}

	langXThreadMgr::langXThreadMgr()
	{
		this->m_id_gen = 0;
	}

	langXThreadMgr::~langXThreadMgr()
	{
	}

	void langXThreadMgr::initMainThreadInfo()
	{
		std::thread::id curThreadId = std::this_thread::get_id();

		int id = this->m_id_gen++;
		langXThread *thread = new langXThread(id);
		thread->setName("main");   // 设置线程名字为主线程
		thread->setStatus(langXThreadStatus::Running);
		this->m_selfmap[id] = thread;
		this->m_idmap[curThreadId] = thread;

	}

	void langXThreadMgr::freeAllThreads()
	{
		if (this->m_idmap.empty())
		{
			return;
		}

		for (auto i = this->m_idmap.begin(); i != this->m_idmap.end(); i++)
		{
			langXThread *thread = i->second;
			if (!thread->isMainThread())
			{
				thread->kill();
			}

			delete thread;
			i->second = nullptr;
		}

		this->m_id_gen = 0;
		this->m_idmap.clear();
		this->m_selfmap.clear();
	}

	langXThread * langXThreadMgr::currentThread()
	{
		std::thread::id curThreadId = std::this_thread::get_id();
		auto it = this->m_idmap.find(curThreadId);
		if (it != this->m_idmap.end())
		{
			return it->second;
		}

		return nullptr;
	}

}