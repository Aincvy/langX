#include <stdio.h>
#include "../include/CoreModule.h"
#include "../include/RegCoreModule.h"
#include "../../../include/XNameSpace.h"
#include "../../../include/ClassInfo.h"
#include "../../../include/LogManager.h"

namespace langX {

    // 声明实现
    CoreModule* coreModule = nullptr;
    Logger* coreModuleLogger = nullptr;


	CoreModule::CoreModule()
	{
		this->setName("core");
	}

	CoreModule::~CoreModule()
	{
	}

	int CoreModule::init(langXState *state)
	{
        coreModuleLogger = m_logger;

		m_logger->debug("init langX-core 库");
		XNameSpace *space = state->getNameSpaceOrCreate("langX.core.util");
		regIterator(state, space);
		regList(state, space);
		regMap(state, space);
		regSet(state, space);
		regQueue(state, space);
		regStack(state, space);
		regVector(state, space);
		regRandom(state, space);

		space = state->getNameSpaceOrCreate("langX.core");
        regDefault(state, space);

		space = state->getNameSpaceOrCreate("langX.core.io");
		regFile(state, space);
		regByteArray(state, space);
		ClassInfo * stream = regStream(state, space);
		regFileStream(state, space, stream);

		// regex
		space = state->getNameSpaceOrCreate("langX.core.regex");
		regMatcher(state, space);
		regPattern(state, space);

		return 0;
	}

	int CoreModule::unload(langXState *state)
	{
		return 0;
	}

}


int loadModule(langX::X3rdModule *& mod)
{
	langX::coreModule = new langX::CoreModule();

	mod = langX::coreModule;

	return 0;
}
