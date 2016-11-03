#include <stdio.h>
#include "../include/CoreModule.h"
#include "../include/RegCoreModule.h"
#include "../../../include/XNameSpace.h"


namespace langX {

	CoreModule::CoreModule()
	{
	}
	CoreModule::~CoreModule()
	{
	}
	int CoreModule::init(langXState *state)
	{
		printf("init langX-Core 库\n");
		XNameSpace *space = state->getNameSpaceOrCreate("langX.core.util");
		regIterator(state, space);
		regList(state, space);
		regMap(state, space);
		regSet(state, space);
		regQueue(state, space);
		regStack(state, space);

		space = state->getNameSpaceOrCreate("langX.core");
		regDeafult(state, space);
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