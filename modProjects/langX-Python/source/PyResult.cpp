
#include "../include/RegPythonModule.h"

#include "../../../include/ClassInfo.h"
#include "../../../include/YLlangX.h"
#include "../../../include/Object.h"
#include "../../../include/langXObject.h"
#include "../../../include/langXObjectRef.h"
#include "../../../include/Allocator.h"
#include "../../../include/Number.h"

namespace langX {


	Object * langX_PyResult_toTuple(X3rdFunction *func, const X3rdArgs &args) {
		if (args.object == nullptr)
		{
			printf("langX_PyResult_toTuple error! NO OBJ!\n");
			return nullptr;
		}

		return nullptr;
	}



	Object * langX_PyResult_toDict(X3rdFunction *func, const X3rdArgs &args) {
		if (args.object == nullptr)
		{
			printf("langX_PyResult_toDict error! NO OBJ!\n");
			return nullptr;
		}

		return nullptr;
	}



	Object * langX_PyResult_toNumber(X3rdFunction *func, const X3rdArgs &args) {
		if (args.object == nullptr)
		{
			printf("langX_PyResult_toNumber error! NO OBJ!\n");
			return nullptr;
		}

		return nullptr;
	}



	Object * langX_PyResult_toStr(X3rdFunction *func, const X3rdArgs &args) {
		if (args.object == nullptr)
		{
			printf("langX_PyResult_toStr error! NO OBJ!\n");
			return nullptr;
		}

		return nullptr;
	}



	int regPyResult(langXState *state, XNameSpace* space) {

		ClassInfo *info = new ClassInfo("PyResult");
		info->addFunction("toTuple", create3rdFunc("toTuple", langX_PyResult_toTuple));
		info->addFunction("toDict", create3rdFunc("toDict", langX_PyResult_toDict));
		info->addFunction("toNumber", create3rdFunc("toNumber", langX_PyResult_toNumber));
		info->addFunction("toStr", create3rdFunc("toStr", langX_PyResult_toStr));

		space->putClass(info);

		return 0;
	}
}


