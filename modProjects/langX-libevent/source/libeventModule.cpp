#include <stdio.h>

#include "../include/libeventModule.h"
#include "../include/ReglibeventModule.h"
#include "../include/RegHttpServer.h"
#include "../../../include/XNameSpace.h"
#include "../../../include/LogManager.h"

namespace langX {

	libeventModule::libeventModule()
	{
		this->setName("libevent");
	}

	libeventModule::~libeventModule()
	{
	}

	int libeventModule::init(langXState *state)
	{
		// 初始化 libevent 库
		logger->debug("初始化libevent库 ");
    
		initServerSupportTools();

		XNameSpace *space = state->getNameSpaceOrCreate("langX.libevent");
		regTcpServer(state, space);
		regTcpClient(state, space);
		regDefaultNetPacket(state, space);
		regHttpServer(state, space);
		regHttpServerRoute(state, space);
		regHttpRequest(state, space);
		regHttpResponse(state, space);

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
