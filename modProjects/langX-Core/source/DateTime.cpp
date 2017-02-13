#include "../include/RegDefaultClasses.h"

#include "../../../include/ClassInfo.h"
#include "../../../include/YLlangX.h"
#include "../../../include/Object.h"
#include "../../../include/langXObject.h"
#include "../../../include/langXObjectRef.h"
#include "../../../include/Allocator.h"
#include "../../../include/Number.h"

namespace langX {

	//  DateTime 的 内部用结构体
	struct DateTimeCoreX
	{
		int year;
		int month;
		int date;
		int hour;
		int minute;
		int second;
		int millisecond;
	};


	Object * langX_DateTime_update(X3rdFunction *func, const X3rdArgs &args) {
		if (args.object == nullptr)
		{
			printf("langX_DateTime_update error! NO OBJ!\n");
			return nullptr;
		}

		return nullptr;
	}



	Object * langX_DateTime_DateTime_Dtor(X3rdFunction *func, const X3rdArgs &args) {
		if (args.object == nullptr)
		{
			printf("langX_DateTime_DateTime_Dtor error! NO OBJ!\n");
			return nullptr;
		}

		return nullptr;
	}



	Object * langX_DateTime_DateTime(X3rdFunction *func, const X3rdArgs &args) {
		if (args.object == nullptr)
		{
			printf("langX_DateTime_DateTime error! NO OBJ!\n");
			return nullptr;
		}

		return nullptr;
	}



	int regDateTime(langXState *state, XNameSpace* space) {

		ClassInfo *info = new ClassInfo("DateTime");
		info->addMember("millisecond", getState()->getAllocator().allocateNumber(0));
		info->addMember("second", getState()->getAllocator().allocateNumber(0));
		info->addMember("minute", getState()->getAllocator().allocateNumber(0));
		info->addMember("hour", getState()->getAllocator().allocateNumber(0));
		info->addMember("date", getState()->getAllocator().allocateNumber(0));
		info->addMember("month", getState()->getAllocator().allocateNumber(0));
		info->addMember("year", getState()->getAllocator().allocateNumber(0));
		info->addFunction("update", create3rdFunc("update", langX_DateTime_update));
		info->addFunction("~DateTime", create3rdFunc("~DateTime", langX_DateTime_DateTime_Dtor));
		info->addFunction("DateTime", create3rdFunc("DateTime", langX_DateTime_DateTime));

		space->putClass(info);

		return 0;
	}
}


