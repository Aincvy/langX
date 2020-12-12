
#include "../include/RegHttpServer.h"

#include "../../../include/ClassInfo.h"
#include "../../../include/NodeCreator.h"
#include "../../../include/Object.h"
#include "../../../include/langXObject.h"
#include "../../../include/Allocator.h"
#include "../../../include/Number.h"
#include "../../../include/StringType.h"

#ifdef WIN32
#include "../../../lib/libevent-2.0.21-stable/include/event2/buffer.h"

#else
#include <event2/buffer.h>
#endif

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

		HttpRequestInfo* reqInfo = (HttpRequestInfo*)args.object->get3rdObj();
		Object *a = args.args[0];
		if (a && a->getType() == ObjectType::STRING)
		{
			const char *type = ((String*)a)->getValue();

			int ret = evhttp_add_header(reqInfo->evRequest->output_headers, "Content-Type", type);
			if (ret == 0)
			{
				return Allocator::allocateNumber(1);
			}
		}

		return Allocator::allocateNumber(0);
	}



	Object * langX_HttpResponse_write(X3rdFunction *func, const X3rdArgs &args) {
		if (args.object == nullptr)
		{
			printf("langX_HttpResponse_write error! NO OBJ!\n");
			return nullptr;
		}

		HttpRequestInfo* reqInfo = (HttpRequestInfo*)args.object->get3rdObj();
		Object *a = args.args[0];
		if (a && a->getType() == ObjectType::STRING)
		{
			String *str = (String*)a;
			str->simpleEscape();
			const char * text = str->getValue();

			evbuffer_add_printf(reqInfo->buffer, text);
		}

		return nullptr;
	}



	Object * langX_HttpResponse_addHeader(X3rdFunction *func, const X3rdArgs &args) {
		if (args.object == nullptr)
		{
			printf("langX_HttpResponse_addHeader error! NO OBJ!\n");
			return nullptr;
		}

		HttpRequestInfo* reqInfo = (HttpRequestInfo*)args.object->get3rdObj();
		Object *a = args.args[0];
		Object *b = args.args[1];
		if (a && b && a->getType() == ObjectType::STRING && b->getType() == ObjectType::STRING)
		{
			const char *key = ((String*)a)->getValue();
			const char *value = ((String*)b)->getValue();

			int ret = evhttp_add_header(reqInfo->evRequest->output_headers, key, value);
			if (ret == 0)
			{
				return Allocator::allocateNumber(1);
			}
		}

		return Allocator::allocateNumber(0);
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


