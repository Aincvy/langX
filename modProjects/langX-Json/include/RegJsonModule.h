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
	class Object;
	class XArray;

	int regJsonArray(langXState *state, XNameSpace* space);

	int regJsonObject(langXState *state, XNameSpace* space);

	// 参数为 这个jsonobj 的根， 如果给个null 则会自动创建一个
	langXObject * createJsonObject(cJSON *);
	// 参数为 这个jsonarray 的根， 如果给个null 则会自动创建一个
	langXObject * createJsonArray(cJSON *);
	
	// 添加元素到对象上
	Object* jsonAddItemToObject(cJSON *, const char *, Object *);
	// 添加元素到数组上
	Object* jsonAddItemToArray(cJSON *, Object *);
	// 将一个json 对象解析成一个对象 !!!  此函数并未实现
	void jsonDecodeToObj(cJSON *, Object *);
	// 将json 解析成一个数组  !!!  此函数并未实现
	void jsonDecodeToArr(cJSON *, XArray *);
	// 获得这个json 对象的值， 主要用于数组解析使用。 
	// 此函数只返回 string/number
	Object* getSimpleJsonValue(cJSON *);

	// 一些数据结构

	//  json 数据的保存
	struct MyJsonData
	{
		cJSON * pJsonRoot;
	};

}