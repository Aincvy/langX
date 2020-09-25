#pragma once
#include "langX.h"

/*
 * 注册一些对象到 顶层的空间里面
 */

namespace langX {

	class langXObjectExtend;
	class ClassInfo;


	// 类注册
	ClassInfo* regLoggerClass(langXState *state);


	// 注册
	void regObjects(langXState *state);

	// 创建一个空的对象
	langXObjectExtend *emptyObject();

}
