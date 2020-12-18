
#include "langXSimple.h"

#include "../include/RegPythonModule.h"
#include "../include/PythonModule.h"


namespace langX {


	Object * langX_PythonHook_importModule(X3rdFunction *func, const X3rdArgs &args) {

		Object *a = args.args[0];
		if (a && a->getType() == STRING)
		{
			auto str = (String*)a;
			str->simpleEscape();

			PyObject *ret = PyImport_ImportModule(str->getValue());
            if (ret == nullptr) {
                pythonModuleLogger->error("module %s import failed.", str->getValue());
                logPythonErrorMsg();
                return nullptr;
            }

			langXObject *obj = claxxPyObj->newObject();
			XClassPyObject * myPyObj = createXClassPyObject();
            myPyObj->type = PyObjectType::Module;
            myPyObj->pyObj = ret;
			obj->set3rdObj(myPyObj);
			return obj->addRef();
		}

		return nullptr;
	}


	Object * langX_PythonHook_doSString(X3rdFunction *func, const X3rdArgs &args) {

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

		return nullptr;
	}



	Object * langX_PythonHook_PythonHook(X3rdFunction *func, const X3rdArgs &args) {

		return nullptr;
	}

	Object * langX_PythonHook_newDict(X3rdFunction *func, const X3rdArgs &args) {

		PyObject *ret = PyDict_New();
		return createLangXObjectPyObj(ret, PyObjectType::Dict)->addRef();

	}



	Object * langX_PythonHook_newTuple(X3rdFunction *func, const X3rdArgs &args) {

		Object *a = args.args[0];
		if (a && a->getType() == NUMBER)
		{
			Number *num = (Number*)a;
			PyObject *ret = PyTuple_New(num->getIntValue());
			return createLangXObjectPyObj(ret, PyObjectType::Tuple)->addRef();
		}

		return Allocator::allocate(NULLOBJECT);
	}


	Object * langX_PythonHook_newList(X3rdFunction *func, const X3rdArgs &args) {

		Object *a = args.args[0];
		if (a && a->getType() == NUMBER)
		{
			Number *num = (Number*)a;
			PyObject *ret = PyList_New(num->getIntValue());
			return createLangXObjectPyObj(ret, PyObjectType::PyListX)->addRef();
		}

		return Allocator::allocate(NULLOBJECT);
	}

	Object * langX_PythonHook_printError(X3rdFunction *func, const X3rdArgs &args) {

		PyErr_Print();

		return nullptr;
	}



	Object * langX_PythonHook_clearError(X3rdFunction *func, const X3rdArgs &args) {
		
		PyErr_Clear();
		return nullptr;
	}


	int regPythonHook(langXState *state, XNameSpace* space) {

		ClassInfo *info = new ClassInfo("PythonHook");
		info->addFunction("importModule", create3rdFunc("import", langX_PythonHook_importModule));
		info->addFunction("doSString", create3rdFunc("doSString", langX_PythonHook_doSString));
		info->addFunction("~PythonHook", create3rdFunc("~PythonHook", langX_PythonHook_PythonHook_Dtor));
		info->addFunction("PythonHook", create3rdFunc("PythonHook", langX_PythonHook_PythonHook));
		info->addFunction("newDict", create3rdFunc("newDict", langX_PythonHook_newDict));
		info->addFunction("newTuple", create3rdFunc("newTuple", langX_PythonHook_newTuple));
		info->addFunction("newList", create3rdFunc("newList", langX_PythonHook_newList));
		info->addFunction("printError", create3rdFunc("printError", langX_PythonHook_printError));
		info->addFunction("clearError", create3rdFunc("clearError", langX_PythonHook_clearError));
		space->putClass(info);

		return 0;
	}
}


