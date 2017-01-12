#include <fstream>
#include <string>
#include <vector>

#include "../include/Config.h"
#include "../include/Utils.h"

namespace langX {



	ConfigX::ConfigX()
	{
	}

	ConfigX::~ConfigX()
	{
	}

	int ConfigX::loadFrom(const char *path)
	{
		std::ifstream fin(path);
		if (!fin)
		{
			return -1;
		}

		std::string s;
		while (std::getline(fin, s)) {

			if (s[0] == '#')
			{
				continue;
			}

			std::vector<std::string> list = splitString(s, "=");
			if (list.size() < 2)
			{
				continue;
			}

			std::string & key = list[0];
			std::string & value = list[1];
			if (key == "LIB_DIR")
			{
				this->m_lib_dir = std::string(value);
			}
			else {
				this->m_lib_list.push_back( std::string(value) );
			}

		}

		return 0;
	}

	std::vector<std::string>& ConfigX::getLibPath()
	{
		return this->m_lib_list;
	}

	std::string & ConfigX::getLibDir()
	{
		return this->m_lib_dir;
	}

}