#include <stdlib.h>
#include <string.h>
#include <stdio.h>

#include "../include/ReglibeventModule.h"
#include "../include/BytesDecoder.h"
#include "../include/BytesEncoder.h"
#include "../include/DefaultBytesDecoder.h"
#include "../include/DefaultBytesEncoder.h"
#include "../include/DefaultNetPacket.h"

#include "../../../include/ClassInfo.h"
#include "../../../include/NodeCreator.h"
#include "../../../include/Object.h"
#include "../../../include/langXObject.h"
#include "../../../include/Allocator.h"
#include "../../../include/Number.h"
#include "../../../include/StringType.h"
#include "../../../include/langXThread.h"

#ifdef WIN32
#include "../../../lib/libevent-2.0.21-stable/include/event2/buffer.h"
#include "../../../lib/libevent-2.0.21-stable/include/event2/bufferevent.h"
#include "../../../lib/libevent-2.0.21-stable/include/event2/listener.h"
#include "../../../lib/libevent-2.0.21-stable/include/event2/util.h"
#include "../../../lib/libevent-2.0.21-stable/include/event2/event.h"

// windows 下 此工具并不可用。 因为项目的某些别的问题所以暂时这样写，以满足需求
short AF_INET = 1;
u_short htons(int port);

#else
#include <event2/bufferevent.h>
#include <event2/buffer.h>
#include <event2/listener.h>
#include <event2/util.h>
#include <event2/event.h>
#endif

namespace langX {


	static void conn_readcb(struct bufferevent *bev, void *user_data)
	{
		// 读的回调
		char msg[4096] = { 0 };
		size_t len = bufferevent_read(bev, msg, sizeof(msg) - 1);

		TcpClientArgs *clientArgs = (TcpClientArgs*)user_data;
		TcpServerArgs *arg = (TcpServerArgs*)clientArgs->serverObject->get3rdObj();

		if (arg->decoderList == nullptr)
		{
			String astr(msg);
			if (arg->readcb)
			{
				// server,client,data
//				Object *arglist[3] = { 0 };
//				arglist[0] = arg->xobject->addRef();
//				arglist[1] = clientArgs->clientObject->addRef();
//				arglist[2] = &astr;
//				arg->readcb->call(arglist, 3, "in libevent conn_readcb");

                auto thread = getState()->getThreadManager()->getMainThread();

                // server,client,data
                arg->readcb->call(thread, "in libevent conn_readcb", 3,arg->xobject->addRef(), clientArgs->clientObject->addRef(), &astr);
			}
		}
		else {
			// 先使用解码器

		}

	}

	static void conn_writecb(struct bufferevent *bev, void *user_data)
	{
		struct evbuffer *output = bufferevent_get_output(bev);
		if (evbuffer_get_length(output) == 0) {
			//printf("flushed over\n");
			//bufferevent_free(bev);
		}
	}

	static void conn_eventcb(struct bufferevent *bev, short events, void *user_data)
	{
		if (events & BEV_EVENT_EOF) {
			printf("Connection closed.\n");
		}
		else if (events & BEV_EVENT_ERROR) {
			printf("Got an error on the connection: %s\n",
				strerror(errno));/*XXX win32*/
		}
		/* None of the other events can happen here, since we haven't enabled
		* timeouts */
		bufferevent_free(bev);
	}


	/* When a new connection is received, the provided callback function is invoked.
	   The listener argument is the connection listener that received the connection.
	   The sock argument is the new socket itself.
	   The addr and len arguments are the address from which
	   the connection was received and the length of that address respectively.
	   The ptr argument is the user-supplied pointer that
		 was passed to evconnlistener_new(). */
	static void listener_cb(struct evconnlistener *listener, evutil_socket_t fd,
			struct sockaddr *sa, int socklen, void *user_data)
	{
		TcpServerArgs *arg = (TcpServerArgs *)user_data;
		struct event_base *base = arg->base;
		struct bufferevent *bev;

