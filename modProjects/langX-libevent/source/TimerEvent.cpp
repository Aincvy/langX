//
// Created by Aincvy(aincvy@gmail.com) on 2020/12/16.
//

#include "libeventModule.h"
#include "ReglibeventModule.h"

#include <time.h>

#include <langXSimple.h>

#include <event2/event.h>


#define QUICK_CALLOC(type) (type*)calloc(1, sizeof(type))

// 类信息得 指针
static langX::ClassInfo* timerEventClass;

namespace langX{

    /**
     * cpp 对象
     */
    struct MyTimerEvent{
        struct event_base *eventBase = nullptr;
        struct event *event = nullptr;
        FunctionRef* callback = nullptr;
    };


    langXObject *newTimerObject(struct event_base* eventBase){
        if (!eventBase) {
            return nullptr;
        }

        auto object = Allocator::newObject(timerEventClass, false , true);
        ((MyTimerEvent*)object->get3rdObj())->eventBase = eventBase;

        return object;
    }


    /**
     * libevent 触发了这个事件
     * @param fd
     * @param event
     * @param arg
     */
    void setTimeoutCallback(evutil_socket_t fd, short event, void *arg){
        auto object = (langXObject*) arg;
        auto ptr = (MyTimerEvent*) object->get3rdObj();

        auto thread = getCurrentState()->curThread();

        // 在调用回调函数得时候， 把 TimerEvent 类得实例传递进去， 让玩家可以进行事件得取消
        //
        langXObjectRef ref(object);
        ptr->callback->call(thread, "timeout callback", 1, &ref);

    }

    /**
     * 添加 事件得真正实现部分
     * @param args
     * @param flags
     * @return  添加成功返回 1 ，失败 返回 null | 后面可能会增加 error code 得返回
     */
    static Object *realWorkTimerEvent(const X3rdArgs &args, short flags){

        // 先尝试判断 当前得对象是否已经被使用了
        auto ptr = MY_TIMER_EVENT_PTR(args);
        if (ptr->event) {
            moduleLogger->error("One timer event only can add 1 event.If you call it again, it will be do nothing.");
            return nullptr;
        }

        // 参数判断和获取
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

        auto event = event_new(ptr->eventBase, 0, flags, setTimeoutCallback, args.object);
        event_add(event, &time);

        ptr->event = event;
        ptr->callback = (FunctionRef*)callback->clone();

        return Allocator::allocateNumber(1);
    }

    /**
     * 释放一个 MyTimerEvent 指针内部得属性内存占用
     * @param ptr
     */
    static void freeMyTimerEvent(MyTimerEvent * ptr){
        if (ptr->event) {
            event_free(ptr->event);
            ptr->event = nullptr;
        }
        if (ptr->callback) {
            Allocator::freeFunctionRef(ptr->callback);
            ptr->callback = nullptr;
        }
    }

    /**
     * langX 函数， set time out
     * @param func
     * @param args
     * @return
     */
    Object * langX_TimerEvent_setTimeout(X3rdFunction *func, const X3rdArgs &args){
        CHECK_OBJECT_NOT_NULL(args, "langX_TimerEvent_setTimeout");
        CHECK_ARGS_SIZE(args, 2);

        return realWorkTimerEvent(args,0);
    }

    /**
     * 每隔 N秒执行一次函数
     * @param func
     * @param args
     * @return
     */
    Object * langX_TimerEvent_setInterval(X3rdFunction *func, const X3rdArgs &args){
        CHECK_OBJECT_NOT_NULL(args, "langX_TimerEvent_setTimeout");
        CHECK_ARGS_SIZE(args, 2);

        return realWorkTimerEvent(args,EV_PERSIST);
    }

    /**
     * 取消当前得事件
     * @param func
     * @param args
     * @return
     */
    Object * langX_TimerEvent_cancel(X3rdFunction *func, const X3rdArgs &args){
        CHECK_OBJECT_NOT_NULL(args, "langX_TimerEvent_setTimeout");

        auto ptr = MY_TIMER_EVENT_PTR(args);
        if (ptr->event) {
            // 取消事件

            // todo add error handle
            event_del(ptr->event);
        }

        // free
        freeMyTimerEvent(ptr);
        return nullptr;
    }

    /**
     * 析构方法
     * @param func
     * @param args
     * @return
     */
    Object * langX_TimerEvent_Dtor(X3rdFunction *func, const X3rdArgs &args){
        CHECK_OBJECT_NOT_NULL(args, "langX_TimerEvent_Dtor");

        auto ptr = MY_TIMER_EVENT_PTR(args);

        freeMyTimerEvent(ptr);
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
    Object * langX_TimerEvent_Timer(X3rdFunction *func, const X3rdArgs &args){
        CHECK_OBJECT_NOT_NULL(args, "langX_TimerEvent_Timer");

        auto ptr = QUICK_CALLOC(MyTimerEvent);
        args.object->set3rdObj(ptr);

        return nullptr;
    }

    void regTimerEvent(langXState* state, XNameSpace* space) {

        ClassInfo* info = new ClassInfo("TimerEvent");

        NullObject nullObject;
        info->addMember("eventBase", &nullObject);
        info->addFunction(create3rdFunc("TimerEvent", langX_TimerEvent_Timer));
        info->addFunction(create3rdFunc("~TimerEvent", langX_TimerEvent_Dtor));
        info->addFunction(create3rdFunc("setTimeout", langX_TimerEvent_setTimeout));
        info->addFunction(create3rdFunc("setInterval", langX_TimerEvent_setInterval));
        info->addFunction(create3rdFunc("cancel", langX_TimerEvent_cancel));

        timerEventClass = info;
        space->putClass(info);
    }

}