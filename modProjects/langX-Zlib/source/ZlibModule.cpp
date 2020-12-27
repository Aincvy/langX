/************************************************************************************//**
 *  @file       ZlibModule.cpp
 *
 *  @brief      Brief descriptinon of ZlibModule.cpp 
 *
 *  @date       2018-02-28 19:05
 *
 ***************************************************************************************/

#include "../include/ZlibModule.h"
#include "../include/RegZlibModule.h"

#include "langX/LogManager.h"
#include "langX/langX.h"

namespace langX{

	ZlibModule::ZlibModule()
	{
		setName("zlib");
	}

	ZlibModule::~ZlibModule()
	{
	}

	int ZlibModule::init(langXState * state)
	{
		logger->info("init zlib lib.");

		XNameSpace* space = state->getNameSpaceOrCreate("langX.zlib");
		
		regZlib(state, space);

		return 0;
	}

	int ZlibModule::unload(langXState *)
	{
		return 0;
	}

}

int loadModule(langX::X3rdModule *& mod) {

	mod = new langX::ZlibModule();

	return 0;
}
