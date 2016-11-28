#include "../include/RegPythonModule.h"

#include "../../../include/ClassInfo.h"
#include "../../../include/YLlangX.h"
#include "../../../include/Object.h"
#include "../../../include/langXObject.h"
#include "../../../include/langXObjectRef.h"
#include "../../../include/Allocator.h"
#include "../../../include/Number.h"
#include "../../../include/String.h"


#ifdef WIN32 
#include "../../../lib/Python-3.5.2/Include/Python.h"
#else
#include <python3.5m/Python.h>
#endif

namespace langX {


	Object * langX_PythonHook_call(X3rdFunction *func, const X3rdArgs &args) {
		if (args.object == nullptr)
		{
			printf("langX_PythonHook_call error! NO OBJ!\n");
			return nullptr;
		}
	


		return nullptr;
	}


	Object * langX_PythonHook_operator_square_brackets(X3rdFunction *func, const X3rdArgs &args) {
		if (args.object == nullptr)
		{
			printf("langX_PythonHook_operator[] error! NO OBJ!\n");
			return nullptr;
		}

		return nullptr;
	}


	Object * langX_PythonHook_get(X3rdFunction *func, const X3rdArgs &args) {
		if (args.object == nullptr)
		{
			printf("langX_PythonHook_get error! NO OBJ!\n");
			return nullptr;
		}

		return nullptr;
	}


	Object * langX_PythonHook_import(X3rdFunction *func, const X3rdArgs &args) {
		if (args.object == nullptr)
		{
			printf("langX_PythonHook_import error! NO OBJ!\n");
			return nullptr;
		}

		return nullptr;
	}


	Object * langX_PythonHook_doSString(X3rdFunction *func, const X3rdArgs &args) {
		if (args.object == nullptr)
		{
			printf("langX_PythonHook_doSString error! NO OBJ!\n");
			return nullptr;
		}

		Object *a = args.args[0];
		if (a && a->getType() == STRING)
		{
			String *str = (String*)a;
			str->simpleEscape();

			PyRun_SimpleString(str->getValue());
		}

		return nullptr;
	}


	Object * langX_PythonHook_PythonHook_Dtor(X3rdFunction *func, const X3rdArgs &args) {
		if (args.object == nullptr)
		{
			printf("langX_PythonHook_PythonHook_Dtor error! NO OBJ!\n");
			return nullptr;
		}

		return nullptr;
	}



	Object * langX_PythonHook_PythonHook(X3rdFunction *func, const X3rdArgs &args) {
		if (args.object == nullptr)
		{
			printf("langX_PythonHook_PythonHook error! NO OBJ!\n");
			return nullptr;
		}

		return nullptr;
	}



	int regPythonHook(langXState *state, XNameSpace* space) {

		ClassInfo *info = new ClassInfo("PythonHook");
		info->addFunction("call", create3rdFunc("call", langX_PythonHook_call));
		info->addFunction("operator[]", create3rdFunc("operator[]", langX_PythonHook_operator_square_brackets));
		info->addFunction("get", create3rdFunc("get", langX_PythonHook_get));
		info->addFunction("import", create3rdFunc("import", langX_PythonHook_import));
		info->addFunction("doSString", create3rdFunc("doSString", langX_PythonHook_doSString));
		info->addFunction("~PythonHook", create3rdFunc("~PythonHook", langX_PythonHook_PythonHook_Dtor));
		info->addFunction("PythonHook", create3rdFunc("PythonHook", langX_PythonHook_PythonHook));
		space->putClass(info);

		return 0;
	}
}


