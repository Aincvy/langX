#pragma once
#include "Object.h"
#include <string>
#include <vector>

namespace langX {

	// 字符串对象
	// 默认值为 空字符串 而不是 null
	class String : public Object
	{
	public:
		String(const char *);
		String(std::string );
		String(const char *, int);
		~String();

		//  将参数的值追加到当前字符串的后面
		void add(const char*);
		//  将参数的值追加到当前字符串的后面
		void add(String *);

		const char * getValue() const;

		const std::string & getStrValue() const;

        // 如果当前字符串 为字符串则返回 false , 否则返回null
		bool isTrue() const;

		ObjectType getType() const;

		Object* clone() const;

		void update(Object *);

		// 获得这个字符串的长度
		int size();

		// 是否包含某字符串
		bool contains(const char *);

		// 是否为空字符串
		bool isEmpty() const;

		// 转换成大写
		std::string upperCase() const;

		// 转换成小写
		std::string lowerCase() const;

		// find return index, else return -1
		int indexOf(const char *);

		std::string subStr(int begin);

		std::string subStr(int begin, int len);

		// 把参数1 替换成 参数2 ,当前字符串不变
		std::string replace(const char *, const char *);

		std::string replaceFirst(const char *, const char *);

		// 分割字符串
		std::vector<std::string> split(const char *);


		void trim();

		// 获得这个字符串的特性字符串 
		const char * characteristic() const;

	private:
		std::string m_value;

		void finalize();


		const char *ccPrefix = "string@[";

	};

}