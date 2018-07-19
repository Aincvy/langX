#include <memory>
#include <stdio.h>
#include "../include/XArray.h"
#include "../include/NullObject.h"
#include "../include/Allocator.h"
#include "../include/YLlangX.h"
#include "../include/Exception.h"
#include "../include/langXObject.h"
#include "../include/langXThread.h"

extern langX::Allocator m_exec_alloc;

namespace langX {

	XArray::XArray(int length)
	{
		if (length <= 0)
		{
			// maybe should throw a execption... 
			return;
		}

		this->m_ref_count = 0;
		this->m_length = length;
		this->m_array = (Object**)calloc(length, sizeof(Object*));

		for (int i = 0; i < length; i++)
		{
			this->m_array[i] = new NullObject();
		}

		//printf("new XArray\n");
	}

	XArray::~XArray()
	{
		free(this->m_array);
		this->m_array = NULL;
	}

	int XArray::getLength() const
	{
		return this->m_length;
	}

	Object * XArray::at(int index) const
	{
		if (index < 0)
		{
			return nullptr;
		}
		if (index >= this->m_length)
		{
			return nullptr;
		}

		return this->m_array[index];
	}

	void XArray::set(int index, Object *obj)
	{
		if (index < 0 || index >= m_length)
		{
			char tmp[100] = { 0 };
			sprintf(tmp, "array index of bounds: %d", index);
			getState()->curThread()->throwException(newIndexOutOfBoundsException(tmp)->addRef());
			return;
		}

		if ((obj == NULL || obj->getType() == NULLOBJECT) && this->m_array[index]->getType() == NULLOBJECT)
		{
			return;
		}

		Object *old = this->m_array[index];

		if (old->getType() == obj->getType())
		{
			if (old->getType() == FUNCTION)
			{
				this->m_array[index] = obj->clone();
			}
			else {
				old->update(obj);
			}

		}
		else {
			this->m_array[index] = obj->clone();
			m_exec_alloc.free(old);
		}
	}

	XArrayRef * XArray::addRef()
	{
		m_ref_count++;
		return new XArrayRef(this);
	}

	void XArray::subRef()
	{
		this->m_ref_count--;
	}

	int XArray::getRefCount() const
	{
		return this->m_ref_count;
	}



	XArrayRef::XArrayRef(XArray *a)
	{
		this->m_array = a;
		//printf("new XArrayRef\n");
	}

	XArrayRef::~XArrayRef()
	{
		//printf("delete XArrayRef\n");
		if (this->m_array != nullptr)
		{
			this->m_array->subRef();
		}
	}

	XArray * XArrayRef::getArray() const
	{
		return this->m_array;
	}

	Object * XArrayRef::at(int index) const
	{
		if (this->m_array == nullptr)
		{
			return nullptr;
		}
		return this->m_array->at(index);
	}

	void XArrayRef::set(int index, Object * obj)
	{
		if (this->m_array == nullptr)
		{
			return;
		}

		this->m_array->set(index, obj);
	}

	int XArrayRef::getLength() const
	{
		if (this->m_array == nullptr)
		{
			return -1;
		}
		this->m_array->getLength();
	}

	bool XArrayRef::isTrue() const
	{
		if (this->m_array == nullptr)
		{
			return false;
		}
		return true;
	}

	ObjectType XArrayRef::getType() const
	{
		return XARRAY;
	}

	Object * XArrayRef::clone() const
	{
		if (this->m_array == nullptr)
		{
			Object *ret = new XArrayRef(nullptr);
			ret->setEmergeEnv(this->getEmergeEnv());
			ret->setCharacteristic(characteristic());
			return ret;
		}
		Object * obj = this->m_array->addRef();
		obj->setEmergeEnv(this->getEmergeEnv());
		obj->setCharacteristic(characteristic());
		obj->setConst(this->isConst());
		obj->setLocal(this->isLocal());
		obj->setName(this->getName());
		return obj;
	}

	void XArrayRef::update(Object * obj)
	{
		if (obj == NULL || obj->getType() != XARRAY)
		{
			getState()->curThread()->throwException(newException("Inner Error! cannot update.. target is not array!")->addRef());
			//printf("cannot update.. target is not array\n");
			return;
		}

		if (this->m_array != nullptr)
		{
			this->m_array->subRef();
			this->m_array = nullptr;
		}

		this->m_array = ((XArrayRef*)obj)->getArray();
	}

	void XArrayRef::finalize()
	{
	}

}