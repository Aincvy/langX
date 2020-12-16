//
// Created by Aincvy(aincvy@gmail.com) on 2020/12/16.
//
#include "libeventModule.h"

#include <time.h>

#include <XNameSpace.h>
#include <ClassInfo.h>
#include <LogManager.h>
#include <langXObject.h>
#include <Allocator.h>
#include <Number.h>
#include <Function.h>
#include <langXThread.h>
#include <TypeHelper.h>

#include <event2/event.h>


#define QUICK_CALLOC(type) (type*)calloc(1, sizeof(type))

namespace langX{

    /**
     * cpp 对象
     */
    struct MyTimer{
        struct event_base *eventBase = nullptr;
        struct event *event = nullptr;
        FunctionRef* callback = nullptr;
    };

    /**
     * libevent 触发了这个事件
     * @param fd
     * @param event
     * @param arg
     */
    void setTimeoutCallback(evutil_socket_t fd, short event, void *arg){
        auto object = (langXObject*) arg;
        auto ptr = (MyTimer*) object->get3rdObj();

        auto thread = getCurrentState()->getThreadManager()->getMainThread();
        ptr->callback->call(thread, "timeout callback", 0);

    }

    /**
     * langX 函数， set time out
     * @param func
     * @param args
     * @return
     */
    Object * langX_Timer_setTimeout(X3rdFunction *func, const X3rdArgs &args){
        CHECK_OBJECT_NOT_NULL(args, "langX_Timer_setTimeout");
        CHECK_ARGS_SIZE(args, 2);

        auto timeArg = args.args[0];
        auto callbackArg = args.args[1];

        struct timeval time;
        time.tv_sec = 1;
        time.tv_usec = 0;

        if (timeArg->getType() == NUMBER) {
            // 数字
            auto number = (Number*) timeArg;
            auto value = number->getDoubleValue();
            if (value <= 0) {
                // 间隔小于等于0
                return nullptr;
            }

            time.tv_sec = number->getIntValue();
            if (!number->isInteger()) {
                // 存在小数部分
                auto tmp = number->getDoubleValue() - time.tv_sec;
                time.tv_usec = (__darwin_suseconds_t)(tmp * 1000000) ;
            }

        } else{
            return nullptr;
        }

        if (callbackArg->getType() != FUNCTION) {
            return nullptr;
        }

        auto callback = (FunctionRef*) callbackArg;

        // todo add error handle..

        auto ptr = MY_TIMER_PTR(args);
        auto event = event_new(ptr->eventBase, 0, 0, setTimeoutCallback, args.object);
        event_add(event, &time);

        ptr->event = event;
        ptr->callback = callback;

        return Allocator::allocateNumber(1);
    }

    Object * langX_Timer_Dtor(X3rdFunction *func, const X3rdArgs &args){
        CHECK_OBJECT_NOT_NULL(args, "langX_Timer_Dtor");

        auto ptr = MY_TIMER_PTR(args);

        if (ptr->event) {
            event_free(ptr->event);
            ptr->event = nullptr;
        }
        if (ptr->callback) {
            Allocator::freeFunctionRef(ptr->callback);
            ptr->callback = nullptr;
        }

        free(ptr);
        RESET_3RD_OBJECT(args);

        return nullptr;
    }

    /**
     * timer 得构造方法
     * @param func
     * @param args
     * @return
     */
    Object * langX_Timer_Timer(X3rdFunction *func, const X3rdArgs &args){
        CHECK_OBJECT_NOT_NULL(args, "langX_Timer_Timer");

        auto ptr = QUICK_CALLOC(MyTimer);
        args.object->set3rdObj(ptr);

        return nullptr;
    }

    void regTimer(langXState* state, XNameSpace* space) {

        ClassInfo* info = new ClassInfo("Timer");
        info->addFunction(create3rdFunc("Timer", langX_Timer_Timer));
        info->addFunction(create3rdFunc("~Timer", langX_Timer_Dtor));
        info->addFunction(create3rdFunc("setTimeout", langX_Timer_setTimeout));

        space->putClass(info);
    }

}