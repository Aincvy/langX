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

langX::ClassInfo *claxxPyObj = NULL;

namespace langX {

	langXObject * createLangXObjectPyObj(PyObject * pyObj , PyObjectType type) {
		langXObject *obj = claxxPyObj->newObject();
		XClassPyObject * t = createXClassPyObject();
		t->pyObj = pyObj;
		t->type = type;
		obj->set3rdObj(t);
		return obj;
	}

	XClassPyObject * createXClassPyObject() {

		XClassPyObject *obj = (XClassPyObject *)calloc(1, sizeof(XClassPyObject));
		obj->type = PyObjectType::Unknown;
		obj->size = -1;
		obj->pyObj = NULL;
		return obj;
	}

	void freeXClassPyObject(XClassPyObject **obj) {

		if (obj)
		{
			XClassPyObject * a = *obj;
			free(a);
			a = NULL;
		}
	}


	Object * langX_PyObject_setType(X3rdFunction *func, const X3rdArgs &args) {
		if (args.object == nullptr)
		{
			printf("langX_PyObject_setType error! NO OBJ!\n");
			return nullptr;
		}

		Object * a = args.args[0];
		if (a && a->getType() == NUMBER)
		{
			Number * b = (Number*)a;
			XClassPyObject *obj = (XClassPyObject *)args.object->get3rdObj();
			obj->type = (PyObjectType)b->getIntValue();
		}

		return nullptr;
	}



	Object * langX_PyObject_getType(X3rdFunction *func, const X3rdArgs &args) {
		if (args.object == nullptr)
		{
			printf("langX_PyObject_getType error! NO OBJ!\n");
			return nullptr;
		}

		XClassPyObject *obj = (XClassPyObject *)args.object->get3rdObj();

		return getState()->getAllocator().allocateNumber((int)obj->type);
	}



	Object * langX_PyObject_toString(X3rdFunction *func, const X3rdArgs &args) {
		if (args.object == nullptr)
		{
			printf("langX_PyObject_toString error! NO OBJ!\n");
			return nullptr;
		}

		XClassPyObject *obj = (XClassPyObject *)args.object->get3rdObj();
		char *p = NULL;
		PyArg_Parse(obj->pyObj, "s", &p);
	
		return new String(p);
	}



	Object * langX_PyObject_toNumber(X3rdFunction *func, const X3rdArgs &args) {
		if (args.object == nullptr)
		{
			printf("langX_PyObject_toNumber error! NO OBJ!\n");
			return nullptr;
		}

		XClassPyObject *pyObj = (XClassPyObject *)args.object->get3rdObj();
		double a = 0;
		PyArg_Parse(pyObj->pyObj, "d", &a);

		return getState()->getAllocator().allocateNumber(a);
	}

	Object * langX_PyObject_callMethod(X3rdFunction *func, const X3rdArgs &args) {
		if (args.object == nullptr)
		{
			printf("langX_PyObject_callMethod error! NO OBJ!\n");
			return nullptr;
		}

		XClassPyObject *pyObj = (XClassPyObject *)args.object->get3rdObj();

		if (PyCallable_Check(pyObj->pyObj) != 1)
		{
			return nullptr;
		}

		Object *a = args.args[0];
		if (a )
		{
			if (a->getType() == OBJECT)
			{
				langXObjectRef *ref1 = (langXObjectRef*)a;
				langXObject *obj = ref1->getRefObject();
				if (!obj->typeCheck("PyObject"))
				{
					return nullptr;
				}

				XClassPyObject *argPyObj = (XClassPyObject *)obj->get3rdObj();
				PyObject *ret = PyEval_CallObject(pyObj->pyObj, argPyObj->pyObj);
				return createLangXObjectPyObj(ret, PyObjectType::Unknown)->addRef();
			}
		}
		else {
			PyObject *ret = PyEval_CallObject(pyObj->pyObj, NULL);
			return createLangXObjectPyObj(ret, PyObjectType::Unknown)->addRef();
		}


		return nullptr;
	}



	Object * langX_PyObject_newInstance(X3rdFunction *func, const X3rdArgs &args) {
		if (args.object == nullptr)
		{
			printf("langX_PyObject_newInstance error! NO OBJ!\n");
			return nullptr;
		}

		XClassPyObject *obj = (XClassPyObject *)args.object->get3rdObj();
		
		PyObject* ret= PyObject_CallObject(obj->pyObj, NULL);

		return createLangXObjectPyObj(ret, PyObjectType::PyInstance )->addRef();
	}



