#pragma once
#include <map>

#include <event2/event.h>
#include <event2/http.h>
#include <event2/keyvalq_struct.h>
#include <event2/http_struct.h>

#include "X3rdModule.h"
#include "langX.h"
#include "XNameSpace.h"
#include "langXObject.h"
#include "Function.h"

namespace langX {

	int regHttpServer(langXState *state, XNameSpace* space);

	int regHttpServerRoute(langXState *state, XNameSpace* space);

	int regHttpRequest(langXState *state, XNameSpace* space);

	int regHttpResponse(langXState *state, XNameSpace* space);


	langXObject *createHttpServerRoute();


	// http server 的一些参数
	struct HttpServerArgs
	{
		event_base *base;
		evhttp *httpd;  
		std::map<std::string, FunctionRef*> routeMap;   // 路由表
		FunctionRef * defaultCB;     //默认的回调函数
		langXObject *routeObj;
		char bindIp[20] ;   // 绑定到的ip地址
		
	};

	// http 的请求信息 ( httprequest 和  httpresponse 都使用这个作为 3rdObj )
	struct HttpRequestInfo
	{
		evhttp_request *evRequest;
		struct evkeyvalq params;  
		struct evbuffer *buffer;
		char method[10];    // GET/POST
	};

	// 释放一个 http request info
	void freeHttpRequestInfo(HttpRequestInfo *&);

	// http request 
	langXObject *createHttpReq(HttpRequestInfo *);
	// http response
	langXObject *createHttpRes(HttpRequestInfo *);

}