#include "../include/RegRedisModule.h"

#include "langX/langXSimple.h"

#include <string.h>

#include <hiredis/hiredis.h>

namespace langX {


	Object *onReply(redisReply *reply, langXRedisInfo *redisInfo) {
		if (reply == nullptr)
		{
			redisInfo->connected = false;
			return nullptr;
		}

		Object *ret = replyToObject(reply);
		freeReplyObject(reply);
		return ret;
	}

	langXRedisInfo * buildLangXRedisInfo(const char * ip, int port, redisContext * redisContext)
	{
		langXRedisInfo * info = (langXRedisInfo*)calloc(sizeof(langXRedisInfo), 1);
		info->ip = strdup(ip);
		info->port = port;
		info->redis = redisContext;
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

			redisReply *reply = (redisReply *)redisCommand(redisInfo->redis, "GET %s", key);
			return onReply(reply, redisInfo);
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
			reply = (redisReply *)redisCommand(redisInfo->redis, "SET %s %s", key, value);
		}
		else if (b->getType() == ObjectType::NUMBER)
		{
			Number *number = (Number*)b;
			if (number->isInteger())
			{
				reply = (redisReply*)redisCommand(redisInfo->redis, "Set %s %d", key, number->getIntValue());
			}
			else {
				reply = (redisReply*)redisCommand(redisInfo->redis, "Set %s %f", key, number->getDoubleValue());
			}
		}
		else if (b->getType() == ObjectType::XARRAY)
		{
			// 数组

		}
		else if (b->getType() == ObjectType::OBJECT)
		{
			// 对象
			langXObjectRef *objectRef = (langXObjectRef*)b;

			Object *str1 = objectRef->getRefObject()->callFunction("toRedisString", "from redis mod", 0);
			if (str1 != NULL)
			{
				if (str1->getType() == ObjectType::STRING)
				{
					const char *value = ((String*)str1)->getValue();
					reply = (redisReply *)redisCommand(redisInfo->redis, "SET %s %s", key, value);
				}

				Allocator::free(str1);
			}

			if (!reply)
			{
				const char * value = b->characteristic();
				reply = (redisReply *)redisCommand(redisInfo->redis, "SET %s %s", key, value);
			}

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

		langXRedisInfo* redisInfo = (langXRedisInfo*)args.object->get3rdObj();
		Object *a = args.args[0];
		if (a && a->getType() == ObjectType::STRING)
		{
			const char *cmd = ((String*)a)->getValue();

			redisReply *reply = (redisReply *)redisCommand(redisInfo->redis, cmd);
			return onReply(reply, redisInfo);
		}

		return nullptr;
	}

	Object * langX_RedisClient_hget(X3rdFunction *func, const X3rdArgs &args) {
		if (args.object == nullptr)
		{
			printf("langX_RedisClient_hget error! NO OBJ!\n");
			return nullptr;
		}

		langXRedisInfo* redisInfo = (langXRedisInfo*)args.object->get3rdObj();
		Object *a = args.args[0];
		Object *b = args.args[0];
		if (a && a->getType() == ObjectType::STRING)
		{
			const char *member = nullptr;
			if (b && b->getType() == ObjectType::STRING) {
				member = ((String*)b)->getValue();
			}
			if (!member)
			{
				return nullptr;
			}

			const char *key = ((String*)a)->getValue();
			redisReply *reply = (redisReply *)redisCommand(redisInfo->redis, "hget %s %s", key                                             , member);

			return onReply(reply, redisInfo);
		}

		return nullptr;
	}


	Object * langX_RedisClient_hset(X3rdFunction *func, const X3rdArgs &args) {
		if (args.object == nullptr)
		{
			printf("langX_RedisClient_hset error! NO OBJ!\n");
			return nullptr;
		}

		langXRedisInfo* redisInfo = (langXRedisInfo*)args.object->get3rdObj();
		Object *a = args.args[0];
		Object *b = args.args[1];
		Object *c = args.args[2];
		if (!a || a->getType() != ObjectType::STRING)
		{
			return nullptr;
		}

		const char *member = nullptr;
		if (b && b->getType() == ObjectType::STRING) {
			member = ((String*)b)->getValue();
		}

		if (!member) {
			return nullptr;
		}

		const char *key = ((String*)a)->getValue();

		redisReply *reply = NULL;
		if (c->getType() == ObjectType::STRING)
		{
			const char *value = ((String*)c)->getValue();
			reply = (redisReply *)redisCommand(redisInfo->redis, "hset %s %s %s", key, member, value);
		}
		else if (c->getType() == ObjectType::NUMBER)
		{
			Number *number = (Number*)c;
			if (number->isInteger())
			{
				reply = (redisReply*)redisCommand(redisInfo->redis, "hset %s %s %d", key, member, number->getIntValue());
			}
			else {
				reply = (redisReply*)redisCommand(redisInfo->redis, "hset %s %s %f", key, member, number->getDoubleValue());
			}
		}
		else if (c->getType() == ObjectType::XARRAY)
		{
			// 数组

		}
		else if (c->getType() == ObjectType::OBJECT)
		{
			// 对象
			langXObjectRef *objectRef = (langXObjectRef*)c;

			Object *str1 = objectRef->getRefObject()->callFunction("toRedisString", "from redis mod", 0);
			if (str1 != NULL)
			{
				if (str1->getType() == ObjectType::STRING)
				{
					const char *value = ((String*)str1)->getValue();
					reply = (redisReply *)redisCommand(redisInfo->redis, "hset %s %s %s", key, member, value);
				}

				Allocator::free(str1);
			}

			if (!reply)
			{
				const char * value = c->characteristic();
				reply = (redisReply *)redisCommand(redisInfo->redis, "hset %s %s %s", key, member, value);
			}

		}

		if (reply)
		{
			freeReplyObject(reply);
		}

		return nullptr;
	}


