#pragma once
#include <string>

/*
*   ����ʱ�䣺  2016-07-04
*   ���ߣ� The World(world@aincvy.com)
*
*   �ļ�������
*   ������     ����ĳ�����ʵľ�����Ϣ
*/

namespace langX {
	/* ����ĳ�����ʵľ�����Ϣ */
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
		// 2016-07-04  �ļ��������Ϣ �ݲ�����
		std::string m_filename;
		int m_line_number;
		std::string m_text;
	};

}