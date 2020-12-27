#include <langX/langXSimple.h>

#include "../include/RegPythonModule.h"
#include "../include/PythonModule.h"

namespace langX {


	int regPyObjectType(langXState *state, XNameSpace* space) {

		ClassInfo *info = new ClassInfo("PyObjectType");
		info->addMember("Module", Number((int) PyObjectType::Unknown));
		info->addMember("Module", Number((int) PyObjectType::Module));
		info->addMember("PyInstance", Number((int)PyObjectType::PyInstance));
		info->addMember("PyClass", Number((int)PyObjectType::PyClass));
		info->addMember("Function", Number((int)PyObjectType::PyFunction));
		info->addMember("Tuple", Number((int)PyObjectType::Tuple));
		info->addMember("Dict", Number((int)PyObjectType::Dict));

		space->putClass(info);

		return 0;
	}
}


