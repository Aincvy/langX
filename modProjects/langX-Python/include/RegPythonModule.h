#pragma once

#include "../../../include/langX.h"
#include "../../../include/XNameSpace.h"


namespace langX {

	extern ClassInfo *claxxPyObj;
	extern ClassInfo *claxxPyObjEasy;

	int regPythonLib(langXState *state, XNameSpace* space);


	int regPythonHook(langXState *state, XNameSpace* space);

	int regPyException(langXState *state, XNameSpace* space);


	int regPyObjectType(langXState *state, XNameSpace* space);

	int regPyObject(langXState *state, XNameSpace* space);

	int regPyException(langXState *state, XNameSpace* space);

	int regPySomeFunction(langXState *state, XNameSpace* space);

	int regPyObjectEasy(langXState *state, XNameSpace* space);

}