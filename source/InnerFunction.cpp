#include "../include/InnerFunction.h"
#include "../include/Object.h"
#include "../include/ExecNode.h"
#include "../include/NodeCreator.h"
#include "../include/StringType.h"
#include "../include/Allocator.h"
#include "../include/Number.h"
#include "../include/Environment.h"
#include "../include/XArray.h"
#include "../extern/y.tab.h"
#include "../include/langXObjectRef.h"
#include "../include/langXThread.h"
#include "XNameSpace.h"
#include "ClassInfo.h"

#include <string.h>
#include <string>
#include <vector>

namespace langX {

	Object * callFunction(Object *obj, Function *func, X3rdArgs *args) {
		if (obj == nullptr || obj->getType() != OBJECT || func == nullptr)
		{
			return nullptr;
		}

		langXObjectRef *ref1 = (langXObjectRef*)obj;

		FunctionRef ref(func);
        ref.setObject(ref1->getRefObject());
		Object *retObj = ref.call(args->args, args->index, "");

		return retObj;
	}

}
