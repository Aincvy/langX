#include "../include/Object.h"

namespace langX {
	Object::Object()
	{
		this->m_ref_count = 0;
	}
	Object::~Object()
	{
	}
	void Object::incRefCount()
	{
		this->m_ref_count++;
	}
	void Object::decRefCount()
	{
		if (--this->m_ref_count <= 0) {
			this->finalize();
		}
	}
}