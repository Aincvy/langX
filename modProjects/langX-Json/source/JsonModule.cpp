#include "../include/JsonModule.h"
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