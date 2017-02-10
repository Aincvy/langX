#pragma once

#include <vector>
#include <string>
#include <map>

#include "../../../include/langX.h"
#include "../../../include/XNameSpace.h"

namespace langX {

	class langXObject;
	class Object;

	int regMysqlClient(langXState *state , XNameSpace* space);

	int regDataTable(langXState *state, XNameSpace* space);

	int regDataRow(langXState *state, XNameSpace* space);


	//  数据表结构
	struct DataTable
	{
		// row data . every item is a DataRow object.
		std::vector<langXObject*> rows;
		// column names. 
		std::vector<std::string> columns;
	};

	//  数据行
	struct DataRow
	{
		// k: col name, v: value 
		std::map<std::string, Object*> kvpair;
		// list value 
		std::vector<Object*> list; 
	};

}