#include "../include/RegCoreModule.h"
#include "../../../include/ClassInfo.h"
#include "../../../include/YLlangX.h"
#include "../../../include/Object.h"
#include "../../../include/langXObject.h"
#include "../../../include/langXObjectRef.h"
#include "../../../include/Allocator.h"
#include "../../../include/Number.h"

namespace langX {


	Object * langX_Matcher_Matcher(X3rdFunction *func, const X3rdArgs &args) {
		if (args.object == nullptr)
		{
			printf("langX_Matcher_Matcher error! NO OBJ!\n");
			return nullptr;
		}

		return nullptr;
	}


	Object * langX_Matcher_Matcher_Dtor(X3rdFunction *func, const X3rdArgs &args) {
		if (args.object == nullptr)
		{
			printf("langX_Matcher_Matcher_Dtor error! NO OBJ!\n");
			return nullptr;
		}

		return nullptr;
	}


	Object * langX_Matcher_find(X3rdFunction *func, const X3rdArgs &args) {
		if (args.object == nullptr)
		{
			printf("langX_Matcher_find error! NO OBJ!\n");
			return nullptr;
		}

		return nullptr;
	}


	Object * langX_Matcher_group(X3rdFunction *func, const X3rdArgs &args) {
		if (args.object == nullptr)
		{
			printf("langX_Matcher_group error! NO OBJ!\n");
			return nullptr;
		}

		return nullptr;
	}


	int regMatcher(langXState *state, XNameSpace* space) {

		ClassInfo *info = new ClassInfo("Matcher");
		info->addFunction("Matcher", create3rdFunc("Matcher", langX_Matcher_Matcher));
		info->addFunction("~Matcher", create3rdFunc("~Matcher", langX_Matcher_Matcher_Dtor));
		info->addFunction("find", create3rdFunc("find", langX_Matcher_find));
		info->addFunction("group", create3rdFunc("group", langX_Matcher_group));

		space->putClass(info);

		return 0;
	}
}


