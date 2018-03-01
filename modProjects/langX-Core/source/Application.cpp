#include <stdlib.h>
#include <unistd.h>

#include "../include/RegDefaultClasses.h"

#include "../../../include/ClassInfo.h"
#include "../../../include/YLlangX.h"
#include "../../../include/Object.h"
#include "../../../include/langXObject.h"
#include "../../../include/langXObjectRef.h"
#include "../../../include/Allocator.h"
#include "../../../include/Number.h"
#include "../../../include/Utils.h"
#include "../../../include/String.h"

namespace langX {


  Object * langX_Application_exit(X3rdFunction *func, const X3rdArgs &args) {
    Object *a = args.args[0];
    int v = 0;
    if(a != nullptr && a->getType() == ObjectType::NUMBER){
       v = ((Number*)a)->getIntValue();
    }
    
    exit(v);
    return nullptr;
  }


  int regApplication(langXState *state, XNameSpace* space) {

    char pathBuf[2048] = {0};
    getcwd(pathBuf, 2048); 

    ClassInfo *info = new ClassInfo("Application");	
    info->addMember("ExecutablePath", Allocator::allocateString(pathBuf));
    info->addMember("StartupPath", Allocator::allocateString(pathBuf));
    info->addMember("IsDebug", Allocator::allocateNumber(1));
    info->addMember("RunPlatform", Allocator::allocateString("Linux"));
    info->addMember("StartTime", Allocator::allocateNumber(getTime()));
    info->addMember("Logger", Allocator::allocate(ObjectType::NULLOBJECT));
    info->addFunction("exit", create3rdFunc("exit", langX_Application_exit));

    space->putClass(info);

    return 0;
  }
}


