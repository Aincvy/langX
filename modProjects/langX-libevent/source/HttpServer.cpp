#include "../include/RegHttpServer.h"

#include "../../../include/ClassInfo.h"
#include "../../../include/YLlangX.h"
#include "../../../include/Object.h"
#include "../../../include/langXObject.h"
#include "../../../include/langXObjectRef.h"
#include "../../../include/Allocator.h"
#include "../../../include/Number.h"

#ifdef WIN32
#include "../../../lib/libevent-2.0.21-stable/include/event2/buffer.h"

#else
#include <event2/buffer.h>
#endif



namespace langX {

	// http server 的默认回调
	static void httpd_handler(struct evhttp_request *req, void *arg) {

		/* 重要部分 */
		
		HttpServerArgs* server = (HttpServerArgs*)arg;
		HttpRequestInfo *reqInfo = new HttpRequestInfo();

		// 解析 method
		const char *cmdtype;
		switch (evhttp_request_get_command(req)) {
		case EVHTTP_REQ_GET: cmdtype = "GET"; break;
		case EVHTTP_REQ_POST: cmdtype = "POST"; break;
		case EVHTTP_REQ_HEAD: cmdtype = "HEAD"; break;
		case EVHTTP_REQ_PUT: cmdtype = "PUT"; break;
		case EVHTTP_REQ_DELETE: cmdtype = "DELETE"; break;
		case EVHTTP_REQ_OPTIONS: cmdtype = "OPTIONS"; break;
		case EVHTTP_REQ_TRACE: cmdtype = "TRACE"; break;
		case EVHTTP_REQ_CONNECT: cmdtype = "CONNECT"; break;
		case EVHTTP_REQ_PATCH: cmdtype = "PATCH"; break;
		default: cmdtype = "unknown"; break;
		}
		sprintf(reqInfo->method,"%s",cmdtype);

		reqInfo->evRequest = req;
		reqInfo->buffer = evbuffer_new();
		const char *uri = evhttp_request_get_uri(req);

		char *decoded_uri;
		decoded_uri = evhttp_decode_uri(uri);
		evhttp_parse_query(decoded_uri, &reqInfo->params);


		// 将请求传递到 langX 脚本内
		delete reqInfo;

		//HTTP header
		evhttp_add_header(req->output_headers, "Server", "langX-libevent");
		evhttp_add_header(req->output_headers, "Content-Type", "text/plain; charset=UTF-8");
		evhttp_add_header(req->output_headers, "Connection", "close");
		//输出的内容
		struct evbuffer *buf;
		buf = evbuffer_new();
		char output[2048] = "\0";
		evbuffer_add_printf(buf, "It works!\n%s\n", output);
		evhttp_send_reply(req, HTTP_OK, "OK", buf);
		evbuffer_free(buf);

	}


	Object * langX_HttpServer_close(X3rdFunction *func, const X3rdArgs &args) {
		if (args.object == nullptr)
		{
			printf("langX_HttpServer_close error! NO OBJ!\n");
			return nullptr;
		}

		// 暂不实现 

		return nullptr;
	}



	Object * langX_HttpServer_serv(X3rdFunction *func, const X3rdArgs &args) {
		if (args.object == nullptr)
		{
			printf("langX_HttpServer_serv error! NO OBJ!\n");
			return nullptr;
		}

		HttpServerArgs* server = (HttpServerArgs*)args.object->get3rdObj();
		event_base_dispatch(server->base);

		return nullptr;
	}



	Object * langX_HttpServer_getRoute(X3rdFunction *func, const X3rdArgs &args) {
		if (args.object == nullptr)
		{
			printf("langX_HttpServer_getRoute error! NO OBJ!\n");
			return nullptr;
		}

		HttpServerArgs* server = (HttpServerArgs*)args.object->get3rdObj();
		
		return server->routeObj->addRef();
	}



	Object * langX_HttpServer_listen(X3rdFunction *func, const X3rdArgs &args) {
		if (args.object == nullptr)
		{
			printf("langX_HttpServer_listen error! NO OBJ!\n");
			return nullptr;
		}

		HttpServerArgs* server = (HttpServerArgs*)args.object->get3rdObj();
		Object *a = args.args[0];
		if (a && a->getType() == ObjectType::NUMBER)
		{
			int port = ((Number*)a)->getIntValue();
			struct evhttp_bound_socket *handle = evhttp_bind_socket_with_handle(server->httpd, server->bindIp, port);
			if (!handle)
			{
				fprintf(stderr, "Server http handle error\n");
				return  getState()->getAllocator().allocateNumber(-1);
			}

			return getState()->getAllocator().allocateNumber(1);
		}

		return getState()->getAllocator().allocateNumber(0);
	}



	Object * langX_HttpServer_HttpServer_Dtor(X3rdFunction *func, const X3rdArgs &args) {
		if (args.object == nullptr)
		{
			printf("langX_HttpServer_HttpServer_Dtor error! NO OBJ!\n");
			return nullptr;
		}

		HttpServerArgs* server = (HttpServerArgs*)args.object->get3rdObj();
		if (server)
		{
			if (server->base)
			{
				event_base_free(server->base);
			}
			if (server->httpd)
			{
				evhttp_free(server->httpd);
			}
			if (server->routeObj)
			{
				delete server->routeObj;
			}

			delete server;
			args.object->set3rdObj(nullptr);
		}
		

		return nullptr;
	}



	Object * langX_HttpServer_HttpServer(X3rdFunction *func, const X3rdArgs &args) {
		if (args.object == nullptr)
		{
			printf("langX_HttpServer_HttpServer error! NO OBJ!\n");
			return nullptr;
		}

		HttpServerArgs* httpServerArgs = new HttpServerArgs();
		httpServerArgs->base = event_base_new();
		if (!httpServerArgs->base) {
			fprintf(stderr, "Could not initialize libevent!\n");
			return nullptr;
		}

		httpServerArgs->httpd = evhttp_new(httpServerArgs->base);
		if (!httpServerArgs->httpd) {
			fprintf(stderr, "couldn't create evhttp. Exiting.\n");
			return nullptr;
		}
		httpServerArgs->routeObj = createHttpServerRoute();
		httpServerArgs->routeObj->set3rdObj(httpServerArgs);

		evhttp_set_timeout(httpServerArgs->httpd, 30);
		evhttp_set_gencb(httpServerArgs->httpd, httpd_handler, httpServerArgs);

		sprintf(httpServerArgs->bindIp, "0.0.0.0");

		args.object->set3rdObj(httpServerArgs);

		return nullptr;
	}



	int regHttpServer(langXState *state, XNameSpace* space) {

		ClassInfo *info = new ClassInfo("HttpServer");
		info->addFunction("close", create3rdFunc("close", langX_HttpServer_close));
		info->addFunction("serv", create3rdFunc("serv", langX_HttpServer_serv));
		info->addFunction("getRoute", create3rdFunc("getRoute", langX_HttpServer_getRoute));
		info->addFunction("listen", create3rdFunc("listen", langX_HttpServer_listen));
		info->addFunction("~HttpServer", create3rdFunc("~HttpServer", langX_HttpServer_HttpServer_Dtor));
		info->addFunction("HttpServer", create3rdFunc("HttpServer", langX_HttpServer_HttpServer));

		space->putClass(info);

		return 0;
	}
}


