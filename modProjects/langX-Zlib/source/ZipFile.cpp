
#include "../../../include/ClassInfo.h"
#include "../../../include/YLlangX.h"
#include "../../../include/Object.h"
#include "../../../include/langXObject.h"
#include "../../../include/langXObjectRef.h"
#include "../../../include/Allocator.h"
#include "../../../include/Number.h"

namespace langX {


Object * langX_ZipFile_ZipFile(X3rdFunction *func, const X3rdArgs &args) {
	if (args.object == nullptr)
	{
		printf("langX_ZipFile_ZipFile error! NO OBJ!\n");
		return nullptr;
	}

	return nullptr;
}


Object * langX_ZipFile_ZipFile_Dtor(X3rdFunction *func, const X3rdArgs &args) {
	if (args.object == nullptr)
	{
		printf("langX_ZipFile_ZipFile_Dtor error! NO OBJ!\n");
		return nullptr;
	}

	return nullptr;
}


Object * langX_ZipFile_add(X3rdFunction *func, const X3rdArgs &args) {
	if (args.object == nullptr)
	{
		printf("langX_ZipFile_add error! NO OBJ!\n");
		return nullptr;
	}

	return nullptr;
}


Object * langX_ZipFile_del(X3rdFunction *func, const X3rdArgs &args) {
	if (args.object == nullptr)
	{
		printf("langX_ZipFile_del error! NO OBJ!\n");
		return nullptr;
	}

	return nullptr;
}


Object * langX_ZipFile_uncompress(X3rdFunction *func, const X3rdArgs &args) {
	if (args.object == nullptr)
	{
		printf("langX_ZipFile_uncompress error! NO OBJ!\n");
		return nullptr;
	}

	return nullptr;
}

  
  int regZipFile(langXState *state, XNameSpace* space) {
	
	ClassInfo *info = new ClassInfo("ZipFile");	
info->addFunction("ZipFile", create3rdFunc("ZipFile", langX_ZipFile_ZipFile));
info->addFunction("~ZipFile", create3rdFunc("~ZipFile", langX_ZipFile_ZipFile_Dtor));
info->addFunction("add", create3rdFunc("add", langX_ZipFile_add));
info->addFunction("del", create3rdFunc("del", langX_ZipFile_del));
info->addFunction("uncompress", create3rdFunc("uncompress", langX_ZipFile_uncompress));
	
	space->putClass(info);
	
  	return 0;
  }
}


