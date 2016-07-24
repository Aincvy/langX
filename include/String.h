#pragma once
#include "Object.h"
#include <string>

namespace langX {

	// �ַ�������
	// Ĭ��ֵΪ ���ַ��� ������ null
	// 07-24  ��ǰ����û����ʵ�֣� ����ʱ��Ҫʹ��
	class String : public Object
	{
	public:
		String(char *);
		~String();

		const char * getValue();

		// �����ǰ�ַ��� Ϊ�ַ����򷵻� false , ���򷵻�null 
		bool isTrue() const;

		ObjectType getType() const;

		Object* clone() const;

	private:
		std::string m_value;

		void finalize();
	};

}