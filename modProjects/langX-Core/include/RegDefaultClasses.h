#pragma once

#include "../../../include/langX.h"
#include "../../../include/XNameSpace.h"

namespace langX {

	// 注册默认的类

	// 注册 Math 类
	int regMath(langXState *state, XNameSpace* space);


	int regDateTime(langXState *state, XNameSpace* space);

}