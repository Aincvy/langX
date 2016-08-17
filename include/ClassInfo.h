#pragma once
#include <map>
#include <string>

/*
 *  date: 2016-08-17
 *  author: hideDragon
 *  file: ClassInfo.h 
 *
 *  desc: ����Ϣ
 */

namespace langX {
	class Object;
	class Function;

	class ClassInfo 
	{
	public:
		ClassInfo(const char*);
		~ClassInfo();

		void addMember(const char*, Object *);
		// �Ƿ�����Ǹ� ��Ա
		bool hasMember(const char*) const;
		Object * getMember(const char *) const;

		void addFunction(const char*, Function*);
		bool hasFunction(const char*) const;
		Function * getFunction(const char *) const;

		const char * getName() const;

	private:
		//  ��ǰ��� �ֶ�map ...
		//  key:  ������,  value:  ����ָ��
		std::map<std::string, Object*> m_members;
		std::map<std::string, Function*> m_functions;

		// ��ǰ���ʲô����
		std::string m_name;
	};

}