#include <vector>

#include "../include/RegMysqlModule.h"
#include "../../../include/ClassInfo.h"
#include "../../../include/YLlangX.h"
#include "../../../include/Object.h"
#include "../../../include/langXObject.h"
#include "../../../include/langXObjectRef.h"
#include "../../../include/Allocator.h"
#include "../../../include/Number.h"
#include "../../../include/StringType.h"

namespace langX {


	Object * langX_DataRow_DataRow(X3rdFunction *func, const X3rdArgs &args) {
		if (args.object == nullptr)
		{
			printf("langX_DataRow_DataRow error! NO OBJ!\n");
			return nullptr;
		}

		DataRow *row = new DataRow();
		args.object->set3rdObj(row);
		return nullptr;
	}

	Object * langX_DataRow_DataRow_Dtor(X3rdFunction *func, const X3rdArgs &args) {
		if (args.object == nullptr)
		{
			printf("langX_DataRow_DataRow_Dtor error! NO OBJ!\n");
			return nullptr;
		}

		DataRow *row = (DataRow *)args.object->get3rdObj();
		std::vector<Object*> list = row->list;

		if (!list.empty())
		{
			for (auto i = list.begin(); i != list.end(); i++)
			{
				Object * a = (*i);
				Allocator::free(a);
			}
		}

		row->kvpair.clear();
		list.clear();
		delete row;
		args.object->set3rdObj(nullptr);

		return nullptr;
	}


	Object * langX_DataRow_Get(X3rdFunction *func, const X3rdArgs &args) {
		if (args.object == nullptr)
		{
			printf("langX_DataTable_Get error! NO OBJ!\n");
			return nullptr;
		}

		DataRow *row = (DataRow *)args.object->get3rdObj();
		std::vector<Object*> list = row->list;

		Object *a = args.args[0];
		if (a )
		{
			if (a->getType() == NUMBER)
			{
				int index = ((Number*)a)->getIntValue();
				if (index >= 0 && index < list.size())
				{
					return list.at(index)->clone();
				}
			}
			else if (a->getType() == STRING)
			{
				const char * key = ((String*)a)->getValue();
				auto itr = row->kvpair.find(key);
				if (itr == row->kvpair.end())
				{
					return Allocator::allocate(NULLOBJECT);
				}
				
				return itr->second->clone();
			}
			
		}

		return Allocator::allocate(NULLOBJECT);
	}


	int regDataRow(langXState *state, XNameSpace* space) {
		
		ClassInfo *dataRow = new ClassInfo("DataRow");	
		dataRow->addMember("colNum", Allocator::allocateNumber(0));
		dataRow->addMember("rowIndex", Allocator::allocateNumber(0));
		dataRow->addFunction("DataRow", create3rdFunc("DataRow", langX_DataRow_DataRow));
		dataRow->addFunction("~DataRow", create3rdFunc("~DataRow", langX_DataRow_DataRow_Dtor));
		dataRow->addFunction("get", create3rdFunc("get", langX_DataRow_Get));
		space->putClass(dataRow);

		return 0;
	}

}