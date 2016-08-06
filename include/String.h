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
		String(const char *);
		~String();

		//  ��������ֵ׷�ӵ���ǰ�ַ����ĺ���
		void add(const char*);
		//  ��������ֵ׷�ӵ���ǰ�ַ����ĺ���
		void add(String *);

		const char * getValue();

		// �����ǰ�ַ��� Ϊ�ַ����򷵻� false , ���򷵻�null 
		bool isTrue() const;

		ObjectType getType() const;

		Object* clone() const;

		void update(Object *);

	private:
		std::string m_value;

		void finalize();
	};

}