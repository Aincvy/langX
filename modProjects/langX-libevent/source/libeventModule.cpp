#include <stdio.h>

#include "../include/libeventModule.h"
#include "../include/ReglibeventModule.h"
#include "../../../include/XNameSpace.h"

namespace langX {



	libeventModule::libeventModule()
	{
	}

	libeventModule::~libeventModule()
	{
	}

	int libeventModule::init(langXState *state)
	{
		// 初始化 libevent 库
		printf("初始化libevent库");
		initServerSupportTools();

		XNameSpace *space = state->getNameSpaceOrCreate("langX.libevent");
		regTcpServer(state, space);
		regTcpClient(state, space);
		regDefaultNetPacket(state, space);

		return 0;
	}

	int libeventModule::unload(langXState *)
	{
		return 0;
	}

}

int loadModule(langX::X3rdModule *& mod)
{
	mod = new langX::libeventModule();

	return 0;
}