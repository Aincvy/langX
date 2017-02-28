
#include "../include/RegHttpServer.h"

#include "../../../include/ClassInfo.h"
#include "../../../include/YLlangX.h"
#include "../../../include/Object.h"
#include "../../../include/langXObject.h"
#include "../../../include/langXObjectRef.h"
#include "../../../include/Allocator.h"
#include "../../../include/Number.h"

static langX::ClassInfo *httpResponseClass;

namespace langX {

	langXObject *createHttpRes(HttpRequestInfo *req) {
		langXObject * obj = httpResponseClass->newObject();
		obj->set3rdObj(req);
		return obj;
	}

	Object * langX_HttpResponse_setContentType(X3rdFunction *func, const X3rdArgs &args) {
		if (args.object == nullptr)
		{
			printf("langX_HttpResponse_setContentType error! NO OBJ!\n");
			return nullptr;
		}

		return nullptr;
	}



	Object * langX_HttpResponse_write(X3rdFunction *func, const X3rdArgs &args) {
		if (args.object == nullptr)
		{
			printf("langX_HttpResponse_write error! NO OBJ!\n");
			return nullptr;
		}

		return nullptr;
	}



	Object * langX_HttpResponse_addHeader(X3rdFunction *func, const X3rdArgs &args) {
		if (args.object == nullptr)
		{
			printf("langX_HttpResponse_addHeader error! NO OBJ!\n");
			return nullptr;
		}

		return nullptr;
	}



	int regHttpResponse(langXState *state, XNameSpace* space) {

		ClassInfo *info = new ClassInfo("HttpResponse");
		info->addFunction("setContentType", create3rdFunc("setContentType", langX_HttpResponse_setContentType));
		info->addFunction("write", create3rdFunc("write", langX_HttpResponse_write));
		info->addFunction("addHeader", create3rdFunc("addHeader", langX_HttpResponse_addHeader));

		space->putClass(info);
		httpResponseClass = info;

		return 0;
	}
}


