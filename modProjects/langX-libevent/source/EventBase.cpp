//
// Created by Aincvy(aincvy@gmail.com) on 2020/12/16.
//

#include "libeventModule.h"
#include "ReglibeventModule.h"

#include <langXSimple.h>

#include <event2/buffer.h>
#include <event2/event.h>



namespace langX{


    Object * langX_EventBase_newTimerEvent(X3rdFunction *func, const X3rdArgs &args);

    // TimerEvent 类得部分实现内容
    extern Object * langX_TimerEvent_setTimeout(X3rdFunction *func, const X3rdArgs &args);
    extern Object * langX_TimerEvent_setInterval(X3rdFunction *func, const X3rdArgs &args);


    /**
     *
     * @param func
     * @param args
     * @param type  具体得类型，  1 setTimeout(),  2 setInterval()
     * @return
     */
    static Object * realAddTimerEvent(X3rdFunction *func, const X3rdArgs &args, int type){
        // 先调用自己得 newTimerEvent()  获取一个新的 TimerEvent 对象
        // 之后调用那个对象得 setTimeout() 方法

        X3rdArgs tmpArgs;
        tmpArgs.object = args.object;
        auto obj = langX_EventBase_newTimerEvent(func, tmpArgs);
        if (!obj) {
            return nullptr;
        }

        // 传递参数给 setTimeout 方法
        // 这里直接强行调用把， 不走langX内部得方法了。。

        // 复制参数
        copyX3rdArgs(args, tmpArgs);
        // 修正对象引用
        tmpArgs.object = ((langXObjectRef*) obj)->getRefObject();

        return type == 1
               ? langX_TimerEvent_setTimeout(nullptr, tmpArgs)
               : langX_TimerEvent_setInterval(nullptr, tmpArgs);
    }


    /**
     *
     * @param func
     * @param args
     * @return
     */
    Object * langX_EventBase_setInterval(X3rdFunction *func, const X3rdArgs &args){

        return realAddTimerEvent(func, args, 2);
    }

    /**
     *
     * @param func
     * @param args
     * @return
     */
    Object * langX_EventBase_setTimeout(X3rdFunction *func, const X3rdArgs &args){

        return realAddTimerEvent(func, args, 1);
    }

    /**
     * 新建一个 timer event
     * @param func
     * @param args
     * @return
     */
    Object * langX_EventBase_newTimerEvent(X3rdFunction *func, const X3rdArgs &args){
        CHECK_OBJECT_NOT_NULL(args, "langX_EventBase_newTimerEvent");
        auto ptr = EVENT_BASE_PTR(args);

        auto object = newTimerObject(ptr);
        if (object) {
            langXObjectRef ref(args.object);
            object->setMember("eventBase", &ref);
            return object->addRef();
        }

        return nullptr;
    }


    /**
     * 循环当前得事件
     * @param func
     * @param args
     * @return
     */
    Object * langX_EventBase_dispatch(X3rdFunction *func, const X3rdArgs &args) {
        CHECK_OBJECT_NOT_NULL(args, "langX_EventBase_dispatch");
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
        info->addFunction(create3rdFunc("newTimerEvent", langX_EventBase_newTimerEvent));
        info->addFunction(create3rdFunc("setTimeout", langX_EventBase_setTimeout));
        info->addFunction(create3rdFunc("setInterval", langX_EventBase_setInterval));

        space->putClass(info);
    }

}