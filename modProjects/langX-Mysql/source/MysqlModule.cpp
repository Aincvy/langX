#include "../include/MysqlModule.h"
#include "../include/RegMysqlModule.h"
#include "../../../include/LogManager.h"

namespace langX {



	MysqlModule::MysqlModule()
	{

	}

	MysqlModule::~MysqlModule()
	{
	}

	int MysqlModule::init(langXState *state)
	{
		logger->debug("init langX-Mysql 库");

		XNameSpace *space = state->getNameSpaceOrCreate("langX.mysql");

		regMysqlClient(state, space);
		regDataTable(state, space);
		regDataRow(state, space);

		return 0;
	}

	int MysqlModule::unload(langXState *state)
	{
		return 0;
	}

}

int loadModule(langX::X3rdModule *& mod)
{
	mod = new langX::MysqlModule();

	return 0;
}
