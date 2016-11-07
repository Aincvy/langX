#ifdef WIN32
#include "../../../lib/MySQL Connector C 6.1/include/mysql.h"
#else
#include <mysql.h>
#endif

#include <stdlib.h>
#include "../include/RegMysqlModule.h"
#include "../../../include/ClassInfo.h"
#include "../../../include/YLlangX.h"
#include "../../../include/Object.h"
#include "../../../include/langXObject.h"
#include "../../../include/Allocator.h"
#include "../../../include/Number.h"
#include "../../../include/String.h"


namespace langX {

	const const char * isConnectedStr = "isConnected";

	void closeMysql(langXObject *object) {
		if (!object)
		{
			return;
		}

		MYSQL *mysql = (MYSQL *)object->get3rdObj();
		((Number*)object->getMember(isConnectedStr))->setValue(0);
		if (mysql)
		{
			mysql_close(mysql);
			free(mysql);
			object->set3rdObj(nullptr);
		}
	}

	MYSQL *initMysql() {
		MYSQL *mysql = (MYSQL*)calloc(1, sizeof(MYSQL));
		mysql_init(mysql);

		return mysql;
	}

	Object * langX_MysqlClient_MysqlClient(X3rdFunction *func, const X3rdArgs &args) {
		if (args.object == nullptr)
		{
			printf("langX_MysqlClient_MysqlClient error! NO OBJ!\n");
			return nullptr;
		}
	
		MYSQL *mysql = initMysql();
		args.object->set3rdObj(mysql);

		return nullptr;
	}


	Object * langX_MysqlClient_MysqlClient_Dtor(X3rdFunction *func, const X3rdArgs &args) {
		if (args.object == nullptr)
		{
			printf("langX_MysqlClient_MysqlClient_Dtor error! NO OBJ!\n");
			return nullptr;
		}

		closeMysql(args.object);

		return nullptr;
	}

	Object * langX_MysqlClient_Connect(X3rdFunction *func, const X3rdArgs &args) {
		if (args.object == nullptr)
		{
			printf("langX_MysqlClient_Connect error! NO OBJ!\n");
			return nullptr;
		}

		MYSQL *mysql = (MYSQL*)args.object->get3rdObj();
		Number *number = (Number *)args.object->getMember(isConnectedStr);
		if (number->isTrue() && mysql)
		{
			closeMysql(args.object);
			number->setValue(0);
		}
		
		int port = 3306;
		Object * serverAddr = args.args[0];
		Object * user = args.args[1];
		Object * pwd = args.args[2];
		Object * dbname = args.args[3];
		Object * portObj = args.args[4];

		if (!serverAddr || !user || !pwd || !dbname )
		{
			return getState()->getAllocator().allocateNumber(0);
		}

		if (serverAddr->getType() != STRING || user->getType() != STRING || pwd->getType() != STRING || dbname->getType() != STRING )
		{
			return getState()->getAllocator().allocateNumber(0);
		}

		if (portObj && portObj->getType() == NUMBER)
		{
			port = ((Number*)portObj)->getIntValue();
		}

		mysql = initMysql();
		if (mysql_real_connect(mysql,((String*)serverAddr)->getValue() , ((String*)user)->getValue(), ((String*)pwd)->getValue(), ((String*)dbname)->getValue(),port,NULL,0)) {
			// 连接成功
			number->setValue(1);
			args.object->set3rdObj(mysql);
			return getState()->getAllocator().allocateNumber(1);
		}
		else {
			// 失败
			free(mysql);
			args.object->set3rdObj(nullptr);
			return getState()->getAllocator().allocateNumber(0);
		}

		return nullptr;
	}

	Object * langX_MysqlClient_Reconnect(X3rdFunction *func, const X3rdArgs &args) {
		if (args.object == nullptr)
		{
			printf("langX_MysqlClient_Reconnect error! NO OBJ!\n");
			return nullptr;
		}



		return nullptr;
	}


	Object * langX_MysqlClient_CharacterSet(X3rdFunction *func, const X3rdArgs &args) {
		// 设置字符集
		if (args.object == nullptr)
		{
			printf("langX_MysqlClient_CharacterSet error! NO OBJ!\n");
			return nullptr;
		}

		if (!args.object->getMember(isConnectedStr)->isTrue())
		{
			return getState()->getAllocator().allocateNumber(0);
		}

		Object *a = args.args[0];
		if (!a || a->getType() != STRING)
		{
			return getState()->getAllocator().allocateNumber(0);
		}

		MYSQL *mysql = (MYSQL*)args.object->get3rdObj();

		if (mysql_set_character_set(mysql, ((String*)a)->getValue()) == 0)
		{
			// 成功
			return getState()->getAllocator().allocateNumber(1);
		}

		return getState()->getAllocator().allocateNumber(0);
	}

