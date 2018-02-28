#include <stdio.h>
#include "../include/CoreModule.h"
#include "../include/RegCoreModule.h"
#include "../../../include/XNameSpace.h"
#include "../../../include/ClassInfo.h"
#include "../../../include/LogManager.h"

namespace langX {

	CoreModule::CoreModule()
	{
	}
	CoreModule::~CoreModule()
	{
	}
	int CoreModule::init(langXState *state)
	{
    logger->debug("init langX-core 库");
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
		regDeafult(state, space);

		space = state->getNameSpaceOrCreate("langX.core.io");
		regFile(state, space);
		regByteArray(state, space);
		ClassInfo * stream = regStream(state, space);
		regFileStream(state, space , stream);

		return 0;
	}
	int CoreModule::unload(langXState *state)
	{
		return 0;
	}
}


int loadModule(langX::X3rdModule *& mod)
{
	mod = new langX::CoreModule();

	return 0;
}
