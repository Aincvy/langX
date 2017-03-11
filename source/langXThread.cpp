
#include "../include/langXThread.h"
#include "../include/Environment.h"
#include "../include/langXObjectRef.h"
#include "../include/Function.h"
#include "../include/ExecNode.h"


// �ͷŻ����ڴ�
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

		// ����ӡ�Լ��������
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
		// ����һ���쳣
		this->setInException(true);

		// �ҵ�try����
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

			// ��Ϊ�������쳣�� ���Ե� try ����֮ǰ�����л�����������������
			//env->setDead(true);
			Environment *p = env->getParent();

			// �˻�һ������ ��ֱ���˻�try ����
			backEnv();

			env = p;
		}

		if (tryEnv == NULL)
		{
			printf("cannot find try env, throw error!\n");
			return;
		}

		//  �˳�try ����
		backEnv(false);

		// check call back first.
		CBCatch c = tryEnv->getCatchCB();
		if (c != NULL)
		{
			c(obj);

			// �½�һ�������������õ�ǰ����Ϊ dead ����
			newEnv();

			// ɾ������
			delete obj->getRefObject();
			delete obj;
			obj = NULL;
		}
		else {
			//setInException(true);
			// ���쳣��ֵ
			// ����catch ����
			env = newEnv();
			Node *cNode = tryEnv->getCatchNode();
			env->putObject(cNode->opr_obj->op[0]->var_obj->name, obj);

			// ִ�� catch ������
			__execNode(cNode->opr_obj->op[1]);

			// ������back ��env
			while (env != this->m_current_env)
			{
				if (this->m_current_env == NULL)
				{
					break;
				}

				backEnv();
			}

			// �������� try-catch ������ʱ�� �� try ִ�к���ͷ�һ�����������Ե�ǰ��������

			// ɾ������
			delete obj->getRefObject();
			delete obj;
			obj = NULL;
		}

		// ����try ����
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
			//  ����
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
		thread->setName("main");   // �����߳�����Ϊ���߳�
		thread->setStatus(langXThreadStatus::Running);
		this->m_selfmap[id] = thread;
		this->m_idmap[curThreadId] = thread;

	}

	langXThread * langXThreadMgr::currentThread()
	{
		return nullptr;
	}

}