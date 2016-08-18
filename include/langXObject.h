#pragma once
#include <map>
#include <string>

namespace langX {

	class Object;
	class ClassInfo;
	class langXObjectRef;

	/*
	 * langXObject  ��object �����ֿ�
	 */
	class langXObject 
	{
	public:
		langXObject(ClassInfo *);
		~langXObject();

		void setMember(const char*, Object *);
		Object * getMember(const char *) const;
		Function *getFunction(const char *) const;
		// �������Ϣ
		const ClassInfo * getClassInfo() const;


		// ����һ�����ã� ���õ������������
		langXObjectRef * addRef();
		//  ����һ������
		void subRef();
		//  ��õ�ǰ��������ô���
		int getRefCount() const;

	private:

		std::map<std::string, Object*> m_members;
		ClassInfo *m_class_info;
		int  m_ref_count = 0;
	};

}