	Object * langX_RedisClient_hdel(X3rdFunction *func, const X3rdArgs &args) {
		if (args.object == nullptr)
		{
			printf("langX_RedisClient_hdel error! NO OBJ!\n");
			return nullptr;
		}

		langXRedisInfo* redisInfo = (langXRedisInfo*)args.object->get3rdObj();
		Object *a = args.args[0];
		Object *b = args.args[0];
		if (a && a->getType() == ObjectType::STRING)
		{
			const char *member = nullptr;
			if (b && b->getType() == ObjectType::STRING) {
				member = ((String*)b)->getValue();
			}
			if (!member)
			{
				return nullptr;
			}

			const char *key = ((String*)a)->getValue();
			redisReply *reply = (redisReply *)redisCommand(redisInfo->redis, "hdel %s %s", key, member);

			return onReply(reply, redisInfo);
		}

		return nullptr;
	}


	Object * langX_RedisClient_keys(X3rdFunction *func, const X3rdArgs &args) {
		if (args.object == nullptr)
		{
			printf("langX_RedisClient_keys error! NO OBJ!\n");
			return nullptr;
		}

		langXRedisInfo* redisInfo = (langXRedisInfo*)args.object->get3rdObj();
		Object *a = args.args[0];
		if (a && a->getType() == ObjectType::STRING)
		{
			const char *value = ((String*)a)->getValue();
			redisReply *reply = (redisReply *)redisCommand(redisInfo->redis, "keys %s", value);

			return onReply(reply, redisInfo);
		}

		return nullptr;
	}


	Object * langX_RedisClient_flush(X3rdFunction *func, const X3rdArgs &args) {
		if (args.object == nullptr)
		{
			printf("langX_RedisClient_flush error! NO OBJ!\n");
			return nullptr;
		}

		langXRedisInfo* redisInfo = (langXRedisInfo*)args.object->get3rdObj();
		void *reply = redisCommand(redisInfo->redis, "flush");
		freeReplyObject(reply);

		return nullptr;
	}


	Object * langX_RedisClient_flushAll(X3rdFunction *func, const X3rdArgs &args) {
		if (args.object == nullptr)
		{
			printf("langX_RedisClient_flushAll error! NO OBJ!\n");
			return nullptr;
		}

		langXRedisInfo* redisInfo = (langXRedisInfo*)args.object->get3rdObj();
		void *reply = redisCommand(redisInfo->redis, "flushall");
		freeReplyObject(reply);

		return nullptr;
	}


	Object * langX_RedisClient_strlen(X3rdFunction *func, const X3rdArgs &args) {
		if (args.object == nullptr)
		{
			printf("langX_RedisClient_strlen error! NO OBJ!\n");
			return nullptr;
		}

		langXRedisInfo* redisInfo = (langXRedisInfo*)args.object->get3rdObj();
		Object *a = args.args[0];
		if (a && a->getType() == ObjectType::STRING)
		{
			const char *key = ((String*)a)->getValue();
			redisReply *reply = (redisReply *)redisCommand(redisInfo->redis, "strlen %s", key);

			return onReply(reply, redisInfo);
		}

		return nullptr;
	}


	Object * langX_RedisClient_del(X3rdFunction *func, const X3rdArgs &args) {
		if (args.object == nullptr)
		{
			printf("langX_RedisClient_del error! NO OBJ!\n");
			return nullptr;
		}

		langXRedisInfo* redisInfo = (langXRedisInfo*)args.object->get3rdObj();
		Object *a = args.args[0];
		if (a && a->getType() == ObjectType::STRING)
		{
			const char *key = ((String*)a)->getValue();
			redisReply *reply = (redisReply *)redisCommand(redisInfo->redis, "del %s", key);

			return onReply(reply, redisInfo);
		}

		return nullptr;
	}


	Object * langX_RedisClient_exists(X3rdFunction *func, const X3rdArgs &args) {
		if (args.object == nullptr)
		{
			printf("langX_RedisClient_exists error! NO OBJ!\n");
			return nullptr;
		}

		langXRedisInfo* redisInfo = (langXRedisInfo*)args.object->get3rdObj();
		Object *a = args.args[0];
		if (a && a->getType() == ObjectType::STRING)
		{
			const char *key = ((String*)a)->getValue();
			redisReply *reply = (redisReply *)redisCommand(redisInfo->redis, "exists %s", key);

			return onReply(reply, redisInfo);
		}

		return nullptr;
	}


