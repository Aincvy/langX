#include <string>
#include <sstream>

#include "../include/Object.h"
#include "../include/Function.h"
#include "../include/langXObject.h"
#include "../include/langXObjectRef.h"

namespace langX {
	langXObjectRef::langXObjectRef(langXObject * obj)
	{
		this->m_object_ref = obj;
	}
	langXObjectRef::~langXObjectRef()
	{
		if (this->m_object_ref != nullptr)
		{
			// 当前对象正在销毁中， 则 直接返回， 不减少引用
			if (this->m_object_ref->isDisposing())
			{
				return;
			}
			this->m_object_ref->subRef(this);
			this->m_object_ref = nullptr;
		}
	}
	langXObject * langXObjectRef::getRefObject()
	{
		return this->m_object_ref;
	}
	void langXObjectRef::setMember(const char *name, Object *obj)
	{
		if (m_object_ref == nullptr)
		{
			return;
		}
		this->m_object_ref->setMember(name, obj);
	}
	Object * langXObjectRef::getMember(const char *name) const
	{
		if (m_object_ref == nullptr)
		{
			return NULL;
		}
		return this->m_object_ref->getMember(name);
	}
	Function * langXObjectRef::getFunction(const char *name) const
	{
		if (m_object_ref == nullptr)
		{
			return NULL;
		}
		return this->m_object_ref->getFunction(name);
	}
	const ClassInfo * langXObjectRef::getClassInfo() const
	{
		if (m_object_ref == nullptr)
		{
			return NULL;
		}
		return this->m_object_ref->getClassInfo();
	}
	Function * langXObjectRef::getConstructor() const
	{
		if (m_object_ref == nullptr)
		{
			return NULL;
		}
		return this->m_object_ref->getConstructor();
	}
	void langXObjectRef::setMembersEmergeEnv(Environment *env)
	{
		if (this->m_object_ref == nullptr)
		{
			return;
		}
		this->m_object_ref->setMembersEmergeEnv(env);
	}
	bool langXObjectRef::isTrue() const
	{
		if (this->m_object_ref == nullptr)
		{
			return false;
		}
		return true;
	}
	ObjectType langXObjectRef::getType() const
	{
		return OBJECT;
	}
	Object * langXObjectRef::clone() const
	{
		langXObjectRef * obj = NULL;
		if (m_object_ref == nullptr)
		{
			obj = new langXObjectRef(NULL);
		}
		else {
			obj = this->m_object_ref->addRef();
		}

		obj->setEmergeEnv(getEmergeEnv());
		obj->setCharacteristic(characteristic());
		obj->setConst(this->isConst());
		obj->setLocal(this->isLocal());
		obj->setName(this->getName());
		return obj;
	}

	void langXObjectRef::update(Object *obj)
	{
		if (obj == NULL)
		{
			return;
		}

		if (this->m_object_ref != NULL)
		{
			this->m_object_ref->subRef(this);
			this->m_object_ref = NULL;
			this->setCharacteristic("no_pointer_to_anything");
		}

		if (obj->getType() == OBJECT)
		{
			this->m_object_ref = ((langXObjectRef*)obj)->getRefObject();
			this->m_object_ref->justAddRef(this);
		}
	}

	void langXObjectRef::setRefObject(langXObject *obj)
	{
		this->m_object_ref = obj;
	}

	void langXObjectRef::finalize()
	{
	}
}