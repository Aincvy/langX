#include "../include/RedisModule.h"
#include "../include/RegRedisModule.h"

#include "langX/langX.h"
#include "langX/XNameSpace.h"
#include "langX/LogManager.h"

namespace langX {

	RedisModule::RedisModule()
	{
		this->setName("redis");
	}

	RedisModule::~RedisModule()
	{
	}

	int RedisModule::init(langXState *state)
	{
		logger->info("init langX-Redis lib.");
		
		XNameSpace *space = state->getNameSpaceOrCreate("langX.redis");
		regRedisClient(state, space);

		regRedisExceptions(state, space);

		return 0;
	}

	int RedisModule::unload(langXState *)
	{
		return 0;
	}

}

int loadModule(langX::X3rdModule *& mod) {

	mod = new langX::RedisModule();

	return 0;
}

