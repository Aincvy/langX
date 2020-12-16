#include <XNameSpace.h>
#include <LogManager.h>

#include "libeventModule.h"
#include "ReglibeventModule.h"
#include "RegHttpServer.h"

namespace langX {

    libeventModule* module = nullptr;
    Logger* moduleLogger = nullptr;

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
		moduleLogger = this->m_logger;
        m_state = state;
        m_logger->debug("初始化libevent库 ");

		initServerSupportTools();

		XNameSpace *space = state->getNameSpaceOrCreate("langX.libevent");
		regTcpServer(state, space);
		regTcpClient(state, space);
		regDefaultNetPacket(state, space);
		regHttpServer(state, space);
		regHttpServerRoute(state, space);
		regHttpRequest(state, space);
		regHttpResponse(state, space);

		regEventBase(state, space);


		return 0;
	}

	int libeventModule::unload(langXState *)
	{
		return 0;
	}

    const char *libeventModule::getName() const {
        return X3rdModule::getName();
    }

    const char *libeventModule::getVersion() const {
        return "0.0.1";
    }

    const char *libeventModule::getRepository() const {
        return "-";
    }

    const char *libeventModule::getAuthor() const {
        return "Aincvy(aincvy@gmail.com)";
    }

    const char *libeventModule::getDescription() const {
        return "Bridge libevent, provide socket functions..";
    }

    const char *libeventModule::getEntrypoint() const {
        return nullptr;
    }

}

int loadModule(langX::X3rdModule *& mod)
{
    langX::module = new langX::libeventModule();
	mod = langX::module;

	return 0;
}
