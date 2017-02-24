#pragma once

#include "../../../include/langX.h"
#include "../../../include/XNameSpace.h"


namespace langX {


	int regJsonArray(langXState *state, XNameSpace* space);

	int regJsonObject(langXState *state, XNameSpace* space);

}