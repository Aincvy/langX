#include <string>
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

	void Object::setName(const char *x)
	{
		this->m_name = std::string(x);
	}
	const char * Object::getName() const
	{
		return this->m_name.c_str();
	}
}