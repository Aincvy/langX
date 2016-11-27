#include "../include/RegPythonModule.h"


#include "../../../include/ClassInfo.h"
#include "../../../include/YLlangX.h"
#include "../../../include/Object.h"
#include "../../../include/langXObject.h"
#include "../../../include/langXObjectRef.h"
#include "../../../include/Allocator.h"
#include "../../../include/Number.h"


#ifdef WIN32 
#include "../../../lib/Python-3.5.2/Include/Python.h"
#else
#include <python3.5m/Python.h>
#endif


namespace langX {

	struct PythonLibInfo
	{
		//  是否已经完成了 加载
		bool loaded;
	};

	void initPythonLib(langXObject *obj) {
		if (obj == nullptr)
		{
			return;
		}

		struct PythonLibInfo *info = (struct PythonLibInfo*)calloc(1, sizeof(struct PythonLibInfo));
		info->loaded = false;
		obj->set3rdObj(info);
	}

	void freePythonLib(langXObject *obj) {
		if (obj == nullptr)
		{
			return;

		}

		struct PythonLibInfo *info = (struct PythonLibInfo*) obj->get3rdObj();
		free(info);

		obj->set3rdObj(nullptr);
	}


	Object * langX_PythonLib_unload(X3rdFunction *func, const X3rdArgs &args) {
		if (args.object == nullptr)
		{
			printf("langX_PythonLib_unload error! NO OBJ!\n");
			return nullptr;
		}

		struct PythonLibInfo *info = (struct PythonLibInfo*) args.object->get3rdObj();
		info->loaded = false;
		Py_Finalize();

		return nullptr;
	}



	Object * langX_PythonLib_isLoad(X3rdFunction *func, const X3rdArgs &args) {
		if (args.object == nullptr)
		{
			printf("langX_PythonLib_isLoad error! NO OBJ!\n");
			return nullptr;
		}

		struct PythonLibInfo *info = (struct PythonLibInfo*) args.object->get3rdObj();
		if (info->loaded)
		{
			return getState()->getAllocator().allocateNumber(1);
		}

		return getState()->getAllocator().allocateNumber(0);

	}



	Object * langX_PythonLib_load(X3rdFunction *func, const X3rdArgs &args) {
		if (args.object == nullptr)
		{
			printf("langX_PythonLib_load error! NO OBJ!\n");
			return nullptr;
		}

		struct PythonLibInfo *info = (struct PythonLibInfo*) args.object->get3rdObj();
		info->loaded = false;

		Py_Initialize();
		
		if (Py_IsInitialized())
		{
			info->loaded = true;
			return getState()->getAllocator().allocateNumber(1);
		}

		return getState()->getAllocator().allocateNumber(0);
	}



	Object * langX_PythonLib_PythonLib_Dtor(X3rdFunction *func, const X3rdArgs &args) {
		if (args.object == nullptr)
		{
			printf("langX_PythonLib_PythonLib_Dtor error! NO OBJ!\n");
			return nullptr;
		}

		freePythonLib(args.object);

		return nullptr;
	}



	Object * langX_PythonLib_PythonLib(X3rdFunction *func, const X3rdArgs &args) {
		if (args.object == nullptr)
		{
			printf("langX_PythonLib_PythonLib error! NO OBJ!\n");
			return nullptr;
		}

		initPythonLib(args.object);

		return nullptr;
	}



	int regPythonLib(langXState *state ,XNameSpace* space) {

		ClassInfo *info = new ClassInfo("PythonLib");
		info->addFunction("unload", create3rdFunc("unload", langX_PythonLib_unload));
		info->addFunction("isLoad", create3rdFunc("isLoad", langX_PythonLib_isLoad));
		info->addFunction("load", create3rdFunc("load", langX_PythonLib_load));
		info->addFunction("~PythonLib", create3rdFunc("~PythonLib", langX_PythonLib_PythonLib_Dtor));
		info->addFunction("PythonLib", create3rdFunc("PythonLib", langX_PythonLib_PythonLib));

		return 0;
	}
}