	Object * langX_PyObject_size(X3rdFunction *func, const X3rdArgs &args) {
		if (args.object == nullptr)
		{
			printf("langX_PyObject_size error! NO OBJ!\n");
			return nullptr;
		}

		XClassPyObject *obj = (XClassPyObject *)args.object->get3rdObj();
		if (obj->size == -1)
		{
			if (obj->type == PyObjectType::Dict)
			{
				int i = PyDict_Size(obj->pyObj);
				obj->size = i;
			}
			else if (obj->size == PyObjectType::Tuple)
			{
				int i = PyTuple_Size(obj->pyObj);
				obj->size = i;
			}
		}

		return getState()->getAllocator().allocateNumber(obj->size);
	}



	Object * langX_PyObject_setItem(X3rdFunction *func, const X3rdArgs &args) {
		if (args.object == nullptr)
		{
			printf("langX_PyObject_setItem error! NO OBJ!\n");
			return nullptr;
		}

		Object * a = args.args[0];
		Object * b = args.args[1];
		if (!a || !b)
		{
			return nullptr;
		}

		XClassPyObject *obj = (XClassPyObject *)args.object->get3rdObj();
		if (obj->type == PyObjectType::Tuple)
		{
			if (a->getType() != NUMBER)
			{
				return nullptr;
			}
			Number *num = (Number*)a;
			int index = num->getIntValue();

			if (b->getType() == NUMBER)
			{
				Number *num2 = (Number*)b;
				if (num2->isInteger())
				{
					PyTuple_SetItem(obj->pyObj, index, Py_BuildValue("i",num2->getIntValue()));
				}
				else {
					PyTuple_SetItem(obj->pyObj, index, Py_BuildValue("d", num2->getDoubleValue()));
				}
			}
			else if (b->getType() == STRING)
			{
				String *str2 = (String*)b;
				PyTuple_SetItem(obj->pyObj, index, Py_BuildValue("s", str2->getValue() ));
			}
			else if (b->getType() == OBJECT)
			{
				
				langXObjectRef *ref1 = (langXObjectRef*)b;
				langXObject *robj = ref1->getRefObject();
				if (!robj->typeCheck("PyObject"))
				{
					return nullptr;
				}

				XClassPyObject *argPyObj = (XClassPyObject *)robj->get3rdObj();
				PyTuple_SetItem(obj->pyObj, index, Py_BuildValue("o", argPyObj->pyObj));
			}
		}
		else if (obj->type == PyObjectType::Dict)
		{
			if (a->getType() != STRING)
			{
				return nullptr;
			}

			String *str = (String*)a;
			const char * index = str->getValue();
			if (b->getType() == NUMBER)
			{
				Number *num2 = (Number*)b;
				if (num2->isInteger())
				{
					PyDict_SetItemString(obj->pyObj, index, Py_BuildValue("i", num2->getIntValue()));
				}
				else {
					PyDict_SetItemString(obj->pyObj, index, Py_BuildValue("d", num2->getDoubleValue()));
				}
			}
			else if (b->getType() == STRING)
			{
				String *str2 = (String*)b;
				PyDict_SetItemString(obj->pyObj, index, Py_BuildValue("s", str2->getValue()));
			}
			else if (b->getType() == OBJECT)
			{
				langXObjectRef *ref1 = (langXObjectRef*)b;
				langXObject *robj = ref1->getRefObject();
				if (!robj->typeCheck("PyObject"))
				{
					return nullptr;
				}

				XClassPyObject *argPyObj = (XClassPyObject *)robj->get3rdObj();
				PyDict_SetItemString(obj->pyObj, index, Py_BuildValue("o", argPyObj->pyObj));
			}
		}

		return nullptr;
	}


	Object * langX_PyObject_getString(X3rdFunction *func, const X3rdArgs &args) {
		if (args.object == nullptr)
		{
			printf("langX_PyObject_getString error! NO OBJ!\n");
			return nullptr;
		}

		XClassPyObject *obj = (XClassPyObject *)args.object->get3rdObj();
		Object *a = args.args[0];
		if (!a)
		{
			return getState()->getAllocator().allocate(NULLOBJECT);
		}

		if (a->getType() == STRING)
		{
			String *str = (String*)a;
			if (obj->type == PyObjectType::Module || obj->type == PyObjectType::Dict)
			{
				PyObject * ret = PyObject_GetAttrString(obj->pyObj, str->getValue());

				char *p = NULL;
				PyArg_Parse(obj->pyObj, "s", &p);

				return new String(p);
			}
		}
		else if (a->getType() == NUMBER)
		{
			int i = ((Number*)a)->getIntValue();
			if (obj->type == PyObjectType::Tuple)
			{
				PyObject * ret = PyTuple_GetItem(obj->pyObj, i);

				char *p = NULL;
				PyArg_Parse(obj->pyObj, "s", &p);

				return new String(p);

			}
		}

		return nullptr;
	}



