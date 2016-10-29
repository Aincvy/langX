#include "../include/Object.h"
#include "../include/DestroyedObject.h"

namespace langX {

	// 被销毁的对象。  没什么好实现的内容。。 

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