#pragma once
#include "Object.h"
#include <string>

namespace langX {

	// �ַ�������
	// Ĭ��ֵΪ ���ַ��� ������ null
	class String : public Object
	{
	public:
		String(char *);
		~String();

		const char * getValue();

		// �����ǰ�ַ��� Ϊ�ַ����򷵻� false , ���򷵻�null 
		bool isTrue() const;

		ObjectType getType() const;

	private:
		std::string m_value;
	};

}