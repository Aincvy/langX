#pragma once

#include "../../../include/langX.h"
#include "../../../include/XNameSpace.h"

#ifdef WIN32
#include "../../../lib/cJSON-1.3.0/cJSON.h"
#else
#include <cjson/cJSON.h>
#endif

namespace langX {

	class langXObject;

	int regJsonArray(langXState *state, XNameSpace* space);

	int regJsonObject(langXState *state, XNameSpace* space);

	// 参数为 这个jsonobj 的根， 如果给个null 则会自动创建一个
	langXObject * createJsonObject(cJSON *);
	// 参数为 这个jsonarray 的根， 如果给个null 则会自动创建一个
	langXObject * createJsonArray(cJSON *);
	
	// 一些数据结构

	//  json 数据的保存
	struct MyJsonData
	{
		cJSON * pJsonRoot;
	};

}