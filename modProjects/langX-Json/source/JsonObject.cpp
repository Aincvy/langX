﻿#include "../include/RegJsonModule.h"

#include "../../../include/ClassInfo.h"
#include "../../../include/YLlangX.h"
#include "../../../include/Object.h"
#include "../../../include/langXObject.h"
#include "../../../include/langXObjectRef.h"
#include "../../../include/Allocator.h"
#include "../../../include/Number.h"
#include "../../../include/String.h"

static langX::ClassInfo *jsonObjectClass;

namespace langX {

	langXObject * createJsonObject(cJSON *root)
	{
		langXObject *obj = jsonObjectClass->newObject();
		MyJsonData *data = new MyJsonData();
		if (root)
		{
			data->pJsonRoot = root;
		}
		else {
			data->pJsonRoot = cJSON_CreateObject();
		}

		obj->set3rdObj(data);
		return obj;
	}


	Object* jsonAddItemToObject(cJSON *root, const char *key, Object *b)
	{
		if (b->getType() == ObjectType::STRING)
		{
			String *str = (String*)b;
			cJSON_AddStringToObject(root, key, str->getValue());
			return Allocator::allocateNumber(1);
		}
		else if (b->getType() == ObjectType::NUMBER)
		{
			Number * num = (Number*)b;
			cJSON_AddNumberToObject(root, key, num->getDoubleValue());
			return Allocator::allocateNumber(1);
		}
		else if (b->getType() == ObjectType::OBJECT)
		{
			langXObjectRef *ref = (langXObjectRef*)b;
			if (ref->getClassInfo()->isInstanceOf("JsonObject") || ref->getClassInfo()->isInstanceOf("JsonArray"))
			{
				MyJsonData *thedata = (MyJsonData*)ref->getRefObject()->get3rdObj();
				cJSON_AddItemToObject(root, key, thedata->pJsonRoot);
				return Allocator::allocateNumber(1);
			}
		}

		return Allocator::allocateNumber(0);
	}

	Object * langX_JsonObject_getJsonArray(X3rdFunction *func, const X3rdArgs &args) {
		if (args.object == nullptr)
		{
			printf("langX_JsonObject_getJsonArray error! NO OBJ!\n");
			return nullptr;
		}

		MyJsonData *data = (MyJsonData*)args.object->get3rdObj();

		Object * a = args.args[0];
		if (a)
		{
			// a 为有效值
			if (a->getType() == ObjectType::STRING)
			{
				String *keyStr = (String*)a;
				cJSON *cjson = cJSON_GetObjectItem(data->pJsonRoot, keyStr->getValue());
				if (cjson == nullptr)
				{
					return Allocator::allocate(NULLOBJECT);
				}

				langXObject *obj = createJsonArray(cjson);
				return obj->addRef();
			}
		}

		return Allocator::allocate(NULLOBJECT);


		return nullptr;
	}


	Object * langX_JsonObject_toJSONString(X3rdFunction *func, const X3rdArgs &args) {
		if (args.object == nullptr)
		{
			printf("langX_JsonObject_toJSONString error! NO OBJ!\n");
			return nullptr;
		}

		MyJsonData *data = (MyJsonData*)args.object->get3rdObj();
		char *p = cJSON_Print(data->pJsonRoot);
		if (p == NULL)
		{
			return Allocator::allocate(NULLOBJECT);
		}

		String *str = Allocator::allocateString(p);
		free(p);

		return str;
	}


	Object * langX_JsonObject_put(X3rdFunction *func, const X3rdArgs &args) {
		if (args.object == nullptr)
		{
			printf("langX_JsonObject_put error! NO OBJ!\n");
			return nullptr;
		}

		MyJsonData *data = (MyJsonData*)args.object->get3rdObj();

		Object * a = args.args[0];
		Object * b = args.args[1];
		if (a && b)
		{
			// a 为有效值
			if (a->getType() == ObjectType::STRING)
			{
				String *keyStr = (String*)a;
				
				return jsonAddItemToObject(data->pJsonRoot, keyStr->getValue(), b);
			}
		}

		return Allocator::allocateNumber(0);
	}



