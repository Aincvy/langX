#include <string>
#include "../include/Object.h"
#include "../include/Function.h"
#include "../include/langXObject.h"
#include "../include/ClassInfo.h"

namespace langX {

	langX::ClassInfo::ClassInfo(const char*name)
	{
		this->m_name = std::string(name);
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
		return hasMember(name, false);
	}

	bool ClassInfo::hasMember(const char *name, bool flag) const
	{
		if (this->m_members.find(name) != this->m_members.end())
		{
			return true;
		}

		if (this->m_parent != NULL)
		{
			return this->m_parent->hasMember(name);
		}

		return false;
	}

	Object * ClassInfo::getMember(const char *name) const
	{
		return getMember(name, false);
	}

	Object * ClassInfo::getMember(const char *name , bool flag) const
	{
		if (!hasMember(name))
		{
			if (this->m_parent == NULL)
			{
				return NULL;
			}

			return this->m_parent->getMember(name, true);
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
		return getFunction(name, false);
	}

	Function * ClassInfo::getFunction(const char *name , bool flag) const
	{
		if (!hasFunction(name))
		{
			if (this->m_parent == NULL)
			{
				return NULL;
			}
			return this->m_parent->getFunction(name, true);
		}
		return this->m_functions.at(name);
	}

	void ClassInfo::setParent(ClassInfo *c)
	{
		this->m_parent = c;
	}

	ClassInfo * ClassInfo::getParent() const
	{
		return this->m_parent;
	}

	const char * ClassInfo::getName() const
	{
		return this->m_name.c_str();
	}

	langXObject * ClassInfo::newObject()
	{
		return new langXObject(this);
	}

	std::map<std::string, Object*>& ClassInfo::getMembers()
	{
		return this->m_members;
	}

	std::map<std::string, Function*>& ClassInfo::getFunctions()
	{
		return this->m_functions;
	}


}