#pragma once
#include <map>
#include <string>

namespace langX {

	class Object;
	class ClassInfo;
	class langXObjectRef;

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
		Object * getMember(const char *) const;
		Function *getFunction(const char *) const;
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

		// 设置这个对象的成员的产生环境
		void setMembersEmergeEnv(Environment *);

	private:

		std::map<std::string, Object*> m_members;
		ClassInfo *m_class_info;
		int  m_ref_count = 0;
	};

}