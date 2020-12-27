#include <stdio.h>

#include "../include/JsonModule.h"
#include "../include/RegJsonModule.h"

#include <langX/langXSimple.h>

namespace langX {

	JsonModule::JsonModule()
	{
		this->setName("json");
	}

	JsonModule::~JsonModule()
	{
	}

	int JsonModule::init(langXState *state)
	{
		logger->debug("init langX-Json库 ");

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
