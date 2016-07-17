#pragma once
#include <map>
#include <string>
#include "Object.h"
#include "Function.h"

namespace langX {

	/*
	 * 环境类  
	 * [果然这什么的 真是难写 - - ]
	 * 这个类表示了 一个环境 ， 包含了一些变量， 函数
	 */
	class Environment
	{
	public:
		Environment();
		~Environment();

		void putObject(const char*, Object*);
		void putObject(const std::string &, Object*);
		Object* getObject(const std::string &);

		void putFunction(const char*, Function*);
		void putFunction(const std::string &, Function*);
		Function* getFunction(const std::string &);

	private:
		std::map<std::string, Object*> m_objects_map;
		std::map<std::string, Function*> m_functions_map;
		std::map<std::string, Object*> m_classes_map;

	};

}