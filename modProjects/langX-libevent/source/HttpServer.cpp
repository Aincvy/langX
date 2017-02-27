#include "../include/RegHttpServer.h"

#include "../../../include/ClassInfo.h"
#include "../../../include/YLlangX.h"
#include "../../../include/Object.h"
#include "../../../include/langXObject.h"
#include "../../../include/langXObjectRef.h"
#include "../../../include/Allocator.h"
#include "../../../include/Number.h"




namespace langX {


	Object * langX_HttpServer_close(X3rdFunction *func, const X3rdArgs &args) {
		if (args.object == nullptr)
		{
			printf("langX_HttpServer_close error! NO OBJ!\n");
			return nullptr;
		}

		return nullptr;
	}



	Object * langX_HttpServer_serv(X3rdFunction *func, const X3rdArgs &args) {
		if (args.object == nullptr)
		{
			printf("langX_HttpServer_serv error! NO OBJ!\n");
			return nullptr;
		}

		

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

		return nullptr;
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


