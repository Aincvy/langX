#include <string>
#include <algorithm>
#include <string.h>

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

		while (m_value.find("\\\"") != std::string::npos)
		{
			// 存在 双引号
			m_value.replace(m_value.find("\\\""), 2, "\"");
		}

		while (m_value.find("\\\'") != std::string::npos)
		{
			// 存在 单引号
			m_value.replace(m_value.find("\\\'"), 2, "\'");
		}

		while (m_value.find("\\\t") != std::string::npos)
		{
			// 存在 制表符
			m_value.replace(m_value.find("\\\t"), 2, "\t");
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
		String *str = new String(this->m_value.c_str());
		str->setEmergeEnv(getEmergeEnv());
		str->setCharacteristic(characteristic());
		str->setConst(this->isConst());
		str->setLocal(this->isLocal());
		return str;
	}
	void String::update(Object *right)
	{
		if (right == NULL || right->getType() != STRING)
		{
			return;
		}
		this->m_value = ((String*)right)->getValue();
	}

	int String::size()
	{
		return this->m_value.size();
	}

	bool String::contains(const char *b)
	{
		auto a = this->m_value.find(b);
		if (a == std::string::npos)
		{
			return false;
		}
		return true;
	}

	bool String::isEmpty() const
	{
		
		return this->m_value.empty();
	}

	std::string String::upperCase() const
	{
		std::string a(this->m_value);

		std::transform(a.begin(), a.end(), a.begin(), ::toupper);

		return a;
	}

	std::string String::lowerCase() const
	{
		std::string a(this->m_value);

		std::transform(a.begin(), a.end(), a.begin(), ::tolower);

		return a;
	}

	int String::indexOf(const char *str)
	{

		int i = this->m_value.find_first_of(str);
		if (i == std::string::npos)
		{
			return -1;
		}
		return i;
	}

	std::string String::subStr(int begin)
	{
		return this->m_value.substr(begin);
	}

	std::string String::subStr(int begin, int len)
	{
		return this->m_value.substr(begin, len);
	}

	std::string String::replace(const char *a, const char *b)
	{
		std::string str(this->m_value);
		auto i = str.find(a);
		int len = strlen(a);
		while (i != std::string::npos)
		{
			str.replace(i , len,b);

			i = str.find(a);
		}
		return str;
	}

	std::string String::replaceFirst(const char *a, const char *b)
	{
		std::string str(this->m_value);
		auto i = str.find(a);
		int len = strlen(a);
		if (i != std::string::npos)
		{
			str.replace(i, len, b);
		}
		return str;
	}

	std::vector<std::string> String::split(const char *delim)
	{
		std::string s = this->m_value;

		std::vector<std::string> elems;
		size_t pos = 0;
		size_t len = s.length();
		size_t delim_len = strlen(delim);
		if (delim_len == 0) return elems;
		while (pos < len)
		{
			int find_pos = s.find(delim, pos);
			if (find_pos < 0)
			{
				elems.push_back(s.substr(pos, len - pos));
				break;
			}
			elems.push_back(s.substr(pos, find_pos - pos));
			pos = find_pos + delim_len;
		}
		return elems;
	}



	void String::finalize()
	{
		delete this;
	}
}