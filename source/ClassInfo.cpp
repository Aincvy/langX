#include <string>
#include <string.h>
#include "../include/Object.h"
#include "../include/Function.h"
#include "../include/langXObject.h"
#include "../include/ClassInfo.h"
#include "../include/Allocator.h"
#include "../include/Environment.h"
#include "../include/YLlangX.h"

extern langX::Allocator m_exec_alloc;

namespace langX {

	langX::ClassInfo::ClassInfo(const char*name)
	{
		this->m_name = std::string(name);
		this->m_classEnv = new ClassBridgeEnv(this);
	}

	langX::ClassInfo::~ClassInfo()
	{
		// �ͷ� member �� ������ͷ�ٽ����ͷ�
		for (auto i = this->m_members.begin(); i != this->m_members.end(); i++)
		{
			m_exec_alloc.free(i->second);
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
			// ���ھ�ֵ
			m_exec_alloc.free(i->second);
		}
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
			return this->m_parent->hasMember(name ,true);
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
		return getState()->getAllocator().newObject(this);
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
		if (strcmp(this->m_name.c_str(), name ) == 0)
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
				// ���ھ�ֵ
				m_exec_alloc.free(abc->second);
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
				// ���ھ�ֵ
				delete (abc->second);
			}

			this->m_functions[str] = obj;
		}

	}

	ClassBridgeEnv * ClassInfo::getClassEnv()
	{
		return this->m_classEnv;
	}


}