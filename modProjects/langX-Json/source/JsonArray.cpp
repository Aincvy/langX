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


	Object * langX_JsonArray_setItem(X3rdFunction *func, const X3rdArgs &args) {
		if (args.object == nullptr)
		{
			printf("langX_JsonArray_setItem error! NO OBJ!\n");
			return nullptr;
		}

		return nullptr;
	}



	Object * langX_JsonArray_put(X3rdFunction *func, const X3rdArgs &args) {
		if (args.object == nullptr)
		{
			printf("langX_JsonArray_put error! NO OBJ!\n");
			return nullptr;
		}

		return nullptr;
	}



	Object * langX_JsonArray_getString(X3rdFunction *func, const X3rdArgs &args) {
		if (args.object == nullptr)
		{
			printf("langX_JsonArray_getString error! NO OBJ!\n");
			return nullptr;
		}

		return nullptr;
	}



	Object * langX_JsonArray_getNumber(X3rdFunction *func, const X3rdArgs &args) {
		if (args.object == nullptr)
		{
			printf("langX_JsonArray_getNumber error! NO OBJ!\n");
			return nullptr;
		}

		return nullptr;
	}



	Object * langX_JsonArray_toStringArray(X3rdFunction *func, const X3rdArgs &args) {
		if (args.object == nullptr)
		{
			printf("langX_JsonArray_toStringArray error! NO OBJ!\n");
			return nullptr;
		}

		return nullptr;
	}



	Object * langX_JsonArray_toNumberArray(X3rdFunction *func, const X3rdArgs &args) {
		if (args.object == nullptr)
		{
			printf("langX_JsonArray_toNumberArray error! NO OBJ!\n");
			return nullptr;
		}

		return nullptr;
	}



	Object * langX_JsonArray_size(X3rdFunction *func, const X3rdArgs &args) {
		if (args.object == nullptr)
		{
			printf("langX_JsonArray_size error! NO OBJ!\n");
			return nullptr;
		}

		return nullptr;
	}



	Object * langX_JsonArray_JsonArray_Dtor(X3rdFunction *func, const X3rdArgs &args) {
		if (args.object == nullptr)
		{
			printf("langX_JsonArray_JsonArray_Dtor error! NO OBJ!\n");
			return nullptr;
		}

		return nullptr;
	}



	Object * langX_JsonArray_getJsonArray(X3rdFunction *func, const X3rdArgs &args) {
		if (args.object == nullptr)
		{
			printf("langX_JsonArray_getJsonArray error! NO OBJ!\n");
			return nullptr;
		}

		return nullptr;
	}



	Object * langX_JsonArray_getJsonObject(X3rdFunction *func, const X3rdArgs &args) {
		if (args.object == nullptr)
		{
			printf("langX_JsonArray_getJsonObject error! NO OBJ!\n");
			return nullptr;
		}

		return nullptr;
	}



	Object * langX_JsonArray_JsonArray(X3rdFunction *func, const X3rdArgs &args) {
		if (args.object == nullptr)
		{
			printf("langX_JsonArray_JsonArray error! NO OBJ!\n");
			return nullptr;
		}

		return nullptr;
	}



	int regJsonArray(langXState *state, XNameSpace* space) {

		ClassInfo *info = new ClassInfo("JsonArray");
		info->addFunction("setItem", create3rdFunc("setItem", langX_JsonArray_setItem));
		info->addFunction("put", create3rdFunc("put", langX_JsonArray_put));
		info->addFunction("getString", create3rdFunc("getString", langX_JsonArray_getString));
		info->addFunction("getNumber", create3rdFunc("getNumber", langX_JsonArray_getNumber));
		info->addFunction("toStringArray", create3rdFunc("toStringArray", langX_JsonArray_toStringArray));
		info->addFunction("toNumberArray", create3rdFunc("toNumberArray", langX_JsonArray_toNumberArray));
		info->addFunction("size", create3rdFunc("size", langX_JsonArray_size));
		info->addFunction("~JsonArray", create3rdFunc("~JsonArray", langX_JsonArray_JsonArray_Dtor));
		info->addFunction("getJsonArray", create3rdFunc("getJsonArray", langX_JsonArray_getJsonArray));
		info->addFunction("getJsonObject", create3rdFunc("getJsonObject", langX_JsonArray_getJsonObject));
		info->addFunction("JsonArray", create3rdFunc("JsonArray", langX_JsonArray_JsonArray));

		space->putClass(info);

		return 0;
	}
}


