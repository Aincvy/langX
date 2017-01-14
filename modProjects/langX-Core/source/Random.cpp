#include "../include/RegCoreModule.h"

#include "../../../include/ClassInfo.h"
#include "../../../include/YLlangX.h"
#include "../../../include/Object.h"
#include "../../../include/langXObject.h"
#include "../../../include/langXObjectRef.h"
#include "../../../include/Allocator.h"
#include "../../../include/Number.h"

namespace langX {


	Object * langX_Random_nextDouble(X3rdFunction *func, const X3rdArgs &args) {
		if (args.object == nullptr)
		{
			printf("langX_Random_nextDouble error! NO OBJ!\n");
			return nullptr;
		}

		return nullptr;
	}



	Object * langX_Random_nextInt(X3rdFunction *func, const X3rdArgs &args) {
		if (args.object == nullptr)
		{
			printf("langX_Random_nextInt error! NO OBJ!\n");
			return nullptr;
		}

		return nullptr;
	}



	Object * langX_Random_Random_Dtor(X3rdFunction *func, const X3rdArgs &args) {
		if (args.object == nullptr)
		{
			printf("langX_Random_Random_Dtor error! NO OBJ!\n");
			return nullptr;
		}

		return nullptr;
	}



	Object * langX_Random_Random(X3rdFunction *func, const X3rdArgs &args) {
		if (args.object == nullptr)
		{
			printf("langX_Random_Random error! NO OBJ!\n");
			return nullptr;
		}

		return nullptr;
	}


	int regRandom(langXState *state, XNameSpace* space) {

		ClassInfo *info = new ClassInfo("Random");
		info->addFunction("nextDouble", create3rdFunc("nextDouble", langX_Random_nextDouble));
		info->addFunction("nextInt", create3rdFunc("nextInt", langX_Random_nextInt));
		info->addFunction("~Random", create3rdFunc("~Random", langX_Random_Random_Dtor));
		info->addFunction("Random", create3rdFunc("Random", langX_Random_Random));

		space->putClass(info);

		return 0;
	}
}


