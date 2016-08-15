#pragma once
#include "Object.h"
#include <string>

namespace langX {

	// 字符串对象
	// 默认值为 空字符串 而不是 null
	// 07-24  当前对象并没进行实现， 请暂时不要使用
	class String : public Object
	{
	public:
		String(const char *);
		~String();

		//  将参数的值追加到当前字符串的后面
		void add(const char*);
		//  将参数的值追加到当前字符串的后面
		void add(String *);

		const char * getValue() const;

		const std::string & getStrValue() const;

		// 对当前字符串进行转义。   \n 会变成换行符
		void simpleEscape();

		// 如果当前字符串 为字符串则返回 false , 否则返回null 
		bool isTrue() const;

		ObjectType getType() const;

		Object* clone() const;

		void update(Object *);

	private:
		std::string m_value;

		void finalize();
	};

}