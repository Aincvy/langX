#pragma once

#include <string>

namespace langX {
	class Execption
	{
	public:
		Execption();
		Execption(int);
		Execption(const char*);
		Execption(const std::string &);
		Execption(int, const char*);
		Execption(int, const std::string &);
		~Execption();

		int getCode() const;
		const char* getMsg() const;

	private:
		int m_code;
		std::string m_msg;
	};
}