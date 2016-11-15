#pragma once

// 内部函数  InnerFunction.h ,  

#include "Object.h"

namespace langX {

	// 第一个参数为 对象， 第二个参数为 函数调用的节点
	Object * callInnerFunc(Object *, Node *);
	
	// 第一个参数为 对象， 第二个参数为 函数名字， 第三个为参数队列
	Object * callInnerFunc(Object *, const char *, X3rdArgs *);
}