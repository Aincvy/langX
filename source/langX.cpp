#include <stdio.h>
#include "../include/langX.h"
#include "../include/Number.h"

namespace langX {

	langXState::langXState()
	{
		this->m_global_env = new Environment();
		this->m_current_env = this->m_global_env;
		this->m_allocator = new Allocator();
	}
	langXState::~langXState()
	{
		//delete this->m_current_env;
		delete this->m_allocator;
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

	void langXState::backEnv()
	{
		Environment *env = this->m_current_env->getParent();
		if (env == NULL)
		{
			return;
		}
		delete this->m_current_env;
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

	Allocator & langXState::getAllocator() const
	{
		return (*this->m_allocator);
	}

}