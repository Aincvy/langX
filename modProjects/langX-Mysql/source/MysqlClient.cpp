#ifdef WIN32
#include "../../../lib/MySQL Connector C 6.1/include/mysql.h"
#else
#include <mysql.h>
#endif

#include <vector>
#include <stdlib.h>
#include "../include/RegMysqlModule.h"
#include "../../../include/ClassInfo.h"
#include "../../../include/YLlangX.h"
#include "../../../include/Object.h"
#include "../../../include/langXObject.h"
#include "../../../include/langXObjectRef.h"
#include "../../../include/Allocator.h"
#include "../../../include/Number.h"
#include "../../../include/StringType.h"


namespace langX {

	const char * const isConnectedStr = "isConnected";

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
			object->set3rdObj(nullptr);
		}
	}

	MYSQL *initMysql() {
		MYSQL *mysql = mysql_init(NULL);

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
			return Allocator::allocateNumber(0);
		}

		if (serverAddr->getType() != STRING || user->getType() != STRING || pwd->getType() != STRING || dbname->getType() != STRING )
		{
			return Allocator::allocateNumber(0);
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
			return Allocator::allocateNumber(1);
		}
		else {
			// 失败
			mysql_close(mysql);
			args.object->set3rdObj(nullptr);
			return Allocator::allocateNumber(0);
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
			return Allocator::allocateNumber(0);
		}

		Object *a = args.args[0];
		if (!a || a->getType() != STRING)
		{
			return Allocator::allocateNumber(0);
		}

		MYSQL *mysql = (MYSQL*)args.object->get3rdObj();

		if (mysql_set_character_set(mysql, ((String*)a)->getValue()) == 0)
		{
			// 成功
			return Allocator::allocateNumber(1);
		}

		return Allocator::allocateNumber(0);
	}

	Object * langX_MysqlClient_LastAffectedRows(X3rdFunction *func, const X3rdArgs &args) {
		//
		if (args.object == nullptr)
		{
			printf("langX_MysqlClient_LastAffectedRows error! NO OBJ!\n");
			return nullptr;
		}

		if (!args.object->getMember(isConnectedStr)->isTrue())
		{
			return Allocator::allocateNumber(0);
		}

		MYSQL *mysql = (MYSQL*)args.object->get3rdObj();

		double a = mysql_affected_rows(mysql);
		return Allocator::allocateNumber(a);
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
		return Allocator::allocateString(mysql_error(mysql));

	}

	Object * langX_MysqlClient_SelectDB(X3rdFunction *func, const X3rdArgs &args) {
		if (args.object == nullptr)
		{
			printf("langX_MysqlClient_SelectDB error! NO OBJ!\n");
			return nullptr;
		}

		if (!args.object->getMember(isConnectedStr)->isTrue())
		{
			return Allocator::allocateNumber(0);
		}

		Object *a = args.args[0];
		if (!a || a->getType() != STRING)
		{
			return Allocator::allocateNumber(0);
		}


		MYSQL *mysql = (MYSQL*)args.object->get3rdObj();

		if (mysql_select_db(mysql, ((String*)a)->getValue()) == 0)
		{
			return Allocator::allocateNumber(1);
		}

		return Allocator::allocateNumber(0);
	}

	Object * langX_MysqlClient_Close(X3rdFunction *func, const X3rdArgs &args) {
		if (args.object == nullptr)
		{
			printf("langX_MysqlClient_Close error! NO OBJ!\n");
			return nullptr;
		}

		if (!args.object->getMember(isConnectedStr)->isTrue())
		{
			return Allocator::allocateNumber(1);
		}

		closeMysql(args.object);

		return Allocator::allocateNumber(1);
	}

	Object * langX_MysqlClient_ExecQuery(X3rdFunction *func, const X3rdArgs &args) {
		if (args.object == nullptr)
		{
			printf("langX_MysqlClient_ExecQuery error! NO OBJ!\n");
			return nullptr;
		}

		if (!args.object->getMember(isConnectedStr)->isTrue())
		{
			return Allocator::allocateNumber(1);
		}

		MYSQL *mysql = (MYSQL*)args.object->get3rdObj();
		Object *a = args.args[0];
		if (a && a->getType() == STRING)
		{
			if (mysql_query(mysql, ((String*)a)->getValue()) == 0)
			{
				// 查询成功
				MYSQL_RES *res_ptr = mysql_store_result(mysql);
				if (res_ptr)
				{
					double rowNum = mysql_num_rows(res_ptr);
					double colNum = mysql_num_fields(res_ptr);
					MYSQL_ROW row;

					XNameSpace *space = getState()->getNameSpace("langX.mysql");
					langXObject * dataTable = space->getClass("DataTable")->newObject();
					dataTable->callConstructor(nullptr, "in langX_MysqlClient_ExecQuery");
					((Number*)dataTable->getMember("rowNum"))->setValue(rowNum);
					((Number*)dataTable->getMember("isEmpty"))->setValue(rowNum <= 0 ? 1 : 0 );
					DataTable * table = (DataTable*)dataTable->get3rdObj();
					std::vector<langXObject*> &tableVec = table->rows;
					std::vector<std::string> &cols = table->columns;

					MYSQL_FIELD *field = NULL;
					while ( field = mysql_fetch_field(res_ptr) )
					{
						cols.push_back(std::string(field->name));
					}

					while ( row = mysql_fetch_row(res_ptr))
					{
						langXObject *dataRow = space->getClass("DataRow")->newObject();
						dataRow->callConstructor(nullptr, "in langX_MysqlClient_ExecQuery");
						tableVec.push_back(dataRow);
						DataRow *xRowObj = (DataRow *)dataRow->get3rdObj();
						std::vector<Object*> &rowVec = xRowObj->list;
						((Number*)dataRow->getMember("colNum"))->setValue(colNum);

;						int j = (int)colNum;
						for (int i = 0; i < j; i++)
						{
							String *str = Allocator::allocateString(row[i]);
							rowVec.push_back(str);

							xRowObj->kvpair.insert(std::make_pair(cols.at(i), str));
						}
					}

					mysql_free_result(res_ptr);
					res_ptr = NULL;

					return dataTable->addRef();
				}

				mysql_free_result(res_ptr);
				res_ptr = NULL;
			}
		}

		return Allocator::allocate(NULLOBJECT);
	}

	Object * langX_MysqlClient_ExecUpdate(X3rdFunction *func, const X3rdArgs &args) {
		if (args.object == nullptr)
		{
			printf("langX_MysqlClient_ExecUpdate error! NO OBJ!\n");
			return nullptr;
		}

		if (!args.object->getMember(isConnectedStr)->isTrue())
		{
			return Allocator::allocateNumber(0);
		}

		MYSQL *mysql = (MYSQL*)args.object->get3rdObj();

		Object *a = args.args[0];

		if (a && a->getType() == STRING)
		{
			if (mysql_query(mysql, ((String*)a)->getValue()) == 0)
			{
				return Allocator::allocateNumber(1);
			}
		}

		return Allocator::allocateNumber(0);
	}


	int regMysqlClient(langXState *state, XNameSpace* space) {

		ClassInfo *mysqlClient = new ClassInfo("MysqlClient");
		mysqlClient->addMember(isConnectedStr, Allocator::allocateNumber(0));
		mysqlClient->addFunction("MysqlClient", create3rdFunc("MysqlClient", langX_MysqlClient_MysqlClient));
		mysqlClient->addFunction("~MysqlClient", create3rdFunc("~MysqlClient", langX_MysqlClient_MysqlClient));
		mysqlClient->addFunction("connect", create3rdFunc("connect", langX_MysqlClient_Connect));
		mysqlClient->addFunction("reconnect", create3rdFunc("reconnect", langX_MysqlClient_Reconnect));
		mysqlClient->addFunction("characterSet", create3rdFunc("characterSet", langX_MysqlClient_CharacterSet));
		mysqlClient->addFunction("lastAffectedRows", create3rdFunc("lastAffectedRows", langX_MysqlClient_LastAffectedRows));
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
