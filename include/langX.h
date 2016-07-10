#pragma once
#include <map>
#include <string>
#include "Object.h"

namespace langX {
	class langXState
	{
	public:
		langXState();
		~langXState();

		void putObject(const char* , Object*);
		void putObject(const std::string &, Object*);
		Object * getObject(const std::string &);

	private:
		std::map<std::string, Object*> m_objects_map;
		std::map<std::string, Object*> m_functions_map;
		std::map<std::string, Object*> m_classes_map;
	};
}