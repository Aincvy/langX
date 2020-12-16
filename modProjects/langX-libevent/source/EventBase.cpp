//
// Created by Aincvy(aincvy@gmail.com) on 2020/12/16.
//

#include "libeventModule.h"

#include <ClassInfo.h>
#include <XNameSpace.h>
#include <LogManager.h>
#include <langXObject.h>
#include <TypeHelper.h>

#include <event2/buffer.h>
#include <event2/event.h>



namespace langX{


    /**
     * 循环当前得事件
     * @param func
     * @param args
     * @return
     */
    Object * langX_EventBase_dispatch(X3rdFunction *func, const X3rdArgs &args) {

        auto ptr = EVENT_BASE_PTR(args);

        event_base_dispatch(ptr);

        return nullptr;
    }

    /**
     * 析构方法
     * @param func
     * @param args
     * @return
     */
    Object * langX_EventBase_Dtor(X3rdFunction *func, const X3rdArgs &args){
        CHECK_OBJECT_NOT_NULL(args, "langX_EventBase_Dtor");

        event_base_free(EVENT_BASE_PTR(args));

        RESET_3RD_OBJECT(args);

        return nullptr;
    }

    /**
     * event base 得构造方法
     * @param func
     * @param args
     * @return
     */
    Object * langX_EventBase_EventBase(X3rdFunction *func, const X3rdArgs &args) {
        CHECK_OBJECT_NOT_NULL(args, "langX_EventBase_EventBase");

        // 在构造方法里面就初始化一个 event base
        auto ptr = event_base_new();
        args.object->set3rdObj(ptr);

        return nullptr;
    }



    void regEventBase(langXState *state, XNameSpace *space){

        auto info = new ClassInfo("EventBase");
        info->addFunction(create3rdFunc("EventBase", langX_EventBase_EventBase));
        info->addFunction(create3rdFunc("~EventBase", langX_EventBase_Dtor));
        info->addFunction(create3rdFunc("dispatch", langX_EventBase_dispatch));

        space->putClass(info);
    }

}