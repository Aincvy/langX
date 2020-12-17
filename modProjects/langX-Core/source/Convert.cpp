#include <iostream>

#include "RegDefaultClasses.h"

#include "langXSimple.h"

namespace langX {


	Object * langX_Convert_toStr(X3rdFunction *func, const X3rdArgs &args) {
		
		Object * a = args.args[0];
		if (a )
		{
			if (a->getType() == ObjectType::NUMBER)
			{
				Number *num = (Number*)a;
				if (num->isInteger())
				{
					return Allocator::allocateString(std::to_string(num->getIntValue()).c_str() );
				}
				return Allocator::allocateString(std::to_string(num->getDoubleValue()).c_str());
			}
			else if (a->getType() == ObjectType::OBJECT)
			{
				langXObjectRef *ref = (langXObjectRef*)a;
				Function *func = ref->getFunction("toString");
				if (func != nullptr)
				{
					return func->call();
				}
			}
		}

		return Allocator::allocate(NULLOBJECT);
	}



	Object * langX_Convert_toNumber(X3rdFunction *func, const X3rdArgs &args) {
		
		Object * a = args.args[0];
		if (a )
		{
			if (a->getType() == ObjectType::STRING)
			{
				const char * value = ((String*)a)->getValue();

				try
				{
					double a = std::stod(value, nullptr);
					return Allocator::allocateNumber(a);
				}
				catch (const std::invalid_argument& )
				{
					// do noting now ..
				}
			}
			else if (a->getType() == ObjectType::OBJECT)
			{
				langXObjectRef *ref = (langXObjectRef*)a;
				Function *func = ref->getFunction("operatorNumber");
				if (func != nullptr)
				{
					return func->call();
				}
			}
		}

		return Allocator::allocate(NULLOBJECT);
	}



	int regConvert(langXState *state, XNameSpace* space) {

		ClassInfo *info = new ClassInfo("Convert");
		info->addFunction("toStr", create3rdFunc("toStr", langX_Convert_toStr));
		info->addFunction("toNumber", create3rdFunc("toNumber", langX_Convert_toNumber));

		space->putClass(info);

		return 0;
	}
}


