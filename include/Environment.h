#pragma once
#include <map>
#include <string>

namespace langX {

	class Object;
	class Function;
	class ClassInfo;

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

		void putObject(const char*, Object*);
		void putObject(const std::string &, Object*);
		Object* getObject(const std::string &);

		void putFunction(const char*, Function*);
		void putFunction(const std::string &, Function*);
		Function* getFunction(const std::string &);

		Environment *getParent() const;
		void setParent(Environment *);

		// 设置限定
		void setRestrict(bool);
		// 是否限定
		bool isRestrict() const;

	private:
		std::map<std::string, Object*> m_objects_map;
		std::map<std::string, Function*> m_functions_map;
		std::map<std::string, Object*> m_classes_map;

		Environment *m_parent = nullptr;

		//  是否限定， 如果限定， 则寻找变量的时候不会去寻找父级环境
		bool m_restrict = false;
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

	private:

		ClassInfo* m_class = NULL;
	};

}