	Object * langX_JsonObject_getString(X3rdFunction *func, const X3rdArgs &args) {
		if (args.object == nullptr)
		{
			printf("langX_JsonObject_getString error! NO OBJ!\n");
			return nullptr;
		}

		MyJsonData *data = (MyJsonData*)args.object->get3rdObj();

		Object * a = args.args[0];
		if (a)
		{
			// a 为有效值
			if (a->getType() == ObjectType::STRING)
			{
				String *keyStr = (String*)a;
				cJSON *cjson = cJSON_GetObjectItem(data->pJsonRoot, keyStr->getValue());
				if (cjson == nullptr)
				{
					return Allocator::allocate(NULLOBJECT);
				}
				return Allocator::allocateString(cjson->valuestring);
			}
		}

		return Allocator::allocate(NULLOBJECT);
	}



	Object * langX_JsonObject_getNumber(X3rdFunction *func, const X3rdArgs &args) {
		if (args.object == nullptr)
		{
			printf("langX_JsonObject_getNumber error! NO OBJ!\n");
			return nullptr;
		}

		MyJsonData *data = (MyJsonData*)args.object->get3rdObj();

		Object * a = args.args[0];
		if (a)
		{
			// a 为有效值
			if (a->getType() == ObjectType::STRING)
			{
				String *keyStr = (String*)a;
				cJSON *cjson = cJSON_GetObjectItem(data->pJsonRoot, keyStr->getValue());
				if (cjson == nullptr)
				{
					return Allocator::allocate(NULLOBJECT);
				}
				return Allocator::allocateNumber(cjson->valuedouble);
			}
		}

		return Allocator::allocate(NULLOBJECT);
	}



	Object * langX_JsonObject_getJsonObject(X3rdFunction *func, const X3rdArgs &args) {
		if (args.object == nullptr)
		{
			printf("langX_JsonObject_getJsonObject error! NO OBJ!\n");
			return nullptr;
		}

		MyJsonData *data = (MyJsonData*)args.object->get3rdObj();

		Object * a = args.args[0];
		if (a)
		{
			// a 为有效值
			if (a->getType() == ObjectType::STRING)
			{
				String *keyStr = (String*)a;
				cJSON *cjson = cJSON_GetObjectItem(data->pJsonRoot, keyStr->getValue());
				if (cjson == nullptr)
				{
					return Allocator::allocate(NULLOBJECT);
				}

				langXObject *obj = createJsonObject(cjson);
				return obj->addRef();
			}
		}

		return Allocator::allocate(NULLOBJECT);
	}



	Object * langX_JsonObject_JsonObject_Dtor(X3rdFunction *func, const X3rdArgs &args) {
		if (args.object == nullptr)
		{
			printf("langX_JsonObject_JsonObject_Dtor error! NO OBJ!\n");
			return nullptr;
		}

		MyJsonData *data = (MyJsonData*)args.object->get3rdObj();

		cJSON_Delete(data->pJsonRoot);
		data->pJsonRoot = nullptr;
		delete data;
		args.object->set3rdObj(nullptr);

		return nullptr;
	}



	Object * langX_JsonObject_JsonObject(X3rdFunction *func, const X3rdArgs &args) {
		if (args.object == nullptr)
		{
			printf("langX_JsonObject_JsonObject error! NO OBJ!\n");
			return nullptr;
		}

		MyJsonData *data = new MyJsonData();
		data->pJsonRoot = cJSON_CreateObject();

		args.object->set3rdObj(data);

		return nullptr;
	}



	int regJsonObject(langXState *state, XNameSpace* space) {

		ClassInfo *info = new ClassInfo("JsonObject");
		info->addFunction("getJsonArray", create3rdFunc("getJsonArray", langX_JsonObject_getJsonArray));
		info->addFunction("put", create3rdFunc("put", langX_JsonObject_put));
		info->addFunction("getString", create3rdFunc("getString", langX_JsonObject_getString));
		info->addFunction("getNumber", create3rdFunc("getNumber", langX_JsonObject_getNumber));
		info->addFunction("getJsonObject", create3rdFunc("getJsonObject", langX_JsonObject_getJsonObject));
		info->addFunction("toJSONString", create3rdFunc("toJSONString", langX_JsonObject_toJSONString));
		info->addFunction("~JsonObject", create3rdFunc("~JsonObject", langX_JsonObject_JsonObject_Dtor));
		info->addFunction("JsonObject", create3rdFunc("JsonObject", langX_JsonObject_JsonObject));

		space->putClass(info);

		jsonObjectClass = info;

		return 0;
	}
}


