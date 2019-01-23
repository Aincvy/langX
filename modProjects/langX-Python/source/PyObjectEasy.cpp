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


namespace langX {

	ClassInfo *claxxPyObjEasy = NULL;

	Object * langX_PyObjectEasy_operator_dot(X3rdFunction *func, const X3rdArgs &args) {
		XClassPyObject *obj = (XClassPyObject *)args.object->get3rdObj();
		if (!obj)
		{
			return nullptr;
		}
		
		// 
		Object *a = args.args[0];

		return langX_PyObject_get_impl(obj,a);
	}
	

	Object * langX_PyObjectEasy_operator_assign(X3rdFunction *func, const X3rdArgs &args) {
		XClassPyObject *obj = (XClassPyObject *)args.object->get3rdObj();
		if (!obj)
		{
			return nullptr;
		}

		// 
		Object *a = args.args[0];
		Object *b = args.args[1];

		return langX_PyObject_set_impl(obj, a,b);
	}

	int regPyObjectEasy(langXState *state, XNameSpace* space) {

		ClassInfo *info = new ClassInfo("PyObjectEasy");
		info->addFunction("~operator.", create3rdFunc("operator.", langX_PyObjectEasy_operator_dot));
		info->addFunction("~operator=", create3rdFunc("operator=", langX_PyObjectEasy_operator_assign));

		space->putClass(info);

		claxxPyObjEasy = info;

		return 0;
	}

	langXObject * createLangXObjectPyObjEasy(PyObject * pyObj, PyObjectType type)
	{	
		langXObject *obj = claxxPyObjEasy->newObject();
		XClassPyObject * t = createXClassPyObject();
		t->pyObj = pyObj;
		t->type = type;
		obj->set3rdObj(t);
		return obj;
	}

}