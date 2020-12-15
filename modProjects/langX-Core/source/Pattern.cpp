
#include "../include/RegCoreModule.h"
#include "../../../include/ClassInfo.h"
#include "../../../include/NodeCreator.h"
#include "../../../include/Object.h"
#include "../../../include/langXObject.h"
#include "../../../include/Allocator.h"
#include "../../../include/Number.h"

namespace langX {


	Object * langX_Pattern_Pattern(X3rdFunction *func, const X3rdArgs &args) {
		if (args.object == nullptr)
		{
			printf("langX_Pattern_Pattern error! NO OBJ!\n");
			return nullptr;
		}

		return nullptr;
	}


	Object * langX_Pattern_Pattern_Dtor(X3rdFunction *func, const X3rdArgs &args) {
		if (args.object == nullptr)
		{
			printf("langX_Pattern_Pattern_Dtor error! NO OBJ!\n");
			return nullptr;
		}

		return nullptr;
	}


	Object * langX_Pattern_match(X3rdFunction *func, const X3rdArgs &args) {
		if (args.object == nullptr)
		{
			printf("langX_Pattern_match error! NO OBJ!\n");
			return nullptr;
		}

		return nullptr;
	}


	int regPattern(langXState *state, XNameSpace* space) {

		ClassInfo *info = new ClassInfo("Pattern");
		info->addFunction("Pattern", create3rdFunc("Pattern", langX_Pattern_Pattern));
		info->addFunction("~Pattern", create3rdFunc("~Pattern", langX_Pattern_Pattern_Dtor));
		info->addFunction("match", create3rdFunc("match", langX_Pattern_match));

		space->putClass(info);

		return 0;
	}
}


