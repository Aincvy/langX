#pragma once
#include <map>
#include <string>

/*
 *  date: 2016-08-17
 *  author: hideDragon
 *  file: ClassInfo.h 
 *
 *  desc: 类信息
 */

namespace langX {
	class Object;
	class Function;
	class langXObject;

	class ClassInfo 
	{
	public:
		ClassInfo(const char*);
		~ClassInfo();

		void addMember(const char*, Object *);
		// 是否包含那个 成员
		bool hasMember(const char*) const;
		// 这个请求是否从子类而来
		bool hasMember(const char*,bool) const;
		Object * getMember(const char *) const;
		// 这个请求是否是从子类产生的
		Object * getMember(const char *,bool) const;

		void addFunction(const char*, Function*);
		bool hasFunction(const char*) const;
		Function * getFunction(const char *) const;
		// 这个请求是否是从子类产生的
		Function * getFunction(const char *,bool) const;

		void setParent(ClassInfo *);
		ClassInfo * getParent() const;

		const char * getName() const;

		langXObject* newObject();

		std::map<std::string, Object*> & getMembers();
		std::map<std::string, Function*> & getFunctions();

	private:
		//  当前类的 字段map ...
		//  key:  属性名,  value:  对象指针
		std::map<std::string, Object*> m_members;
		std::map<std::string, Function*> m_functions;

		// 当前类叫什么名字
		std::string m_name;

		// 父类
		ClassInfo *m_parent = nullptr;
	};

}