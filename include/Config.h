#pragma once

#include <string>
#include <vector>

/*
 * @date 2017-01-11  �����ļ�
 */

namespace langX {

	class ConfigX
	{
	public:
		ConfigX();
		~ConfigX();

		// ���ļ��м�������
		void loadFrom(const char *);

	private:

		std::string m_lib_dir;
		std::vector<std::string> m_lib_list;

	};



}