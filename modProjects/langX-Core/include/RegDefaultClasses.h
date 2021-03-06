#pragma once

#include "langX/langX.h"
#include "langX/XNameSpace.h"

namespace langX {

	// 注册默认的类

	// 注册 Math 类
	int regMath(langXState *state, XNameSpace* space);


	int regDateTime(langXState *state, XNameSpace* space);

    void regTimeSpan(langXState *state, XNameSpace *space);

	int regConvert(langXState *state, XNameSpace* space);

	int regThread(langXState *state, XNameSpace* space);

	int regStringBuilder(langXState *state, XNameSpace* space);

	int regApplication(langXState *state, XNameSpace* space);

}
