//
// Created by Aincvy(aincvy@gmail.com) on 2020/12/17.
//

#include "CoreModule.h"
#include "RegDefaultClasses.h"

#include "langX/langXSimple.h"

langX::ClassInfo *timeSpanClass;

#define MEMBER_TOTAL_MILLISECOND "totalMillisecond"

namespace langX{


    langXObject *newTimeSpan(long ms){
        auto obj = Allocator::newObject(timeSpanClass);

        Number number((double )ms);
        obj->setMember(MEMBER_TOTAL_MILLISECOND, &number);

        return obj;
    }

    /**
     * 转换成 秒数表示得时间
     * @param func
     * @param args
     * @return  一个浮点数
     */
    Object * langX_TimeSpan_getSeconds(X3rdFunction *func, const X3rdArgs &args){
        CHECK_OBJECT_NOT_NULL(args, "langX_TimeSpan_getSeconds");

        auto object =args.object;
        auto msNumber = (Number*)object->getMember(MEMBER_TOTAL_MILLISECOND);

        auto ms = msNumber->getLongValue();

        // 毫秒， 转换成秒
        int secondPart = (int)(ms / 1000);
        int milliSecondPart = (int)(ms - secondPart * 1000);
        float result = ((float )milliSecondPart / 1000.0f) + (float )secondPart;

        return Allocator::allocateNumber(result);
    }


    void regTimeSpan(langXState *state, XNameSpace *space){
        auto info = new ClassInfo("TimeSpan");
        info->addMember(MEMBER_TOTAL_MILLISECOND, shortcutNumberZero);
        info->addFunction(create3rdFunc("getSeconds",langX_TimeSpan_getSeconds ));

        timeSpanClass = info;
        space->putClass(info);
    }

}