#pragma once

#include "../../../include/langX.h"
#include "../../../include/XNameSpace.h"
#include "../../../include/Object.h"


#ifdef WIN32
#include "../../../lib/hiredis-0.14.0/hiredis.h"
#else
#include <hiredis/hiredis.h>
#endif

namespace langX {


	struct langXRedisInfo {
		redisContext *redis;
		char *ip;
		int port;
		bool connected;
		bool autoReConnect;
	};

	struct langXRedisInfo* buildLangXRedisInfo(const char*ip, int port, redisContext *redisContext);

	// 把一个 redis reply 转成 一个 langX 对象
	Object * replyToObject(redisReply *);

	int regRedisClient(langXState *state, XNameSpace* space);

	int regRedisExcceptions(langXState *state, XNameSpace* space);



}