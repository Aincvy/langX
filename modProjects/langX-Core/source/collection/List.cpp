#include <list>
#include <string.h>

#include "CoreModule.h"
#include "RegCoreModule.h"

#include "langX/langXSimple.h"


namespace langX {

	Object * langX_List_List(X3rdFunction *func, const X3rdArgs &args) {
		if (args.object == nullptr)
		{
			coreModuleLogger->error("langX_List_List error! NO OBJ!");
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
			coreModuleLogger->error("langX_List_List_Dtor error! NO OBJ!");
			return nullptr;
		}

		std::list<Object*> * list = (std::list<Object*> *)args.object->get3rdObj();

		for (auto i = list->begin(); i != list->end(); i++)
		{
			Object *t = (*i);
			Allocator::free(t);
		}

		list->clear();
		delete list;

		return nullptr;
	}

	Object * langX_List_Add(X3rdFunction *func, const X3rdArgs &args) {

		if (args.object == nullptr)
		{
			coreModuleLogger->error("langX_List_Add error! NO OBJ!");
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
			coreModuleLogger->error("langX_List_Remove error! NO OBJ!");
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
					Allocator::free(*i);
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
			coreModuleLogger->error("langX_List_Get error! NO OBJ!");
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
					return Allocator::copy(*i);
				}
			}
		}

		return nullptr;
	}

	Object * langX_List_Size(X3rdFunction *func, const X3rdArgs &args) {
		if (args.object == nullptr)
		{
			coreModuleLogger->error("langX_List_Size error! NO OBJ!");
			return nullptr;
		}

		std::list<Object*> * list = (std::list<Object*> *)args.object->get3rdObj();

		return Allocator::allocateNumber(list->size());
	}

	Object * langX_List_Set(X3rdFunction *func, const X3rdArgs &args) {

		if (args.object == nullptr)
		{
			coreModuleLogger->error("langX_List_Size error! NO OBJ!");
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
				Allocator::free(*i);
				*i = b->clone();
			}
		}

		return nullptr;
	}

	Object * langX_List_Clear(X3rdFunction *func, const X3rdArgs &args) {

		if (args.object == nullptr)
		{
			coreModuleLogger->error("langX_List_Clear error! NO OBJ!");
			return nullptr;
		}

		std::list<Object*> * list = (std::list<Object*> *)args.object->get3rdObj();
		list->clear();

		return nullptr;
	}

    Object * langX_List_ToArray(X3rdFunction *func, const X3rdArgs &args) {

        if (args.object == nullptr)
        {
            coreModuleLogger->error("langX_List_ToArray error! NO OBJ!");
            return nullptr;
        }

        auto list = (std::list<Object*> *)args.object->get3rdObj();

        auto array = Allocator::allocateArray(list->size());
        for (auto i = list->begin(); i != list->end() ; i++){
            array->add( *i );
        }

        return array->addRef();
    }


	Object * langX_List_Iterator(X3rdFunction *func, const X3rdArgs &args) {
		if (args.object == nullptr)
		{
			coreModuleLogger->error("langX_List_Iterator error! NO OBJ!");
			return nullptr;
		}

		// todo
		std::list<Object*> * list = (std::list<Object*> *)args.object->get3rdObj();

		return nullptr;
	}


	int regList(langXState *state, XNameSpace* space) {

		ClassInfo *list = new ClassInfo("List");
		list->addFunction(create3rdFunc("List", langX_List_List));
		list->addFunction(create3rdFunc("~List", langX_List_List_Dtor));
		list->addFunction(create3rdFunc("add", langX_List_Add));
		list->addFunction(create3rdFunc("remove", langX_List_Remove));
		list->addFunction(create3rdFunc("get", langX_List_Get));
		list->addFunction(create3rdFunc("operator[]", langX_List_Get));
		list->addFunction(create3rdFunc("size", langX_List_Size));
		list->addFunction(create3rdFunc("set", langX_List_Set));
		list->addFunction(create3rdFunc("iterator", langX_List_Iterator));
		list->addFunction(create3rdFunc("clear", langX_List_Clear));
		list->addFunction(create3rdFunc("toArray", langX_List_ToArray));
		space->putClass(list);

		return 0;
	}



}