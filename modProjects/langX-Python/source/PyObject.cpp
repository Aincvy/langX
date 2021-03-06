#include <langX/langXSimple.h>
#include <langX/XArray.h>

#include "RegPythonModule.h"
#include "PythonModule.h"



namespace langX {

	ClassInfo *claxxPyObj = nullptr;

	langXObject * createLangXObjectPyObj(PyObject * pyObj, PyObjectType type) {
		langXObject *obj = claxxPyObj->newObject();
		XClassPyObject * t = createXClassPyObject();
		t->pyObj = pyObj;
		t->type = type;
		obj->set3rdObj(t);

		if (pyObj == nullptr){
		    logPythonErrorMsg();
		} else {
		    // 存在 python 对象
		    detectPyType(t);
		}

		return obj;
	}

	XClassPyObject * createXClassPyObject() {

		XClassPyObject *obj = (XClassPyObject *)calloc(1, sizeof(XClassPyObject));
		obj->type = PyObjectType::Unknown;
		obj->size = -1;
		obj->pyObj = nullptr;
		return obj;
	}

	void freeXClassPyObject(XClassPyObject **obj) {

		if (obj)
		{
			XClassPyObject * a = *obj;
			free(a);
			a = nullptr;
		}
	}


	Object * langX_PyObject_setType(X3rdFunction *func, const X3rdArgs &args) {
		if (args.object == nullptr)
		{
			pythonModuleLogger->error("langX_PyObject_setType error! NO OBJ!");
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
			pythonModuleLogger->error("langX_PyObject_getType error! NO OBJ!");
			return nullptr;
		}

		XClassPyObject *obj = (XClassPyObject *)args.object->get3rdObj();

		return Allocator::allocateNumber((int)obj->type);
	}

	Object * langX_PyObject_toString(X3rdFunction *func, const X3rdArgs &args) {
		if (args.object == nullptr)
		{
			pythonModuleLogger->error("langX_PyObject_toString error! NO OBJ!");
			return nullptr;
		}

		XClassPyObject *obj = (XClassPyObject *)args.object->get3rdObj();
		char *p = nullptr;
		PyArg_Parse(obj->pyObj, "s", &p);

		if (p == nullptr)
		{
			return new String("");
		}
		return new String(p);
	}

	Object * langX_PyObject_toNumber(X3rdFunction *func, const X3rdArgs &args) {
		if (args.object == nullptr)
		{
			pythonModuleLogger->error("langX_PyObject_toNumber error! NO OBJ!");
			return nullptr;
		}

		XClassPyObject *pyObj = (XClassPyObject *)args.object->get3rdObj();
		double a = 0;
		PyArg_Parse(pyObj->pyObj, "d", &a);

		return Allocator::allocateNumber(a);
	}

	Object * langX_PyObject_callMethod(X3rdFunction *func, const X3rdArgs &args) {
		if (args.object == nullptr)
		{
			pythonModuleLogger->error("langX_PyObject_callMethod error! NO OBJ!");
			return nullptr;
		}

		XClassPyObject *pyObj = (XClassPyObject *)args.object->get3rdObj();

		if (PyCallable_Check(pyObj->pyObj) != 1)
		{
			return nullptr;
		}

		Object *a = args.args[0];
		if (a)
		{
			PyObject *arg = nullptr;
			bool flag = false;
			if (a->getType() == OBJECT)
			{
				langXObjectRef *ref1 = (langXObjectRef*)a;
				langXObject *obj = ref1->getRefObject();
				if (!obj->typeCheck("PyObject"))
				{
					return nullptr;
				}

				XClassPyObject *argPyObj = (XClassPyObject *)obj->get3rdObj();
				auto tmp = argPyObj->pyObj;
                if (PyTuple_Check(tmp)) {
                    // 是一个 tuple 类型 ，参数调用得时候只能传递这个类型
                    arg = tmp;
                    flag = true;
                }
			}

            if (!flag) {
                // 自动转换类型, 不支持的类型会返回nullptr
                XArray array(args.index);
                x3rdArgsToArray(args, &array);
                XArrayRef ref(&array);
                arg = langXToPyObject(&ref);
            }

			PyObject *ret = PyEval_CallObject(pyObj->pyObj, arg);
            if (ret == nullptr) {
                logPythonErrorMsg();
                return nullptr;
            }
			return createLangXObjectPyObj(ret, PyObjectType::Unknown)->addRef();
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
			pythonModuleLogger->error("langX_PyObject_newInstance error! NO OBJ!");
			return nullptr;
		}

		XClassPyObject *obj = (XClassPyObject *)args.object->get3rdObj();

		PyObject* ret = PyObject_CallObject(obj->pyObj, NULL);

		return createLangXObjectPyObj(ret, PyObjectType::PyInstance)->addRef();
	}

