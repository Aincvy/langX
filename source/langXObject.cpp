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
		// �����ɸ������
		ClassInfo *pclass = claxxInfo->getParent();
		if (pclass != nullptr)
		{
			this->m_parent = pclass->newObject();
		}

		this->m_class_info = claxxInfo;
		this->m_my_env = new ObjectBridgeEnv(this);
		this->m_my_env->setParent(NULL);

		std::map<std::string, Object*> & map = claxxInfo->getMembers();
		for (auto i = map.begin(); i != map.end(); i++)
		{
			Object *obj = i->second->clone();
			//  ����ֶ�ֵ Ϊ����ר�У� ��������Ҳ�Ƕ���Ļ���
			obj->setEmergeEnv(this->m_my_env);
			this->m_members[i->first] = obj;
		}

	}

	langXObject::~langXObject()
	{
		// �ȸɵ��Լ��� �ٸɵ��������
		
		// �ȵ����Լ��� ��������
		std::string str = "~";
		str += this->m_class_info->getName();
		callFunction(str.c_str());

		if (this->m_my_env != NULL)
		{
			delete this->m_my_env;
			this->m_my_env = NULL;
		}

		// �ɵ��������
		if (this->m_parent != NULL)
		{
			delete this->m_parent;
			this->m_parent = NULL;
		}
	}

	void langXObject::setMember(const char *name, Object *obj)
	{
		setMember(name, obj, false);
	}

	void langXObject::setMember(const char *name, Object *obj, bool flag)
	{
		if (this->m_members.find(name) == this->m_members.end())
		{
			if (this->m_parent == NULL)
			{
				printf("cannot find member %s!\n", name);
				return;
			}
			
			this->m_parent->setMember(name, obj, true);
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

	bool langXObject::hasMember(const char *name) const
	{
		if (this->m_members.find(name) == this->m_members.end())
		{
			if (this->m_parent == NULL)
			{
				return false;
			}

			return this->m_parent->hasMember(name);
		}
		return true;
	}

	Object * langXObject::getMember(const char *name) const
	{
		return getMember(name, false);
	}

	Object * langXObject::getMember(const char *name, bool flag) const
	{
		if (this->m_members.find(name) != this->m_members.end())
		{
			return this->m_members.at(name);
		}

		if (this->m_parent != NULL)
		{
			return this->m_parent->getMember(name, true);
		}

		return NULL;
	}

	Function * langXObject::getFunction(const char *name) const
	{
		return getFunction(name, false);
	}

	Function * langXObject::getFunction(const char *name, bool flag) const
	{
		return this->m_class_info->getFunction(name,flag);
	}

	const ClassInfo * langXObject::getClassInfo() const
	{
		return this->m_class_info;
	}

	const char * langXObject::getClassName() const
	{
		return this->m_class_info->getName();
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

	Object * langXObject::callFunction(const char *name) const
	{
		Function * func = getFunction(name);
		if (func == NULL)
		{
			//printf("cannot find func: %s\n" , name);
			return NULL;
		}

		getState()->newEnv2(this->m_my_env);
		Object *obj = func->call();
		getState()->backEnv();

		return obj;
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