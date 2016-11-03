#include <set>

#include "../include/RegCoreModule.h"
#include "../../../include/ClassInfo.h"
#include "../../../include/YLlangX.h"
#include "../../../include/Object.h"
#include "../../../include/Allocator.h"
#include "../../../include/langXObject.h"
#include "../../../include/Number.h"

namespace langX {

	Object * langX_Set_Set(X3rdFunction *func, const X3rdArgs &args) {
		if (args.object == nullptr)
		{
			printf("langX_List_List error! NO OBJ!\n");
			return nullptr;
		}

		std::set<Object*> * set = new std::set<Object*>();
		args.object->set3rdObj(set);

		return nullptr;
	}

	Object * langX_Set_Set_Dtor(X3rdFunction *func, const X3rdArgs &args) {
		if (args.object == nullptr)
		{
			printf("langX_List_List_Dtor error! NO OBJ!\n");
			return nullptr;
		}

		std::set<Object*> * set = (std::set<Object*> *)args.object->get3rdObj();

		for (auto i = set->begin(); i != set->end(); i++)
		{
			Object *t = (*i);
			getState()->getAllocator().free(t);
		}

		set->clear();
		delete set;

		return nullptr;
	}

	Object * langX_Set_Add(X3rdFunction *func, const X3rdArgs &args) {

		if (args.object == nullptr)
		{
			printf("langX_List_Add error! NO OBJ!\n");
			return nullptr;
		}

		std::set<Object*> * set = (std::set<Object*> *)args.object->get3rdObj();

		Object *a = args.args[0];
		if (a != nullptr)
		{
			set->insert(a->clone());
		}

		return nullptr;
	}

	Object * langX_Set_First(X3rdFunction *func, const X3rdArgs &args) {

		if (args.object == nullptr)
		{
			printf("langX_List_Add error! NO OBJ!\n");
			return nullptr;
		}

		std::set<Object*> * set = (std::set<Object*> *)args.object->get3rdObj();
		if (set->empty())
		{
			return nullptr;
		}

		return (*set->begin());
	}

	Object * langX_Set_Remove(X3rdFunction *func, const X3rdArgs &args) {

		if (args.object == nullptr)
		{
			printf("langX_List_Add error! NO OBJ!\n");
			return nullptr;
		}

		std::set<Object*> * set = (std::set<Object*> *)args.object->get3rdObj();

		// TODO 

		return nullptr;
	}

	Object * langX_Set_Size(X3rdFunction *func, const X3rdArgs &args) {
		if (args.object == nullptr)
		{
			printf("langX_List_Size error! NO OBJ!\n");
			return nullptr;
		}

		std::set<Object*> * set = (std::set<Object*> *)args.object->get3rdObj();

		return getState()->getAllocator().allocateNumber(set->size());
	}


	Object * langX_Set_Iterator(X3rdFunction *func, const X3rdArgs &args) {

		return nullptr;
	}

	int regSet(langXState *state, XNameSpace* space) {

		ClassInfo *set = new ClassInfo("Set");
		set->addFunction("Set", create3rdFunc("Set", langX_Set_Set));
		set->addFunction("~Set", create3rdFunc("~Set", langX_Set_Set_Dtor));
		set->addFunction("add", create3rdFunc("add", langX_Set_Add));
		set->addFunction("first", create3rdFunc("first", langX_Set_First));
		set->addFunction("remove", create3rdFunc("remove", langX_Set_Remove));
		set->addFunction("size", create3rdFunc("size", langX_Set_Size));
		set->addFunction("iterator", create3rdFunc("iterator", langX_Set_Iterator));
		space->putClass(set);

		return 0;
	}
}