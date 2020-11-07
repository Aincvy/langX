#include "../../include/RegObjects.h"

#include "../../include/ClassInfo.h"
#include "../../include/YLlangX.h"
#include "../../include/Object.h"
#include "../../include/langXObject.h"
#include "../../include/langXObjectRef.h"
#include "../../include/Allocator.h"
#include "../../include/Number.h"
#include "../../include/XNameSpace.h"
#include "../../include/LogManager.h"
#include "../../include/StringType.h"

namespace langX {

	Object * langX_langXLogger_info(X3rdFunction *func, const X3rdArgs &args) {
		if (args.object == nullptr)
		{
			printf("langX_langXLogger_info error! NO OBJ!\n");
			return nullptr;
		}

		Object *a = args.args[0];
		if (a && a->getType() == ObjectType::STRING)
		{
			String *string = (String*)a;
			const char * v = string->getValue();
			logger->info(v);
		}

		return nullptr;
	}


	Object * langX_langXLogger_debug(X3rdFunction *func, const X3rdArgs &args) {
		if (args.object == nullptr)
		{
			printf("langX_langXLogger_debug error! NO OBJ!\n");
			return nullptr;
		}

		return nullptr;
	}


	Object * langX_langXLogger_error(X3rdFunction *func, const X3rdArgs &args) {
		if (args.object == nullptr)
		{
			printf("langX_langXLogger_error error! NO OBJ!\n");
			return nullptr;
		}

		return nullptr;
	}


	Object * langX_langXLogger_trace(X3rdFunction *func, const X3rdArgs &args) {
		if (args.object == nullptr)
		{
			printf("langX_langXLogger_trace error! NO OBJ!\n");
			return nullptr;
		}

		return nullptr;
	}


	ClassInfo* reglangXLogger(langXState *state, XNameSpace* space) {

		ClassInfo *info = new ClassInfo("langXLogger");
		info->addFunction("info", create3rdFunc("info", langX_langXLogger_info));
		info->addFunction("debug", create3rdFunc("debug", langX_langXLogger_debug));
		info->addFunction("error", create3rdFunc("error", langX_langXLogger_error));
		info->addFunction("trace", create3rdFunc("trace", langX_langXLogger_trace));

		space->putClass(info);

		return info;
	}

	/// 
	ClassInfo* regLoggerClass(langXState * state)
	{
		XNameSpace *space = state->getNameSpaceOrCreate("langX.extend");

		return reglangXLogger(state, space);
	}

}