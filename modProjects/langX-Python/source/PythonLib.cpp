#include "../include/RegPythonModule.h"


#include "../../../include/ClassInfo.h"
#include "../../../include/NodeCreator.h"
#include "../../../include/Object.h"
#include "../../../include/langXObject.h"
#include "../../../include/Allocator.h"
#include "../../../include/Number.h"
#include "../../../include/LogManager.h"


#ifdef WIN32 
#include "../../../lib/Python-3.5.2/Include/Python.h"
#else
#include <python/Python.h>
#endif


namespace langX {

	Object * langX_PythonLib_unload(X3rdFunction *func, const X3rdArgs &args) {

		Py_Finalize();

		return nullptr;
	}



	Object * langX_PythonLib_isLoad(X3rdFunction *func, const X3rdArgs &args) {


		if (Py_IsInitialized())
		{
			return Allocator::allocateNumber(1);
		}

		return Allocator::allocateNumber(0);

	}

	Object * langX_PythonLib_load(X3rdFunction *func, const X3rdArgs &args) {
		
		if (Py_IsInitialized())
		{
			return Allocator::allocateNumber(1);
		}

		Py_Initialize();
		
		if (Py_IsInitialized())
		{
			logger->debug("load python lib ok.");
			return Allocator::allocateNumber(1);
		}

		logger->debug("load python lib fail.");
		return Allocator::allocateNumber(0);
	}



	Object * langX_PythonLib_PythonLib_Dtor(X3rdFunction *func, const X3rdArgs &args) {

		return nullptr;
	}



	Object * langX_PythonLib_PythonLib(X3rdFunction *func, const X3rdArgs &args) {

		return nullptr;
	}



	int regPythonLib(langXState *state ,XNameSpace* space) {

		ClassInfo *info = new ClassInfo("PythonLib");
		info->addFunction("unload", create3rdFunc("unload", langX_PythonLib_unload));
		info->addFunction("isLoad", create3rdFunc("isLoad", langX_PythonLib_isLoad));
		info->addFunction("load", create3rdFunc("load", langX_PythonLib_load));
		info->addFunction("~PythonLib", create3rdFunc("~PythonLib", langX_PythonLib_PythonLib_Dtor));
		info->addFunction("PythonLib", create3rdFunc("PythonLib", langX_PythonLib_PythonLib));
		space->putClass(info);

		return 0;
	}
}


