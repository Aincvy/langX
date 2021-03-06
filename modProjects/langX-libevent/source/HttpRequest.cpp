﻿
#include "../include/RegHttpServer.h"

#include "langX/langXSimple.h"


static langX::ClassInfo *httpRequestClass;

namespace langX {

	langXObject *createHttpReq(HttpRequestInfo *req) {
		langXObject * obj = httpRequestClass->newObject();
		obj->set3rdObj(req);
		return obj;
	}

	Object * langX_HttpRequest_getBufferData(X3rdFunction *func, const X3rdArgs &args) {
		if (args.object == nullptr)
		{
			printf("langX_HttpRequest_getBufferData error! NO OBJ!\n");
			return nullptr;
		}

		return Allocator::allocate(NULLOBJECT);
	}



	Object * langX_HttpRequest_getPostData(X3rdFunction *func, const X3rdArgs &args) {
		if (args.object == nullptr)
		{
			printf("langX_HttpRequest_getPostData error! NO OBJ!\n");
			return nullptr;
		}

		return Allocator::allocate(NULLOBJECT);
	}



	Object * langX_HttpRequest_getParameter(X3rdFunction *func, const X3rdArgs &args) {
		if (args.object == nullptr)
		{
			printf("langX_HttpRequest_getParameter error! NO OBJ!\n");
			return nullptr;
		}

		HttpRequestInfo* reqInfo = (HttpRequestInfo*)args.object->get3rdObj();
		Object* a = args.args[0];
		if (a && a->getType() == ObjectType::STRING)
		{
			const char *key = ((String*)a)->getValue();
			const char * value = evhttp_find_header(&reqInfo->params, key);

			if (value == nullptr)
			{
				return Allocator::allocateString("");
			}
			return Allocator::allocateString(value);
		}

		return Allocator::allocate(NULLOBJECT);
	}



	Object * langX_HttpRequest_getHeader(X3rdFunction *func, const X3rdArgs &args) {
		if (args.object == nullptr)
		{
			printf("langX_HttpRequest_getHeader error! NO OBJ!\n");
			return nullptr;
		}

		HttpRequestInfo* reqInfo = (HttpRequestInfo*)args.object->get3rdObj();
		Object* a = args.args[0];
		if (a && a->getType() == ObjectType::STRING)
		{
			const char *key = ((String*)a)->getValue();
			const char * value=evhttp_find_header(reqInfo->evRequest->input_headers, key);
			
			return Allocator::allocateString(value);
		}

		return Allocator::allocate(NULLOBJECT);
	}



	Object * langX_HttpRequest_getUrl(X3rdFunction *func, const X3rdArgs &args) {
		if (args.object == nullptr)
		{
			printf("langX_HttpRequest_getUrl error! NO OBJ!\n");
			return nullptr;
		}

		HttpRequestInfo* reqInfo = (HttpRequestInfo*)args.object->get3rdObj();

		return Allocator::allocateString(reqInfo->evRequest->uri);
	}



	Object * langX_HttpRequest_getUri(X3rdFunction *func, const X3rdArgs &args) {
		if (args.object == nullptr)
		{
			printf("langX_HttpRequest_getUri error! NO OBJ!\n");
			return nullptr;
		}

		HttpRequestInfo* reqInfo = (HttpRequestInfo*)args.object->get3rdObj();

		return Allocator::allocateString(reqInfo->evRequest->uri);
	}



	Object * langX_HttpRequest_getMethod(X3rdFunction *func, const X3rdArgs &args) {
		if (args.object == nullptr)
		{
			printf("langX_HttpRequest_getMethod error! NO OBJ!\n");
			return nullptr;
		}

		HttpRequestInfo* reqInfo= (HttpRequestInfo*)args.object->get3rdObj();

		return Allocator::allocateString(reqInfo->method);
	}



	int regHttpRequest(langXState *state, XNameSpace* space) {

		ClassInfo *info = new ClassInfo("HttpRequest");
		info->addFunction("getBufferData", create3rdFunc("getBufferData", langX_HttpRequest_getBufferData));
		info->addFunction("getPostData", create3rdFunc("getPostData", langX_HttpRequest_getPostData));
		info->addFunction("getParameter", create3rdFunc("getParameter", langX_HttpRequest_getParameter));
		info->addFunction("getHeader", create3rdFunc("getHeader", langX_HttpRequest_getHeader));
		info->addFunction("getUrl", create3rdFunc("getUrl", langX_HttpRequest_getUrl));
		info->addFunction("getUri", create3rdFunc("getUri", langX_HttpRequest_getUri));
		info->addFunction("getMethod", create3rdFunc("getMethod", langX_HttpRequest_getMethod));

		space->putClass(info);
		httpRequestClass = info;

		return 0;
	}
}


