
#include "../include/RegDefaultClasses.h"

#include "../../../include/ClassInfo.h"
#include "../../../include/YLlangX.h"
#include "../../../include/Object.h"
#include "../../../include/langXObject.h"
#include "../../../include/langXObjectRef.h"
#include "../../../include/Allocator.h"
#include "../../../include/Number.h"

namespace langX {


	Object * langX_Thread_run(X3rdFunction *func, const X3rdArgs &args) {
		if (args.object == nullptr)
		{
			printf("langX_Thread_run error! NO OBJ!\n");
			return nullptr;
		}

		return nullptr;
	}



	Object * langX_Thread_sleep(X3rdFunction *func, const X3rdArgs &args) {
		if (args.object == nullptr)
		{
			printf("langX_Thread_sleep error! NO OBJ!\n");
			return nullptr;
		}

		return nullptr;
	}



	Object * langX_Thread_currentThread(X3rdFunction *func, const X3rdArgs &args) {
		if (args.object == nullptr)
		{
			printf("langX_Thread_currentThread error! NO OBJ!\n");
			return nullptr;
		}

		return nullptr;
	}



	Object * langX_Thread_getName(X3rdFunction *func, const X3rdArgs &args) {
		if (args.object == nullptr)
		{
			printf("langX_Thread_getName error! NO OBJ!\n");
			return nullptr;
		}

		return nullptr;
	}



	Object * langX_Thread_getId(X3rdFunction *func, const X3rdArgs &args) {
		if (args.object == nullptr)
		{
			printf("langX_Thread_getId error! NO OBJ!\n");
			return nullptr;
		}

		return nullptr;
	}



	int regThread(langXState *state, XNameSpace* space) {

		ClassInfo *info = new ClassInfo("Thread");
		info->addFunction("run", create3rdFunc("run", langX_Thread_run));
		info->addFunction("sleep", create3rdFunc("sleep", langX_Thread_sleep));
		info->addFunction("currentThread", create3rdFunc("currentThread", langX_Thread_currentThread));
		info->addFunction("getName", create3rdFunc("getName", langX_Thread_getName));
		info->addFunction("getId", create3rdFunc("getId", langX_Thread_getId));

		space->putClass(info);

		return 0;
	}
}


