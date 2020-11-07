#include <string>
#include <string.h>
#include "../include/Object.h"
#include "../include/Function.h"
#include "../include/langXObject.h"
#include "../include/ClassInfo.h"
#include "../include/Allocator.h"
#include "../include/Environment.h"
#include "../include/NodeCreator.h"

namespace langX {
	langX::ClassInfo::ClassInfo(const char*name)
	{
		this->m_name = std::string(name);
		this->m_classEnv = new ClassBridgeEnv(this);
	}

	langX::ClassInfo::~ClassInfo()
	{
		// 释放 member ， 函数回头再进行释放
		for (auto i = this->m_members.begin(); i != this->m_members.end(); i++)
		{
			if (i->second)
			{
				Allocator::free(i->second);
			}
		}
		this->m_members.clear();

		delete this->m_classEnv;
	}

	void ClassInfo::addMember(const char *name, Object *obj)
	{
		if (obj == NULL)
		{
			return;
		}
		auto i = this->m_members.find(name);
		if (i != this->m_members.end())
		{
			// 存在旧值
			Allocator::free(i->second);
		}
		Object *t = obj->clone();
		t->setName(name);
		this->m_members[name] = t;
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
			return this->m_parent->hasMember(name, true);
		}

		return false;
	}

	Object * ClassInfo::getMember(const char *name) const
	{
		return getMember(name, false);
	}

	Object * ClassInfo::getMember(const char *name, bool flag) const
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
		func->setClassInfo(this);
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

	Function * ClassInfo::getFunction(const char *name, bool flag) const
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
		return newObject(true);
	}

	langXObject * ClassInfo::newObject(bool flag)
	{
		if (flag)
		{
			return Allocator::newObject(this);
		}

		return new langXObject(this);
	}

	langXObjectExtend* ClassInfo::newExtendObject()
	{
		return (langXObjectExtend*)Allocator::newObject(this, true, true);
	}

	std::map<std::string, Object*>& ClassInfo::getMembers()
	{
		return this->m_members;
	}

	std::map<std::string, Function*>& ClassInfo::getFunctions()
	{
		return this->m_functions;
	}

	bool ClassInfo::isInstanceOf(const char *name) const
	{
		if (strcmp(this->m_name.c_str(), name) == 0)
		{
			return true;
		}

		if (this->m_parent != NULL)
		{
			return this->m_parent->isInstanceOf(name);
		}
		return false;
	}

	void ClassInfo::expand(ClassInfo *c1)
	{
		if (c1 == NULL)
		{
			return;
		}

		std::map<std::string, Object*>& members = c1->getMembers();

		for (auto i = members.begin(); i != members.end(); i++)
		{
			std::string str = i->first;
			Object *obj = i->second;

			auto abc = this->m_members.find(str);
			if (abc != this->m_members.end())
			{
				// 存在旧值
				Allocator::free(abc->second);
			}

			this->m_members[str] = obj->clone();
		}

		std::map<std::string, Function*>& funcs = c1->getFunctions();
		for (auto i = funcs.begin(); i != funcs.end(); i++)
		{
			std::string str = i->first;
			Function *obj = i->second;

			auto abc = this->m_functions.find(str);
			if (abc != this->m_functions.end())
			{
				// 存在旧值
				delete (abc->second);
			}

			obj->setClassInfo(this);    // 把类信息重新定位到当前类信息对象
			this->m_functions[str] = obj;
		}

		if (!this->m_local)
		{
			if (c1->isLocal())
			{
				this->m_local = true;
			}
		}
	}

	ClassBridgeEnv * ClassInfo::getClassEnv()
	{
		return this->m_classEnv;
	}

	bool ClassInfo::isLocal() const
	{
		return this->m_local;
	}

	void ClassInfo::setLocal(bool f)
	{
		this->m_local = f;
	}
}