	Object * langX_RedisClient_zadd(X3rdFunction *func, const X3rdArgs &args) {
		if (args.object == nullptr)
		{
			printf("langX_RedisClient_zadd error! NO OBJ!\n");
			return nullptr;
		}

		langXRedisInfo* redisInfo = (langXRedisInfo*)args.object->get3rdObj();
		Object *a = args.args[0];
		Object *b = args.args[1];
		Object *c = args.args[2];
		if (a && a->getType() == ObjectType::STRING)
		{
			const char *key = ((String*)a)->getValue();
			float point = 0;
			const char *member = nullptr;
			if (b && b ->getType() == ObjectType::NUMBER)
			{
				point = (float) ((Number*)b)->getDoubleValue();
			}
			if (c && c->getType() == ObjectType::STRING) {
				member = ((String*)c)->getValue();
			}
			if (!member)
			{
				return nullptr;
			}

			redisReply *reply = (redisReply *)redisCommand(redisInfo->redis, "zadd %s %f %s", key, point, member);
			return onReply(reply, redisInfo);
		}

		return nullptr;
	}


	Object * langX_RedisClient_zcount(X3rdFunction *func, const X3rdArgs &args) {
		if (args.object == nullptr)
		{
			printf("langX_RedisClient_zcount error! NO OBJ!\n");
			return nullptr;
		}

		langXRedisInfo* redisInfo = (langXRedisInfo*)args.object->get3rdObj();
		Object *a = args.args[0];
		Object *b = args.args[1];
		Object *c = args.args[2];
		if (a && a->getType() == ObjectType::STRING)
		{
			const char *key = ((String*)a)->getValue();
			int start = 0;
			int end = -1;
			if (b &&b->getType() == ObjectType::NUMBER)
			{
				start = ((Number*)b)->getIntValue();
			}
			if (c && c->getType() == ObjectType::NUMBER)
			{
				end = ((Number*)c)->getIntValue();
			}

			redisReply *reply = (redisReply *)redisCommand(redisInfo->redis, "zcount %s %d %d", key,start ,end);

			return onReply(reply, redisInfo);
		}

		return nullptr;
	}


	Object * langX_RedisClient_zrange(X3rdFunction *func, const X3rdArgs &args) {
		if (args.object == nullptr)
		{
			printf("langX_RedisClient_zrange error! NO OBJ!\n");
			return nullptr;
		}

		return nullptr;
	}


	Object * langX_RedisClient_zscore(X3rdFunction *func, const X3rdArgs &args) {
		if (args.object == nullptr)
		{
			printf("langX_RedisClient_zscore error! NO OBJ!\n");
			return nullptr;
		}

		langXRedisInfo* redisInfo = (langXRedisInfo*)args.object->get3rdObj();
		Object *a = args.args[0];
		Object *b = args.args[1];
		if (a && a->getType() == ObjectType::STRING)
		{
			const char *key = ((String*)a)->getValue();
			const char *member = nullptr;
			if (b && b->getType() == ObjectType::STRING) {
				member = ((String*)b)->getValue();
			}
			if (!member)
			{
				return nullptr;
			}

			redisReply *reply = (redisReply *)redisCommand(redisInfo->redis, "zscore %s %f %s", key, member);
			return onReply(reply, redisInfo);
		}

		return nullptr;
	}


	int regRedisClient(langXState *state, XNameSpace* space) {

		ClassInfo *info = new ClassInfo("RedisClient");
		info->addFunction("connect", create3rdFunc("connect", langX_RedisClient_connect));

		info->addFunction("get", create3rdFunc("get", langX_RedisClient_get));
		info->addFunction("put", create3rdFunc("put", langX_RedisClient_put));
		info->addFunction("cmd", create3rdFunc("cmd", langX_RedisClient_cmd));
		info->addFunction("hget", create3rdFunc("hget", langX_RedisClient_hget));
		info->addFunction("hset", create3rdFunc("hset", langX_RedisClient_hset));
		info->addFunction("hdel", create3rdFunc("hdel", langX_RedisClient_hdel));
		info->addFunction("keys", create3rdFunc("keys", langX_RedisClient_keys));
		info->addFunction("flush", create3rdFunc("flush", langX_RedisClient_flush));
		info->addFunction("flushAll", create3rdFunc("flushAll", langX_RedisClient_flushAll));
		info->addFunction("strlen", create3rdFunc("strlen", langX_RedisClient_strlen));
		info->addFunction("del", create3rdFunc("del", langX_RedisClient_del));
		info->addFunction("exists", create3rdFunc("exists", langX_RedisClient_exists));
		info->addFunction("zadd", create3rdFunc("zadd", langX_RedisClient_zadd));
		info->addFunction("zcount", create3rdFunc("zcount", langX_RedisClient_zcount));
		info->addFunction("zrange", create3rdFunc("zrange", langX_RedisClient_zrange));
		info->addFunction("zscore", create3rdFunc("zscore", langX_RedisClient_zscore));

		space->putClass(info);

		return 0;
	}
}
