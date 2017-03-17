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
#include "../include/langXObject.h"
#include "../include/langXObjectRef.h"
#include "../include/XArray.h"

namespace langX {

	const int Allocator::GC_OBJECT_COUNT = 1500;
	int Allocator::m_a_count = 0;
	std::list<langXObject*> Allocator::m_objects;

	Allocator::Allocator()
	{
	}
	Allocator::~Allocator()
	{
	}

	Object * Allocator::copy(Object *obj)
	{
		if (obj == NULL)
		{
			return NULL; 
		}

		Object *ret = allocate(obj->getType());
		if (ret == NULL)
		{
			return NULL;
		}

		ret->setEmergeEnv(obj->getEmergeEnv());
		ret->setCharacteristic(obj->characteristic());
		ret->setLocal(obj->isLocal());
		ret->setConst(obj->isConst());
		ret->update(obj);
		return ret;
	}

	Object * Allocator::allocate(ObjectType t)
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
		else if (t == ObjectType::XARRAY)
		{
			return new XArrayRef(NULL);
		}
		else if (t == ObjectType::FUNCTION)
		{
			return new FunctionRef(NULL);
		}

		return NULL;
	}

	void Allocator::free(Object *obj)
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
			delete (FunctionRef*) obj;
		}
		else if (obj->getType() == XARRAY)
		{
			delete (XArrayRef *) obj;
		}
	}
	
	Number * Allocator::allocateNumber()
	{
		return new Number();
	}
	Number * Allocator::allocateNumber(double v)
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

	String * Allocator::allocateString()
	{
		return new String("");
	}

	String * Allocator::allocateString(const char *str)
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

	XArray * Allocator::allocateArray(int size)
	{
		return new XArray(size);
	}

	FunctionRef * Allocator::allocateFunctionRef(Function *f)
	{
		return new FunctionRef(f);
	}

	void Allocator::freeFunctionRef(FunctionRef *f)
	{
		delete f;
	}

	langXObject * Allocator::newObject(ClassInfo *c)
	{
		checkGC();

		//printf("new object %s . now object count: %d\n" ,c->getName(), m_a_count);
		langXObject *p = new langXObject(c);
		m_objects.push_back(p);
		m_a_count++;
		
		return p;
	}

	void Allocator::gc()
	{
		printf("gc start \n");

		int count = 0;
		for (auto i = m_objects.begin(); i != m_objects.end(); i++)
		{
			langXObject *obj = (*i);
			if (obj->getRefCount() <= 0)
			{
				delete obj;
				m_objects.erase(i++);
				count++;
			}
		}

		m_a_count -= count;
		printf("free %d object(s)\n" , count);
	}



	void Allocator::checkGC()
	{

		if (m_a_count >= GC_OBJECT_COUNT)
		{
			gc();
		}
		
	}

	void Allocator::freeAllObjs()
	{
		for (auto i = m_objects.begin(); i != m_objects.end(); i++)
		{
			langXObject *obj = (*i);
			delete obj;
		}

		m_objects.clear();
		m_a_count = 0;
	}


}