#include <stdio.h>
#include "../include/langX.h"
#include "../include/Object.h"
#include "../include/Number.h"
#include "../include/Environment.h"
#include "../include/Allocator.h"

namespace langX {

	langXState::langXState()
	{
		this->m_global_env = new Environment();
		this->m_global_env->setParent(NULL);
		this->m_current_env = this->m_global_env;
		this->m_allocator = new Allocator();

		this->m_env_list.push_front(this->m_current_env);
	}
	langXState::~langXState()
	{
		//delete this->m_current_env;
		
		delete this->m_allocator;

		if (!this->m_env_list.empty())
		{
			for (auto i = m_env_list.begin(); i != m_env_list.end(); i++)
			{
				Environment *env = (*i);
				delete env;
			}

			this->m_env_list.clear();
		}

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
		Environment *env = new Environment();
		env->setParent(this->m_current_env);
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
		this->m_current_env = env;
		return env;
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
			delete this->m_current_env;
		}
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

	void langXState::addEnvToList(Environment *env)
	{
		if (env == NULL)
		{
			return;
		}

		this->m_env_list.push_front(env);
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

	Allocator & langXState::getAllocator() const
	{
		return (*this->m_allocator);
	}

}