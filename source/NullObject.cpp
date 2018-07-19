#include <string>

#include "../include/Object.h"
#include "../include/NullObject.h"

namespace langX {

	NullObject::NullObject()
	{
		setCharacteristic("no_pointer_to_anything");
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
		obj->setCharacteristic(characteristic());
		obj->setConst(this->isConst());
		obj->setLocal(this->isLocal());
		obj->setName(this->getName());
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