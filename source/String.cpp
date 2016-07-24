#include "../include/String.h"

namespace langX {
	String::String(char *v)
	{
		this->m_value = std::string(v);
		free(v);
	}
	String::~String()
	{

	}
	const char * String::getValue()
	{
		return m_value.c_str();
	}
	bool String::isTrue() const
	{
		return this->m_value.length() != 0;
	}
	ObjectType String::getType() const
	{
		return ObjectType::STRING;
	}
	Object * String::clone() const
	{
		return nullptr;
	}
	void String::finalize()
	{
		delete this;
	}
}