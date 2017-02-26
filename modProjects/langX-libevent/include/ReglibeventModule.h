#pragma once

#ifdef WIN32
#include "../../../lib/libevent-2.0.21-stable/include/event2/buffer.h"
#include "../../../lib/libevent-2.0.21-stable/include/event2/bufferevent.h"
#include "../../../lib/libevent-2.0.21-stable/include/event2/listener.h"
#include "../../../lib/libevent-2.0.21-stable/include/event2/util.h"
#include "../../../lib/libevent-2.0.21-stable/include/event2/event.h"

// windows �� �˹��߲������á� ��Ϊ��Ŀ��ĳЩ�������������ʱ����д������������

/*
* Socket address, internet style.
*/
struct sockaddr_in {
	short   sin_family;
	u_short sin_port;
	struct  in_addr sin_addr;
	char    sin_zero[8];
};

#else
#include <event2/bufferevent.h>
#include <event2/buffer.h>
#include <event2/listener.h>
#include <event2/util.h>
#include <event2/event.h>
#endif

#include "../../../include/X3rdModule.h"
#include "../../../include/langX.h"
#include "../../../include/XNameSpace.h"
#include "../../../include/langXObject.h"
#include "../../../include/Function.h"



namespace langX {

	int regTcpServer(langXState *state, XNameSpace *space);

	int regTcpClient(langXState *state, XNameSpace *space);

	int regDefaultNetPacket(langXState *state, XNameSpace *space);

	int regHttpServer(langXState *state, XNameSpace* space);

	int regHttpServerRoute(langXState *state, XNameSpace* space);

	// ��ʼ��server ��Ҫ��һЩ����
	void initServerSupportTools();

	// TcpServer ��һЩ����
	struct TcpServerArgs
	{
		struct evconnlistener *listener;
		struct event_base *base;
		langX::langXObject *xobject;
		struct sockaddr_in sin;

		langX::FunctionRef *acceptcb;
		langX::FunctionRef *readcb;
		langX::FunctionRef *writecb;
		langX::FunctionRef *clientclosecb;
		langX::FunctionRef *serverclosecb;
	};

	// TcpClient ��һЩ����
	struct TcpClientArgs
	{
		struct bufferevent *bev;
		langX::langXObject *serverObject;
		langX::langXObject *clientObject;
	};

	// http ��������Ϣ
	struct HttpRequest
	{

	};

}