#pragma once

#ifdef WIN32
#include "../../../lib/libevent-2.0.21-stable/include/event2/buffer.h"
#include "../../../lib/libevent-2.0.21-stable/include/event2/bufferevent.h"
#include "../../../lib/libevent-2.0.21-stable/include/event2/listener.h"
#include "../../../lib/libevent-2.0.21-stable/include/event2/util.h"
#include "../../../lib/libevent-2.0.21-stable/include/event2/event.h"

// windows 下 此工具并不可用。 因为项目的某些别的问题所以暂时这样写，以满足需求

struct  in_addr {

};

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

#include <list>

#include "../../../include/X3rdModule.h"
#include "../../../include/langX.h"
#include "../../../include/XNameSpace.h"
#include "../../../include/langXObject.h"
#include "../../../include/Function.h"
#include "BytesDecoder.h"
#include "BytesEncoder.h"


namespace langX {

	int regTcpServer(langXState *state, XNameSpace *space);

	int regTcpClient(langXState *state, XNameSpace *space);

	int regDefaultNetPacket(langXState *state, XNameSpace *space);

	// 初始化server 需要的一些工具
	void initServerSupportTools();

	// TcpServer 的一些参数
	struct TcpServerArgs
	{
		struct evconnlistener *listener;
		struct event_base *base;
		langX::langXObject *xobject;
		struct sockaddr_in sin;

		// 写数据的时候的 编码器列表
		std::list<BytesEncoder*>* encoderList;
		// 解码器列表
		std::list<BytesDecoder*>* decoderList;

		langX::FunctionRef *acceptcb;
		langX::FunctionRef *readcb;
		langX::FunctionRef *writecb;
		langX::FunctionRef *clientclosecb;
		langX::FunctionRef *serverclosecb;
	};

	// TcpClient 的一些参数
	struct TcpClientArgs
	{
		struct bufferevent *bev;
		langX::langXObject *serverObject;
		langX::langXObject *clientObject;
	};



}
