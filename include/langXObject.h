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

	private:

		std::map<std::string, Object*> m_members;
		ClassInfo *m_class_info;
		int  m_ref_count = 0;
	};

}