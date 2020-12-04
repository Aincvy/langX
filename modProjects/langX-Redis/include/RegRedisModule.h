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

	// ��һ�� redis reply ת�� һ�� langX ����
	Object * replyToObject(redisReply *);

	int regRedisClient(langXState *state, XNameSpace* space);

	int regRedisExceptions(langXState *state, XNameSpace* space);



}