		bev = bufferevent_socket_new(base, fd, BEV_OPT_CLOSE_ON_FREE);
		if (!bev) {
			fprintf(stderr, "Error constructing bufferevent!");
			event_base_loopbreak(base);
			return;
		}

		// 调用 onaccept 回调
		langXObject * clientObject = getState()->getNameSpace("langX.libevent")->getClass("TcpClient")->newObject();
		TcpClientArgs *clientArgs = (TcpClientArgs*)calloc(1, sizeof(TcpClientArgs));
		clientArgs->bev = bev;
		clientArgs->clientObject = clientObject;
		clientArgs->serverObject = arg->xobject;
		clientObject->set3rdObj(clientArgs);

		if (arg->acceptcb != nullptr)
		{
			// server,client
//			Object *arglist[2] = { 0 };
//			arglist[0] = arg->xobject->addRef();
//			arglist[1] = clientObject->addRef();
//			arg->acceptcb->call(arglist, 2, "in libevent listener_cb");
			//printf("call acceptcb cb\n");

			auto thread = getState()->getThreadManager()->getMainThread();

            // server,client
			arg->acceptcb->call(thread, "in libevent listener_cb", 2, arg->xobject->addRef(), clientObject->addRef());
		}

		bufferevent_setcb(bev, conn_readcb, conn_writecb, conn_eventcb, clientArgs);
		bufferevent_enable(bev, EV_PERSIST | EV_READ);

	}

	BytesEncoder * bytesEncoder = nullptr;
	BytesDecoder * bytesDecoder = nullptr;

	void initServerSupportTools() {
		bytesEncoder = new DefaultBytesEncoder();
		bytesDecoder = new DefaultBytesDecoder();
	}

	// 这个函数内部并不会free arg 参数
	void freeTcpServerArg(TcpServerArgs *arg) {

		if (arg->listener)
		{
			evconnlistener_free(arg->listener);
			arg->listener = nullptr;
		}
		if (arg->base)
		{
			event_base_free(arg->base);
			arg->base = nullptr;
		}
		arg->xobject = nullptr;

		if (arg->encoderList)
		{
			delete arg->encoderList;
		}
		if (arg->decoderList) {
			delete arg->decoderList;
		}
	}

	Object * langX_TcpServer_TcpServer_Dtor(X3rdFunction *func, const X3rdArgs &args) {
		if (args.object == nullptr)
		{
			printf("langX_TcpServer_TcpServer_Dtor error! NO OBJ!\n");
			return nullptr;
		}

		TcpServerArgs *arg = (TcpServerArgs*)args.object->get3rdObj();
		freeTcpServerArg(arg);
		free(arg);
		arg = nullptr;
		args.object->set3rdObj(nullptr);

		return nullptr;
	}

	Object * langX_TcpServer_TcpServer(X3rdFunction *func, const X3rdArgs &args) {
		if (args.object == nullptr)
		{
			printf("langX_TcpServer_TcpServer error! NO OBJ!\n");
			return nullptr;
		}

		TcpServerArgs *arg = (TcpServerArgs*)calloc(1, sizeof(TcpServerArgs));
		arg->xobject = args.object;
		arg->base = event_base_new();
		arg->encoderList = nullptr;
		arg->decoderList = nullptr;
		memset(&arg->sin, 0, sizeof(struct sockaddr_in));
		args.object->set3rdObj(arg);

		if (!arg->base) {
			fprintf(stderr, "Could not initialize libevent!\n");
			//return 1;
		}

		return nullptr;
	}


	Object * langX_TcpServer_serv(X3rdFunction *func, const X3rdArgs &args) {
		if (args.object == nullptr)
		{
			printf("langX_TcpServer_serv error! NO OBJ!\n");
			return nullptr;
		}

		TcpServerArgs *arg = (TcpServerArgs*)args.object->get3rdObj();

		if (!arg->base)
		{
			// not listen.
			return Allocator::allocateNumber(0);
		}

		event_base_dispatch(arg->base);

		return Allocator::allocateNumber(1);
	}



