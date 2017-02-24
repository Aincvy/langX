#include <stdio.h>

#include "../include/JsonModule.h"
#include "../include/RegJsonModule.h"
#include "../../../include/XNameSpace.h"

namespace langX {

	JsonModule::JsonModule()
	{
	}

	JsonModule::~JsonModule()
	{
	}

	int JsonModule::init(langXState *state)
	{
		printf("init langX-Json¿â\n");

		XNameSpace *space = state->getNameSpaceOrCreate("langX.json");

		regJsonArray(state, space);
		regJsonObject(state, space);

		return 0;
	}

	int JsonModule::unload(langXState *state)
	{
		return 0;
	}

}

int loadModule(langX::X3rdModule *& mod)
{
	mod = new langX::JsonModule();

	return 0;
}