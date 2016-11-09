#include <vector>
#include <string.h>

#include "../include/RegCoreModule.h"
#include "../../../include/ClassInfo.h"
#include "../../../include/YLlangX.h"
#include "../../../include/Object.h"
#include "../../../include/langXObject.h"
#include "../../../include/Allocator.h"
#include "../../../include/Number.h"

namespace langX {

	Object * langX_Vector_Vector(X3rdFunction *func, const X3rdArgs &args) {
		if (args.object == nullptr)
		{
			printf("langX_Vector_Vector error! NO OBJ!\n");
			return nullptr;
		}

		std::vector<Object*> * vector = new std::vector<Object*>();
		args.object->set3rdObj(vector);

		return nullptr;
	}

	Object * langX_Vector_Vector_Dtor(X3rdFunction *func, const X3rdArgs &args) {
		if (args.object == nullptr)
		{
			printf("langX_Vector_Vector_Dtor error! NO OBJ!\n");
			return nullptr;
		}

		std::vector<Object*> * vector = (std::vector<Object*> *)args.object->get3rdObj();

		for (auto i = vector->begin(); i != vector->end(); i++)
		{
			Object *t = (*i);
			getState()->getAllocator().free(t);
		}

		vector->clear();
		delete vector;

		return nullptr;
	}

	Object * langX_Vector_Add(X3rdFunction *func, const X3rdArgs &args) {

		if (args.object == nullptr)
		{
			printf("langX_Vector_Add error! NO OBJ!\n");
			return nullptr;
		}

		std::vector<Object*> * vector = (std::vector<Object*> *)args.object->get3rdObj();

		Object *a = args.args[0];
		if (a != nullptr)
		{
			vector->push_back(a->clone());
		}

		return nullptr;
	}


	Object * langX_Vector_Remove(X3rdFunction *func, const X3rdArgs &args) {

		if (args.object == nullptr)
		{
			printf("langX_Vector_Remove error! NO OBJ!\n");
			return nullptr;
		}

		std::vector<Object*> * vector = (std::vector<Object*> *)args.object->get3rdObj();
		Object *a = args.args[0];
		if (a != nullptr)
		{
			if (a->getType() == ObjectType::NUMBER)
			{
				int index = ((Number*)a)->getIntValue();
				if (index < vector->size())
				{
					auto i = vector->begin();
					for (int a = 0; a < index; a++)
					{
						i++;
					}
					getState()->getAllocator().free(*i);
					vector->erase(i++);
				}
			}
			else {
				const char * str = a->characteristic();
				for (auto i = vector->begin(); i != vector->end(); i++)
				{
					if (strcmp(str, (*i)->characteristic()) == 0)
					{
						// ���
						vector->erase(i++);
						break;
					}
				}
			}
		}

		return nullptr;
	}

	Object * langX_Vector_Get(X3rdFunction *func, const X3rdArgs &args) {

		if (args.object == nullptr)
		{
			printf("langX_Vector_Get error! NO OBJ!\n");
			return nullptr;
		}

		std::vector<Object*> * vector = (std::vector<Object*> *)args.object->get3rdObj();
		Object *a = args.args[0];
		if (a != nullptr)
		{
			if (a->getType() == ObjectType::NUMBER)
			{
				int index = ((Number*)a)->getIntValue();
				if (index < vector->size())
				{
					//  ����ֵ�� copy
					return getState()->getAllocator().copy( vector->at(index));
				}
			}
		}

		return nullptr;
	}

	Object * langX_Vector_Size(X3rdFunction *func, const X3rdArgs &args) {
		if (args.object == nullptr)
		{
			printf("langX_Vector_Size error! NO OBJ!\n");
			return nullptr;
		}

		std::vector<Object*> * vector = (std::vector<Object*> *)args.object->get3rdObj();
		
		return getState()->getAllocator().allocateNumber(vector->size());
	}


	Object * langX_Vector_First(X3rdFunction *func, const X3rdArgs &args) {

		if (args.object == nullptr)
		{
			printf("langX_Vector_First error! NO OBJ!\n");
			return nullptr;
		}

		std::vector<Object*> * vector = (std::vector<Object*> *)args.object->get3rdObj();
		if (vector->empty())
		{
			return getState()->getAllocator().allocate(NULLOBJECT);
		}


		return getState()->getAllocator().copy(vector->front());
	}

	Object * langX_Vector_Last(X3rdFunction *func, const X3rdArgs &args) {

		if (args.object == nullptr)
		{
			printf("langX_Vector_Last error! NO OBJ!\n");
			return nullptr;
		}

		std::vector<Object*> * vector = (std::vector<Object*> *)args.object->get3rdObj();
		if (vector->empty())
		{
			return getState()->getAllocator().allocate(NULLOBJECT);
		}


		return getState()->getAllocator().copy(vector->back());
	}

	Object * langX_Vector_Iterator(X3rdFunction *func, const X3rdArgs &args) {

		return nullptr;
	}


	int regVector(langXState *state, XNameSpace* space) {

		ClassInfo *vector = new ClassInfo("Vector");
		vector->addFunction("Vector", create3rdFunc("Vector", langX_Vector_Vector));
		vector->addFunction("~Vector", create3rdFunc("~Vector", langX_Vector_Vector_Dtor));
		vector->addFunction("add", create3rdFunc("add", langX_Vector_Add));
		vector->addFunction("remove", create3rdFunc("remove", langX_Vector_Remove));
		vector->addFunction("get", create3rdFunc("get", langX_Vector_Get));
		vector->addFunction("size", create3rdFunc("size", langX_Vector_Size));
		vector->addFunction("first", create3rdFunc("first", langX_Vector_First));
		vector->addFunction("last", create3rdFunc("last", langX_Vector_Last));
		vector->addFunction("iterator", create3rdFunc("iterator", langX_Vector_Iterator));

		space->putClass(vector);
		return 0;
	}

}