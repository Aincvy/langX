#include <list>
#include "../include/RegCoreModule.h"
#include "../../../include/ClassInfo.h"
#include "../../../include/YLlangX.h"
#include "../../../include/Object.h"
#include "../../../include/langXObject.h"
#include "../../../include/Allocator.h"
#include "../../../include/Number.h"

namespace langX{

	Object * langX_List_List(X3rdFunction *func, const X3rdArgs &args) {
		if (args.object == nullptr)
		{
			printf("langX_Exception_Exception error! NO OBJ!\n");
			return nullptr;
		}

		std::list<Object*> * list = new std::list<Object*>();
		
		args.object->set3rdObj(list);
		return nullptr;
	}

	// ��������
	Object * langX_List_List_Dtor(X3rdFunction *func, const X3rdArgs &args) {
		if (args.object == nullptr)
		{
			printf("langX_Exception_Exception error! NO OBJ!\n");
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
			printf("langX_Exception_Exception error! NO OBJ!\n");
			return nullptr;
		}

		std::list<Object*> * list = (std::list<Object*> *)args.object->get3rdObj();

		Object *a = args.args[0];
		if (a != nullptr)
		{
			list->push_back(a);
		}

		return nullptr;
	}

	Object * langX_List_Remove(X3rdFunction *func, const X3rdArgs &args) {

		return nullptr;
	}

	Object * langX_List_Get(X3rdFunction *func, const X3rdArgs &args) {

		return nullptr;
	}

	Object * langX_List_Size(X3rdFunction *func, const X3rdArgs &args) {
		if (args.object == nullptr)
		{
			printf("langX_Exception_Exception error! NO OBJ!\n");
			return nullptr;
		}

		std::list<Object*> * list = (std::list<Object*> *)args.object->get3rdObj();

		return getState()->getAllocator().allocateNumber(list->size());
	}

	Object * langX_List_Set(X3rdFunction *func, const X3rdArgs &args) {

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
		list->addFunction("set", create3rdFunc("set", langX_List_Set));
		list->addFunction("iterator", create3rdFunc("iterator", langX_List_Iterator));
		space->putClass(list);

		return 0;
	}

}