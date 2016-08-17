#include "../include/Object.h"
#include "../include/Function.h"
#include "../include/ClassInfo.h"

namespace langX {

	langX::ClassInfo::ClassInfo()
	{
	}

	langX::ClassInfo::~ClassInfo()
	{
	}

	void ClassInfo::addMember(const char *name, Object *obj)
	{
		this->m_members[name] = obj->clone();
	}

	bool ClassInfo::hasMember(const char *name) const
	{
		if (this->m_members.find(name) != this->m_members.end())
		{
			return true;
		}
		return false;
	}

	Object * ClassInfo::getMember(const char *name) const
	{
		if (!hasMember(name))
		{
			return NULL;
		}
		return this->m_members.at(name);
	}

	void ClassInfo::addFunction(const char *name, Function *func)
	{
		this->m_functions[name] = func;
	}

	bool ClassInfo::hasFunction(const char *name) const
	{
		if (this->m_functions.find(name) != this->m_functions.end())
		{
			return true;
		}
		return false;
	}

	Function * ClassInfo::getFunction(const char *name) const
	{
		if (!hasFunction(name))
		{
			return NULL;
		}
		return this->m_functions.at(name);
	}


}