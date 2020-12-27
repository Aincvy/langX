#pragma once
#include <list>
#include <map>
#include <string>


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
	class langXObjectExtend;

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

		// 布尔类型
		static Number* allocateTrue();
		static Number* allocateFalse();

		static String *allocateString();
		static String *allocateString(const char *);
		static String *allocateString(std::string);
		static String *allocateString(const char*, int);
		static void freeString(String *);

		static Object* allocateNull();

		// 申请一个数组
		static XArray *allocateArray(int size);

		static FunctionRef *allocateFunctionRef(Function *);
		static void freeFunctionRef(FunctionRef *);

		/**
		 * 根据类名创建一个该类得对象 ， 会调用该类得构造函数
		 * @return
		 */
		static langXObject * newObject(const char *);

		/**
		 * 根据类名创建一个该类得对象 | 第二个参数可以指定是否调用构造函数
		 * @return
		 */
		static langXObject * newObject(const char*, bool );
		// 创建一个对象 
		static langXObject * newObject(ClassInfo *, bool extend,bool callCtor);

		/**
		 *  创建一个对象
		 * @return
		 */
		static langXObject * newObject(ClassInfo *) ;

		/**
		 * 创建该类得对象， 并调用该类得构造函数
		 * @return
		 */
        static langXObject * newObjectWithCtor(ClassInfo *clz) ;

		static langXObjectExtend * newExtendObject(ClassInfo * );			// 创建一个具有拓展能力的对象
		static void freeObject(langXObject *);                                     //  释放掉一个对象

		// 垃圾回收
		static void gc();

		// 检测垃圾回收
		static void checkGC();
		
		// 清理掉所有的对象
		static void freeAllObjs();

		// 检测数组是否有无引用的情况
		static void checkArrayGC();

		// 回收数组的垃圾
		static void arrayGC();

	private:
		// key: 对象的特征字符串, value:  对象
		static std::map<std::string, langXObject*> m_object_map;
		static std::list<XArray*> m_arrays;

		// 对象的申请次数
		static int m_a_count;

		// 申请的对象数量到达这个就进行gc 
		static const int GC_OBJECT_COUNT;
	};

}
