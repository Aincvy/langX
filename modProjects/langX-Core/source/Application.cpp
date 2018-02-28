
#include "../../../include/ClassInfo.h"
#include "../../../include/YLlangX.h"
#include "../../../include/Object.h"
#include "../../../include/langXObject.h"
#include "../../../include/langXObjectRef.h"
#include "../../../include/Allocator.h"
#include "../../../include/Number.h"

namespace langX {


Object * langX_Application_exit(X3rdFunction *func, const X3rdArgs &args) {
	if (args.object == nullptr)
	{
		printf("langX_Application_exit error! NO OBJ!\n");
		return nullptr;
	}

	return nullptr;
}

  
  int regApplication(langXState *state, XNameSpace* space) {
	
	ClassInfo *info = new ClassInfo("Application");	
info->addMember("ExecutablePath", getState()->getAllocator().allocateNumber(0));
info->addMember("StartupPath", getState()->getAllocator().allocateNumber(0));
info->addMember("IsDebug", getState()->getAllocator().allocateNumber(0));
info->addMember("RunPlatform", getState()->getAllocator().allocateNumber(0));
info->addMember("StartTime", getState()->getAllocator().allocateNumber(0));
info->addMember("Logger", getState()->getAllocator().allocateNumber(0));
info->addFunction("exit", create3rdFunc("exit", langX_Application_exit));
	
	space->putClass(info);
	
  	return 0;
  }
}


