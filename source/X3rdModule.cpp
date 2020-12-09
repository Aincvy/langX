#include <stdlib.h>
#include <string.h>

#include "X3rdModule.h"


namespace langX {
	X3rdModule::X3rdModule()
	{
		this->m_name = nullptr;
	}

	X3rdModule::~X3rdModule()
	{
	}

	int X3rdModule::init(langXState *)
	{
		return 0;
	}

	int X3rdModule::unload(langXState *)
	{
		return 0;
	}
	const char * X3rdModule::getName() const
	{
		return this->m_name;
	}
	void X3rdModule::setName(const char *name)
	{
		if (!name)
		{
			return;
		}

		checkForFreeName();

		this->m_name = strdup(name);
	}
	void X3rdModule::setSoObj(void * soObj)
	{
		this->m_soObj = soObj;
	}
	void * X3rdModule::getSoObj() const
	{
		return this->m_soObj;
	}
	void X3rdModule::checkForFreeName()
	{
		if (m_name)
		{
			free(m_name);
			m_name = nullptr;
		}
	}
}