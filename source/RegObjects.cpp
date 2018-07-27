
#include "../include/RegObjects.h"
#include "../include/RegFunctions.h"
#include "../include/ClassInfo.h"
#include "../include/langXObject.h"
#include "../include/langXObjectRef.h"
#include "../include/Allocator.h"
#include "../include/Environment.h"

namespace langX {

	void regLogger(langXState *state) {
		langXObjectExtend *obj = emptyObject();
		
		
		langXObjectRef *ref = obj->addRef();
		state->getGlobalEnv()->putObject("langXLogger", ref);
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