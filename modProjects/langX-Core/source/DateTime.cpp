#include <time.h>

#include "../include/RegDefaultClasses.h"

#include "../../../include/ClassInfo.h"
#include "../../../include/NodeCreator.h"
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


	void updateTime(DateTimeCoreX *dateTime) {

		time_t now = time(NULL);
		struct tm * time = localtime(&now);
		
		dateTime->year = time->tm_year + 1900;
		dateTime->month = time->tm_mon + 1;  // tm_mon 为[0-11]
		dateTime->date = time->tm_mday;
		dateTime->hour = time->tm_hour;
		dateTime->minute = time->tm_min;
		dateTime->second = time->tm_sec;
		dateTime->millisecond = 0;
	}

	Object * langX_DateTime_update(X3rdFunction *func, const X3rdArgs &args) {
		if (args.object == nullptr)
		{
			printf("langX_DateTime_update error! NO OBJ!\n");
			return nullptr;
		}

		DateTimeCoreX* time = (DateTimeCoreX*)args.object->get3rdObj();
		updateTime(time);

		args.object->setMember("millisecond", Allocator::allocateNumber(time->millisecond));
		args.object->setMember("second", Allocator::allocateNumber(time->second));
		args.object->setMember("minute", Allocator::allocateNumber(time->minute));
		args.object->setMember("hour", Allocator::allocateNumber(time->hour));
		args.object->setMember("date", Allocator::allocateNumber(time->date));
		args.object->setMember("month", Allocator::allocateNumber(time->month));
		args.object->setMember("year", Allocator::allocateNumber(time->year));

		return nullptr;
	}



	Object * langX_DateTime_DateTime_Dtor(X3rdFunction *func, const X3rdArgs &args) {
		if (args.object == nullptr)
		{
			printf("langX_DateTime_DateTime_Dtor error! NO OBJ!\n");
			return nullptr;
		}

		DateTimeCoreX* time = (DateTimeCoreX*)args.object->get3rdObj();
		delete time;
		args.object->set3rdObj(nullptr);

		return nullptr;
	}



	Object * langX_DateTime_DateTime(X3rdFunction *func, const X3rdArgs &args) {
		if (args.object == nullptr)
		{
			printf("langX_DateTime_DateTime error! NO OBJ!\n");
			return nullptr;
		}

		DateTimeCoreX* time = new DateTimeCoreX();
		args.object->set3rdObj(time);
		langX_DateTime_update(func, args);

		return nullptr;
	}



	int regDateTime(langXState *state, XNameSpace* space) {

		ClassInfo *info = new ClassInfo("DateTime");
		info->addMember("millisecond", Allocator::allocateNumber(0));
		info->addMember("second", Allocator::allocateNumber(0));
		info->addMember("minute", Allocator::allocateNumber(0));
		info->addMember("hour", Allocator::allocateNumber(0));
		info->addMember("date", Allocator::allocateNumber(0));
		info->addMember("month", Allocator::allocateNumber(0));
		info->addMember("year", Allocator::allocateNumber(0));
		info->addFunction("update", create3rdFunc("update", langX_DateTime_update));
		info->addFunction("~DateTime", create3rdFunc("~DateTime", langX_DateTime_DateTime_Dtor));
		info->addFunction("DateTime", create3rdFunc("DateTime", langX_DateTime_DateTime));

		space->putClass(info);

		return 0;
	}
}


