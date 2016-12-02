#include "../include/RegPythonModule.h"
#include "../include/PythonModule.h"

#include "../../../include/Function.h"
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

extern langX::ClassInfo *claxxPyObj;

namespace langX {

	Object * langX_PythonHook_importModule(X3rdFunction *func, const X3rdArgs &args) {
		if (args.object == nullptr)
		{
			printf("langX_PythonHook_import error! NO OBJ!\n");
			return nullptr;
		}

		Object *a = args.args[0];
		if (a && a->getType() == STRING)
		{
			String *str = (String*)a;
			str->simpleEscape();

			PyObject *ret = PyImport_ImportModule(str->getValue());
			langXObject *aobj = claxxPyObj->newObject();
			XClassPyObject * bobj = createXClassPyObject();
			bobj->type = PyObjectType::Module;
			bobj->pyObj = ret;
			aobj->set3rdObj(bobj);
			return aobj->addRef();
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

	Object * langX_PythonHook_newDict(X3rdFunction *func, const X3rdArgs &args) {
		if (args.object == nullptr)
		{
			printf("langX_PythonHook_newDict error! NO OBJ!\n");
			return nullptr;
		}

		PyObject *ret = PyDict_New();
		return createLangXObjectPyObj(ret, PyObjectType::Dict)->addRef();

	}



	Object * langX_PythonHook_newTuple(X3rdFunction *func, const X3rdArgs &args) {
		if (args.object == nullptr)
		{
			printf("langX_PythonHook_newTuple error! NO OBJ!\n");
			return nullptr;
		}

		Object *a = args.args[0];
		if (a && a->getType() == NUMBER)
		{
			Number *num = (Number*)a;
			PyObject *ret = PyTuple_New(num->getIntValue());
			return createLangXObjectPyObj(ret, PyObjectType::Tuple)->addRef();
		}

		return getState()->getAllocator().allocate(NULLOBJECT);
	}



	int regPythonHook(langXState *state, XNameSpace* space) {

		ClassInfo *info = new ClassInfo("PythonHook");
		info->addFunction("importModule", create3rdFunc("import", langX_PythonHook_importModule));
		info->addFunction("doSString", create3rdFunc("doSString", langX_PythonHook_doSString));
		info->addFunction("~PythonHook", create3rdFunc("~PythonHook", langX_PythonHook_PythonHook_Dtor));
		info->addFunction("PythonHook", create3rdFunc("PythonHook", langX_PythonHook_PythonHook));
		info->addFunction("newDict", create3rdFunc("newDict", langX_PythonHook_newDict));
		info->addFunction("newTuple", create3rdFunc("newTuple", langX_PythonHook_newTuple));
		space->putClass(info);

		return 0;
	}
}

