#include "../include/RegJsonModule.h"

#include "../../../include/ClassInfo.h"
#include "../../../include/YLlangX.h"
#include "../../../include/Object.h"
#include "../../../include/langXObject.h"
#include "../../../include/langXObjectRef.h"
#include "../../../include/Allocator.h"
#include "../../../include/Number.h"
#include "../../../include/String.h"
#include "../../../include/XArray.h"
#include "../../../include/NullObject.h"

static langX::ClassInfo *jsonArrayClass;

namespace langX {

	langXObject * langX::createJsonArray(cJSON *root)
	{

		langXObject *obj = jsonArrayClass->newObject();
		MyJsonData *data = new MyJsonData();
		if (root)
		{
			data->pJsonRoot = root;
		}
		else {
			data->pJsonRoot = cJSON_CreateArray();
		}

		obj->set3rdObj(data);
		return obj;
	}

	Object * langX_JsonArray_setItem(X3rdFunction *func, const X3rdArgs &args) {
		if (args.object == nullptr)
		{
			printf("langX_JsonArray_setItem error! NO OBJ!\n");
			return nullptr;
		}

		return langX_JsonArray_put(func,args);
	}



	Object * langX_JsonArray_put(X3rdFunction *func, const X3rdArgs &args) {
		if (args.object == nullptr)
		{
			printf("langX_JsonArray_put error! NO OBJ!\n");
			return nullptr;
		}

		MyJsonData *data = (MyJsonData*)args.object->get3rdObj();

		Object * b = args.args[0];
		if (b)
		{
			// a 为有效值
			if (b->getType() == ObjectType::STRING)
			{
				String *str = (String*)b;

				cJSON_AddItemToArray(data->pJsonRoot, cJSON_CreateString(str->getValue()));
				return getState()->getAllocator().allocateNumber(1);
			}
			else if (b->getType() == ObjectType::NUMBER)
			{
				Number * num = (Number*)b;
				cJSON_AddItemToArray(data->pJsonRoot, cJSON_CreateNumber(num->getDoubleValue()));
				return getState()->getAllocator().allocateNumber(1);
			}
		}

		return getState()->getAllocator().allocateNumber(0);
	}



	Object * langX_JsonArray_getString(X3rdFunction *func, const X3rdArgs &args) {
		if (args.object == nullptr)
		{
			printf("langX_JsonArray_getString error! NO OBJ!\n");
			return nullptr;
		}

		MyJsonData *data = (MyJsonData*)args.object->get3rdObj();
		Object * a = args.args[0];

		if (a && a->getType() == ObjectType::NUMBER)
		{
			int index = ((Number*)a)->getIntValue();

			cJSON *cjson = cJSON_GetArrayItem(data->pJsonRoot, index);
			if (cjson == nullptr) {
				return getState()->getAllocator().allocate(NULLOBJECT);
			}

			return getState()->getAllocator().allocateString(cjson->valuestring);
		}
		

		return getState()->getAllocator().allocate(NULLOBJECT);
	}



	Object * langX_JsonArray_getNumber(X3rdFunction *func, const X3rdArgs &args) {
		if (args.object == nullptr)
		{
			printf("langX_JsonArray_getNumber error! NO OBJ!\n");
			return nullptr;
		}

		MyJsonData *data = (MyJsonData*)args.object->get3rdObj();
		Object * a = args.args[0];

		if (a && a->getType() == ObjectType::NUMBER)
		{
			int index = ((Number*)a)->getIntValue();

			cJSON *cjson = cJSON_GetArrayItem(data->pJsonRoot, index);
			if (cjson == nullptr) {
				return getState()->getAllocator().allocate(NULLOBJECT);
			}

			return getState()->getAllocator().allocateNumber(cjson->valuedouble);
		}


		return getState()->getAllocator().allocate(NULLOBJECT);
	}



	Object * langX_JsonArray_toStringArray(X3rdFunction *func, const X3rdArgs &args) {
		if (args.object == nullptr)
		{
			printf("langX_JsonArray_toStringArray error! NO OBJ!\n");
			return nullptr;
		}

		MyJsonData *data = (MyJsonData*)args.object->get3rdObj();
		int size = cJSON_GetArraySize(data->pJsonRoot);

		XArray *array1 = new XArray(size);
		NullObject nullObj;

		for (size_t i = 0; i < size; i++)
		{
			cJSON *cjson = cJSON_GetArrayItem(data->pJsonRoot, i);
			if (cjson == nullptr)
			{
				array1->set(i, &nullObj);
			}
			else {
				String str(cjson->valuestring);
				array1->set(i, &str);
			}
		}

		return array1->addRef();
	}



