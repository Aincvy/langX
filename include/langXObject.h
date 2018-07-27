#pragma once
#include <map>
#include <vector>
#include <string>

namespace langX {

	class Object;
	class ClassInfo;
	class langXObjectRef;
	class ObjectBridgeEnv;
	class Environment;
	class Function;
	class langXThread;
	struct NodeLink;

	/*
	 * langXObject  与object 独立分开
	 */
	class langXObject 
	{
	public:
		langXObject(ClassInfo *);
		virtual ~langXObject();

		// 判断这个对象是否是指定的类型
		bool typeCheck(const char *) const;

		//  设置 arg1 的值为 arg2 ，如果arg1的类型和arg2的类型不一样， 会释放arg1的内存
		//  更新arg1 为arg2 或者 设置arg1 为 arg2 的一个副本
		void setMember(const char*, Object *);
		//  这个请求是否是来自子类 
		void setMember(const char*, Object *,bool);
		//  是否存在某个成员
		bool hasMember(const char *) const;

		Object * getMember(const char *) const;
		//  这个请求是否是来自子类 
		Object * getMember(const char *,bool) const;
		//  获得这个对象的属性和值的 map 
		const std::map<std::string, Object*> & getMemberMap() const;

		virtual Function *getFunction(const char *) const;
		//  这个请求是否是来自子类 
		Function *getFunction(const char *,bool) const;
		
		// 获得类信息
		const ClassInfo * getClassInfo() const;
		// 获得类名字
		const char * getClassName() const;

		// 只是自增一个自己的引用次数
		void justAddRef(langXObjectRef *);
		// 生成一个引用， 引用到这个对象身上
		langXObjectRef * addRef();
		//  减少一个引用计数
		void subRef();
		//  减少一个引用计数
		void subRef(langXObjectRef *);
		//  获得当前对象的引用次数
		int getRefCount() const;

		// 获得构造函数
		Function * getConstructor() const;
		// 调用这个类的构造函数
		void callConstructor(ArgsList *, const char *, NodeLink *, langXThread *);

		// 调用这个类的构造函数  | 给第三方库使用的，强制执行构造函数
		void callConstructor(ArgsList *, const char * );

		// 调用无参函数 ,如果找不到函数，直接返回NULL
		Object * callFunction(const char*) const;

		// 设置这个对象的成员的产生环境
		void setMembersEmergeEnv(Environment *);

		// 获得类的环境
		Environment *getObjectEnvironment() const;

		// 获得引用记数小于等于0的时间
		long getZeroRefTime() const;

		// 设置第三方对象
		void set3rdObj(void *);

		// 获得第三方对象
		void * get3rdObj() const; 

		// 返回这个对象的特性字符串
		const char * characteristic() const;

		// 此对象是否在销毁中
		bool isDisposing() const;

	protected:
		// 当前对象的成员列表
		std::map<std::string, Object*> m_members;

	private:

		// 引用的那些引用
		std::vector<langXObjectRef*> m_refs;

		ClassInfo *m_class_info;
		// 当前对象的环境
		ObjectBridgeEnv *m_my_env;
		int  m_ref_count = 0;
		// 引用变成0，及负数的时间
		long m_zero_ref_time = 0;
		// 父类的对象
		langXObject *m_parent = nullptr;

		// 引用的第三方对象
		void *m_3rdObj; 

		// 这个对象的特性字符串
		std::string m_characteristic;

		// 此对象是否在销毁中
		bool m_disposing = false;
	};


	// 具有扩展能力的 langXObject
	class langXObjectExtend : public langXObject {

	public:
		langXObjectExtend(ClassInfo *);
		~langXObjectExtend();

		// 添加一个成员到对象里面
		void addMember(const char *, Object *);

		// 添加一个函数到成员里面
		void addFunction(const char*, Function *);

		Function *getFunction(const char *) const;

	private:
		// key: 函数名, value: 函数
		std::map<std::string, Function*> m_function_map;
	};

}