	Object * langX_MysqlClient_Option(X3rdFunction *func, const X3rdArgs &args) {
		// 设置 mysql 选项
		if (args.object == nullptr)
		{
			printf("langX_MysqlClient_Option error! NO OBJ!\n");
			return nullptr;
		}

		MYSQL *mysql = (MYSQL*)args.object->get3rdObj();


		return nullptr;
	}

	Object * langX_MysqlClient_LastErrorMsg(X3rdFunction *func, const X3rdArgs &args) {
		if (args.object == nullptr)
		{
			printf("langX_MysqlClient_LastErrorMsg error! NO OBJ!\n");
			return nullptr;
		}

		if (!args.object->getMember(isConnectedStr)->isTrue())
		{
			return nullptr;
		}
		
		MYSQL *mysql = (MYSQL*)args.object->get3rdObj();
		return getState()->getAllocator().allocateString(mysql_error(mysql));

	}

	Object * langX_MysqlClient_SelectDB(X3rdFunction *func, const X3rdArgs &args) {
		if (args.object == nullptr)
		{
			printf("langX_MysqlClient_SelectDB error! NO OBJ!\n");
			return nullptr;
		}

		if (!args.object->getMember(isConnectedStr)->isTrue())
		{
			return getState()->getAllocator().allocateNumber(0);
		}

		Object *a = args.args[0];
		if (!a || a->getType() != STRING)
		{
			return getState()->getAllocator().allocateNumber(0);
		}


		MYSQL *mysql = (MYSQL*)args.object->get3rdObj();

		if (mysql_select_db(mysql, ((String*)a)->getValue()) == 0)
		{
			return getState()->getAllocator().allocateNumber(1);
		}

		return getState()->getAllocator().allocateNumber(0);
	}

	Object * langX_MysqlClient_Close(X3rdFunction *func, const X3rdArgs &args) {
		if (args.object == nullptr)
		{
			printf("langX_MysqlClient_Close error! NO OBJ!\n");
			return nullptr;
		}

		if (!args.object->getMember(isConnectedStr)->isTrue())
		{
			return getState()->getAllocator().allocateNumber(1);
		}

		closeMysql(args.object);

		return getState()->getAllocator().allocateNumber(1);
	}

	Object * langX_MysqlClient_ExecQuery(X3rdFunction *func, const X3rdArgs &args) {
		if (args.object == nullptr)
		{
			printf("langX_MysqlClient_ExecQuery error! NO OBJ!\n");
			return nullptr;
		}

		if (!args.object->getMember(isConnectedStr)->isTrue())
		{
			return getState()->getAllocator().allocateNumber(1);
		}

		

		return nullptr;
	}

	Object * langX_MysqlClient_ExecUpdate(X3rdFunction *func, const X3rdArgs &args) {
		if (args.object == nullptr)
		{
			printf("langX_MysqlClient_ExecUpdate error! NO OBJ!\n");
			return nullptr;
		}

		MYSQL *mysql = (MYSQL*)args.object->get3rdObj();

		return nullptr;
	}


	int regMysqlClient(langXState *state, XNameSpace* space) {

		ClassInfo *mysqlClient = new ClassInfo("MysqlClient");
		mysqlClient->addMember(isConnectedStr, getState()->getAllocator().allocateNumber(0));
		mysqlClient->addMember("affectedRows", getState()->getAllocator().allocateNumber(0));
		mysqlClient->addFunction("MysqlClient", create3rdFunc("MysqlClient", langX_MysqlClient_MysqlClient));
		mysqlClient->addFunction("~MysqlClient", create3rdFunc("~MysqlClient", langX_MysqlClient_MysqlClient));
		mysqlClient->addFunction("connect", create3rdFunc("connect", langX_MysqlClient_Connect));
		mysqlClient->addFunction("reconnect", create3rdFunc("reconnect", langX_MysqlClient_Reconnect));
		mysqlClient->addFunction("characterSet", create3rdFunc("characterSet", langX_MysqlClient_CharacterSet));
		mysqlClient->addFunction("option", create3rdFunc("option", langX_MysqlClient_Option));
		mysqlClient->addFunction("lastErrorMsg", create3rdFunc("lastErrorMsg", langX_MysqlClient_LastErrorMsg));
		mysqlClient->addFunction("selectDB", create3rdFunc("selectDB", langX_MysqlClient_SelectDB));
		mysqlClient->addFunction("close", create3rdFunc("close", langX_MysqlClient_Close));
		mysqlClient->addFunction("execQuery", create3rdFunc("execQuery", langX_MysqlClient_ExecQuery));
		mysqlClient->addFunction("execUpdate", create3rdFunc("execUpdate", langX_MysqlClient_ExecUpdate));

		space->putClass(mysqlClient);
		return 0;
	}

}