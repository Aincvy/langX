#include <stdio.h>
#include "../include/langX.h"
#include "../include/Number.h"

namespace langX {
	langXState::langXState()
	{
	}
	langXState::~langXState()
	{
	}
	void langXState::putObject(const char * name, Object *obj)
	{
		this->m_global_env.putObject(name, obj);
	}

	void langXState::putObject(const std::string &name, Object *obj)
	{
		this->m_global_env.putObject(name, obj);
	}
	Object * langXState::getObject(const std::string &name)
	{
		return this->m_global_env.getObject(name);
	}

}