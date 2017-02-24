#include "../include/RegJsonModule.h"

#include "../../../include/ClassInfo.h"
#include "../../../include/YLlangX.h"
#include "../../../include/Object.h"
#include "../../../include/langXObject.h"
#include "../../../include/langXObjectRef.h"
#include "../../../include/Allocator.h"
#include "../../../include/Number.h"

#ifdef WIN32
#include "../../../lib/cJSON-1.3.0/cJSON.h"
#else
#include <cjson/cJSON.h>
#endif

namespace langX {


	Object * langX_JsonObject_getJsonArray(X3rdFunction *func, const X3rdArgs &args) {
		if (args.object == nullptr)
		{
			printf("langX_JsonObject_getJsonArray error! NO OBJ!\n");
			return nullptr;
		}

		return nullptr;
	}



	Object * langX_JsonObject_put(X3rdFunction *func, const X3rdArgs &args) {
		if (args.object == nullptr)
		{
			printf("langX_JsonObject_put error! NO OBJ!\n");
			return nullptr;
		}

		return nullptr;
	}



	Object * langX_JsonObject_getString(X3rdFunction *func, const X3rdArgs &args) {
		if (args.object == nullptr)
		{
			printf("langX_JsonObject_getString error! NO OBJ!\n");
			return nullptr;
		}

		return nullptr;
	}



	Object * langX_JsonObject_getNumber(X3rdFunction *func, const X3rdArgs &args) {
		if (args.object == nullptr)
		{
			printf("langX_JsonObject_getNumber error! NO OBJ!\n");
			return nullptr;
		}

		return nullptr;
	}



	Object * langX_JsonObject_getJsonObject(X3rdFunction *func, const X3rdArgs &args) {
		if (args.object == nullptr)
		{
			printf("langX_JsonObject_getJsonObject error! NO OBJ!\n");
			return nullptr;
		}

		return nullptr;
	}



	Object * langX_JsonObject_JsonObject_Dtor(X3rdFunction *func, const X3rdArgs &args) {
		if (args.object == nullptr)
		{
			printf("langX_JsonObject_JsonObject_Dtor error! NO OBJ!\n");
			return nullptr;
		}

		return nullptr;
	}



	Object * langX_JsonObject_JsonObject(X3rdFunction *func, const X3rdArgs &args) {
		if (args.object == nullptr)
		{
			printf("langX_JsonObject_JsonObject error! NO OBJ!\n");
			return nullptr;
		}

		return nullptr;
	}



	int regJsonObject(langXState *state, XNameSpace* space) {

		ClassInfo *info = new ClassInfo("JsonObject");
		info->addFunction("getJsonArray", create3rdFunc("getJsonArray", langX_JsonObject_getJsonArray));
		info->addFunction("put", create3rdFunc("put", langX_JsonObject_put));
		info->addFunction("getString", create3rdFunc("getString", langX_JsonObject_getString));
		info->addFunction("getNumber", create3rdFunc("getNumber", langX_JsonObject_getNumber));
		info->addFunction("getJsonObject", create3rdFunc("getJsonObject", langX_JsonObject_getJsonObject));
		info->addFunction("~JsonObject", create3rdFunc("~JsonObject", langX_JsonObject_JsonObject_Dtor));
		info->addFunction("JsonObject", create3rdFunc("JsonObject", langX_JsonObject_JsonObject));

		space->putClass(info);

		return 0;
	}
}


