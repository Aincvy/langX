#include "../include/RegCoreModule.h"

#include "../../../include/ClassInfo.h"
#include "../../../include/YLlangX.h"
#include "../../../include/Object.h"
#include "../../../include/langXObject.h"
#include "../../../include/langXObjectRef.h"
#include "../../../include/Allocator.h"
#include "../../../include/Number.h"
#include "../../../include/Utils.h"

static const long addend = 0xBL;
static const long mask = (1L << 48) - 1;
static const long multiplier = 0x5FECCE00DL;
static const double DOUBLE_UNIT = 0x1.0p-53;

namespace langX {


	int next(int bits, langXObject *object ) {

		long *i = (long*)object->get3rdObj();

		long oldseed = *i;
		long nextseed = (oldseed * multiplier + addend) & mask;
		*i = nextseed;

		return (int)(nextseed >> (48 - bits));
	}

	Object * langX_Random_nextDouble(X3rdFunction *func, const X3rdArgs &args) {
		if (args.object == nullptr)
		{
			printf("langX_Random_nextDouble error! NO OBJ!\n");
			return nullptr;
		}

		langXObject *obj = args.object;

		double a = (((long)next(26, obj)) << 27 + next(27, obj)) * DOUBLE_UNIT;

		return getState()->getAllocator().allocateNumber(a);
	}



	Object * langX_Random_nextInt(X3rdFunction *func, const X3rdArgs &args) {
		if (args.object == nullptr)
		{
			printf("langX_Random_nextInt error! NO OBJ!\n");
			return nullptr;
		}

		
		int abc = next(32, args.object);

		Object *a = args.args[0];
		if (a && a->getType() == NUMBER)
		{
			int max = ((Number*)a)->getIntValue();

			for (; abc > max; abc %= max);   // 分号在这
			
		}

		return getState()->getAllocator().allocateNumber(abc);
	}



	Object * langX_Random_Random_Dtor(X3rdFunction *func, const X3rdArgs &args) {
		if (args.object == nullptr)
		{
			printf("langX_Random_Random_Dtor error! NO OBJ!\n");
			return nullptr;
		}

		long *i = (long*)args.object->get3rdObj();
		free(i);
		args.object->set3rdObj(nullptr);

		return nullptr;
	}



	Object * langX_Random_Random(X3rdFunction *func, const X3rdArgs &args) {
		if (args.object == nullptr)
		{
			printf("langX_Random_Random error! NO OBJ!\n");
			return nullptr;
		}

		long *i = (long*)calloc(1, sizeof(long));
		args.object->set3rdObj(i);

		Object *a = args.args[0];
		if ( a && a->getType() == NUMBER)
		{
			int val = ((Number*)a)->getIntValue();
			*i = val;
		}
		else {
			*i = getTime();
		}

		return nullptr;
	}


	int regRandom(langXState *state, XNameSpace* space) {

		ClassInfo *info = new ClassInfo("Random");
		info->addFunction("nextDouble", create3rdFunc("nextDouble", langX_Random_nextDouble));
		info->addFunction("nextInt", create3rdFunc("nextInt", langX_Random_nextInt));
		info->addFunction("~Random", create3rdFunc("~Random", langX_Random_Random_Dtor));
		info->addFunction("Random", create3rdFunc("Random", langX_Random_Random));

		space->putClass(info);

		return 0;
	}
}


