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
		int loadFrom(const char *);

		//  获得所有的 lib 的路径
		std::vector<std::string> & getLibPath();

		// 获得 
		std::string & getLibDir();

	private:

		std::string m_lib_dir;
		std::vector<std::string> m_lib_list;

	};



}