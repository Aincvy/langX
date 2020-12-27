#include <math.h>

#include "RegDefaultClasses.h"

#include "langX/langXSimple.h"

namespace langX {


	Object * langX_Math_Abs(X3rdFunction *func, const X3rdArgs &args) {

		Object *a = args.args[0];
		if (a != nullptr && a->getType() == NUMBER)
		{
			return Allocator::allocateNumber(abs(((Number*)a)->getIntValue()));
		}

		return nullptr;
	}

	Object * langX_Math_Pow(X3rdFunction *func, const X3rdArgs &args) {

		Object *a = args.args[0];
		Object *b = args.args[1];
		if (a != nullptr && a->getType() == NUMBER && b && b->getType() == NUMBER)
		{
			double i = ((Number*)a)->getDoubleValue();
			double j = ((Number*)b)->getDoubleValue();


			return Allocator::allocateNumber(pow(i,j));
		}
		
		return nullptr;
	}

	Object * langX_Math_Sqrt(X3rdFunction *func, const X3rdArgs &args) {

		Object *a = args.args[0];
		if (a != nullptr && a->getType() == NUMBER)
		{
			double i = ((Number*)a)->getDoubleValue();

			return Allocator::allocateNumber(sqrt(i));
		}

		return nullptr;
	}

	Object * langX_Math_Max(X3rdFunction *func, const X3rdArgs &args) {

		Object *a = args.args[0];
		Object *b = args.args[1];
		if (a != nullptr && a->getType() == NUMBER && b && b->getType() == NUMBER)
		{
			double i = ((Number*)a)->getDoubleValue();
			double j = ((Number*)b)->getDoubleValue();
			double k = i;
			if (j > i)
			{
				k = j;
			}
			
			return Allocator::allocateNumber(k);
		}

		return nullptr;
	}

	Object * langX_Math_Min(X3rdFunction *func, const X3rdArgs &args) {

		Object *a = args.args[0];
		Object *b = args.args[1];
		if (a != nullptr && a->getType() == NUMBER && b && b->getType() == NUMBER)
		{
			double i = ((Number*)a)->getDoubleValue();
			double j = ((Number*)b)->getDoubleValue();
			double k = i;
			if (j < i)
			{
				k = j;
			}

			return Allocator::allocateNumber(k);
		}

		

		return nullptr;
	}

	Object * langX_Math_Log(X3rdFunction *func, const X3rdArgs &args) {

		Object *a = args.args[0];
		if (a != nullptr && a->getType() == NUMBER)
		{
			double i = ((Number*)a)->getDoubleValue();

			return Allocator::allocateNumber(log(i));
		}

		return nullptr;
	}

	Object * langX_Math_Sin(X3rdFunction *func, const X3rdArgs &args) {

		Object *a = args.args[0];
		if (a != nullptr && a->getType() == NUMBER)
		{
			double i = ((Number*)a)->getDoubleValue();

			return Allocator::allocateNumber(sin(i));
		}

		return nullptr;
	}

	Object * langX_Math_Cos(X3rdFunction *func, const X3rdArgs &args) {

		Object *a = args.args[0];
		if (a != nullptr && a->getType() == NUMBER)
		{
			double i = ((Number*)a)->getDoubleValue();

			return Allocator::allocateNumber(cos(i));
		}

		return nullptr;
	}

	Object * langX_Math_Tan(X3rdFunction *func, const X3rdArgs &args) {

		Object *a = args.args[0];
		if (a != nullptr && a->getType() == NUMBER)
		{
			double i = ((Number*)a)->getDoubleValue();

			return Allocator::allocateNumber(tan(i));
		}

		return nullptr;
	}

	Object * langX_Math_Asin(X3rdFunction *func, const X3rdArgs &args) {

		Object *a = args.args[0];
		if (a != nullptr && a->getType() == NUMBER)
		{
			double i = ((Number*)a)->getDoubleValue();

			return Allocator::allocateNumber(asin(i));
		}

		return nullptr;
	}

	Object * langX_Math_Acos(X3rdFunction *func, const X3rdArgs &args) {

		Object *a = args.args[0];
		if (a != nullptr && a->getType() == NUMBER)
		{
			double i = ((Number*)a)->getDoubleValue();

			return Allocator::allocateNumber(acos(i));
		}

		return nullptr;
	}

	Object * langX_Math_Atan(X3rdFunction *func, const X3rdArgs &args) {

		Object *a = args.args[0];
		if (a != nullptr && a->getType() == NUMBER)
		{
			double i = ((Number*)a)->getDoubleValue();

			return Allocator::allocateNumber(atan(i));
		}

		return nullptr;
	}


	int regMath(langXState *state, XNameSpace* space) {

		ClassInfo *math = new ClassInfo("Math");
		math->addMember("PI", Allocator::allocateNumber(M_PI));
		math->addFunction("abs", create3rdFunc("abs", langX_Math_Abs));
		math->addFunction("pow", create3rdFunc("pow", langX_Math_Pow));
		math->addFunction("sqrt", create3rdFunc("sqrt", langX_Math_Sqrt));
		math->addFunction("max", create3rdFunc("max", langX_Math_Max));
		math->addFunction("min", create3rdFunc("min", langX_Math_Min));
		math->addFunction("log", create3rdFunc("log", langX_Math_Log));
		math->addFunction("sin", create3rdFunc("sin", langX_Math_Sin));
		math->addFunction("cos", create3rdFunc("cos", langX_Math_Cos));
		math->addFunction("tan", create3rdFunc("tan", langX_Math_Tan));
		math->addFunction("asin", create3rdFunc("asin", langX_Math_Asin));
		math->addFunction("acos", create3rdFunc("acos", langX_Math_Acos));
		math->addFunction("atan", create3rdFunc("atan", langX_Math_Atan));

		space->putClass(math);
		return 0;
	}

}