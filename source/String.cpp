#include "../include/String.h"

namespace langX {
	String::String(const char *v)
	{
		this->m_value = std::string(v);
	}
	String::~String()
	{

	}
	void String::add(const char * str)
	{
		this->m_value += str;
	}
	void String::add(String *str)
	{
		add(str->getValue());
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
		return new String(this->m_value.c_str());
	}
	void String::update(Object *right)
	{
		if (right == NULL || right->getType() != STRING)
		{
			return;
		}
		this->m_value = ((String*)right)->getValue();
	}

	void String::finalize()
	{
		delete this;
	}
}