	Object * langX_TcpServer_listen(X3rdFunction *func, const X3rdArgs &args) {
		if (args.object == nullptr)
		{
			printf("langX_TcpServer_listen error! NO OBJ!\n");
			return nullptr;
		}

		Object *a = args.args[0];
		if (!a || a->getType() != NUMBER)
		{
			return Allocator::allocateNumber(0);
		}

		int port = ((Number*)a)->getIntValue();
		((Number*)args.object->getMember("listenPort"))->setValue(port);

		TcpServerArgs *arg = (TcpServerArgs*)args.object->get3rdObj();
		arg->sin.sin_family = AF_INET;
		arg->sin.sin_port = htons(port);

		arg->listener = evconnlistener_new_bind(arg->base, listener_cb, (void *)arg,
			LEV_OPT_REUSEABLE | LEV_OPT_CLOSE_ON_FREE, -1,
			(struct sockaddr*)&arg->sin,
			sizeof(arg->sin));

		if (!arg->listener) {
			fprintf(stderr, "Could not create a listener!\n");
			return Allocator::allocateNumber(0);
		}

		return Allocator::allocateNumber(1);
	}



	Object * langX_TcpServer_onServerClose(X3rdFunction *func, const X3rdArgs &args) {
		if (args.object == nullptr)
		{
			printf("langX_TcpServer_onServerClose error! NO OBJ!\n");
			return nullptr;
		}

		TcpServerArgs *arg = (TcpServerArgs*)args.object->get3rdObj();

		Object *a = args.args[0];
		if (a && a->getType() == FUNCTION)
		{
			FunctionRef * b = (FunctionRef*)a;
			arg->serverclosecb = (FunctionRef *)b->clone();
			//return Allocator::allocateNumber(1);
		}

		return args.object->addRef();
	}



	Object * langX_TcpServer_onClientClose(X3rdFunction *func, const X3rdArgs &args) {
		if (args.object == nullptr)
		{
			printf("langX_TcpServer_onClientClose error! NO OBJ!\n");
			return nullptr;
		}

		TcpServerArgs *arg = (TcpServerArgs*)args.object->get3rdObj();

		Object *a = args.args[0];
		if (a && a->getType() == FUNCTION)
		{
			FunctionRef * b = (FunctionRef*)a;
			arg->clientclosecb = (FunctionRef *)b->clone();
			//return Allocator::allocateNumber(1);
		}

		return args.object->addRef();
	}



	Object * langX_TcpServer_onWrite(X3rdFunction *func, const X3rdArgs &args) {
		if (args.object == nullptr)
		{
			printf("langX_TcpServer_onWrite error! NO OBJ!\n");
			return nullptr;
		}

		TcpServerArgs *arg = (TcpServerArgs*)args.object->get3rdObj();

		Object *a = args.args[0];
		if (a && a->getType() == FUNCTION)
		{
			FunctionRef * b = (FunctionRef*)a;
			arg->writecb = (FunctionRef *)b->clone();
			//return Allocator::allocateNumber(1);
		}

		//return Allocator::allocateNumber(0);
		return args.object->addRef();
	}



	Object * langX_TcpServer_onRead(X3rdFunction *func, const X3rdArgs &args) {
		if (args.object == nullptr)
		{
			printf("langX_TcpServer_onRead error! NO OBJ!\n");
			return nullptr;
		}

		TcpServerArgs *arg = (TcpServerArgs*)args.object->get3rdObj();

		Object *a = args.args[0];
		if (a && a->getType() == FUNCTION)
		{
			FunctionRef * b = (FunctionRef*)a;
			arg->readcb = (FunctionRef *)b->clone();
			//return Allocator::allocateNumber(1);
		}

		return args.object->addRef();

	}



