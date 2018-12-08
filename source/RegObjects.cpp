
#include "../include/RegObjects.h"
#include "../include/RegFunctions.h"
#include "../include/ClassInfo.h"
#include "../include/langXObject.h"
#include "../include/langXObjectRef.h"
#include "../include/Allocator.h"
#include "../include/Environment.h"
#include "../include/LogManager.h"

namespace langX {

	void regLogger(langXState *state) {
		ClassInfo *loggerClass = regLoggerClass(state);

		langXObject *obj= loggerClass->newObject(false);

		state->getGlobalEnv()->putObject("logger", obj->addRef());
		logger->debug("reg logger object to global.");
	}

	void regObjects(langXState * state)
	{
		regLogger(state);

	}

	langXObjectExtend * emptyObject()
	{
		return Allocator::newExtendObject(c_empty_class);
	}

}