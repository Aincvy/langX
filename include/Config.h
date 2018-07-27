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

		// 获取运行库目录的位置
		const std::string & getRTLibDir() const;

	private:

		// rt 脚本库的目录
		std::string m_rtlib_dir;
		// .so 动态库的目录
		std::string m_lib_dir;
		std::string m_log4cpp_path;
		std::vector<std::string> m_lib_list;


	};



}
