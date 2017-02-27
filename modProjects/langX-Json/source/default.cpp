#include "../include/RegJsonModule.h"

#include "../../../include/ClassInfo.h"
#include "../../../include/YLlangX.h"
#include "../../../include/Object.h"
#include "../../../include/langXObject.h"
#include "../../../include/langXObjectRef.h"
#include "../../../include/Allocator.h"
#include "../../../include/Number.h"

namespace langX {


	Object * langX_default_jsonDecode(X3rdFunction *func, const X3rdArgs &args) {
		if (args.object == nullptr)
		{
			printf("langX_default_jsonDecode error! NO OBJ!\n");
			return nullptr;
		}



		return nullptr;
	}



	Object * langX_default_jsonEncode(X3rdFunction *func, const X3rdArgs &args) {
		if (args.object == nullptr)
		{
			printf("langX_default_jsonEncode error! NO OBJ!\n");
			return nullptr;
		}

		return nullptr;
	}



	int regdefault(langXState *state, XNameSpace* space) {

		ClassInfo *info = new ClassInfo("default");
		info->addFunction("jsonDecode", create3rdFunc("jsonDecode", langX_default_jsonDecode));
		info->addFunction("jsonEncode", create3rdFunc("jsonEncode", langX_default_jsonEncode));

		space->putClass(info);

		return 0;
	}
}


