//
// Created by Aincvy(aincvy@gmail.com) on 2020/12/18.
//

#include <langXSimple.h>

#include "RegPythonModule.h"
#include "PythonModule.h"

#include <datetime.h>

namespace langX{


    Object * langX_PyDateTime_init(X3rdFunction *func, const X3rdArgs &args){
        auto clz = func->getClassInfo();

        // 判断是否已经初始化过了
        auto object = clz->getMember("__init");
        if (object->isTrue()) {
            // 已经初始化过了
            return Allocator::allocateNumber(1);
        }

        PyDateTime_IMPORT;
        ((Number*)object)->setValue(1);

        return Allocator::allocateNumber(1);
    }

    /**
     * 从一个 langX.core.DateTime 对象转换成一个 python 得 dateTime 对象
     * @param func
     * @param args
     * @return
     */
    Object * langX_PyDateTime_fromDateTime(X3rdFunction *func, const X3rdArgs &args){
        CHECK_ARGS_SIZE(args, 1);

        auto dateArg = args.args[0];
        if (!dateArg || dateArg->getType() != ObjectType::OBJECT) {
            return nullptr;
        }

        auto dateObj = (langXObjectRef*) dateArg;
        auto year = getIntFromObject(dateObj, "year");
        auto month = getIntFromObject(dateObj, "month");
        auto date = getIntFromObject(dateObj, "date");
        auto hour = getIntFromObject(dateObj, "hour");
        auto minute = getIntFromObject(dateObj, "minute");
        auto second = getIntFromObject(dateObj, "second");
        auto ms = getIntFromObject(dateObj, "millisecond");

        auto str = dateObj->getRefObject()->callFunction("toString", "get string from python", 0);
        moduleLogger->debug("date: %s", ((String*)str)->getValue());

        auto object = PyDateTime_FromDateAndTime(year, month, date, hour, minute, second, ms * 1000);
        auto myObj = createLangXObjectPyObj(object, PyObjectType::Unknown);

        return myObj->addRef();
    }

    /**
     * 使用 日期初始化一个 datetime 对象
     * @param func
     * @param args
     * @return
     */
    Object * langX_PyDateTime_newDate(X3rdFunction *func, const X3rdArgs &args){
        CHECK_ARGS_SIZE(args, 3);

        // 读取参数
        int year,month,date;
        year = month = date = 1;
        readNumber(args, 0, &year);
        readNumber(args, 1, &month);
        readNumber(args, 2, &date);

        auto object = PyDate_FromDate(year, month, date);
        auto myObj = createLangXObjectPyObj(object, PyObjectType::Unknown);

        return myObj->addRef();
    }

    /**
     * 使用日期和时间初始化一个datetime 对象
     * @param func
     * @param args
     * @return
     */
    Object * langX_PyDateTime_newDateTime(X3rdFunction *func, const X3rdArgs &args){
        CHECK_ARGS_SIZE(args, 6);

        // 读取参数
        int year,month,date, hour, minute, second,ms;
        year = month = date = 1;
        hour = minute = second = ms = 0;
        readNumber(args, 0, &year);
        readNumber(args, 1, &month);
        readNumber(args, 2, &date);
        readNumber(args, 3, &hour);
        readNumber(args, 4, &minute);
        readNumber(args, 5, &second);

        if (args.index >= 7) {
            readNumber(args, 6, &ms);
        }

        auto dateObject = PyDateTime_FromDateAndTime(year, month, date, hour, minute, second, ms * 1000);
        auto myObj = createLangXObjectPyObj(dateObject, PyObjectType::Unknown);

        return myObj->addRef();
    }

    /**
     * 将一个 python 得 datetime对象 转换成一个  langX.core.DateTime 得对象
     * @param func
     * @param args
     * @return
     */
    Object * langX_PyDateTime_toDateTime(X3rdFunction *func, const X3rdArgs &args){
        CHECK_ARGS_SIZE(args, 1);

        auto dateTimeArg = args.args[0];
        if (!dateTimeArg || dateTimeArg->getType() != OBJECT){
            return nullptr;
        }

        auto ref = (langXObjectRef*) dateTimeArg;
        if (!ref->getClassInfo()->isInstanceOf("PyObject")) {
            return nullptr;
        }

        auto tmp = (XClassPyObject*) ref->getRefObject()->get3rdObj();
        if (tmp == nullptr || tmp->pyObj == nullptr) {
            return nullptr;
        }

        //
        int year,month,date, hour, minute, second,ms;
        year = month = date = 1;
        hour = minute = second = ms = 0;

        auto pyObj = tmp->pyObj;
        if (PyDate_Check(pyObj)) {
            // 是一个date
            year = PyDateTime_GET_YEAR(pyObj);
            month = PyDateTime_GET_MONTH(pyObj);
            date = PyDateTime_GET_DAY(pyObj);

            if (PyDateTime_Check(pyObj)) {
                // 是一个 dateTime
                hour = PyDateTime_DATE_GET_HOUR(pyObj);
                minute = PyDateTime_DATE_GET_MINUTE(pyObj);
                second = PyDateTime_DATE_GET_SECOND(pyObj);
                ms = PyDateTime_DATE_GET_MICROSECOND(pyObj) / 1000;    // 微妙转换成毫秒
            }

        } else if (PyTime_Check(pyObj)){
            // 是一个 time
            hour = PyDateTime_TIME_GET_HOUR(pyObj);
            minute = PyDateTime_TIME_GET_MINUTE(pyObj);
            second = PyDateTime_TIME_GET_SECOND(pyObj);
            ms = PyDateTime_TIME_GET_MICROSECOND(pyObj) / 1000;    // 微妙转换成毫秒
        }

        // new 一个 DateTime 对象， 然后返回出去
        auto dateTimeClass = func->getLangX()->getClassByFullName("langX.core.DateTime");
        auto object = Allocator::newObject(dateTimeClass, false, true);

        // 依次赋值
        Number tmpNumber(year);
        object->setMember("year", &tmpNumber);
        tmpNumber.setValue(month);
        object->setMember("month", &tmpNumber);
        tmpNumber.setValue(date);
        object->setMember("date", &tmpNumber);
        tmpNumber.setValue(hour);
        object->setMember("hour", &tmpNumber);
        tmpNumber.setValue(minute);
        object->setMember("minute", &tmpNumber);
        tmpNumber.setValue(second);
        object->setMember("second", &tmpNumber);
        tmpNumber.setValue(ms);
        object->setMember("millisecond", &tmpNumber);

        // 调用 DateTime 得同步方法
        object->callFunction("syncFromMember", "sync member to 3rdObject from python datetime", 0);

        return object->addRef();
    }

    void regPyDateTime(langXState *state, XNameSpace *space){
        // 注入 python 得 DateTime 模块得帮助类
        auto info = new ClassInfo("PyDateTime");
        info->addMember("__init", shortcutNumberZero);
        info->addFunction(create3rdFunc("init", langX_PyDateTime_init));
        info->addFunction(create3rdFunc("fromDateTime", langX_PyDateTime_fromDateTime));
        info->addFunction(create3rdFunc("toDateTime", langX_PyDateTime_toDateTime));
        info->addFunction(create3rdFunc("newDate", langX_PyDateTime_newDate));
        info->addFunction(create3rdFunc("newDateTime", langX_PyDateTime_newDateTime));

        space->putClass(info);

    }

}