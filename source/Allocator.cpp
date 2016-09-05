#include <stdio.h>
#include <string>
#include "../include/Object.h"
#include "../include/Number.h"
#include "../include/String.h"
#include "../include/NullObject.h"
#include "../include/Allocator.h"
#include "../include/NullObject.h"
#include "../include/Function.h"
#include "../include/ClassInfo.h"
#include "../include/langXObjectRef.h"

namespace langX {
	Allocator::Allocator()
	{
	}
	Allocator::~Allocator()
	{
	}

	Object * Allocator::copy(Object *obj) const
	{
		if (obj == NULL)
		{
			return NULL; 
		}
		if (obj->getType() == FUNCTION )
		{
			return  obj;
		}
		Object *ret = allocate(obj->getType());
		if (ret == NULL)
		{
			return NULL;
		}

		ret->setEmergeEnv(obj->getEmergeEnv());
		ret->update(obj);
		return ret;
	}

	Object * Allocator::allocate(ObjectType t) const
	{
		if (t == ObjectType::UNKNOWN)
		{
			return NULL;
		}
		else if (t == ObjectType::NUMBER)
		{
			return new Number();
		}
		else if (t == ObjectType::STRING)
		{
			return new String("");
		}
		else if (t == ObjectType::NULLOBJECT )
		{
			return new NullObject();
		}
		else if (t == ObjectType::OBJECT)
		{
			return new langXObjectRef(NULL);
		}

		return NULL;
	}

	void Allocator::free(Object *obj) const
	{
		if (obj == NULL)
		{
			return;
		}
		if (obj->getType() == NUMBER)
		{
			delete (Number*)obj;
		}
		else if (obj->getType() == STRING)
		{
			delete (String*)obj;
		}else if(obj->getType() == OBJECT){
			delete (langXObjectRef*)obj;
		}
		else if (obj->getType() == NULLOBJECT)
		{
			delete (NullObject*)obj;
		}
		else if (obj->getType() == FUNCTION)
		{
			// do nothing in free funtion.
		}
	}
	
	Number * Allocator::allocateNumber() const
	{
		return new Number();
	}
	Number * Allocator::allocateNumber(double v) const
	{
		return new Number(v);
	}
	void Allocator::freeNumber(Number *v)
	{
		if (v == NULL)
		{
			return;
		}
		delete v;
	}

	String * Allocator::allocateString() const
	{
		return new String("");
	}

	String * Allocator::allocateString(const char *str) const
	{
		return new String(str);
	}

	void Allocator::freeString(String *str)
	{
		if (str == NULL)
		{
			return;
		}
		delete str;
	}


}