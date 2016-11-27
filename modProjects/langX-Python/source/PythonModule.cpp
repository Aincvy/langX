#include <stdio.h>

#include "../include/PythonModule.h"
#include "../include/RegPythonModule.h"

#include "../../../include/langX.h"
#include "../../../include/XNameSpace.h"

namespace langX {



	PythonModule::PythonModule()
	{
	}

	PythonModule::~PythonModule()
	{
	}

	int PythonModule::init(langXState *state)
	{
		printf("init langX-Mysql ¿â\n");

		XNameSpace *space = state->getNameSpaceOrCreate("langX.python");

		regPythonLib(state, space);
		regPythonHook(state, space);

		return 0;
	}

	int PythonModule::unload(langXState *)
	{
		return 0;
	}

}

int loadModule(langX::X3rdModule *& mod) {
	
	mod = new langX::PythonModule();

	return 0;
}