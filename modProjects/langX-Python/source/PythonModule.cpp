#include "../include/PythonModule.h"

namespace langX {



	PythonModule::PythonModule()
	{
	}

	PythonModule::~PythonModule()
	{
	}

	int PythonModule::init(langXState *)
	{
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