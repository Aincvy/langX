
#include <langXSimple.h>

#include "../include/PythonModule.h"
#include "../include/RegPythonModule.h"

namespace langX {

    PythonModule* pythonModule;
    Logger* pythonModuleLogger;

	PythonModule::PythonModule()
	{
		this->setName("python");
	}

	PythonModule::~PythonModule()
	{
	}

	int PythonModule::init(langXState *state)
	{
	    pythonModuleLogger = m_logger;
		m_logger->debug("init langX-Python 库. " );
		m_logger->debug("python version: %s", Py_GetVersion());

		XNameSpace *space = state->getNameSpaceOrCreate("langX.python");

		regPythonLib(state, space);
		regPythonHook(state, space);
		regPyException(state, space);
		regPyObjectType(state, space);
		regPyObject(state, space);
		regPyObjectEasy(state, space);

		regPySomeFunction(state, space);

		return 0;
	}

	int PythonModule::unload(langXState *)
	{
		return 0;
	}

    const char *PythonModule::getDescription() const {
        return "bridge python functions...  you can call python library...";
    }

    const char *PythonModule::getAuthor() const {
        return "Aincvy(aincvy@gmail.com)";
    }

    const char *PythonModule::getRepository() const {
        return "https://github.com/Aincvy/langX";
    }

    const char *PythonModule::getVersion() const {
        return "0.0.1";
    }

    void logPythonErrorMsg(){
        auto ex = PyErr_Occurred();
        if (!ex) {
            return;
        }

        PyObject *pType, *pValue, *pTraceback;
        PyErr_Fetch(&pType, &pValue, &pTraceback);
        PyErr_NormalizeException(&pType, &pValue, &pTraceback);

        //Get error type and message
        PyObject* str_exc_type = PyObject_Repr(pType);
        PyObject* pyStr = PyUnicode_AsEncodedString(str_exc_type, "utf-8", "AS_STRING Error ~");
        const char *strExcType =  PyBytes_AS_STRING(pyStr);

        PyObject* str_exc_value = PyObject_Repr(pValue);
        PyObject* pyExcValueStr = PyUnicode_AsEncodedString(str_exc_value, "utf-8", "AS_STRING Error ~");
        const char *strExcValue =  PyBytes_AS_STRING(pyExcValueStr);

        pythonModuleLogger->error("Python Error Got!");
        pythonModuleLogger->error("error type: %s", strExcType);
        pythonModuleLogger->error("error  msg: %s", strExcValue);

        Py_XDECREF(pType);
        Py_XDECREF(pValue);
        Py_XDECREF(pTraceback);

        Py_XDECREF(str_exc_type);
        Py_XDECREF(pyStr);

        Py_XDECREF(str_exc_value);
        Py_XDECREF(pyExcValueStr);
    }


    void detectPyType(XClassPyObject *obj) {
        PyObject *pyObj = obj->pyObj;

        if (PyDict_Check(pyObj))
        {
            obj->type = PyObjectType::Dict;
        }
        else if (PyTuple_Check(pyObj))
        {
            obj->type = PyObjectType::Tuple;
        }
        else if (PyList_Check(pyObj))
        {
            obj->type = PyObjectType::PyListX;
        }
        else if (PyLong_Check(pyObj))
        {
            obj->type = PyObjectType::PyNumber;
        }
        else if (PyBool_Check(pyObj))
        {
            obj->type = PyObjectType::PyBool;
        }
        else if (PyBytes_Check(pyObj))
        {
            obj->type = PyObjectType::PyString;
        }
        else if (PyModule_Check(pyObj))
        {
            obj->type = PyObjectType::Module;
        }

    }

    //
    PyObject * langXToPyObject(Object *obj) {

        Object *value = obj;
        PyObject *pyValue = nullptr;
        if (value->getType() == ObjectType::STRING)
        {
            String *t = (String*)value;
            pyValue = Py_BuildValue("s", t->getValue());
        }
        else if (value->getType() == ObjectType::NUMBER)
        {
            Number *t = (Number*)value;
            if (t->isInteger())
            {
                pyValue = Py_BuildValue("i", t->getIntValue());
            }
            else {
                pyValue = Py_BuildValue("d", t->getDoubleValue());
            }
        }
        else if (value->getType() == ObjectType::XARRAY)
        {
            // 数组
            XArray *array = ((XArrayRef*)value)->getArray();
            int length = array->getLength();
            pyValue = PyTuple_New(length);
            for (size_t i = 0; i < length; i++)
            {
                Object * a = array->at(i);
                PyObject * t = langXToPyObject(a);

                PyTuple_SetItem(pyValue, i, t);
            }
        }
        else if (value->getType() == ObjectType::NULLOBJECT)
        {
            Py_RETURN_NONE;
        }

        return pyValue;
    }

}

int loadModule(langX::X3rdModule *& mod) {
	
	langX::pythonModule = new langX::PythonModule();
    mod = langX::pythonModule;

	return 0;
}
