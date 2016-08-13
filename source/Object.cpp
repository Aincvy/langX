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
	bool Object::isLocal() const
	{
		return this->m_is_local;
	}
	bool Object::isPrivate() const
	{
		return this->m_is_private;
	}
	bool Object::isPublic() const
	{
		return this->m_is_public;
	}
}