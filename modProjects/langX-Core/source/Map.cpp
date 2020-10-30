#include <map>
#include <string>

#include "../include/RegCoreModule.h"
#include "../include/RegCoreModule.h"
#include "../../../include/ClassInfo.h"
#include "../../../include/YLlangX.h"
#include "../../../include/Object.h"
#include "../../../include/langXObject.h"
#include "../../../include/Allocator.h"
#include "../../../include/Number.h"

namespace langX {

	Object * langX_Map_Map(X3rdFunction *func, const X3rdArgs &args) {
		if (args.object == nullptr)
		{
			printf("langX_Map_Map error! NO OBJ!\n");
			return nullptr;
		}

		std::map<std::string, Object*> * map = new std::map<std::string, Object*>();
		args.object->set3rdObj(map);

		return nullptr;
	}

	Object * langX_Map_Map_Dtor(X3rdFunction *func, const X3rdArgs &args) {
		if (args.object == nullptr)
		{
			printf("langX_Map_Map_Dtor error! NO OBJ!\n");
			return nullptr;
		}

		std::map<std::string, Object*> * map = (std::map<std::string, Object*> *)args.object->get3rdObj();

		for (auto i = map->begin(); i != map->end(); i++)
		{
			Object *t = i->second;
			Allocator::free(t);
		}

		map->clear();
		delete map;

		return nullptr;
	}

	Object * langX_Map_Put(X3rdFunction *func, const X3rdArgs &args) {
		if (args.object == nullptr)
		{
			printf("langX_Map_Map_Dtor error! NO OBJ!\n");
			return nullptr;
		}

		std::map<std::string, Object*> * map = (std::map<std::string, Object*> *)args.object->get3rdObj();

		Object *a = args.args[0];
		Object *b = args.args[1];
		if (a && b)
		{
			const char * c = a->characteristic();
			auto i = map->find(c);
			if (i != map->end())
			{
				Allocator::free(i->second);
				i->second = b->clone();
			}
			else {
				map->insert(std::make_pair(c, b->clone()));
			}
			return Allocator::allocateNumber(1);
		}

		return Allocator::allocateNumber(0);
	}


	Object * langX_Map_Size(X3rdFunction *func, const X3rdArgs &args) {
		if (args.object == nullptr)
		{
			printf("langX_Map_Map_Dtor error! NO OBJ!\n");
			return nullptr;
		}

		std::map<std::string, Object*> * map = (std::map<std::string, Object*> *)args.object->get3rdObj();

		return Allocator::allocateNumber(map->size());
	}

	Object * langX_Map_Get(X3rdFunction *func, const X3rdArgs &args) {
		if (args.object == nullptr)
		{
			printf("langX_Map_Map_Dtor error! NO OBJ!\n");
			return nullptr;
		}

		std::map<std::string, Object*> * map = (std::map<std::string, Object*> *)args.object->get3rdObj();

		Object *a = args.args[0];
		if (a )
		{
			const char * c = a->characteristic();

			auto i = map->find(c);
			if (i != map->end())
			{
				return Allocator::copy(i->second);
			}
		}

		return Allocator::allocate(NULLOBJECT);
	}

	Object * langX_Map_Remove(X3rdFunction *func, const X3rdArgs &args) {
		if (args.object == nullptr)
		{
			printf("langX_Map_Map_Dtor error! NO OBJ!\n");
			return nullptr;
		}

		std::map<std::string, Object*> * map = (std::map<std::string, Object*> *)args.object->get3rdObj();

		Object *a = args.args[0];
		if (a)
		{
			const char * c = a->characteristic();

			auto i = map->find(c);
			if (i != map->end())
			{
				// t 会被从map中移除， 所以直接返回出去就好了。
				Object * t = i->second;
				map->erase(i++);
				return t;
			}
		}

		return Allocator::allocate(NULLOBJECT);
	}

	Object * langX_Map_ContainsKey(X3rdFunction *func, const X3rdArgs &args) {
		if (args.object == nullptr)
		{
			printf("langX_Map_Map_Dtor error! NO OBJ!\n");
			return nullptr;
		}

		std::map<std::string, Object*> * map = (std::map<std::string, Object*> *)args.object->get3rdObj();
		
		Object *a = args.args[0];
		if (a)
		{
			const char * c = a->characteristic();
			if (map->find(c) != map->end())
			{
				return  Allocator::allocateNumber(1);
			}
		}

		return  Allocator::allocateNumber(0);
	}
	//containsKey

	int regMap(langXState *state, XNameSpace* space) {

		ClassInfo *map = new ClassInfo("Map");
		map->addFunction("Map", create3rdFunc("Map", langX_Map_Map));
		map->addFunction("~Map", create3rdFunc("~Map", langX_Map_Map_Dtor));
		map->addFunction("put", create3rdFunc("put", langX_Map_Put));
		map->addFunction("get", create3rdFunc("get", langX_Map_Get));
		map->addFunction("remove", create3rdFunc("remove", langX_Map_Remove));
		map->addFunction("size", create3rdFunc("size", langX_Map_Size));
		map->addFunction("containsKey", create3rdFunc("containsKey", langX_Map_ContainsKey));

		space->putClass(map);
		return 0;
	}

}