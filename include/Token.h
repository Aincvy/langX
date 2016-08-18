#pragma once
#include <string>

/*
*   创建时间：  2016-07-04
*   作者： The World(world@aincvy.com)
*
*   文件描述：
*   描述：     保存某个单词的具体信息
*/

namespace langX {
	/* 保存某个单词的具体信息 */
	class Token
	{
	public:
		Token(int line_number);
		~Token();

		int getLineNumber() const;

		bool isNumber() const;
		bool isString() const;
		bool isIdentifier() const;
		std::string getText() const;

	private:
		// 2016-07-04  文件名相关信息 暂不启用
		std::string m_filename;
		int m_line_number;
		std::string m_text;
	};

}