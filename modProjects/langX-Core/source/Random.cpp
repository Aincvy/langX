#include <random>

#include "../include/RegCoreModule.h"

#include "../../../include/ClassInfo.h"
#include "../../../include/NodeCreator.h"
#include "../../../include/Object.h"
#include "../../../include/langXObject.h"
#include "../../../include/Allocator.h"
#include "../../../include/Number.h"
#include "../../../include/Utils.h"

namespace langX {


	Object * langX_Random_nextDouble(X3rdFunction *func, const X3rdArgs &args) {
		if (args.object == nullptr)
		{
			printf("langX_Random_nextDouble error! NO OBJ!\n");
			return nullptr;
		}

		std::mt19937 *gen = (std::mt19937 *)args.object->get3rdObj();
		std::random_device rd;
		
		double abc = std::uniform_real_distribution<double>(0.0,1.0)((*gen));

		return Allocator::allocateNumber(abc);
	}



	Object * langX_Random_nextInt(X3rdFunction *func, const X3rdArgs &args) {
		if (args.object == nullptr)
		{
			printf("langX_Random_nextInt error! NO OBJ!\n");
			return nullptr;
		}

		std::mt19937 *gen = (std::mt19937 *)args.object->get3rdObj();
		std::random_device rd;
		
		int abc = 0;
		Object *a = args.args[0];
		if (a && a->getType() == NUMBER)
		{
			int max = ((Number*)a)->getIntValue();

			abc = std::uniform_int_distribution<int>(0,max)((*gen));
		}
		else {
			abc = std::uniform_int_distribution<int>(0 )((*gen));
		}

		return Allocator::allocateNumber(abc);
	}



	Object * langX_Random_Random_Dtor(X3rdFunction *func, const X3rdArgs &args) {
		if (args.object == nullptr)
		{
			printf("langX_Random_Random_Dtor error! NO OBJ!\n");
			return nullptr;
		}

		std::mt19937 *gen = (std::mt19937 *)args.object->get3rdObj();
		delete gen;
		args.object->set3rdObj(nullptr);

		return nullptr;
	}



	Object * langX_Random_Random(X3rdFunction *func, const X3rdArgs &args) {
		if (args.object == nullptr)
		{
			printf("langX_Random_Random error! NO OBJ!\n");
			return nullptr;
		}

		std::mt19937 *gen = new std::mt19937();
		args.object->set3rdObj(gen);

		Object *a = args.args[0];
		if ( a && a->getType() == NUMBER)
		{
			int val = ((Number*)a)->getIntValue();
			gen->seed(val);
		}
		else {
			gen->seed(getTime());
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


