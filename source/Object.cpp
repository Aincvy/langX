#include <string>
#include "../include/Object.h"
#include "../include/Utils.h"

namespace langX {

	Object::Object()
	{
		this->m_ref_count = 0;
		
		char t[100];
		randomCharacteristic(t, 100, this, 8);
		this->m_characteristic = std::string(t);
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

	Environment * Object::getEmergeEnv() const
	{
		return this->m_emerge_env;
	}

	void Object::setEmergeEnv(Environment *env)
	{
		this->m_emerge_env = env;
	}

	const char * Object::getName() const
	{
		return this->m_name.c_str();
	}

	void Object::setName(std::string name)
	{
		this->m_name = name;
	}

	const char * Object::characteristic() const
	{
		return this->m_characteristic.c_str();
	}

	void Object::setCharacteristic(const char *a)
	{
		this->m_characteristic = std::string(a);
	}

}