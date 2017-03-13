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
	class XArray;

	// 主要用来申请一个对象
	class Allocator
	{
	public:
		Allocator();
		~Allocator();

		// 复制一个参数对象，  和clone操作差不多
		static Object *copy(Object *);

		static Object *allocate(ObjectType);
		static void free(Object *);

		static Number *allocateNumber();
		static Number *allocateNumber(double );
		static void freeNumber(Number *);

		static String *allocateString();
		static String *allocateString(const char *);
		static void freeString(String *);

		// 申请一个数组
		static XArray *allocateArray(int size);

		static FunctionRef *allocateFunctionRef(Function *);
		static void freeFunctionRef(FunctionRef *);

		static langXObject * newObject(ClassInfo *) ;

		// 垃圾回收
		static void gc();

		// 检测垃圾回收
		static void checkGC();
		
		// 清理掉所有的对象
		static void freeAllObjs();

	private:
		static std::list<langXObject*> m_objects;

		// 对象的申请次数
		static int m_a_count;

		// 申请的对象数量到达这个就进行gc 
		static const int GC_OBJECT_COUNT;
	};


	const int Allocator::GC_OBJECT_COUNT = 1500;
	int Allocator::m_a_count = 0;
	std::list<langXObject*> Allocator::m_objects;

}