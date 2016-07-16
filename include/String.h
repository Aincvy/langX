#pragma once
#include "Object.h"
#include <string>

namespace langX {

	// 字符串对象
	// 默认值为 空字符串 而不是 null
	class String : public Object
	{
	public:
		String(char *);
		~String();

		const char * getValue();

		// 如果当前字符串 为字符串则返回 false , 否则返回null 
		bool isTrue() const;

		ObjectType getType() const;

	private:
		std::string m_value;
	};

}