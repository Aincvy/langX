#include <stdio.h>
#include "../include/CoreModule.h"


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
