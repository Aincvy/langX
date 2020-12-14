
#include "../../../include/LogManager.h"

#include "../include/PythonModule.h"
#include "../include/RegPythonModule.h"

namespace langX {

    PythonModule* pythonModule;
    Logger* pythonModuleLogger;

	PythonModule::PythonModule()
	{
		this->setName("python");
	}

	PythonModule::~PythonModule()
	{
	}

	int PythonModule::init(langXState *state)
	{
	    pythonModuleLogger = m_logger;
		m_logger->debug("init langX-Python 库. " );
		m_logger->debug("python version: %s", Py_GetVersion());

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

    const char *PythonModule::getDescription() const {
        return "bridge python functions...  you can call python library...";
    }

    const char *PythonModule::getAuthor() const {
        return "Aincvy(aincvy@gmail.com)";
    }

    const char *PythonModule::getRepository() const {
        return "https://github.com/Aincvy/langX";
    }

    const char *PythonModule::getVersion() const {
        return "0.0.1";
    }


}

int loadModule(langX::X3rdModule *& mod) {
	
	langX::pythonModule = new langX::PythonModule();
    mod = langX::pythonModule;

	return 0;
}
