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

	// 主要用来申请一个对象
	class Allocator
	{
	public:
		Allocator();
		~Allocator();

		// 复制一个参数对象，  和clone操作差不多
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

		// 垃圾回收
		void gc();

		// 检测垃圾回收
		void checkGC();

	private:
		std::list<langXObject*> m_objects;

		// 对象的申请次数
		int m_a_count = 0;

		// 申请的对象数量到达这个就进行gc 
		const int GC_OBJECT_COUNT = 1500;
	};

}