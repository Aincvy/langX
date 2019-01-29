#pragma once
#include "Object.h"

namespace langX {

	class XArrayRef;

	/*  �������������֮�����ʹ�� */

	//  ����
	class XArray
	{
	public:

		// ʹ����Ӧ��ʹ�� Allocator::allocateArray() ����������һ�����飬 ������ֱ�� new 
		XArray(int length);
		~XArray();

		int getLength() const;

		Object * at(int index) const;

		// ��set ��ʱ�����һ�� obj �ĸ���
		void set(int index, Object *);

		// ���һ������ĩβ
		bool add(Object *);

		// ֻ������һ���Լ������ô���
		//void justAddRef();
		// ����һ�����ã� ���õ������������
		XArrayRef * addRef();
		//  ����һ������
		void subRef();
		//  ��õ�ǰ��������ô���
		int getRefCount() const;

		// ��¡��ǰ���� | ��ȿ�¡
		XArray *clone() const;

	private:
		Object** m_array = nullptr;
		int m_length = 0;
		// ������Ӻ�����ʱ�� �α�
		int m_add_cursor = 0;

		int  m_ref_count = 0;
	};

	// дһ����ȡ�  ��������
	class XArrayRef : public Object
	{
	public:
		XArrayRef(XArray * );
		~XArrayRef();

		XArray * getArray() const;

		Object * at(int index) const;
		// ��set ��ʱ�����һ�� obj �ĸ���
		void set(int index, Object *);
		int getLength() const;

		/* ��ǰֵ���Ա�ʾΪ��ô��  null,0,false �������ʾΪ��  */
		bool isTrue() const ;
		/* ��õ�ǰ���������  */
		ObjectType getType() const ;
		/* ��¡��ǰ���� ���س�һ���µĶ��� */
		Object* clone() const ;
		Object* clone(bool) const;

		/* ���Լ�Update ��Ŀ���ֵ
		���������Ӧ�ã� Ҳ����update ���ڵĻ���   */
		void update(Object *) ;

	private:

		void finalize();

		XArray* m_array;

	};


}