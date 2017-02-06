#include "../include/ReglibeventModule.h"

#include "../../../include/ClassInfo.h"
#include "../../../include/YLlangX.h"
#include "../../../include/Object.h"
#include "../../../include/langXObject.h"
#include "../../../include/langXObjectRef.h"
#include "../../../include/Allocator.h"
#include "../../../include/Number.h"

namespace langX {


	Object * langX_HttpServerRoute_route(X3rdFunction *func, const X3rdArgs &args) {
		if (args.object == nullptr)
		{
			printf("langX_HttpServerRoute_route error! NO OBJ!\n");
			return nullptr;
		}

		return nullptr;
	}



	int regHttpServerRoute(langXState *state, XNameSpace* space) {

		ClassInfo *info = new ClassInfo("HttpServerRoute");
		info->addFunction("route", create3rdFunc("route", langX_HttpServerRoute_route));
		space->putClass(info);

		return 0;
	}
}


