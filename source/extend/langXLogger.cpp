#include "RegObjects.h"

#include "ClassInfo.h"
#include "NodeCreator.h"
#include "langXObject.h"
#include "XNameSpace.h"
#include "StringType.h"
#include "LogManager.h"

namespace langX {

	Object * langX_langXLogger_info(X3rdFunction *func, const X3rdArgs &args) {

		Object *a = args.args[0];
		if (a && a->getType() == ObjectType::STRING)
		{
			String *string = (String*)a;
			const char * v = string->getValue();
			logger->info("[from script] %s" ,v);
		}

		return nullptr;
	}


	Object * langX_langXLogger_debug(X3rdFunction *func, const X3rdArgs &args) {

        Object *a = args.args[0];
        if (a && a->getType() == ObjectType::STRING)
        {
            String *string = (String*)a;
            const char * v = string->getValue();
            logger->debug("[from script] %s" ,v);
        }

		return nullptr;
	}


	Object * langX_langXLogger_error(X3rdFunction *func, const X3rdArgs &args) {
	    Object *a = args.args[0];
        if (a && a->getType() == ObjectType::STRING)
        {
            String *string = (String*)a;
            const char * v = string->getValue();
            logger->error("[from script] %s" ,v);
        }

		return nullptr;
	}


	Object * langX_langXLogger_trace(X3rdFunction *func, const X3rdArgs &args) {

        Object *a = args.args[0];
        if (a && a->getType() == ObjectType::STRING)
        {
            String *string = (String*)a;
            const char * v = string->getValue();
            logger->debug("[Trace from script] %s" ,v);
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