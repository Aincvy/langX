#include <string>

#include "../include/Object.h"
#include "../include/NullObject.h"

namespace langX {

	NullObject::NullObject()
	{
	}
	NullObject::~NullObject()
	{
	}
	bool NullObject::isTrue() const
	{
		return false;
	}
	ObjectType NullObject::getType() const
	{
		return NULLOBJECT;
	}
	Object * NullObject::clone() const
	{
		NullObject *obj = new NullObject();
		obj->setEmergeEnv(getEmergeEnv());
		return obj;
	}
	void NullObject::update(Object *)
	{
		// do nothing.
	}
	void NullObject::finalize()
	{
	}

}