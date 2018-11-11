#pragma once

#include "../../../include/langX.h"
#include "../../../include/XNameSpace.h"


#ifdef WIN32
#include "../../../lib/hiredis-0.14.0/hiredis.h"
#else
#include <hiredis/hiredis.h>
#endif

namespace langX {


	struct langXRedisInfo {
		redisContext *redisContext;
		char *ip;
		int port;
		bool connected;
	};

	struct langXRedisInfo* buildLangXRedisInfo(const char*ip, int port, redisContext *redisContext);

}