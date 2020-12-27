#include <langX/langXSimple.h>
#include <langX/Environment.h>

#include "../include/PythonModule.h"
#include "../include/RegPythonModule.h"

static langX::ClassInfo *pyExceptionClass;

namespace langX {

	Object * langX_PyException_PyException(X3rdFunction *func, const X3rdArgs & args) {
		if (args.object == NULL)
		{
			printf("langX_PyException_PyException error! NO OBJ!\n");
			return NULL;
		}

		langXObject * object = args.object;
		if (args.index <= 0)
		{
			printf("langX_PyException_PyException error! NO ARG!\n");
			return NULL;
		}

		if (args.args[0]->getType() != STRING)
		{
			printf("langX_PyException_PyException error! TYPE ERROR!\n");
			return NULL;
		}

		object->setMember("message", args.args[0]);
		return NULL;
	}

	int regPyException(langXState *state, XNameSpace* space) {

		// python 库 运行的时候出现的异常
		ClassInfo * exception = state->getGlobalEnv()->getClass("Exception");

		ClassInfo *pyException = new ClassInfo("PyException");
		pyException->setParent(exception);
		pyException->addFunction("PyException", create3rdFunc("PyException", langX_PyException_PyException));
		space->putClass(pyException);

        pyExceptionClass = pyException;

		return 0;
	}

	langXObject * newPyException(const char * message) {

		langXObject *obj = pyExceptionClass->newObject();
		obj->setMember("message", new String(message));
		return obj;

	}

}
