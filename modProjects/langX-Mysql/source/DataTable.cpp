#include <vector>

#include "../include/RegMysqlModule.h"
#include "../../../include/ClassInfo.h"
#include "../../../include/YLlangX.h"
#include "../../../include/Object.h"
#include "../../../include/langXObject.h"
#include "../../../include/langXObjectRef.h"
#include "../../../include/Allocator.h"
#include "../../../include/Number.h"

namespace langX {

	Object * langX_DataTable_DataTable(X3rdFunction *func, const X3rdArgs &args) {
		if (args.object == nullptr)
		{
			printf("langX_DataTable_DataTable error! NO OBJ!\n");
			return nullptr;
		}
		
		std::vector<langXObjectRef*> *list = new std::vector<langXObjectRef*>();
		args.object->set3rdObj(list);

		return nullptr;
	}

	Object * langX_DataTable_DataTable_Dtor(X3rdFunction *func, const X3rdArgs &args) {
		if (args.object == nullptr)
		{
			printf("langX_DataTable_DataTable_Dtor error! NO OBJ!\n");
			return nullptr;
		}

		std::vector<langXObjectRef*> *list = (std::vector<langXObjectRef*> *) args.object->get3rdObj();

		if (!list->empty())
		{
			for (auto i = list->begin(); i != list->end(); i++)
			{
				langXObjectRef * a = (*i);
				delete a;
			}
		}

		list->clear();
		delete list;
		args.object->set3rdObj(nullptr);

		return nullptr;
	}


	Object * langX_DataTable_Get(X3rdFunction *func, const X3rdArgs &args) {
		if (args.object == nullptr)
		{
			printf("langX_DataTable_Get error! NO OBJ!\n");
			return nullptr;
		}

		std::vector<langXObjectRef*> *list = (std::vector<langXObjectRef*> *) args.object->get3rdObj();
		
		Object *a = args.args[0];
		if (a && a->getType() == NUMBER)
		{
			int index = ((Number*)a)->getIntValue();
			if (index >= 0 && index < list->size())
			{
				return list->at(index)->clone();
			}
		}

		return getState()->getAllocator().allocate(NULLOBJECT);
	}


	int regDataTable(langXState *state, XNameSpace* space) {
		
		ClassInfo *dataTable = new ClassInfo("DataTable");
		dataTable->addMember("rowNum", getState()->getAllocator().allocateNumber(0));
		dataTable->addMember("isEmpty", getState()->getAllocator().allocateNumber(0));
		dataTable->addFunction("DataTable", create3rdFunc("DataTable", langX_DataTable_DataTable));
		dataTable->addFunction("~DataTable", create3rdFunc("~DataTable", langX_DataTable_DataTable_Dtor));
		dataTable->addFunction("get", create3rdFunc("get", langX_DataTable_Get));

		space->putClass(dataTable);
		return 0;
	}

}