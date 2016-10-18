#include "../include/Object.h"
#include "../include/DestroyedObject.h"

namespace langX {



	DestroyedObject::DestroyedObject()
	{
	}

	DestroyedObject::~DestroyedObject()
	{
	}

	bool DestroyedObject::isTrue() const
	{
		return false;
	}

	ObjectType DestroyedObject::getType() const
	{
		return ObjectType::DESTROYEDOBJECT;
	}

	Object * DestroyedObject::clone() const
	{
		return new DestroyedObject();
	}

	void DestroyedObject::update(Object *)
	{
	}

	void DestroyedObject::finalize()
	{

	}

}