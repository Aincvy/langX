#include "../include/Object.h"
#include "../include/ClassInfo.h"
#include "../include/langXObject.h"
#include "../include/langXObjectRef.h"

namespace langX {

	langXObject::langXObject(ClassInfo *claxxInfo)
	{
		this->m_class_info = claxxInfo;
		
		std::map<std::string, Object*> & map = claxxInfo->getMembers();
		for (auto i = map.begin(); i != map.end(); i++)
		{
			this->m_members[i->first] = i->second->clone();
		}
	}

	langXObject::~langXObject()
	{
	}

	void langXObject::setMember(const char *name, Object *obj)
	{
		this->m_members[name] = obj->clone();
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