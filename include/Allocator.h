#pragma once
#include <list>

namespace langX {
	class Object;
	enum ObjectType;
	class Number;
	class String;
	class FunctionRef;
	class Function;
	class langXObject;
	class ClassInfo;

	// ��Ҫ��������һ������
	class Allocator
	{
	public:
		Allocator();
		~Allocator();

		// ����һ����������  ��clone�������
		Object *copy(Object *) const;

		Object *allocate(ObjectType) const;
		void free(Object *) const;

		Number *allocateNumber() const;
		Number *allocateNumber(double ) const;
		void freeNumber(Number *);

		String *allocateString() const;
		String *allocateString(const char *) const;
		void freeString(String *);

		FunctionRef *allocateFunctionRef(Function *) const;
		void freeFunctionRef(FunctionRef *) const;

		langXObject * newObject(ClassInfo *) ;

		// ��������
		void gc();

		// �����������
		void checkGC();

	private:
		std::list<langXObject*> m_objects;

		// ������������
		int m_a_count = 0;

		// ����Ķ���������������ͽ���gc 
		const int GC_OBJECT_COUNT = 1500;
	};

}