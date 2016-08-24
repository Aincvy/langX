#include <memory>
#include "../include/XArray.h"

namespace langX {

	XArray::XArray(int length)
	{
		this->m_length = length;
		this->m_array = (Object**)calloc(length, sizeof(Object*));
	}

	XArray::~XArray()
	{
		free(this->m_array);
		this->m_array = NULL;
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

	}

	void XArray::justAddRef()
	{
		this->m_ref_count++;
	}

	XArrayRef * XArray::addRef()
	{
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
	}

	XArrayRef::~XArrayRef()
	{
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
			return nullptr;
		}
		return this->m_array->addRef();
	}

	void XArrayRef::update(Object *)
	{
	}

	void XArrayRef::finalize()
	{
	}

}