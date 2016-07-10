#include "..\include\Execption.h"

namespace langX {
	Execption::Execption()
	{
		m_code = 0;
		m_msg = "";
	}
	Execption::Execption(int i)
	{
		this->m_code = i;
	}
	Execption::Execption(const char *msg)
	{
		this->m_msg = msg;
	}
	Execption::Execption(const std::string &msg)
	{
		this->m_msg = msg;
	}
	Execption::Execption(int i, const char *msg)
	{
		this->m_code = i;
		this->m_msg = msg;
	}
	Execption::Execption(int i, const std::string &msg)
	{
		this->m_code = i;
		this->m_msg = msg;
	}
	Execption::~Execption()
	{
	}
	int Execption::getCode() const
	{
		return this->m_code;
	}
	const char * Execption::getMsg() const
	{
		return m_msg.c_str();
	}
}