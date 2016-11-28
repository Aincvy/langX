#include "../include/RegPythonModule.h"

#include "../../../include/ClassInfo.h"
#include "../../../include/YLlangX.h"
#include "../../../include/Object.h"
#include "../../../include/langXObject.h"
#include "../../../include/langXObjectRef.h"
#include "../../../include/Allocator.h"
#include "../../../include/Number.h"

#ifdef WIN32 
#include "../../../lib/Python-3.5.2/Include/Python.h"
#else
#include <python3.5m/Python.h>
#endif


namespace langX {


	Object * langX_PyObject_setType(X3rdFunction *func, const X3rdArgs &args) {
		if (args.object == nullptr)
		{
			printf("langX_PyObject_setType error! NO OBJ!\n");
			return nullptr;
		}

		return nullptr;
	}



	Object * langX_PyObject_getType(X3rdFunction *func, const X3rdArgs &args) {
		if (args.object == nullptr)
		{
			printf("langX_PyObject_getType error! NO OBJ!\n");
			return nullptr;
		}

		return nullptr;
	}



	Object * langX_PyObject_toString(X3rdFunction *func, const X3rdArgs &args) {
		if (args.object == nullptr)
		{
			printf("langX_PyObject_toString error! NO OBJ!\n");
			return nullptr;
		}

		return nullptr;
	}



	Object * langX_PyObject_toNumber(X3rdFunction *func, const X3rdArgs &args) {
		if (args.object == nullptr)
		{
			printf("langX_PyObject_toNumber error! NO OBJ!\n");
			return nullptr;
		}

		return nullptr;
	}



	Object * langX_PyObject_toDictFromModule(X3rdFunction *func, const X3rdArgs &args) {
		if (args.object == nullptr)
		{
			printf("langX_PyObject_toDictFromModule error! NO OBJ!\n");
			return nullptr;
		}

		return nullptr;
	}



	Object * langX_PyObject_callMethod(X3rdFunction *func, const X3rdArgs &args) {
		if (args.object == nullptr)
		{
			printf("langX_PyObject_callMethod error! NO OBJ!\n");
			return nullptr;
		}

		return nullptr;
	}



	Object * langX_PyObject_newInstance(X3rdFunction *func, const X3rdArgs &args) {
		if (args.object == nullptr)
		{
			printf("langX_PyObject_newInstance error! NO OBJ!\n");
			return nullptr;
		}

		return nullptr;
	}



	Object * langX_PyObject_size(X3rdFunction *func, const X3rdArgs &args) {
		if (args.object == nullptr)
		{
			printf("langX_PyObject_size error! NO OBJ!\n");
			return nullptr;
		}

		return nullptr;
	}



	Object * langX_PyObject_setItem(X3rdFunction *func, const X3rdArgs &args) {
		if (args.object == nullptr)
		{
			printf("langX_PyObject_setItem error! NO OBJ!\n");
			return nullptr;
		}

		return nullptr;
	}



	Object * langX_PyObject_put(X3rdFunction *func, const X3rdArgs &args) {
		if (args.object == nullptr)
		{
			printf("langX_PyObject_put error! NO OBJ!\n");
			return nullptr;
		}

		return nullptr;
	}



	Object * langX_PyObject_getString(X3rdFunction *func, const X3rdArgs &args) {
		if (args.object == nullptr)
		{
			printf("langX_PyObject_getString error! NO OBJ!\n");
			return nullptr;
		}

		return nullptr;
	}



	Object * langX_PyObject_getNumber(X3rdFunction *func, const X3rdArgs &args) {
		if (args.object == nullptr)
		{
			printf("langX_PyObject_getNumber error! NO OBJ!\n");
			return nullptr;
		}

		return nullptr;
	}



	Object * langX_PyObject_get(X3rdFunction *func, const X3rdArgs &args) {
		if (args.object == nullptr)
		{
			printf("langX_PyObject_get error! NO OBJ!\n");
			return nullptr;
		}

		return nullptr;
	}



	Object * langX_PyObject_operator_square_brackets(X3rdFunction *func, const X3rdArgs &args) {
		if (args.object == nullptr)
		{
			printf("langX_PyObject_operator_square_brackets error! NO OBJ!\n");
			return nullptr;
		}

		return nullptr;
	}



	int regPyObject(langXState *state, XNameSpace* space) {

		ClassInfo *info = new ClassInfo("PyObject");
		info->addFunction("setType", create3rdFunc("setType", langX_PyObject_setType));
		info->addFunction("getType", create3rdFunc("getType", langX_PyObject_getType));
		info->addFunction("toString", create3rdFunc("toString", langX_PyObject_toString));
		info->addFunction("toNumber", create3rdFunc("toNumber", langX_PyObject_toNumber));
		info->addFunction("toDictFromModule", create3rdFunc("toDictFromModule", langX_PyObject_toDictFromModule));
		info->addFunction("callMethod", create3rdFunc("callMethod", langX_PyObject_callMethod));
		info->addFunction("newInstance", create3rdFunc("newInstance", langX_PyObject_newInstance));
		info->addFunction("size", create3rdFunc("size", langX_PyObject_size));
		info->addFunction("setItem", create3rdFunc("setItem", langX_PyObject_setItem));
		info->addFunction("put", create3rdFunc("put", langX_PyObject_put));
		info->addFunction("getString", create3rdFunc("getString", langX_PyObject_getString));
		info->addFunction("getNumber", create3rdFunc("getNumber", langX_PyObject_getNumber));
		info->addFunction("get", create3rdFunc("get", langX_PyObject_get));
		info->addFunction("operator[]", create3rdFunc("operator[]", langX_PyObject_operator_square_brackets));

		space->putClass(info);

		return 0;
	}
}