	Object * langX_JsonArray_toNumberArray(X3rdFunction *func, const X3rdArgs &args) {
		if (args.object == nullptr)
		{
			printf("langX_JsonArray_toNumberArray error! NO OBJ!\n");
			return nullptr;
		}

		MyJsonData *data = (MyJsonData*)args.object->get3rdObj();
		int size = cJSON_GetArraySize(data->pJsonRoot);

		XArray *array1 = new XArray(size);
		NullObject nullObj;

		for (size_t i = 0; i < size; i++)
		{
			cJSON *cjson = cJSON_GetArrayItem(data->pJsonRoot, i);
			if (cjson == nullptr)
			{
				array1->set(i, &nullObj);
			}
			else {
				Number num1(cjson->valuedouble);
				array1->set(i, &num1);
			}
		}

		return array1->addRef();
	}



	Object * langX_JsonArray_size(X3rdFunction *func, const X3rdArgs &args) {
		if (args.object == nullptr)
		{
			printf("langX_JsonArray_size error! NO OBJ!\n");
			return nullptr;
		}

		MyJsonData *data = (MyJsonData*)args.object->get3rdObj();
		int size = cJSON_GetArraySize(data->pJsonRoot);

		return getState()->getAllocator().allocateNumber(size);
	}



	Object * langX_JsonArray_JsonArray_Dtor(X3rdFunction *func, const X3rdArgs &args) {
		if (args.object == nullptr)
		{
			printf("langX_JsonArray_JsonArray_Dtor error! NO OBJ!\n");
			return nullptr;
		}

		MyJsonData *data = (MyJsonData*)args.object->get3rdObj();

		cJSON_Delete(data->pJsonRoot);
		data->pJsonRoot = nullptr;
		delete data;
		args.object->set3rdObj(nullptr);

		return nullptr;
	}



	Object * langX_JsonArray_getJsonArray(X3rdFunction *func, const X3rdArgs &args) {
		if (args.object == nullptr)
		{
			printf("langX_JsonArray_getJsonArray error! NO OBJ!\n");
			return nullptr;
		}

		MyJsonData *data = (MyJsonData*)args.object->get3rdObj();
		Object * a = args.args[0];

		if (a && a->getType() == ObjectType::NUMBER)
		{
			int index = ((Number*)a)->getIntValue();

			cJSON *cjson = cJSON_GetArrayItem(data->pJsonRoot, index);
			if (cjson == nullptr) {
				return getState()->getAllocator().allocate(NULLOBJECT);
			}

			return createJsonArray(cjson)->addRef();
		}


		return getState()->getAllocator().allocate(NULLOBJECT);
	}



	Object * langX_JsonArray_getJsonObject(X3rdFunction *func, const X3rdArgs &args) {
		if (args.object == nullptr)
		{
			printf("langX_JsonArray_getJsonObject error! NO OBJ!\n");
			return nullptr;
		}

		MyJsonData *data = (MyJsonData*)args.object->get3rdObj();
		Object * a = args.args[0];

		if (a && a->getType() == ObjectType::NUMBER)
		{
			int index = ((Number*)a)->getIntValue();

			cJSON *cjson = cJSON_GetArrayItem(data->pJsonRoot, index);
			if (cjson == nullptr) {
				return getState()->getAllocator().allocate(NULLOBJECT);
			}

			return createJsonObject(cjson)->addRef();
		}


		return getState()->getAllocator().allocate(NULLOBJECT);
	}



	Object * langX_JsonArray_JsonArray(X3rdFunction *func, const X3rdArgs &args) {
		if (args.object == nullptr)
		{
			printf("langX_JsonArray_JsonArray error! NO OBJ!\n");
			return nullptr;
		}

		MyJsonData *data = new MyJsonData();
		data->pJsonRoot = cJSON_CreateArray();

		args.object->set3rdObj(data);

		return nullptr;
	}



	int regJsonArray(langXState *state, XNameSpace* space) {

		ClassInfo *info = new ClassInfo("JsonArray");
		info->addFunction("setItem", create3rdFunc("setItem", langX_JsonArray_setItem));
		info->addFunction("put", create3rdFunc("put", langX_JsonArray_put));
		info->addFunction("getString", create3rdFunc("getString", langX_JsonArray_getString));
		info->addFunction("getNumber", create3rdFunc("getNumber", langX_JsonArray_getNumber));
		info->addFunction("toStringArray", create3rdFunc("toStringArray", langX_JsonArray_toStringArray));
		info->addFunction("toNumberArray", create3rdFunc("toNumberArray", langX_JsonArray_toNumberArray));
		info->addFunction("size", create3rdFunc("size", langX_JsonArray_size));
		info->addFunction("~JsonArray", create3rdFunc("~JsonArray", langX_JsonArray_JsonArray_Dtor));
		info->addFunction("getJsonArray", create3rdFunc("getJsonArray", langX_JsonArray_getJsonArray));
		info->addFunction("getJsonObject", create3rdFunc("getJsonObject", langX_JsonArray_getJsonObject));
		info->addFunction("JsonArray", create3rdFunc("JsonArray", langX_JsonArray_JsonArray));

		space->putClass(info);
		jsonArrayClass = info;

		return 0;
	}
}


