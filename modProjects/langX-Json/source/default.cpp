#include <map>

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

namespace langX {


	Object * langX_default_jsonDecode(X3rdFunction *func, const X3rdArgs &args) {
		if (args.object == nullptr)
		{
			printf("langX_default_jsonDecode error! NO OBJ!\n");
			return nullptr;
		}

		Object * a = args.args[0];
		if (a && a->getType() == ObjectType::STRING)
		{
			String * str = (String*)a;
			cJSON *root = cJSON_Parse(str->getValue());
			if (root == nullptr)
			{
				return getState()->getAllocator().allocate(NULLOBJECT);
			}

			if (root->type == cJSON_Object)
			{
				return createJsonObject(root)->addRef();
			}
			else if (root->type == cJSON_Array)
			{
				return createJsonArray(root)->addRef();
			}
		}

		return getState()->getAllocator().allocate(NULLOBJECT);
	}



	Object * langX_default_jsonEncode(X3rdFunction *func, const X3rdArgs &args) {
		if (args.object == nullptr)
		{
			printf("langX_default_jsonEncode error! NO OBJ!\n");
			return nullptr;
		}

		Object * a = args.args[0];
		int returnType = 1;  // 返回类型，1 字符串， 2 jsonObject|jsonArray对象
		Object * b = args.args[1];
		if (b && b->getType() == ObjectType::NUMBER)
		{
			returnType = ((Number*)b)->getIntValue();
		}

		cJSON *root = nullptr;

		if (a && a->getType() == ObjectType::OBJECT)
		{
			langXObjectRef *ref = (langXObjectRef*)a;
			langXObject *obj = ref->getRefObject();
			const std::map<std::string, Object*> &map = obj->getMemberMap();
			root = cJSON_CreateObject();

			for (auto i = map.begin(); i != map.end(); i++)
			{
				jsonAddItemToObject(root, i->first.c_str(), i->second);
			}
		}
		else if (a && a->getType() == ObjectType::XARRAY)
		{
			XArrayRef *ref = (XArrayRef*)a;
			root = cJSON_CreateArray();

			for (int i = 0; i < ref->getLength(); i++) {
				jsonAddItemToArray(root, ref->at(i));
			}
		}
		if (root == nullptr)
		{
			return getState()->getAllocator().allocate(NULLOBJECT);
		}

		Object * ret = nullptr;
		if (returnType == 2)
		{
			//  返回jsonObject|jsonArray对象
			if (root->type == cJSON_Array)
			{
				ret= createJsonArray(root)->addRef();
			}
			else if (root->type == cJSON_Object)
			{
				ret= createJsonObject(root)->addRef();
			}
			else {
				ret = getState()->getAllocator().allocate(NULLOBJECT);
			}
		}
		else {
			// 返回字符串

			char *p = cJSON_Print(root);
			ret = getState()->getAllocator().allocateString(p);
			free(p);

		}

		return ret;
	}



	int regdefault(langXState *state, XNameSpace* space) {

		ClassInfo *info = new ClassInfo("default");
		info->addFunction("jsonDecode", create3rdFunc("jsonDecode", langX_default_jsonDecode));
		info->addFunction("jsonEncode", create3rdFunc("jsonEncode", langX_default_jsonEncode));

		space->putClass(info);

		return 0;
	}
}


