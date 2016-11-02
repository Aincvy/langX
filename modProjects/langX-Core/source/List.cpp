#include <list>
#include "../include/RegCoreModule.h"
#include "../../../include/ClassInfo.h"
#include "../../../include/YLlangX.h"

namespace langX{

	Object * langX_List_List(X3rdFunction *func, const X3rdArgs &args) {

		return nullptr;
	}


	int regList(langXState *state, XNameSpace* space) {

		ClassInfo *list = new ClassInfo("List");
		list->addFunction("List", create3rdFunc("List", langX_List_List));
		space->putClass(list);

		return 0;
	}

}