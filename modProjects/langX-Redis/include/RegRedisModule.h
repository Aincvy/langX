#pragma once

#include "langX/langX.h"
#include "langX/XNameSpace.h"
#include "langX/Object.h"

#include <hiredis/hiredis.h>


namespace langX {


	struct langXRedisInfo {
		redisContext *redis;
		char *ip;
		int port;
		bool connected;
		bool autoReConnect;
	};

	struct langXRedisInfo* buildLangXRedisInfo(const char*ip, int port, redisContext *redisContext);

	// convert redisReply to langX
	Object * replyToObject(redisReply *);

	int regRedisClient(langXState *state, XNameSpace* space);

	int regRedisExceptions(langXState *state, XNameSpace* space);



}