	Object * langX_PyObject_size(X3rdFunction *func, const X3rdArgs &args) {
		if (args.object == nullptr)
		{
			pythonModuleLogger->error("langX_PyObject_size error! NO OBJ!");
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
			else if (obj->type == PyObjectType::Tuple)
			{
				int i = PyTuple_Size(obj->pyObj);
				obj->size = i;
			}
			else if (obj->type == PyObjectType::PyListX)
			{
				int i = PyList_Size(obj->pyObj);
				obj->size = i;
			}
		}

		return Allocator::allocateNumber(obj->size);
	}



	Object * langX_PyObject_setItem(X3rdFunction *func, const X3rdArgs &args) {
		if (args.object == nullptr)
		{
			pythonModuleLogger->error("langX_PyObject_setItem error! NO OBJ!");
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
					PyTuple_SetItem(obj->pyObj, index, Py_BuildValue("i", num2->getIntValue()));
				}
				else {
					PyTuple_SetItem(obj->pyObj, index, Py_BuildValue("d", num2->getDoubleValue()));
				}
			}
			else if (b->getType() == STRING)
			{
				String *str2 = (String*)b;
				PyTuple_SetItem(obj->pyObj, index, Py_BuildValue("s", str2->getValue()));
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
		else if (obj->type == PyObjectType::PyListX)
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
					PyList_SetItem(obj->pyObj, index, Py_BuildValue("i", num2->getIntValue()));
				}
				else {
					PyList_SetItem(obj->pyObj, index, Py_BuildValue("d", num2->getDoubleValue()));
				}
			}
			else if (b->getType() == STRING)
			{
				String *str2 = (String*)b;
				PyList_SetItem(obj->pyObj, index, Py_BuildValue("s", str2->getValue()));
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
				PyList_SetItem(obj->pyObj, index, Py_BuildValue("o", argPyObj->pyObj));
			}
		}

		return nullptr;
	}


	Object * langX_PyObject_getString(X3rdFunction *func, const X3rdArgs &args) {
		if (args.object == nullptr)
		{
			pythonModuleLogger->error("langX_PyObject_getString error! NO OBJ!");
			return nullptr;
		}

		XClassPyObject *obj = (XClassPyObject *)args.object->get3rdObj();
		Object *a = args.args[0];
		if (!a)
		{
			return Allocator::allocate(NULLOBJECT);
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
			else if (obj->type == PyObjectType::PyListX)
			{
				PyObject * ret = PyList_GetItem(obj->pyObj, i);

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
			pythonModuleLogger->error("langX_PyObject_getNumber error! NO OBJ!");
			return nullptr;
		}

		XClassPyObject *obj = (XClassPyObject *)args.object->get3rdObj();
		Object *a = args.args[0];
		if (!a)
		{
			return Allocator::allocate(NULLOBJECT);
		}

		if (a->getType() == STRING)
		{
			String *str = (String*)a;
			if (obj->type == PyObjectType::Module || obj->type == PyObjectType::Dict)
			{
				PyObject * ret = PyObject_GetAttrString(obj->pyObj, str->getValue());

				double a = 0;
				PyArg_Parse(ret, "d", &a);

				return Allocator::allocateNumber(a);
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

				return Allocator::allocateNumber(a);

			}
			else if (obj->type == PyObjectType::PyListX)
			{
				PyObject * ret = PyList_GetItem(obj->pyObj, i);

				double a = 0;
				PyArg_Parse(ret, "d", &a);

				return Allocator::allocateNumber(a);
			}
		}

		return nullptr;
	}



	Object * langX_PyObject_set_impl(XClassPyObject * obj, Object * key, Object *value)
	{
		if (!key || !value)
		{
			return Allocator::allocate(NULLOBJECT);
		}

		if (obj->pyObj == nullptr)
		{
			return Allocator::allocate(NULLOBJECT);
		}

		if (key->getType() == STRING)
		{
			String *str = (String*)key;
			if (obj->type == PyObjectType::Module || obj->type == PyObjectType::Dict || obj->type == PyObjectType::Unknown)
			{
				PyObject *pyValue = langXToPyObject(value);

				auto ret = PyObject_SetAttrString(obj->pyObj, str->getValue(), pyValue);
                freePyObjectRef(pyValue);

                if (ret == -1) {
                    // 失败
                    logPythonErrorMsg();
                    return Allocator::allocateNumber(0);
                }
				return Allocator::allocateNumber(1);
			}
		}

		return nullptr;
	}

	Object * langX_PyObject_get_impl(XClassPyObject * obj, Object * a)
	{
		if (!a)
		{
			return Allocator::allocate(NULLOBJECT);
		}

		if (obj->pyObj == nullptr)
		{
			return Allocator::allocate(NULLOBJECT);
		}

		if (a->getType() == STRING)
		{
			String *str = (String*)a;
			if (obj->type == PyObjectType::Module || obj->type == PyObjectType::Dict || obj->type == PyObjectType::Unknown)
			{
				PyObject * ret = PyObject_GetAttrString(obj->pyObj, str->getValue());
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
			else if (obj->type == PyObjectType::PyListX)
			{
				PyObject * ret = PyList_GetItem(obj->pyObj, i);
				return createLangXObjectPyObj(ret, PyObjectType::Unknown)->addRef();
			}
		}

		return nullptr;
	}

	Object * langX_PyObject_get(X3rdFunction *func, const X3rdArgs &args) {
		if (args.object == nullptr)
		{
			pythonModuleLogger->error("langX_PyObject_get error! NO OBJ!");
			return nullptr;
		}

		XClassPyObject *obj = (XClassPyObject *)args.object->get3rdObj();
		Object *a = args.args[0];

		return langX_PyObject_get_impl(obj, a);
	}

	Object * langX_PyObject_set(X3rdFunction *func, const X3rdArgs &args) {
		if (args.object == nullptr)
		{
			pythonModuleLogger->error("langX_PyObject_get error! NO OBJ!");
			return nullptr;
		}

		XClassPyObject *obj = (XClassPyObject *)args.object->get3rdObj();
		Object *a = args.args[0];
		Object *b = args.args[1];

		return langX_PyObject_set_impl(obj, a, b);
	}

	Object * langX_PyObject_operator_square_brackets(X3rdFunction *func, const X3rdArgs &args) {
		if (args.object == nullptr)
		{
			pythonModuleLogger->error("langX_PyObject_operator_square_brackets error! NO OBJ!");
			return nullptr;
		}

		return langX_PyObject_get(func, args);
	}

	Object * langX_PyObject_PyObject_Dtor(X3rdFunction *func, const X3rdArgs &args) {
		if (args.object == nullptr)
		{
			pythonModuleLogger->error("langX_PyObject_PyObject_Dtor error! NO OBJ!");
			return nullptr;
		}

		XClassPyObject *obj = (XClassPyObject *)args.object->get3rdObj();

        if (obj->pyObj) {
            Py_DECREF(obj->pyObj);
            obj->pyObj = nullptr;
        }

		freeXClassPyObject(&obj);
		args.object->set3rdObj(nullptr);

		return nullptr;
	}

	Object * langX_PyObject_isNull(X3rdFunction *func, const X3rdArgs &args) {
		if (args.object == nullptr)
		{
			pythonModuleLogger->error("langX_PyObject_isNull error! NO OBJ!");
			return nullptr;
		}

		XClassPyObject *obj = (XClassPyObject *)args.object->get3rdObj();
		if (obj->pyObj == nullptr)
		{
			return Allocator::allocateNumber(1);
		}

		return Allocator::allocateNumber(0);
	}

	Object * langX_PyObject_o(X3rdFunction *func, const X3rdArgs &args) {
		if (args.object == nullptr)
		{
			pythonModuleLogger->error("langX_PyObject_isNull error! NO OBJ!");
			return nullptr;
		}

		XClassPyObject *obj = (XClassPyObject *)args.object->get3rdObj();
		langXObject *tmp = createLangXObjectPyObjEasy(obj->pyObj, obj->type);

		return tmp->addRef();
	}

	Object * langX_PyObject_value(X3rdFunction *func, const X3rdArgs &args) {
		if (args.object == nullptr)
		{
			pythonModuleLogger->error("langX_PyObject_isNull error! NO OBJ!");
			return nullptr;
		}

		XClassPyObject *obj = (XClassPyObject *)args.object->get3rdObj();
		if (PyLong_Check(obj->pyObj) || PyFloat_Check(obj->pyObj))
		{
			return langX_PyObject_toNumber(func, args);
		}
		else if (PyBytes_Check(obj->pyObj) || PyUnicode_Check(obj->pyObj))
		{
			return langX_PyObject_toString(func, args);
		}
		else if (obj->type == PyObjectType::PyBool || PyBool_Check(obj->pyObj))
		{
			int ret = PyObject_IsTrue(obj->pyObj);
			if (ret)
			{
				return Allocator::allocateNumber(1);
			}
			else {
				return Allocator::allocateNumber(0);
			}
		}

		return Allocator::allocate(ObjectType::NULLOBJECT);
	}

	Object * langX_PyObject_detectPyType(X3rdFunction *func, const X3rdArgs &args) {
		if (args.object == nullptr)
		{
			pythonModuleLogger->error("langX_PyObject_isNull error! NO OBJ!");
			return nullptr;
		}

		XClassPyObject *obj = (XClassPyObject *)args.object->get3rdObj();

		detectPyType(obj);

		return nullptr;
	}

	int regPyObject(langXState *state, XNameSpace* space) {

		ClassInfo *info = new ClassInfo("PyObject");
		info->addFunction(create3rdFunc("~PyObject", langX_PyObject_PyObject_Dtor));
		info->addFunction(create3rdFunc("setType", langX_PyObject_setType));
		info->addFunction(create3rdFunc("getType", langX_PyObject_getType));
		info->addFunction(create3rdFunc("toStr", langX_PyObject_toString));
		info->addFunction(create3rdFunc("toString", langX_PyObject_toString));
		info->addFunction(create3rdFunc("toNumber", langX_PyObject_toNumber));
		info->addFunction(create3rdFunc("callMethod", langX_PyObject_callMethod));
		info->addFunction(create3rdFunc("newInstance", langX_PyObject_newInstance));
		info->addFunction(create3rdFunc("size", langX_PyObject_size));
		info->addFunction(create3rdFunc("setItem", langX_PyObject_setItem));
		info->addFunction(create3rdFunc("getString", langX_PyObject_getString));
		info->addFunction(create3rdFunc("getNumber", langX_PyObject_getNumber));
		info->addFunction(create3rdFunc("get", langX_PyObject_get));
		info->addFunction(create3rdFunc("set2", langX_PyObject_set));
		info->addFunction(create3rdFunc("set", langX_PyObject_set));
		info->addFunction(create3rdFunc("operator[]", langX_PyObject_operator_square_brackets));
		info->addFunction(create3rdFunc("isNull", langX_PyObject_isNull));
		info->addFunction(create3rdFunc("o", langX_PyObject_o));
		info->addFunction(create3rdFunc("value", langX_PyObject_value));
		info->addFunction(create3rdFunc("detectPyType", langX_PyObject_detectPyType));

		space->putClass(info);

		claxxPyObj = info;

		return 0;
	}
}
