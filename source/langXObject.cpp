#include <string>
#include "../include/Object.h"
#include "../include/ClassInfo.h"
#include "../include/Function.h"
#include "../include/langXObject.h"
#include "../include/langXObjectRef.h"

namespace langX {

	langXObject::langXObject(ClassInfo *claxxInfo)
	{
		this->m_class_info = claxxInfo;
		
		std::map<std::string, Object*> & map = claxxInfo->getMembers();
		for (auto i = map.begin(); i != map.end(); i++)
		{
			Object *obj = i->second->clone();
			obj->setName(i->first.c_str());
			this->m_members[i->first] = obj;
		}
	}

	langXObject::~langXObject()
	{
	}

	void langXObject::setMember(const char *name, Object *obj)
	{
		Object * a = obj->clone();
		a->setName(name);
		this->m_members[name] = a;
	}

	Object * langXObject::getMember(const char *name) const
	{
		if (this->m_members.find(name) != this->m_members.end())
		{
			return this->m_members.at(name);
		}

		return NULL;
	}

	Function * langXObject::getFunction(const char *name) const
	{
		return this->m_class_info->getFunction(name);
	}

	const ClassInfo * langXObject::getClassInfo() const
	{
		return this->m_class_info;
	}

	void langXObject::justAddRef()
	{
		this->m_ref_count++;
	}

	langXObjectRef * langXObject::addRef()
	{
		this->m_ref_count++;
		return new langXObjectRef(this);
	}

	void langXObject::subRef()
	{
		this->m_ref_count--;
	}

	int langXObject::getRefCount() const
	{
		return this->m_ref_count;
	}



}