	Object * langX_TcpServer_onAccept(X3rdFunction *func, const X3rdArgs &args) {
		if (args.object == nullptr)
		{
			printf("langX_TcpServer_onAccept error! NO OBJ!\n");
			return nullptr;
		}

		TcpServerArgs *arg = (TcpServerArgs*)args.object->get3rdObj();

		Object *a = args.args[0];
		if (a && a->getType() == FUNCTION)
		{
			FunctionRef * b = (FunctionRef*)a;
			arg->acceptcb = (FunctionRef *)b->clone();
			//return Allocator::allocateNumber(1);
		}

		return args.object->addRef();
	}

	Object * langX_TcpServer_close(X3rdFunction *func, const X3rdArgs &args) {
		if (args.object == nullptr)
		{
			printf("langX_TcpServer_close error! NO OBJ!\n");
			return nullptr;
		}

		TcpServerArgs *arg = (TcpServerArgs*)args.object->get3rdObj();
		//free(arg);       wtf...  这都是啥- -
		event_base_loopbreak(arg->base);
		event_base_free(arg->base);
		arg->base = nullptr;
		arg->xobject = nullptr;
		free(arg);

		args.object->set3rdObj(nullptr);

		return nullptr;
	}

	// 添加一个解码器 或者编码器
	Object * langX_TcpServer_addXCoder(X3rdFunction *func, const X3rdArgs &args) {
		if (args.object == nullptr)
		{
			printf("langX_TcpServer_addXCoder error! NO OBJ!\n");
			return nullptr;
		}

		TcpServerArgs *arg = (TcpServerArgs*)args.object->get3rdObj();

		if (arg->encoderList == nullptr)
		{
			arg->encoderList = new std::list<BytesEncoder*>();
		}
		if (arg->decoderList == nullptr)
		{
			arg->decoderList = new std::list<BytesDecoder*>();
		}

		for (size_t i = 0; i < args.index; i++)
		{
			Object *obj = args.args[i];

			if (obj == nullptr || obj->getType() != ObjectType::OBJECT)
			{
				continue;
			}

			langXObjectRef *ref = (langXObjectRef*)obj;
			if (ref->getFunction("encode") != nullptr)
			{
				langXBytesEncoder* encoder = new  langXBytesEncoder();
				arg->encoderList->push_back(encoder);
			}

			if (ref->getFunction("decode") != nullptr)
			{
				langXBytesDecoder *decoder = new langXBytesDecoder(ref->getRefObject());
				arg->decoderList->push_back(decoder);
			}

		}

	}


	int regTcpServer(langXState *state, XNameSpace* space) {

		ClassInfo *info = new ClassInfo("TcpServer");
		info->addMember("listenPort", Allocator::allocateNumber(0));

		info->addFunction("~TcpServer", create3rdFunc("~TcpServer", langX_TcpServer_TcpServer_Dtor));
		info->addFunction("TcpServer", create3rdFunc("TcpServer", langX_TcpServer_TcpServer));
		info->addFunction("close", create3rdFunc("close", langX_TcpServer_close));
		info->addFunction("serv", create3rdFunc("serv", langX_TcpServer_serv));
		info->addFunction("listen", create3rdFunc("listen", langX_TcpServer_listen));
		info->addFunction("onServerClose", create3rdFunc("onServerClose", langX_TcpServer_onServerClose));
		info->addFunction("onClientClose", create3rdFunc("onClientClose", langX_TcpServer_onClientClose));
		info->addFunction("onWrite", create3rdFunc("onWrite", langX_TcpServer_onWrite));
		info->addFunction("onRead", create3rdFunc("onRead", langX_TcpServer_onRead));
		info->addFunction("onAccept", create3rdFunc("onAccept", langX_TcpServer_onAccept));
		info->addFunction("addXCoder", create3rdFunc("addXCoder", langX_TcpServer_onAccept));

		space->putClass(info);

		return 0;
	}
}
