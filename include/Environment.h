#pragma once
#include <map>
#include <string>
#include "Object.h"
#include "Function.h"

namespace langX {

	/*
	 * ������  
	 * [��Ȼ��ʲô�� ������д - - ]
	 * ������ʾ�� һ������ �� ������һЩ������ ����
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