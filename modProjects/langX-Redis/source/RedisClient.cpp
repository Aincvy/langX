#include "../include/RegRedisModule.h"

#include "../../../include/ClassInfo.h"
#include "../../../include/YLlangX.h"
#include "../../../include/Object.h"
#include "../../../include/langXObject.h"
#include "../../../include/langXObjectRef.h"
#include "../../../include/Allocator.h"
#include "../../../include/Number.h"
#include "../../../include/String.h"

#include <string.h>

#ifdef WIN32
#include "../../../lib/hiredis-0.14.0/hiredis.h"
#else
#include <hiredis/hiredis.h>
#endif

namespace langX {

	langXRedisInfo * buildLangXRedisInfo(const char * ip, int port, redisContext * redisContext)
	{
		langXRedisInfo * info = (langXRedisInfo*)calloc(sizeof(langXRedisInfo), 1);
		info->ip = strdup(ip);
		info->port = port;
		info->redisContext = redisContext;
		info->connected = redisContext != nullptr;
		return info;
	}

	Object * replyToObject(redisReply *reply) {
		if (reply == NULL)
		{
			return NULL;
		}

		switch (reply->type)
		{
		case REDIS_REPLY_INTEGER:
			return Allocator::allocateNumber(reply->integer);
		case REDIS_REPLY_STRING:
			return Allocator::allocateString(reply->str);
		case REDIS_REPLY_ARRAY:
			// TODO 
			break;
		case REDIS_REPLY_ERROR:
			break;
		case REDIS_REPLY_NIL:
			return Allocator::allocateNull();
		case REDIS_REPLY_STATUS:
			break;
		default:
			break;
		}

		return NULL;
	}


	Object * langX_RedisClient_connect(X3rdFunction *func, const X3rdArgs &args) {
		if (args.object == nullptr)
		{
			printf("langX_RedisClient_connect error! NO OBJ!\n");
			return nullptr;
		}

		Object *a = args.args[0];
		Object *b = args.args[1];
		if (a && b && a->getType() == ObjectType::STRING && b->getType() == ObjectType::NUMBER)
		{
			const char *ip = ((String*)a)->getValue();
			int port = ((Number*)b)->getIntValue();

			redisContext *redis = redisConnect(ip, port);

			langXRedisInfo* info = buildLangXRedisInfo(ip, port, redis);
			args.object->set3rdObj(info);

		}

		return nullptr;
	}


	Object * langX_RedisClient_get(X3rdFunction *func, const X3rdArgs &args) {
		if (args.object == nullptr)
		{
			printf("langX_RedisClient_get error! NO OBJ!\n");
			return nullptr;
		}

		langXRedisInfo* redisInfo = (langXRedisInfo*)args.object->get3rdObj();
		Object *a = args.args[0];
		if (a && a->getType() == ObjectType::STRING)
		{
			const char *key = ((String*)a)->getValue();

			redisReply *reply= (redisReply *)redisCommand(redisInfo->redisContext, "GET %s", key);
			if (reply == nullptr)
			{
				// error .
				redisInfo->connected = false;

				return nullptr;
			}

			Object *ret = replyToObject(reply);
			freeReplyObject(reply);

			return ret;
		}

		return nullptr;
	}

	Object * langX_RedisClient_put(X3rdFunction *func, const X3rdArgs &args) {
		if (args.object == nullptr)
		{
			printf("langX_RedisClient_put error! NO OBJ!\n");
			return nullptr;
		}

		langXRedisInfo* redisInfo = (langXRedisInfo*)args.object->get3rdObj();
		Object *a = args.args[0];
		Object *b = args.args[1];
		if (!a || a->getType() != ObjectType::STRING)
		{
			return nullptr;
		}

		const char *key = ((String*)a)->getValue();

		redisReply *reply = NULL;
		if (b->getType() == ObjectType::STRING)
		{
			const char *value = ((String*)b)->getValue();
			reply = (redisReply *)redisCommand(redisInfo->redisContext, "SET %s %s", key, value);
		}
		else if (b->getType() == ObjectType::NUMBER)
		{
			Number *number = (Number*)b;
			if (number->isInteger())
			{
				reply = (redisReply*)redisCommand(redisInfo->redisContext, "Set %s %d", key, number->getIntValue());
			}
			else {
				reply = (redisReply*)redisCommand(redisInfo->redisContext, "Set %s %f", key, number->getDoubleValue());
			}
		}
		else if (b->getType() == ObjectType::XARRAY)
		{
			// 数组

		}
		else if (b->getType() == ObjectType::OBJECT)
		{
			// 对象

		}
		
		if (reply)
		{
			freeReplyObject(reply);
		}
			
		return nullptr;
	}


	Object * langX_RedisClient_cmd(X3rdFunction *func, const X3rdArgs &args) {
		if (args.object == nullptr)
		{
			printf("langX_RedisClient_cmd error! NO OBJ!\n");
			return nullptr;
		}

		return nullptr;
	}


	int regRedisClient(langXState *state, XNameSpace* space) {

		ClassInfo *info = new ClassInfo("RedisClient");
		info->addFunction("connect", create3rdFunc("connect", langX_RedisClient_connect));

		info->addFunction("get", create3rdFunc("get", langX_RedisClient_get));
		info->addFunction("put", create3rdFunc("put", langX_RedisClient_put));
		info->addFunction("cmd", create3rdFunc("cmd", langX_RedisClient_cmd));

		space->putClass(info);

		return 0;
	}
}


