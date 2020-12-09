#include <time.h>
#include <sys/time.h>

#include "../include/RegDefaultClasses.h"

#include "../../../include/ClassInfo.h"
#include "../../../include/NodeCreator.h"
#include "../../../include/Object.h"
#include "../../../include/langXObject.h"
#include "../../../include/langXObjectRef.h"
#include "../../../include/Allocator.h"
#include "../../../include/Number.h"
#include "../../../include/LogManager.h"
#include "../../../include/TypeHelper.h"



#define TimeUnitMilliSecond 1
#define TimeUnitSecond 2
#define TimeUnitMinute 3
#define TimeUnitHour 4
#define TimeUnitDay 5
#define TimeUnitWeek 6
#define TimeUnitMonth 7
#define TimeUnitYear 8


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

		// unix 时间戳  毫秒数
		long timestamp;


		/**
		 * 设置当前对象的属性
		 * @param year
		 * @param month
		 * @param date
		 * @param hour
		 * @param minute
		 * @param second
		 */
		void setProperties(int year, int month, int date, int hour, int minute, int second, int ms){
            this->year = year;
            this->month = month;
            this->date = date;
            this->hour = hour;
            this->minute = minute;
            this->second = second;
            this->millisecond = ms;
		}

		/**
		 * 从当前的属性中 更新时间戳的值
		 */
		void updateTimestamp(){
            struct tm timeInfo;
            timeInfo.tm_year = year - 1900;
            timeInfo.tm_mon = month - 1;
            timeInfo.tm_mday = date;
            timeInfo.tm_hour = hour;
            timeInfo.tm_min = minute;
            timeInfo.tm_sec = second;

            auto tmp = mktime(&timeInfo);
            timestamp = tmp * 1000 + millisecond;
		}

	};


	/**
	 * 更新 dateTime 的值。
	 * @param dateTime        时间的结果存放的地方
	 * @param unixTimestamp   以秒为单位的 unix 时间戳
	 */
	void updateTime(DateTimeCoreX *dateTime, time_t unixTimestamp){

        struct tm timeBuf;
        auto time = &timeBuf;
        localtime_r(&unixTimestamp, time);

        dateTime->year = time->tm_year + 1900;
        dateTime->month = time->tm_mon + 1;  // tm_mon 为[0-11]
        dateTime->date = time->tm_mday;
        dateTime->hour = time->tm_hour;
        dateTime->minute = time->tm_min;
        dateTime->second = time->tm_sec;

    }

    /**
     * 更新 dateTime 到现在的时间
     * @param dateTime
     */
	void updateTime(DateTimeCoreX *dateTime) {

        struct timeval tv;
		gettimeofday(&tv, nullptr);
		auto ms = tv.tv_usec / 1000;

		updateTime(dateTime, tv.tv_sec);

		dateTime->millisecond = ms;
		dateTime->timestamp = tv.tv_sec * 1000 + ms;
	}

	/**
	 * 转换 time 的属性到  object 内部
	 * @param time
	 * @param object
	 */
    void setDateTimeObject(DateTimeCoreX *time, langXObject *object){
        object->setMember("millisecond", Allocator::allocateNumber(time->millisecond));
        object->setMember("second", Allocator::allocateNumber(time->second));
        object->setMember("minute", Allocator::allocateNumber(time->minute));
        object->setMember("hour", Allocator::allocateNumber(time->hour));
        object->setMember("date", Allocator::allocateNumber(time->date));
        object->setMember("month", Allocator::allocateNumber(time->month));
        object->setMember("year", Allocator::allocateNumber(time->year));
	}

	/**
	 * 从langX 传来的时间戳 转换
	 * @param dateTime
	 * @param timestamp
	 * @param msPart
	 */
    void updateFromTimestamp(DateTimeCoreX *dateTime, Number *timestamp, bool msPart){
        time_t theTime = timestamp->getLongValue();
        auto ms = 0;

        // 毫秒部分
        if (msPart) {
            ms = theTime - theTime / 1000 * 1000;
            theTime = theTime / 1000;
        }

        updateTime(dateTime, theTime);

        dateTime->millisecond = ms;
        dateTime->timestamp = theTime * 1000 + ms;
    }

    /**
     * 建立一个 DateTime 类的对象
     * @param time
     * @param state
     * @return
     */
    langXObject *mkDateTimeObject(DateTimeCoreX *time, langXState *state){
        // 生成一个对象
        auto clz = state->getClassByFullName("langX.core.DateTime");
        auto obj = Allocator::newObject(clz, false, false);
        obj->set3rdObj(time);

        return obj;
    }

    /**
     * 从 unix 时间戳上 转换成一个 DateTime对象
     * @param timeArg
     * @param msPart
     * @return
     */
    Object *fromUnixTimeStamp(Number *timeArg, bool msPart, langXState *state) {
        auto time = new DateTimeCoreX();
        updateFromTimestamp(time, timeArg, msPart);

        auto obj = mkDateTimeObject(time, state);
        setDateTimeObject(time, obj);

        return obj->addRef();
    }

    /**
     * 设置一个 dateTime的属性
     * @param dateTime
     * @param year
     * @param month
     * @param date
     * @param hour
     * @param minute
     * @param second
     */
    void setProperties(DateTimeCoreX *dateTime, int year, int month, int date, int hour, int minute, int second){
        dateTime->year = year;
        dateTime->month = month;
        dateTime->date = date;
        dateTime->hour = hour;
        dateTime->minute = minute;
        dateTime->second = second;

        // 更新时间戳

    }

	Object * langX_DateTime_update(X3rdFunction *func, const X3rdArgs &args) {
		if (args.object == nullptr)
		{
            logger->error("langX_DateTime_update error! NO OBJ!");
			return nullptr;
		}

		DateTimeCoreX* time = (DateTimeCoreX*)args.object->get3rdObj();
		updateTime(time);

        setDateTimeObject(time, args.object);

		return nullptr;
	}

	Object * langX_DateTime_DateTime_Dtor(X3rdFunction *func, const X3rdArgs &args) {
		if (args.object == nullptr)
		{
            logger->error("langX_DateTime_DateTime_Dtor error! NO OBJ!");
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
			logger->error("langX_DateTime_DateTime error! NO OBJ!");
			return nullptr;
		}

		DateTimeCoreX* time = new DateTimeCoreX();
		args.object->set3rdObj(time);
		langX_DateTime_update(func, args);

		return nullptr;
	}

	/**
	 * plus( value, unit)    增加 value 个 unit单位的时间
	 * @param func
	 * @param args
	 * @return
	 */
    Object * langX_DateTime_plus(X3rdFunction *func, const X3rdArgs &args){
        if (args.object == nullptr) {
            return nullptr;
        }

        auto object = args.object;
        auto dateTime = (DateTimeCoreX*) object->get3rdObj();

        int value, unit;

        readNumber(args, 0, &value);
        readNumber(args, 1, &unit);

        switch (unit) {
            case TimeUnitYear:
                dateTime->year += value;
                break;
            case TimeUnitMonth:
                dateTime->month += value;
                while (dateTime->month > 12) {
                    dateTime->month -= 12;
                    dateTime->year++;
                }
                break;
            case TimeUnitWeek:
                dateTime->timestamp += value * 7 * 24 * 60 * 60 * 1000  ;
                break;
            case TimeUnitDay:
                dateTime->timestamp += value * 24 * 60 * 60 * 1000;
                break;
            case TimeUnitHour:
                dateTime->timestamp += value * 60 * 60 * 1000;
                break;
            case TimeUnitMinute:
                dateTime->timestamp += value * 60 * 1000;
                break;
            case TimeUnitSecond:
                dateTime->timestamp += value * 1000 ;
                break;
            case TimeUnitMilliSecond:
            {
                dateTime->timestamp += value;
                break;
            }
            default:
                logger->error("[DateTime] TimeUnit Error: %d", unit);
                break;
        }

        if (unit != TimeUnitYear && unit != TimeUnitMonth) {
            auto tmp = dateTime->timestamp / 1000;
            updateTime(dateTime, tmp);

            dateTime->millisecond = dateTime->timestamp - tmp * 1000;
        } else{
            // 需要更新下时间戳
            dateTime->updateTimestamp();
        }

        setDateTimeObject(dateTime, object);
        return object->addRef();
    }

	// 下面的静态方法

    /**
     * 从 unix时间戳转换   参数是以秒为单位的
     * @param func
     * @param args
     * @return
     */
    Object * langX_DateTime_fromUnixTimeStamp(X3rdFunction *func, const X3rdArgs &args){

        auto a = args.args[0];
        if (!a || a->getType() != NUMBER) {
            return nullptr;       // 参数没传， 或者非数字， 就返回null
        }

        return fromUnixTimeStamp((Number*)a, false, func->getLangX());
    }

    /**
     * 从 unix时间戳转换   参数是以毫秒为单位的
     * @param func
     * @param args
     * @return
     */
    Object * langX_DateTime_fromUnixTimeStampMS(X3rdFunction *func, const X3rdArgs &args){

        auto a = args.args[0];
        if (!a || a->getType() != NUMBER) {
            return nullptr;       // 参数没传， 或者非数字， 就返回null
        }

        return fromUnixTimeStamp((Number*)a, true, func->getLangX());
    }


    /**
     * 从 年月日获取到对象
     * @param func
     * @param args
     * @return
     */
    Object * langX_DateTime_fromDate(X3rdFunction *func, const X3rdArgs &args){
        if (args.index < 3) {
            return nullptr;
        }

        auto year = 1900;
        auto month = 1;
        auto date = 1;
        auto hour = 0;
        auto minute = 0;
        auto second = 0;
        auto ms = 0;

        readNumber(args, 0, &year);
        readNumber(args, 1, &month);
        readNumber(args, 2, &date);
        readNumber(args, 3, &hour);
        readNumber(args, 4, &minute);
        readNumber(args, 5, &second);
        readNumber(args, 6, &ms);

        auto dateTime = new DateTimeCoreX();
        dateTime->setProperties(year, month, date, hour,minute,second,ms);
        dateTime->updateTimestamp();

        return mkDateTimeObject(dateTime, func->getLangX())->addRef();
    }



	int regDateTime(langXState *state, XNameSpace* space) {

        //  DateTime

		ClassInfo *info = new ClassInfo("DateTime");
		info->addMember("millisecond", Allocator::allocateNumber(0));
		info->addMember("second", Allocator::allocateNumber(0));
		info->addMember("minute", Allocator::allocateNumber(0));
		info->addMember("hour", Allocator::allocateNumber(0));
		info->addMember("date", Allocator::allocateNumber(1));
		info->addMember("month", Allocator::allocateNumber(1));
		info->addMember("year", Allocator::allocateNumber(1900));
		info->addFunction("update", create3rdFunc("update", langX_DateTime_update));
		info->addFunction(create3rdFunc("plus", langX_DateTime_plus));
		info->addFunction("~DateTime", create3rdFunc("~DateTime", langX_DateTime_DateTime_Dtor));
		info->addFunction("DateTime", create3rdFunc("DateTime", langX_DateTime_DateTime));
		info->addFunction("fromUnixTimeStamp", create3rdFunc("fromUnixTimeStamp", langX_DateTime_fromUnixTimeStamp));
		info->addFunction(create3rdFunc("fromDate", langX_DateTime_fromUnixTimeStampMS));

		space->putClass(info);

        //  TimeUnit
        ClassInfo *timeUnitClass = new ClassInfo("TimeUnit");
        timeUnitClass->addMember("MilliSecond", Allocator::allocateNumber(TimeUnitMilliSecond));
        timeUnitClass->addMember("Second", Allocator::allocateNumber(TimeUnitSecond));
        timeUnitClass->addMember("Minute", Allocator::allocateNumber(TimeUnitMinute));
        timeUnitClass->addMember("Hour", Allocator::allocateNumber(TimeUnitHour));
        timeUnitClass->addMember("Day", Allocator::allocateNumber(TimeUnitDay));
        timeUnitClass->addMember("Week", Allocator::allocateNumber(TimeUnitWeek));
        timeUnitClass->addMember("Month", Allocator::allocateNumber(TimeUnitMonth));
        timeUnitClass->addMember("Year", Allocator::allocateNumber(TimeUnitYear));
        space->putClass(timeUnitClass);

		return 0;
	}
}


