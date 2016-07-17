#pragma once
#include <map>
#include <string>
#include "Object.h"
#include "Environment.h"

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
		// ȫ�ֻ���
		Environment m_global_env;
	};
}