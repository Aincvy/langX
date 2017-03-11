
#include "../include/langXThread.h"
#include "../include/Environment.h"
#include "../include/langXObjectRef.h"
#include "../include/Function.h"
#include "../include/ExecNode.h"


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

		TryEnvironment *tryEnv = new TryEnvironment();
		tryEnv->setParent( nullptr );
		tryEnv->setCatchCB(gTryCatchCB);
		tryEnv->setDeep(1);
		this->m_current_env = tryEnv;
	}

	langXThread::~langXThread()
	{
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

	Environment * langXThread::getCurrentEnv() const
	{
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

		EnvironmentBridgeEnv *bEnv = new EnvironmentBridgeEnv(env);
		bEnv->setParent(this->m_current_env);
		bEnv->setDeep((++this->m_current_deep));
		this->m_current_env = bEnv;
		return bEnv;
	}

	void langXThread::backToDeep1Env()
	{
		if (this->m_current_deep <= 1)
		{
			return;
		}

		while (this->m_current_deep != 2) {
			backEnv();
		}

		if (this->m_current_env->getType() == TScriptEnvironment)
		{
			backEnv(false);
		}
		else {
			backEnv();
		}
	}

	void langXThread::throwException(langXObjectRef *obj)
	{
		// 丢出一个异常
		this->setInException(true);

		// 找到try环境
		TryEnvironment *tryEnv = NULL;
		Environment *env = this->m_current_env;
		while (1)
		{
			if (env == NULL)
			{
				break;
			}

			if (env->isTryEnvironment())
			{
				if (env->isEnvEnvironment())
				{
					tryEnv = (TryEnvironment *)((EnvironmentBridgeEnv*)env)->getBridgeEnv();
				}
				else {
					tryEnv = (TryEnvironment *)env;
				}
				break;
			}

			// 因为丢出了异常， 所以到 try 环境之前的所有环境都会变成死亡环境
			//env->setDead(true);
			Environment *p = env->getParent();

			// 退回一级环境 ，直到退回try 环境
			backEnv();

			env = p;
		}

		if (tryEnv == NULL)
		{
			printf("cannot find try env, throw error!\n");
			return;
		}

		//  退出try 环境
		backEnv(false);

		// check call back first.
		CBCatch c = tryEnv->getCatchCB();
		if (c != NULL)
		{
			c(obj);

			// 新建一个环境，并设置当前环境为 dead 环境
			newEnv();

			// 删除对象
			delete obj->getRefObject();
			delete obj;
			obj = NULL;
		}
		else {
			//setInException(true);
			// 将异常赋值
			// 进入catch 环境
			env = newEnv();
			Node *cNode = tryEnv->getCatchNode();
			env->putObject(cNode->opr_obj->op[0]->var_obj->name, obj);

			// 执行 catch 块的语句
			__execNode(cNode->opr_obj->op[1]);

			// 将环境back 到env
			while (env != this->m_current_env)
			{
				if (this->m_current_env == NULL)
				{
					break;
				}

				backEnv();
			}

			// 主动进行 try-catch 操作的时候 ， try 执行后会释放一个环境，所以当前环境保留

			// 删除对象
			delete obj->getRefObject();
			delete obj;
			obj = NULL;
		}

		// 销毁try 环境
		delete tryEnv;
		tryEnv = NULL;
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
		this->m_current_env->putObject(name, obj);
	}

	void langXThread::putObject(const std::string &name, Object *obj)
	{
		this->m_current_env->putObject(name, obj);
	}
	Object * langXThread::getObject(const std::string &name)
	{
		return this->m_current_env->getObject(name);
	}

	Environment * langXThread::getEnvironment(int deep)
	{
		if (this->m_current_deep < deep)
		{
			return nullptr;
		}

		if (this->m_current_deep == deep)
		{
			return this->m_current_env;
		}

		Environment *env = this->m_current_env->getParent();
		while (env != nullptr && env->getDeep() != deep)
		{
			env = env->getParent();
		}

		return env;
	}

	void langXThread::backEnv()
	{
		backEnv(true);
	}

	void langXThread::backEnv(bool flag)
	{
		Environment *env = this->m_current_env->getParent();
		if (env == NULL)
		{
			return;
		}
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

	langXThread * langXThreadMgr::currentThread()
	{
		return nullptr;
	}

}