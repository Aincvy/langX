#include "../include/RegPythonModule.h"
#include "../include/PythonModule.h"

#include "../../../include/Function.h"
#include "../../../include/ClassInfo.h"
#include "../../../include/NodeCreator.h"
#include "../../../include/Object.h"
#include "../../../include/langXObject.h"
#include "../../../include/Allocator.h"
#include "../../../include/Number.h"

namespace langX {


	int regPyObjectType(langXState *state, XNameSpace* space) {

		ClassInfo *info = new ClassInfo("PyObjectType");
		info->addMember("Module", Allocator::allocateNumber((int) PyObjectType::Unknown));
		info->addMember("Module", Allocator::allocateNumber((int) PyObjectType::Module));
		info->addMember("PyInstance", Allocator::allocateNumber((int)PyObjectType::PyInstance));
		info->addMember("PyClass", Allocator::allocateNumber((int)PyObjectType::PyClass));
		info->addMember("Function", Allocator::allocateNumber((int)PyObjectType::PyFunction));
		info->addMember("Tuple", Allocator::allocateNumber((int)PyObjectType::Tuple));
		info->addMember("Dict", Allocator::allocateNumber((int)PyObjectType::Dict));

		space->putClass(info);

		return 0;
	}
}


