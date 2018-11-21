#include "../include/RegZlibModule.h"

#include "../../../include/ClassInfo.h"
#include "../../../include/YLlangX.h"
#include "../../../include/Object.h"
#include "../../../include/langXObject.h"
#include "../../../include/langXObjectRef.h"
#include "../../../include/Allocator.h"
#include "../../../include/Number.h"

namespace langX {


	Object * langX_Zip_compress(X3rdFunction *func, const X3rdArgs &args) {
		if (args.object == nullptr)
		{
			printf("langX_Zip_compress error! NO OBJ!\n");
			return nullptr;
		}

		return nullptr;
	}


	Object * langX_Zip_uncompress(X3rdFunction *func, const X3rdArgs &args) {
		if (args.object == nullptr)
		{
			printf("langX_Zip_uncompress error! NO OBJ!\n");
			return nullptr;
		}

		return nullptr;
	}


	Object * langX_Zip_compressFile(X3rdFunction *func, const X3rdArgs &args) {
		if (args.object == nullptr)
		{
			printf("langX_Zip_compressFile error! NO OBJ!\n");
			return nullptr;
		}

		return nullptr;
	}


	Object * langX_Zip_compressFolder(X3rdFunction *func, const X3rdArgs &args) {
		if (args.object == nullptr)
		{
			printf("langX_Zip_compressFolder error! NO OBJ!\n");
			return nullptr;
		}

		return nullptr;
	}


	Object * langX_Zip_uncompressFile(X3rdFunction *func, const X3rdArgs &args) {
		if (args.object == nullptr)
		{
			printf("langX_Zip_uncompressFile error! NO OBJ!\n");
			return nullptr;
		}

		return nullptr;
	}


	int regZip(langXState *state, XNameSpace* space) {

		ClassInfo *info = new ClassInfo("Zip");
		info->addFunction("compress", create3rdFunc("compress", langX_Zip_compress));
		info->addFunction("uncompress", create3rdFunc("uncompress", langX_Zip_uncompress));
		info->addFunction("compressFile", create3rdFunc("compressFile", langX_Zip_compressFile));
		info->addFunction("compressFolder", create3rdFunc("compressFolder", langX_Zip_compressFolder));
		info->addFunction("uncompressFile", create3rdFunc("uncompressFile", langX_Zip_uncompressFile));

		space->putClass(info);

		return 0;
	}
}


