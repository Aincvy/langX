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
#include "../include/YLlangX.h"
#include "../include/XNameSpace.h"

namespace langX {
	const int Allocator::GC_OBJECT_COUNT = 85000;
	int Allocator::m_a_count = 0;
	std::list<XArray*> Allocator::m_arrays;
	std::map<std::string, langXObject*> Allocator::m_object_map;

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
		else if (t == ObjectType::NULLOBJECT)
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
		}
		else if (obj->getType() == OBJECT) {
			delete (langXObjectRef*)obj;
		}
		else if (obj->getType() == NULLOBJECT)
		{
			delete (NullObject*)obj;
		}
		else if (obj->getType() == FUNCTION)
		{
			delete (FunctionRef*)obj;
		}
		else if (obj->getType() == XARRAY)
		{
			delete (XArrayRef *)obj;
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

	Object * Allocator::allocateNull()
	{
		return allocate(ObjectType::NULLOBJECT);
	}

	XArray * Allocator::allocateArray(int size)
	{
		checkArrayGC();

		XArray *a = new XArray(size);
		m_arrays.push_back(a);

		return a;
	}

	FunctionRef * Allocator::allocateFunctionRef(Function *f)
	{
		return new FunctionRef(f);
	}

	void Allocator::freeFunctionRef(FunctionRef *f)
	{
		delete f;
	}

	langXObject * Allocator::newObject(const char *path) {
		return Allocator::newObject(path, false);
	}

	langXObject * Allocator::newObject(const char *path, bool callCtor) {
		ClassInfo *c = getState()->getClassByFullName(path);
		return Allocator::newObject(c, false, callCtor);
	}

	langXObject * Allocator::newObject(ClassInfo *c) {
		return Allocator::newObject(c,false, false);
	}

	langXObjectExtend * Allocator::newExtendObject(ClassInfo *c)
	{
		return (langXObjectExtend*) newObject(c, true, true);
	}

	langXObject * Allocator::newObject(ClassInfo *c, bool extend, bool callCtor)
	{
		checkGC();

		//printf("new object %s . now object count: %d\n" ,c->getName(), m_a_count);
		langXObject *p;
		if (extend)
		{
			p = new langXObjectExtend(c);
		}
		else {
			p = new langXObject(c);
		}
		m_object_map[std::string(p->characteristic())] = p;
		m_a_count++;

		if (callCtor) {
			p->callConstructor(nullptr, "default initialization by Allocator");
		}

		return p;
	}

	void Allocator::freeObject(langXObject *obj)
	{
		if (obj == nullptr) {
			return;
		}

		std::string str(obj->characteristic());
		m_object_map.erase(str);

		delete obj;       // 解放对象占用的内存
	}

	void Allocator::gc()
	{
		printf("gc start \n");

		int count = 0;
		for (auto i = m_object_map.begin(); i != m_object_map.end(); i++)
		{
			langXObject *obj = i->second;
			if (obj->getRefCount() <= 0)
			{
				delete obj;
				m_object_map.erase(i++);
				count++;
			}
		}

		m_a_count -= count;
		printf("free %d object(s)\n", count);
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
		for (auto i = m_object_map.begin(); i != m_object_map.end(); i++)
		{
			langXObject *obj = i->second;
			delete obj;
		}

		m_object_map.clear();
		m_a_count = 0;
	}

	void Allocator::checkArrayGC()
	{
		if (m_arrays.size() > GC_OBJECT_COUNT)
		{
			arrayGC();
		}
	}

	void Allocator::arrayGC()
	{
		int count = 0;
		for (auto i = m_arrays.begin(); i != m_arrays.end(); i++)
		{
			XArray * a = *i;
			if (a->getRefCount() <= 0)
			{
				delete a;
				m_arrays.erase(i++);
				count++;
			}
		}

		printf("free %d array \n", count);
	}
}