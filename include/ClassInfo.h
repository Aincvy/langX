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
	class langXObjectExtend;
	class ClassBridgeEnv;

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

		// 生成一个本类的对象
		langXObject* newObject();
		// 生成一个本类的对象  参数： true 将生成的对象放入Allocator进行登记， false: 不放
		langXObject* newObject(bool );

		// 生成一个可扩展的本类 对象
		langXObjectExtend* newExtendObject();

		std::map<std::string, Object*> & getMembers();
		std::map<std::string, Function*> & getFunctions();

		// 当前类是否是该类 OR 该类的子类
		bool isInstanceOf(const char *) const;

		// 扩展这个类， 或者说叫 填充这个类
		void expand(ClassInfo *);

		// 获得这个类的桥接环境
		ClassBridgeEnv *getClassEnv();

		// 这个类是否为 local 类型
		bool isLocal() const;
		// 设置 local 属性
		void setLocal(bool);

	private:
		//  当前类的 字段map ...
		//  key:  属性名,  value:  对象指针
		std::map<std::string, Object*> m_members;
		std::map<std::string, Function*> m_functions;

		// 当前类叫什么名字
		std::string m_name;

		//  当前类的桥接环境
		ClassBridgeEnv *m_classEnv;
		// local 属性
		bool m_local;

		// 父类
		ClassInfo *m_parent = nullptr;
	};

}