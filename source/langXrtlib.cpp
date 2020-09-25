#define _DARWIN_C_SOURCE

#include <string>
#include <iostream>
#include <dirent.h>

#include "../include/langXrtlib.h"
#include "../include/langX.h"
#include "../include/Config.h"
#include "../include/LogManager.h"
#include "../include/Utils.h"


namespace langX {


	XrtNameSpace::XrtNameSpace(const char *name) : XNameSpace(name)
	{

	}

	XrtNameSpace::~XrtNameSpace()
	{
	}


	void initRTNameSpace(langXState *state)
	{
		XNameSpace *rootSpace = state->getNameSpaceOrCreate("langX");
		XrtNameSpace *rtns = new XrtNameSpace("rt");

		rootSpace->putNameSpace(rtns->getName(), rtns);
	}

	// 执行一个文件夹
	void doFolder(langXState *state, const std::string & dir) {

		// 查找目录里面的所有的文件
		DIR *dp = NULL;
		struct dirent *dirp;
		if ((dp = opendir(dir.c_str())) == NULL)
		{
			logger->debug("can not open rtlib dir: %s", dir.c_str());
			return;
		}

		while ((dirp = readdir(dp)) != NULL)
		{
			std::string filename(dirp->d_name);
			std::string fullpath = dir + "/" + filename;
			if (filename == "." || filename == ".." || filename == "notLoad")
			{
				// 过滤这两个底层的目录
				continue;
			}

			if (dirp->d_type == DT_DIR)
			{
				// 是一个目录
				doFolder(state, fullpath);
			}
			else if (dirp->d_type == DT_REG)
			{
				 // 常规文件， 应该是一个脚本
				if (filename != "Main.lx")
				{
					// 只加载文件夹里面的 Main.lx 文件
					continue;
				}

				state->doFile(fullpath.c_str());
			}

		}
		closedir(dp);

	}

	//
	void loadRTLib(langXState *state) {
		// 找到目录，然后加载里面的全部脚本
		const ConfigX & config = state->getConfig();
		const std::string & dir= config.getRTLibDir();

		if (dir.empty())
		{
			// 如果目录为空就直接返回
			return;
		}

		doFolder(state, dir);
	}

}
