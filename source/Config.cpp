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
			if (value.empty())
			{
				continue;
			}
			if (key == "LIB_DIR" || key == "XX")
			{
        if( key == "LIB_DIR"){
          this->m_lib_dir = std::string(value);
        } else if(key == "log4cpp"){
          this->m_log4cpp_path = std::string(value);
        }

				char tmpChar = value[value.length() - 1];
				if (tmpChar == '\r' || tmpChar == '\n')
				{
					this->m_lib_dir = value.substr(0, value.length() - 1);
				}else
				if (value.length() > 1)
				{
					// \r\n
					char tmpChar1 = value[value.length() - 2];
					if (tmpChar1 == '\r' && tmpChar == '\n')
					{
						this->m_lib_dir = value.substr(0, value.length() - 2);
					}
				}

			}
			else {
				std::string tmpStr = std::string(value);

				char tmpChar = value[value.length() - 1];
				if (tmpChar == '\r' || tmpChar == '\n')
				{
					tmpStr = value.substr(0, value.length() - 1);
				}
				else
					if (value.length() > 1)
					{
						// \r\n
						char tmpChar1 = value[value.length() - 2];
						if (tmpChar1 == '\r' && tmpChar == '\n')
						{
							tmpStr = value.substr(0, value.length() - 2);
						}
					}

				this->m_lib_list.push_back(tmpStr);
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
