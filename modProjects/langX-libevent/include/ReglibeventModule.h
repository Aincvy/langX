#pragma once

#include <event2/bufferevent.h>
#include <event2/buffer.h>
#include <event2/listener.h>
#include <event2/util.h>
#include <event2/event.h>

#include <list>

#include "langX/X3rdModule.h"
#include "langX/langX.h"
#include "langX/XNameSpace.h"
#include "langX/langXObject.h"
#include "langX/Function.h"

#include "BytesDecoder.h"
#include "BytesEncoder.h"


namespace langX {

	int regTcpServer(langXState *state, XNameSpace *space);

	int regTcpClient(langXState *state, XNameSpace *space);

	int regDefaultNetPacket(langXState *state, XNameSpace *space);

	/**
	 * event base 类 注入
	 * @param state
	 * @param space
	 */
    void regEventBase(langXState *state, XNameSpace *space);

    /**
     *
     * @param state
     * @param space
     */
    void regTimerEvent(langXState* state, XNameSpace* space);



    /**
     * 新建一个 timer 得对象
     * @param eventBase
     * @return
     */
    langXObject *newTimerObject(struct event_base* eventBase);


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
