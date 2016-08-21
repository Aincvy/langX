#include <string>
#include "../include/Object.h"
#include "../include/ClassInfo.h"
#include "../include/Function.h"
#include "../include/YLlangX.h"
#include "../include/Allocator.h"
#include "../include/langXObject.h"
#include "../include/langXObjectRef.h"
#include "../include/Environment.h"

namespace langX {



	langXObject::langXObject(ClassInfo *claxxInfo)
	{
		this->m_class_info = claxxInfo;
		this->m_my_env = new ObjectBridgeEnv(this);

		std::map<std::string, Object*> & map = claxxInfo->getMembers();
		for (auto i = map.begin(); i != map.end(); i++)
		{
			Object *obj = i->second->clone();
			//  类的字段值 为对象专有， 产生环境也是对象的环境
			obj->setEmergeEnv(this->m_my_env);
			this->m_members[i->first] = obj;
		}

	}

	langXObject::~langXObject()
	{
		if (this->m_my_env != NULL)
		{
			delete this->m_my_env;
			this->m_my_env = NULL;
		}
	}

	void langXObject::setMember(const char *name, Object *obj)
	{
		if (this->m_members.find(name) == this->m_members.end())
		{
			printf("cannot find member %s!\n" ,name);
			return;
		}

		Object *a = this->m_members[name];
		if (a->getType() == obj->getType())
		{
			a->update(obj);
		}
		else {
			getState()->getAllocator().free(a);
			a = NULL;
			this->m_members.find(name)->second = obj->clone();
		}
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

	Function * langXObject::getConstructor() const
	{
		return getFunction(this->m_class_info->getName());
	}

	void langXObject::setMembersEmergeEnv(Environment *env)
	{
		for (auto i = this->m_members.begin(); i != this->m_members.end(); i++)
		{
			i->second->setEmergeEnv(env);
		}
	}

	Environment * langXObject::getObjectEnvironment() const
	{
		return this->m_my_env;
	}



}