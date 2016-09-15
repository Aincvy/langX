#include <stdio.h>
#include <algorithm>
#include "../include/ClassInfo.h"
#include "../include/langX.h"
#include "../include/Object.h"
#include "../include/Number.h"
#include "../include/Environment.h"
#include "../include/Allocator.h"
#include "../include/StackTrace.h"
#include "../include/ExecNode.h"
#include "../include/langXObject.h"
#include "../include/langXObjectRef.h"
#include "../include/YLlangX.h"
#include "../include/Exception.h"
#include "../include/Function.h"
#include "../include/XNameSpace.h"

// �л��������� �ļ�ָ��
extern void pushBuffer(FILE *fp);

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

	langXState::langXState()
	{
		XNameSpace *s = new XNameSpace("$NoName1");
		this->m_namespace_map[s->getName()] = s;
		this->m_global_env = new GlobalEnvironment();
		this->m_global_env->setParent(NULL);
		this->m_global_env->setDeep(0);
		TryEnvironment *tryEnv = new TryEnvironment();
		tryEnv->setParent(this->m_global_env);
		tryEnv->setCatchCB(gTryCatchCB);
		tryEnv->setDeep(1);
		this->m_current_env = tryEnv;
		this->m_current_deep = 1;
		this->m_allocator = new Allocator();

		this->m_stacktrace.newFrame(NULL, NULL, "<startFrame>");
	}

	langXState::~langXState()
	{
		for (std::map<std::string, XNameSpace*>::iterator i = this->m_namespace_map.begin(); i != this->m_namespace_map.end(); i++)
		{
			XNameSpace *p = i->second;
			delete p;
		}
		this->m_namespace_map.clear();

		delete this->m_allocator;

		backToDeep1Env();

		while (this->m_current_env != NULL && this->m_current_env->getParent() != NULL)
		{
			backEnv();
		}

		//  �����������ĵ�ǰ��������  m_global_env  �����������ͷ� m_global_env
		freeEnv(&this->m_current_env);
		
		for (auto i = this->m_script_env_map.begin(); i != this->m_script_env_map.end(); i++)
		{
			delete (i->second);
		}

		this->m_script_env_map.clear();
	}

	void langXState::putObject(const char * name, Object *obj)
	{
		this->m_current_env->putObject(name, obj);
	}

	void langXState::putObject(const std::string &name, Object *obj)
	{
		this->m_current_env->putObject(name, obj);
	}
	Object * langXState::getObject(const std::string &name)
	{
		return this->m_current_env->getObject(name);
	}



	Environment * langXState::newEnv()
	{
		Environment *env = new DefaultEnvironment();
		env->setParent(this->m_current_env);
		env->setDeep((++this->m_current_deep));
		this->m_current_env = env;
		return env;
	}

	Environment * langXState::newEnv(Environment *env)
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

	Environment * langXState::newEnv2(Environment *env)
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

	void langXState::backEnv()
	{
		backEnv(true);
	}

	void langXState::backEnv(bool flag)
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

	Environment * langXState::getCurrentEnv() const
	{
		return this->m_current_env;
	}

	Environment * langXState::getGlobalEnv() const
	{
		return this->m_global_env;
	}

	Environment * langXState::getNearestObjectEnv() const
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

	Environment * langXState::getEnvironment(int deep)
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

	void langXState::reg3rd(const char *name, X3rdFuncWorker worker)
	{
		X3rdFunction *func = new X3rdFunction();
		func->setName(name);
		func->setWorker(worker);
		func->setParamsList(NULL);
		func->setLangX(this);
		this->m_global_env->putFunction(name, func);
	}

	void langXState::unreg3rd(const char *name)
	{
		// do nothing now. 

	}

	void langXState::regClass(ClassInfo *c)
	{
		if (c == NULL)
		{
			return;
		}

		this->m_script_env->putClass(c->getName(), c);
	}

	void langXState::regClassToGlobal(ClassInfo *c)
	{
		if (c == NULL)
		{
			return;
		}

		this->m_global_env->putClass(c->getName(), c);
	}

	Allocator & langXState::getAllocator() const
	{
		return (*this->m_allocator);
	}

	StackTrace & langXState::getStackTrace()
	{
		return this->m_stacktrace;
	}

	void langXState::printStackTrace() const
	{
		StrackTraceFrameArray array1 = this->m_stacktrace.frames();

		// ����ӡ�Լ��������
		for (int i = array1.length - 2; i >= 0; i--)
		{
			printf("%s\n", array1.frame[i]->getInfo());
		}

		free(array1.frame);
	}

	void langXState::throwException(langXObjectRef *obj)
	{
		// ����һ���쳣

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
			this->m_current_env->setDead(true);

			// ɾ������
			delete obj->getRefObject();
			delete obj;
			obj = NULL;
		}
		else {
			setInException(true);
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
			// ����ǰ��������Ϊ���������� �����Ϳ��Ժ��� try �ڵ�ʣ������ˣ�
			env->setDead(true);

			setInException(false);

			// ɾ������
			delete obj->getRefObject();
			//delete obj;
			obj = NULL;
		}

		// ����try ����
		delete tryEnv;
		tryEnv = NULL;
	}

	langXObject * langXState::newObject(const char * name) const
	{
		ClassInfo* classinfo = this->m_global_env->getClass(name);
		if (classinfo == NULL)
		{
			return NULL;
		}

		return classinfo->newObject();
	}

	ClassInfo * langXState::getClass(const char *name) const
	{
		ClassInfo * c = nullptr;
		if (this->m_script_env != nullptr)
		{
			c = this->m_script_env->getClass(name);
			if (c != nullptr)
			{
				return c;
			}
		}

		return this->m_global_env->getClass(name);
	}

	XNameSpace * langXState::getNameSpaceOrCreate(const char *name)
	{
		if (this->m_namespace_map.find(name) != this->m_namespace_map.end())
		{
			return this->m_namespace_map[name];
		}

		XNameSpace *space = new XNameSpace(name);
		this->m_namespace_map[name] = space;
		return space;
	}

	XNameSpace * langXState::getNameSpace(const char *name)
	{
		if (this->m_namespace_map.find(name) != this->m_namespace_map.end())
		{
			return this->m_namespace_map[name];
		}
		return nullptr;
	}

	void langXState::changeNameSpace(XNameSpace *s)
	{
		if (s == nullptr)
		{
			return;
		}

		//  �ͷ��ڴ浽 ���Ϊ1 �� ����
		backToDeep1Env();

		this->m_script_env = new XNameSpaceEnvironment(s);
		this->m_current_deep++;
		this->m_script_env->setDeep(this->m_current_deep);
		this->m_script_env->setParent(this->m_current_env);
		this->m_current_env = this->m_script_env;
	}

	void langXState::newScriptEnv(const char * name)
	{
		if (name == NULL)
		{
			return;
		}

		//  �ͷ��ڴ浽 ���Ϊ1 �� ����
		backToDeep1Env();
		

		ScriptEnvironment *env = new ScriptEnvironment(name);
		this->m_script_env = env;
		this->m_script_env_map[name] = env;
		this->m_current_deep++;
		this->m_script_env->setDeep(this->m_current_deep);
		this->m_script_env->setParent(this->m_current_env);
		this->m_current_env = this->m_script_env;
	}

	int langXState::doFile(const char *filename)
	{
		if (filename == NULL)
		{
			return -1;
		}

		FILE *fp = fopen(filename,"r");
		if (fp == NULL)
		{
			throwException(newFileNotFoundException(filename)->addRef());
			return -1;
		}
		
		m_didScripts.push_back(filename);
		
		this->pushScriptEnvToDoingStack();
		pushBuffer(fp);
		return 0;
	}

	bool langXState::isDidScript(const char *f)
	{
		std::list<std::string>::iterator it = std::find(m_didScripts.begin(), m_didScripts.end(), f);

		if (it == m_didScripts.end())
		{
			return false;
		}

		return true;
	}

	void langXState::addToDidScripts(const char *f)
	{
		this->m_didScripts.push_back(f);
	}

	void langXState::pushDoingFile(const char * f)
	{
		this->m_doing_files.push(f);
	}

	const char* langXState::popDoingFile()
	{
		if (this->m_doing_files.empty())
		{
			return NULL;
		}
		const char * x = this->m_doing_files.top();
		this->m_doing_files.pop();
		return x;
	}

	const char * langXState::getParsingFile() const
	{
		return this->m_parsing_file;
	}

	void langXState::setParsingFile(const char *f)
	{
		this->m_parsing_file = f;
	}

	int langXState::pushScriptEnvToDoingStack()
	{
		if (this->m_script_env->getType() == TScriptEnvironment) {
			this->m_doing_script_envs.push((ScriptEnvironment*)this->m_script_env);
			return 0;
		}

		return -1;
	}

	int langXState::popScriptEnvToDoingStack()
	{
		if (this->m_doing_script_envs.empty())
		{
			return -1;
		}

		ScriptEnvironment *screnv = this->m_doing_script_envs.top();
		if (this->m_script_env != screnv)
		{
			backToDeep1Env();
			newEnv(screnv);
			this->m_script_env = screnv;
		}
		
		this->m_doing_script_envs.pop();

		return 0;
	}

	void langXState::backToDeep1Env()
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

}