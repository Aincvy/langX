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

	// ִ��һ���ļ���
	void doFolder(langXState *state, const std::string & dir) {

		// ����Ŀ¼��������е��ļ�
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
				// �����������ײ��Ŀ¼ 
				continue;
			}

			if (dirp->d_type == DT_DIR)
			{
				// ��һ��Ŀ¼
				doFolder(state, fullpath);
			}
			else if (dirp->d_type == DT_REG)
			{
				 // �����ļ��� Ӧ����һ���ű�
				if (filename != "Main.lx")
				{
					// ֻ�����ļ�������� Main.lx �ļ�
					continue;
				}

				state->doFile(fullpath.c_str());
			}

		}
		closedir(dp);

	}

	// 
	void loadRTLib(langXState *state) {
		// �ҵ�Ŀ¼��Ȼ����������ȫ���ű�
		const ConfigX & config = state->getConfig();
		const std::string & dir= config.getRTLibDir();

		if (dir.empty())
		{
			// ���Ŀ¼Ϊ�վ�ֱ�ӷ���
			return; 
		}

		doFolder(state, dir);
	}

}

