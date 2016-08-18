#include <string>
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
	const char * String::getValue() const
	{
		return m_value.c_str();
	}
	const std::string & String::getStrValue() const
	{
		return this->m_value;
	}
	void String::simpleEscape()
	{
		// TODO  \\n  变成 \n  两个字符
		while (m_value.find("\\n") != std::string::npos)
		{
			// 存在换行符
			m_value.replace(m_value.find("\\n") , 2, "\n");
		}
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