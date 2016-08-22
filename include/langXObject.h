#pragma once
#include <map>
#include <string>

namespace langX {

	class Object;
	class ClassInfo;
	class langXObjectRef;
	class ObjectBridgeEnv;
	class Environment;

	/*
	 * langXObject  与object 独立分开
	 */
	class langXObject 
	{
	public:
		langXObject(ClassInfo *);
		~langXObject();

		//  设置 arg1 的值为 arg2 ，如果arg1的类型和arg2的类型不一样， 会释放arg1的内存
		//  更新arg1 为arg2 或者 设置arg1 为 arg2 的一个副本
		void setMember(const char*, Object *);
		//  这个请求是否是来自子类 
		void setMember(const char*, Object *,bool);

		Object * getMember(const char *) const;
		//  这个请求是否是来自子类 
		Object * getMember(const char *,bool) const;

		Function *getFunction(const char *) const;
		//  这个请求是否是来自子类 
		Function *getFunction(const char *,bool) const;
		
		// 获得类信息
		const ClassInfo * getClassInfo() const;

		// 只是自增一个自己的引用次数
		void justAddRef();
		// 生成一个引用， 引用到这个对象身上
		langXObjectRef * addRef();
		//  减少一个引用
		void subRef();
		//  获得当前对象的引用次数
		int getRefCount() const;

		// 获得构造函数
		Function * getConstructor() const;

		// 调用无参函数 ,如果找不到函数，直接返回NULL
		Object * callFunction(const char*) const;

		// 设置这个对象的成员的产生环境
		void setMembersEmergeEnv(Environment *);

		// 获得类的环境
		Environment *getObjectEnvironment() const;

	private:

		std::map<std::string, Object*> m_members;
		ClassInfo *m_class_info;
		// 当前对象的环境
		ObjectBridgeEnv *m_my_env;
		int  m_ref_count = 0;

		// 父类的对象
		langXObject *m_parent = nullptr;
	};

}