#pragma once
#include "langX.h"

/*
  注册一些 函数  
*/

namespace langX {

	void regFunctions(langXState *);

	// 对象的元数据信
	static ClassInfo * c_metadata;
	// 空类， 当想返回某个对象的时候可以考虑使用
	static ClassInfo * c_empty_class;

}