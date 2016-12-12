#include "../include/RegCoreModule.h"

#include "../../../include/ClassInfo.h"
#include "../../../include/YLlangX.h"
#include "../../../include/Object.h"
#include "../../../include/langXObject.h"
#include "../../../include/langXObjectRef.h"
#include "../../../include/Allocator.h"
#include "../../../include/Number.h"

namespace langX {


	Object * langX_ByteArray_length(X3rdFunction *func, const X3rdArgs &args) {
		if (args.object == nullptr)
		{
			printf("langX_ByteArray_length error! NO OBJ!\n");
			return nullptr;
		}

		return nullptr;
	}



	Object * langX_ByteArray_operator_square_brackets(X3rdFunction *func, const X3rdArgs &args) {
		if (args.object == nullptr)
		{
			printf("langX_ByteArray_operator_square_brackets error! NO OBJ!\n");
			return nullptr;
		}

		return nullptr;
	}



	Object * langX_ByteArray_ByteArray_Dtor(X3rdFunction *func, const X3rdArgs &args) {
		if (args.object == nullptr)
		{
			printf("langX_ByteArray_ByteArray_Dtor error! NO OBJ!\n");
			return nullptr;
		}

		return nullptr;
	}



	Object * langX_ByteArray_ByteArray(X3rdFunction *func, const X3rdArgs &args) {
		if (args.object == nullptr)
		{
			printf("langX_ByteArray_ByteArray error! NO OBJ!\n");
			return nullptr;
		}

		return nullptr;
	}



	int regByteArray(langXState *state, XNameSpace* space) {

		ClassInfo *info = new ClassInfo("ByteArray");
		info->addFunction("length", create3rdFunc("length", langX_ByteArray_length));
		info->addFunction("operator[]", create3rdFunc("operator[]", langX_ByteArray_operator_square_brackets));
		info->addFunction("~ByteArray", create3rdFunc("~ByteArray", langX_ByteArray_ByteArray_Dtor));
		info->addFunction("ByteArray", create3rdFunc("ByteArray", langX_ByteArray_ByteArray));

		space->putClass(info);

		return 0;
	}
}


