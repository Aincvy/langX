#include <map>

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

		std::map<Object*, Object*> * map = new std::map<Object*, Object*>();
		args.object->set3rdObj(map);

		return nullptr;
	}


	int regMap(langXState *state, XNameSpace* space) {

		ClassInfo *map = new ClassInfo("Map");
		map->addFunction("Map", create3rdFunc("Map", langX_Map_Map));

		space->putClass(map);
		return 0;
	}

}