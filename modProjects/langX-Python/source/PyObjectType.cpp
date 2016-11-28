#include "../include/RegPythonModule.h"

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
		info->addMember("Module", getState()->getAllocator().allocateNumber(1));
		info->addMember("PyObject", getState()->getAllocator().allocateNumber(2));
		info->addMember("PyClass", getState()->getAllocator().allocateNumber(3));
		info->addMember("Function", getState()->getAllocator().allocateNumber(4));
		info->addMember("Tuple", getState()->getAllocator().allocateNumber(5));
		info->addMember("Dict", getState()->getAllocator().allocateNumber(6));

		space->putClass(info);

		return 0;
	}
}


