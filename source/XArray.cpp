#include <memory>
#include <stdio.h>

#include "XArray.h"
#include "NullObject.h"
#include "Allocator.h"
#include "NodeCreator.h"
#include "Exception.h"
#include "langXObject.h"
#include "langXThread.h"


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

		if ((obj == nullptr || obj->getType() == NULLOBJECT) && this->m_array[index]->getType() == NULLOBJECT)
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
            Allocator::free(old);
		}
	}

	bool XArray::add(Object *obj)
	{
		if (this->m_add_cursor >= this->m_length)
		{
			return false;
		}

		set(this->m_add_cursor++, obj);

		return true;
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

	XArray * XArray::clone() const
	{
		XArray *arr = Allocator::allocateArray(this->m_length);

		for (size_t i = 0; i < this->m_length; i++)
		{
			Object *obj = at(i);
			if (obj->getType() == ObjectType::XARRAY)
			{
				XArrayRef *xar = (XArrayRef*)obj;

				XArray *nxa = xar->getArray()->clone();
				XArrayRef nxar(nxa);
				arr->set(i, &nxar);

			}
			else {
				arr->set(i, obj);
			}

		}

		return arr;
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

		return this->m_array->getLength();
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

	Object * XArrayRef::clone(bool flag) const
	{
		if (!flag || this->m_array == nullptr)
		{
			return  clone();
		}

		Object * obj = this->m_array->clone()->addRef();
		obj->setEmergeEnv(this->getEmergeEnv());
		obj->setCharacteristic(characteristic());
		obj->setConst(this->isConst());
		obj->setLocal(this->isLocal());
		obj->setName(this->getName());
		return obj;
	}

	void XArrayRef::update(const Object * obj)
	{
		if (obj == NULL || obj->getType() != XARRAY)
		{
			getState()->curThread()->throwException(newException("Inner Error! cannot update.. target is not array!")->addRef());
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