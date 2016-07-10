#include "../include/Object.h"

namespace langX {
	Object::Object()
	{
	}
	Object::~Object()
	{
	}
	ObjectType Object::getType() const
	{
		return UNKNOWN;
	}
}