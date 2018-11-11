#include "../include/RedisModule.h"

namespace langX {



	RedisModule::RedisModule()
	{

	}

	RedisModule::~RedisModule()
	{
	}

	int RedisModule::init(langXState *)
	{
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

