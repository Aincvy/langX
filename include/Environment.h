#pragma once
#include <map>
#include <string>
#include "Object.h"

namespace langX {

	class Function;
	class ClassInfo;
	class langXObject;
	class langXObjectRef;

	/*
	 * 环境类  
	 * [果然这什么的 真是难写 - - ]
	 * 这个类表示了 一个环境 ， 包含了一些变量， 函数
	 */
	class Environment
	{
	public:
		Environment();
		/* 在释放这个对象的时候并不会施放他的父级环境对象 */
		~Environment();

		virtual void putObject(const char*, Object*);
		virtual void putObject(const std::string &, Object*);
		virtual Object* getObject(const std::string &);
		// 只从自己的环境中寻找对象
		virtual Object* getObjectSelf(const char *) const;

		virtual void putFunction(const char*, Function*);
		virtual void putFunction(const std::string &, Function*);
		virtual Function* getFunction(const std::string &);

		void putClass(const char *, ClassInfo *);
		ClassInfo *getClass(const char *);

		Environment *getParent() const;
		void setParent(Environment *);

		//  死亡符号。  如果当前环境为 死亡环境， 则不应该执行节点，直接返回就好了
		void setDead(bool);
		//  死亡符号。  如果当前环境为 死亡环境， 则不应该执行节点，直接返回就好了
		bool isDead() const;

		// 设置限定
		void setRestrict(bool);
		// 是否限定
		bool isRestrict() const;

		// 是否是类的桥接环境
		virtual bool isClassEnvironment() const;
		// 是否是对象的桥接环境
		virtual bool isObjectEnvironment() const;
		// 是否是 try 环境
		virtual bool isTryEnvironment() const;
		// 是否是 环境的桥接环境
		virtual bool isEnvEnvironment() const;

	private:
		std::map<std::string, Object*> m_objects_map;
		std::map<std::string, Function*> m_functions_map;
		std::map<std::string, ClassInfo*> m_classes_map;

		Environment *m_parent = nullptr;

		//  是否限定， 如果限定， 则寻找变量的时候不会去寻找父级环境
		//  限定只会针对  变量， 不会针对 函数
		bool m_restrict = false;
		//  死亡符号。  如果当前环境为 死亡环境， 则不应该执行节点，直接返回就好了
		bool m_dead = false;
	};


	// 类的桥接环境  
	class ClassBridgeEnv : public Environment
	{
	public:
		ClassBridgeEnv(ClassInfo *);
		~ClassBridgeEnv();

		void putObject(const char*, Object*);
		void putObject(const std::string &, Object*);
		Object* getObject(const std::string &);

		void putFunction(const char*, Function*);
		void putFunction(const std::string &, Function*);
		Function* getFunction(const std::string &);

		bool isClassEnvironment() const;

	private:

		ClassInfo* m_class = NULL;
	};

	//  对象的桥接环境
	class ObjectBridgeEnv : public Environment
	{
	public:
		ObjectBridgeEnv(langXObject *);
		~ObjectBridgeEnv();

		void putObject(const char*, Object*);
		void putObject(const std::string &, Object*);
		Object* getObject(const std::string &);

		Function* getFunction(const std::string &);

		// 获得桥接的是哪个对象
		langXObject *getEnvObject() const;

		bool isObjectEnvironment() const;

	private:

		langXObject* m_object = NULL;
	};

	// catch 块的 callback
	typedef void (*CBCatch)(langXObjectRef *);

	//  try-catch 中的 try 环境
	class TryEnvironment : public Environment
	{
	public:
		TryEnvironment();
		~TryEnvironment();

		bool isTryEnvironment() const;

		void setCatchCB(CBCatch);
		CBCatch getCatchCB() const;

		void setCatchNode(Node *);
		Node *getCatchNode() const;

	private:
		// catach 节点的根节点
		Node * m_catch_node = nullptr;
		// 优先使用 callback, 如果callback 不存在则使用catch节点
		CBCatch m_catch_cb = NULL;
	};


	// 环境的桥接环境
	class EnvironmentBridgeEnv : public Environment
	{
	public:
		EnvironmentBridgeEnv(Environment *);
		~EnvironmentBridgeEnv();

		// 放置对象到桥接的那个环境中
		void putObject(const char*, Object*);
		// 放置对象到桥接的那个环境中
		void putObject(const std::string &, Object*);
		// 如果桥接的环境没有这个Object ，则会 搜索父环境
		Object* getObject(const std::string &);
		// 只从桥接的那个环境中寻找对象
		Object* getObjectSelf(const char *) const;

		// 放置函数到桥接的那个环境中
		void putFunction(const char*, Function*);
		// 放置函数到桥接的那个环境中
		void putFunction(const std::string &, Function*);
		//  如果桥接的目标环境没有这个函数， 则会搜寻父环境
		Function* getFunction(const std::string &);

		// 获得 桥接的是哪个环境
		Environment *getBridgeEnv();

		bool isEnvEnvironment() const;
		bool isClassEnvironment() const;
		bool isObjectEnvironment() const;
		bool isTryEnvironment() const;

	private:
		Environment *m_env = nullptr;
	};

}