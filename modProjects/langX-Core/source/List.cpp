#include <list>
#include <string.h>

#include "../include/RegCoreModule.h"
#include "../../../include/ClassInfo.h"
#include "../../../include/YLlangX.h"
#include "../../../include/Object.h"
#include "../../../include/langXObject.h"
#include "../../../include/Allocator.h"
#include "../../../include/Number.h"

namespace langX {

	Object * langX_List_List(X3rdFunction *func, const X3rdArgs &args) {
		if (args.object == nullptr)
		{
			printf("langX_List_List error! NO OBJ!\n");
			return nullptr;
		}

		std::list<Object*> * list = new std::list<Object*>();
		args.object->set3rdObj(list);

		return nullptr;
	}

	// 析构函数
	Object * langX_List_List_Dtor(X3rdFunction *func, const X3rdArgs &args) {
		if (args.object == nullptr)
		{
			printf("langX_List_List_Dtor error! NO OBJ!\n");
			return nullptr;
		}

		std::list<Object*> * list = (std::list<Object*> *)args.object->get3rdObj();

		for (auto i = list->begin(); i != list->end(); i++)
		{
			Object *t = (*i);
			getState()->getAllocator().free(t);
		}

		list->clear();
		delete list;

		return nullptr;
	}

	Object * langX_List_Add(X3rdFunction *func, const X3rdArgs &args) {

		if (args.object == nullptr)
		{
			printf("langX_List_Add error! NO OBJ!\n");
			return nullptr;
		}

		std::list<Object*> * list = (std::list<Object*> *)args.object->get3rdObj();

		Object *a = args.args[0];
		if (a != nullptr)
		{
			list->push_back(a->clone());
		}

		return nullptr;
	}

	Object * langX_List_Remove(X3rdFunction *func, const X3rdArgs &args) {

		if (args.object == nullptr)
		{
			printf("langX_List_Remove error! NO OBJ!\n");
			return nullptr;
		}

		std::list<Object*> * list = (std::list<Object*> *)args.object->get3rdObj();
		Object *a = args.args[0];
		if (a != nullptr)
		{
			if (a->getType() == ObjectType::NUMBER)
			{
				int index = ((Number*)a)->getIntValue();
				if (index < list->size())
				{
					auto i = list->begin();
					for (int a = 0; a < index; a++)
					{
						i++;
					}
					getState()->getAllocator().free(*i);
					list->erase(i++);
				}
			}
			else {
				const char * str = a->characteristic();
				for (auto i = list->begin(); i != list->end(); i++)
				{
					if (strcmp(str,(*i)->characteristic()) == 0)
					{
						// 相等
						list->erase(i++);
						break;
					}
				}
			}
		}

		return nullptr;
	}

	Object * langX_List_Get(X3rdFunction *func, const X3rdArgs &args) {

		if (args.object == nullptr)
		{
			printf("langX_List_Get error! NO OBJ!\n");
			return nullptr;
		}

		std::list<Object*> * list = (std::list<Object*> *)args.object->get3rdObj();
		Object *a = args.args[0];
		if (a != nullptr)
		{
			if (a->getType() == ObjectType::NUMBER)
			{
				int index = ((Number*)a)->getIntValue();
				if (index < list->size())
				{
					//  返回值的 copy
					auto i = list->begin();
					for (int a = 0; a < index; a++)
					{
						i++;
					}
					return getState()->getAllocator().copy(*i);
				}
			}
		}

		return nullptr;
	}

	Object * langX_List_Size(X3rdFunction *func, const X3rdArgs &args) {
		if (args.object == nullptr)
		{
			printf("langX_List_Size error! NO OBJ!\n");
			return nullptr;
		}

		std::list<Object*> * list = (std::list<Object*> *)args.object->get3rdObj();

		return getState()->getAllocator().allocateNumber(list->size());
	}

	Object * langX_List_Set(X3rdFunction *func, const X3rdArgs &args) {

		if (args.object == nullptr)
		{
			printf("langX_List_Size error! NO OBJ!\n");
			return nullptr;
		}
		if (args.index < 1)
		{
			// 缺少参数
			return nullptr;
		}

		std::list<Object*> * list = (std::list<Object*> *)args.object->get3rdObj();
		Object *a = args.args[0];
		Object *b = args.args[1];
		if (a != nullptr && b != nullptr)
		{
			if (a->getType() == ObjectType::NUMBER)
			{
				int index = ((Number*)a)->getIntValue();
				if (index >= list->size())
				{
					return nullptr;
				}

				auto i = list->begin();
				for (int a = 0; a < index; a++)
				{
					i++;
				}
				getState()->getAllocator().free(*i);
				*i = b->clone();
			}
		}


		return nullptr;
	}

	Object * langX_List_Iterator(X3rdFunction *func, const X3rdArgs &args) {

		return nullptr;
	}


	int regList(langXState *state, XNameSpace* space) {

		ClassInfo *list = new ClassInfo("List");
		list->addFunction("List", create3rdFunc("List", langX_List_List));
		list->addFunction("~List", create3rdFunc("~List", langX_List_List_Dtor));
		list->addFunction("add", create3rdFunc("add", langX_List_Add));
		list->addFunction("remove", create3rdFunc("remove", langX_List_Remove));
		list->addFunction("get", create3rdFunc("get", langX_List_Get));
		list->addFunction("size", create3rdFunc("size", langX_List_Size));
		list->addFunction("set2", create3rdFunc("set2", langX_List_Set));
		list->addFunction("iterator", create3rdFunc("iterator", langX_List_Iterator));
		space->putClass(list);

		return 0;
	}

}