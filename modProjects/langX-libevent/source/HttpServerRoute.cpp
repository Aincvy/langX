#include "../include/RegHttpServer.h"

#include "ClassInfo.h"
#include "TypeHelper.h"
#include "Object.h"
#include "langXObject.h"
#include "Allocator.h"
#include "Number.h"
#include "StringType.h"

static langX::ClassInfo *httpServerRouteClass;

namespace langX {

	langXObject * createHttpServerRoute()
	{
		return httpServerRouteClass->newObject();
	}

	Object * langX_HttpServerRoute_route(X3rdFunction *func, const X3rdArgs &args) {
		if (args.object == nullptr)
		{
			printf("langX_HttpServerRoute_route error! NO OBJ!\n");
			return nullptr;
		}

		HttpServerArgs* server = (HttpServerArgs*)args.object->get3rdObj();
		Object *a = args.args[0];
		Object *b = args.args[1];
		if (a && b && a->getType() == ObjectType::STRING && b->getType() == ObjectType::FUNCTION)
		{
			String *str = (String*)a;
			FunctionRef *ref = (FunctionRef*)b;
			server->routeMap[std::string(str->getValue())] = (FunctionRef *)ref->clone();

			return Allocator::allocateNumber(1);
		}

		return Allocator::allocateNumber(0);
	}



	int regHttpServerRoute(langXState *state, XNameSpace* space) {

		ClassInfo *info = new ClassInfo("HttpServerRoute");
		info->addFunction("route", create3rdFunc("route", langX_HttpServerRoute_route));

		space->putClass(info);
		httpServerRouteClass = info;

		return 0;
	}
}


