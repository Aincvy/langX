#pragma once

#include "langX/langX.h"
#include "langX/XNameSpace.h"

#include <cjson/cJSON.h>

namespace langX {

	class langXObject;
	class Object;
	class XArray;

	int regJsonArray(langXState *state, XNameSpace* space);

	int regJsonObject(langXState *state, XNameSpace* space);

	//
	langXObject * createJsonObject(cJSON *);
	//
	langXObject * createJsonArray(cJSON *);
	
	//
	cJSON *langXArrayToJson(XArrayRef *ref);
	//
	cJSON *langXObjectToJson(langXObjectRef *objRef);
	//
	Object* jsonAddItemToObject(cJSON *, const char *, Object *);
	Object* jsonAddItemToObjectOrArray(cJSON *root, const char *key, Object *b, bool isArray);
	//
	Object* jsonAddItemToArray(cJSON *, Object *);
	//
	void jsonDecodeToObj(cJSON *, Object *);
	//
	void jsonDecodeToArr(cJSON *, XArray *);
	//
	//
	Object* getSimpleJsonValue(cJSON *);

	//
	Object * langX_JsonObject_langXObj(X3rdFunction *func, const X3rdArgs &args);
	Object *cJsonToLangXObject(cJSON *root, langXState *state);
	Object * cJsonToLangXObject_obj(cJSON *root, ClassInfo *empty);
	Object * cJsonToLangXObject_array(cJSON *root, ClassInfo *empty);

	//

	//  json
	struct MyJsonData
	{
		cJSON * pJsonRoot;
	};

}
