#include "../include/RegPythonModule.h"
#include "../include/PythonModule.h"

#include "../../../include/Function.h"
#include "../../../include/ClassInfo.h"
#include "../../../include/YLlangX.h"
#include "../../../include/Object.h"
#include "../../../include/langXObject.h"
#include "../../../include/langXObjectRef.h"
#include "../../../include/Allocator.h"
#include "../../../include/Number.h"

namespace langX {


	int regPyObjectType(langXState *state, XNameSpace* space) {

		ClassInfo *info = new ClassInfo("PyObjectType");
		info->addMember("Module", getState()->getAllocator().allocateNumber((int) PyObjectType::Unknown));
		info->addMember("Module", getState()->getAllocator().allocateNumber((int) PyObjectType::Module));
		info->addMember("PyInstance", getState()->getAllocator().allocateNumber((int)PyObjectType::PyInstance));
		info->addMember("PyClass", getState()->getAllocator().allocateNumber((int)PyObjectType::PyClass));
		info->addMember("Function", getState()->getAllocator().allocateNumber((int)PyObjectType::PyFunction));
		info->addMember("Tuple", getState()->getAllocator().allocateNumber((int)PyObjectType::Tuple));
		info->addMember("Dict", getState()->getAllocator().allocateNumber((int)PyObjectType::Dict));

		space->putClass(info);

		return 0;
	}
}


