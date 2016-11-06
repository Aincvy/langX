#pragma once

#include "../../../include/langX.h"
#include "../../../include/XNameSpace.h"

namespace langX {

	int regMysqlClient(langXState *state , XNameSpace* space);

	int regDataTable(langXState *state, XNameSpace* space);

	int regDataRow(langXState *state, XNameSpace* space);

}