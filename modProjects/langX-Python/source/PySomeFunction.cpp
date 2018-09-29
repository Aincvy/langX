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



	Object * langX_PyFunctions_Import(X3rdFunction *func, const X3rdArgs &args) {
		
		Object *a = args.args[0];
		if (a == nullptr)
		{
			return Allocator::allocate(ObjectType::NULLOBJECT);;
		}

		if (a->getType() != ObjectType::STRING)
		{
			return Allocator::allocate(ObjectType::NULLOBJECT);;
		}

		String *str = (String*)a;
		str->simpleEscape();
		const char * name = str->getValue();
		PyObject *ret = PyImport_ImportModule(str->getValue());
		langXObject *aobj = claxxPyObj->newObject();
		XClassPyObject * bobj = createXClassPyObject();
		bobj->type = PyObjectType::Module;
		bobj->pyObj = ret;
		aobj->set3rdObj(bobj);

		return aobj->addRef();
	}

	Object * langX_PyFunctions_ToPyObject(X3rdFunction *func, const X3rdArgs &args) {

		Object *a = args.args[0];
		if (a == nullptr)
		{
			return Allocator::allocate(ObjectType::NULLOBJECT);;
		}

		PyObject *pyObj = langXToPyObject(a);
		return createLangXObjectPyObj(pyObj, PyObjectType::Unknown)->addRef();
	}


	int regPySomeFunction(langXState *state, XNameSpace* space) {
		// 注册一些函数进去
		
		space->putFunction("import", create3rdFunc("import", langX_PyFunctions_Import));
		space->putFunction("toPyObject", create3rdFunc("toPyObject", langX_PyFunctions_ToPyObject));

		return 0;
	}

}