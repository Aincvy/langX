#pragma once

#include <string>
#include <vector>

/*
 * @date 2017-01-11  创建文件
 */

namespace langX {

	class ConfigX
	{
	public:
		ConfigX();
		~ConfigX();

		// 从文件中加载配置
		void loadFrom(const char *);

	private:

		std::string m_lib_dir;
		std::vector<std::string> m_lib_list;

	};



}