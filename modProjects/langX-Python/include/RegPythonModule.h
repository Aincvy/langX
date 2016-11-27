#pragma once

#include "../../../include/langX.h"
#include "../../../include/XNameSpace.h"


namespace langX {



	int regPythonLib(langXState *state, XNameSpace* space);


	int regPythonHook(langXState *state, XNameSpace* space);

}