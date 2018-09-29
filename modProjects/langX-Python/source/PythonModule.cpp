#include <stdio.h>

#include "../include/PythonModule.h"
#include "../include/RegPythonModule.h"

#include "../../../include/langX.h"
#include "../../../include/XNameSpace.h"
#include "../../../include/LogManager.h"

namespace langX {

	PythonModule::PythonModule()
	{
		this->setName("python");
	}

	PythonModule::~PythonModule()
	{
	}

	int PythonModule::init(langXState *state)
	{
		logger->debug("init langX-Python 库");

		XNameSpace *space = state->getNameSpaceOrCreate("langX.python");

		regPythonLib(state, space);
		regPythonHook(state, space);
		regPyException(state, space);
		regPyObjectType(state, space);
		regPyObject(state, space);
		regPyObjectEasy(state, space);

		regPySomeFunction(state, space);

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
