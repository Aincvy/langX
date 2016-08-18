#include "../include/Object.h"
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
			this->m_object_ref->subRef();
		}
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
		if (m_object_ref == nullptr)
		{
			return nullptr;
		}
		return this->m_object_ref->addRef();
	}

	void langXObjectRef::update(Object *obj)
	{

	}

	void langXObjectRef::finalize()
	{

	}
}