	Object * langX_PyObject_getNumber(X3rdFunction *func, const X3rdArgs &args) {
		if (args.object == nullptr)
		{
			printf("langX_PyObject_getNumber error! NO OBJ!\n");
			return nullptr;
		}

		XClassPyObject *obj = (XClassPyObject *)args.object->get3rdObj();
		Object *a = args.args[0];
		if (!a)
		{
			return getState()->getAllocator().allocate(NULLOBJECT);
		}

		if (a->getType() == STRING)
		{
			String *str = (String*)a;
			if (obj->type == PyObjectType::Module || obj->type == PyObjectType::Dict)
			{
				PyObject * ret = PyObject_GetAttrString(obj->pyObj, str->getValue());

				double a = 0;
				PyArg_Parse(ret, "d", &a);

				return getState()->getAllocator().allocateNumber(a);

				
			}
		}
		else if (a->getType() == NUMBER)
		{
			int i = ((Number*)a)->getIntValue();
			if (obj->type == PyObjectType::Tuple)
			{
				PyObject * ret = PyTuple_GetItem(obj->pyObj, i);

				double a = 0;
				PyArg_Parse(ret, "d", &a);

				return getState()->getAllocator().allocateNumber(a);
				
			}
		}

		return nullptr;
	}



	Object * langX_PyObject_get(X3rdFunction *func, const X3rdArgs &args) {
		if (args.object == nullptr)
		{
			printf("langX_PyObject_get error! NO OBJ!\n");
			return nullptr;
		}
		
		XClassPyObject *obj = (XClassPyObject *)args.object->get3rdObj();
		Object *a = args.args[0];
		if (!a)
		{
			return getState()->getAllocator().allocate(NULLOBJECT);
		}

		if (a->getType() == STRING)
		{
			String *str = (String*)a;
			if (obj->type == PyObjectType::Module || obj->type == PyObjectType::Dict)
			{
				PyObject * ret =PyObject_GetAttrString(obj->pyObj, str->getValue());
				return createLangXObjectPyObj(ret, PyObjectType::Unknown)->addRef();
			}
		}
		else if (a->getType() == NUMBER)
		{
			int i = ((Number*)a)->getIntValue();
			if (obj->type == PyObjectType::Tuple)
			{
				PyObject * ret = PyTuple_GetItem(obj->pyObj, i);
				return createLangXObjectPyObj(ret, PyObjectType::Unknown)->addRef();
			}
		}

		return nullptr;
	}



	Object * langX_PyObject_operator_square_brackets(X3rdFunction *func, const X3rdArgs &args) {
		if (args.object == nullptr)
		{
			printf("langX_PyObject_operator_square_brackets error! NO OBJ!\n");
			return nullptr;
		}

		return langX_PyObject_get(func,args);
	}

	Object * langX_PyObject_PyObject_Dtor(X3rdFunction *func, const X3rdArgs &args) {
		if (args.object == nullptr)
		{
			printf("langX_PyObject_PyObject_Dtor error! NO OBJ!\n");
			return nullptr;
		}

		XClassPyObject *obj = (XClassPyObject *)args.object->get3rdObj();
		Py_DECREF(obj->pyObj);
		obj->pyObj = NULL;
		freeXClassPyObject(&obj);
		args.object->set3rdObj(nullptr);

		return nullptr;
	}


	int regPyObject(langXState *state, XNameSpace* space) {

		ClassInfo *info = new ClassInfo("PyObject");
		info->addFunction("~PyObject", create3rdFunc("~PyObject", langX_PyObject_PyObject_Dtor));
		info->addFunction("setType", create3rdFunc("setType", langX_PyObject_setType));
		info->addFunction("getType", create3rdFunc("getType", langX_PyObject_getType));
		info->addFunction("toStr", create3rdFunc("toStr", langX_PyObject_toString));
		info->addFunction("toNumber", create3rdFunc("toNumber", langX_PyObject_toNumber));
		info->addFunction("callMethod", create3rdFunc("callMethod", langX_PyObject_callMethod));
		info->addFunction("newInstance", create3rdFunc("newInstance", langX_PyObject_newInstance));
		info->addFunction("size", create3rdFunc("size", langX_PyObject_size));
		info->addFunction("setItem", create3rdFunc("setItem", langX_PyObject_setItem));
		info->addFunction("getString", create3rdFunc("getString", langX_PyObject_getString));
		info->addFunction("getNumber", create3rdFunc("getNumber", langX_PyObject_getNumber));
		info->addFunction("get", create3rdFunc("get", langX_PyObject_get));
		info->addFunction("operator[]", create3rdFunc("operator[]", langX_PyObject_operator_square_brackets));

		space->putClass(info);

		claxxPyObj = info;

		return 0;
	}
}


