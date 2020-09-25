#pragma once

// 内部函数  InnerFunction.h ,

#include "Object.h"
#include "Function.h"

namespace langX {

	// 第一个参数为 对象， 第二个参数为 函数调用的节点
	Object * callInnerFunc(Object *, Node *);

	// 第一个参数为 对象， 第二个参数为 函数名字， 第三个为参数队列
	// 调用此方法的时候， 应该把所有参数赋值好
	Object * callInnerFunc(Object *, const char *, X3rdArgs *);

	// 第一个对象为使用函数的对象， 第二个参数为函数， 第三个参数为 参数列表
	// 调用此方法的时候， 应该把所有参数赋值好
	Object * callFunction(Object *, Function *, X3rdArgs *);

}
