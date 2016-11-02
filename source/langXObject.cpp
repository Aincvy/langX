#include <string>
#include "../include/Object.h"
#include "../include/ClassInfo.h"
#include "../include/Function.h"
#include "../include/YLlangX.h"
#include "../include/Allocator.h"
#include "../include/langXObject.h"
#include "../include/langXObjectRef.h"
#include "../include/Environment.h"
#include "../include/Utils.h"
#include "../include/DestroyedObject.h"

namespace langX {



	langXObject::langXObject(ClassInfo *claxxInfo)
	{
		// 先生成父类对象
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
			//  类的字段值 为对象专有， 产生环境也是对象的环境
			obj->setEmergeEnv(this->m_my_env);
			obj->setName(i->first);
			this->m_members[i->first] = obj;
		}

	}

	langXObject::~langXObject()
	{
		// 先干掉自己， 再干掉父类对象
		
		// 先调用自己的 析构函数
		std::string str = "~";
		str += this->m_class_info->getName();
		callFunction(str.c_str());

		if (this->m_my_env != NULL)
		{
			delete this->m_my_env;
			this->m_my_env = NULL;
		}

		// 清理引用
		DestroyedObject destoryObj;
		for (auto i = this->m_refs.begin(); i != this->m_refs.end(); i++)
		{
			langXObjectRef *r = (*i);
			r->getEmergeEnv()->putObject(r->getName(), &destoryObj);

			delete r;
			r = NULL;
		}
		this->m_refs.clear();

		// 干掉父类对象
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
			a = obj->clone();
			a->setName(name);
			this->m_members.find(name)->second = a;
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

	void langXObject::justAddRef(langXObjectRef *r)
	{
		this->m_ref_count++;
		if (r)
		{
			this->m_refs.push_back(r);
		}
		this->m_zero_ref_time = 0;
	}

	langXObjectRef * langXObject::addRef()
	{
		this->m_ref_count++;
		langXObjectRef *r = new langXObjectRef(this);
		this->m_refs.push_back(r);
		this->m_zero_ref_time = 0;
		return r;
	}

	void langXObject::subRef()
	{
		if (-- this->m_ref_count <= 0)
		{
			this->m_zero_ref_time = getTime();
		}
		this->m_ref_count--;
	}

	void langXObject::subRef(langXObjectRef *r)
	{
		if (!r)
		{
			return;
		}

		for (auto i = m_refs.begin(); i != m_refs.end(); i++)
		{
			if ((*i) == r)
			{
				m_refs.erase(i++);
				break;
			}
		}
		subRef();
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

	long langXObject::getZeroRefTime() const
	{
		return this->m_zero_ref_time;
	}

	void langXObject::set3rdObj(void *p)
	{
		this->m_3rdObj = p;
	}

	void * langXObject::get3rdObj() const
	{
		return this->m_3rdObj;
	}



}