#pragma once

#include <vector>
#include <string>

#include "../../../include/langX.h"
#include "../../../include/XNameSpace.h"

namespace langX {

	class langXObject;

	int regMysqlClient(langXState *state , XNameSpace* space);

	int regDataTable(langXState *state, XNameSpace* space);

	int regDataRow(langXState *state, XNameSpace* space);


	///  数据表结构
	struct DataTable
	{
		// row data . every item is a DataRow object.
		std::vector<langXObject*> rows;
		// column names. 
		std::vector<std::string> columns;
	};

}