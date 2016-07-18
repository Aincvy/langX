#include <stdio.h>
#include "../include/langX.h"
#include "../include/Number.h"

namespace langX {
	langXState::langXState()
	{
		this->m_current_env = new Environment();
	}
	langXState::~langXState()
	{
		//delete this->m_current_env;
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

}