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
#include "../../../include/LogManager.h"

namespace langX {

  Object* getSimpleJsonValue(cJSON *root) {
    if (!root)
    {
      return nullptr;
    }

    if (root->type == cJSON_String) {
      return Allocator::allocateString(root->valuestring);
    }
    else if (root->type == cJSON_Number) {
      return Allocator::allocateNumber(root->valuedouble);
    }
    else if (root->type == cJSON_True) {
      return Allocator::allocateNumber(1);
    }
    else if (root->type == cJSON_False) {
      return Allocator::allocateNumber(0);
    }

    return nullptr;
  }

  void jsonDecodeToArr(cJSON *root, XArray *array1) {
    //if (!root || !array1)
    //{
    //	return;
    //}

    //if (root->type == cJSON_Array) {
    //	// 数组
    //	if (obj->getType() == NULLOBJECT)
    //	{
    //		// 给的对象是个空， 初始化这个对象	 
    //		int size = cJSON_GetArraySize(root);
    //		XArray *array1 = new XArray(size);

    //		for (size_t i = 0; i < size; i++)
    //		{
    //			cJSON *cjson = cJSON_GetArrayItem(root, i);
    //			Object *tmp2 = getSimpleJsonValue(cjson);
    //			if (tmp2 != nullptr)
    //			{
    //				array1->set(i, tmp2);
    //			}
    //			Allocator::free(tmp2);
    //		}

    //		obj = array1->addRef();
    //	}
    //	else if (obj->getType() == XARRAY)
    //	{
    //		// 

    //	}

    //	return;
    //}

  }

  void jsonDecodeToObj(cJSON *root, Object *obj) {
    if (!root || !obj)
    {
      return;
    }



    if (obj->getType() != ObjectType::OBJECT)
    {
      return;
    }
    langXObject *xobj = ((langXObjectRef*)obj)->getRefObject();

    if (root->type == cJSON_Object) {


      cJSON *child = root->child;
      while (child != nullptr)
      {
        if (child->type == cJSON_Object)
        {
          // 这个元素的第一个元素是一个对象
          Object * tmp1 = xobj->getMember(child->string);
          if (tmp1 && tmp1->getType() == ObjectType::OBJECT)
          {
            // 都是对象
            jsonDecodeToObj(child, tmp1);
          }
        }
        else if (child->type == cJSON_Array)
        {

        }
        else {
          jsonDecodeToObj(child, obj);
        }

        child = child->next;
      }
    } 
    else if (root->type == cJSON_String) {
      String str(root->valuestring);
      xobj->setMember(root->string, &str);
    }
    else if (root->type == cJSON_Number) {
      Number num(root->valuedouble);
      xobj->setMember(root->string, &num);
    }
    else if (root->type == cJSON_True){
      Number num(1);
      xobj->setMember(root->string, &num);
    }
    else if (root->type == cJSON_False) {
      Number num(0);
      xobj->setMember(root->string, &num);
    }

  }


  Object * langX_default_jsonDecode(X3rdFunction *func, const X3rdArgs &args) {
    if (args.object == nullptr)
    {
      logger->error("langX_default_jsonDecode error! NO OBJ!\n");
      return nullptr;
    }

    Object * a = args.args[0];
    Object * b = args.args[1];
    if (a && a->getType() == ObjectType::STRING)
    {
      String * str = (String*)a;
      cJSON *root = cJSON_Parse(str->getValue());
      if (root == nullptr)
      {
        return Allocator::allocate(NULLOBJECT);
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

    return Allocator::allocate(NULLOBJECT);
  }



  Object * langX_default_jsonEncode(X3rdFunction *func, const X3rdArgs &args) {
    if (args.object == nullptr)
    {
      logger->error("langX_default_jsonEncode error! NO OBJ!\n");
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
      return Allocator::allocate(NULLOBJECT);
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
        ret = Allocator::allocate(NULLOBJECT);
      }
    }
    else {
      // 返回字符串

      char *p = cJSON_Print(root);
      ret = Allocator::allocateString(p);
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


