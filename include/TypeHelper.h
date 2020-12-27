//
// Created by Aincvy(aincvy@gmail.com) on 2020/12/9.
//

#pragma once

#include "Object.h"
#include "Function.h"


/**
 * 快速申请 一个类型得内存
 */
#define QUICK_CALLOC(type) (type*)calloc(1, sizeof(type))

/**
 * 检测 3rd 函数得参数个数是否足够
 * 如果不足够， 则返回一个 nullptr 出去
 */
#define CHECK_ARGS_SIZE(args, num) \
if (args.index < num) { \
    return nullptr; \
} void(0)



/**
 * 强转一个 Object* 类型得指针成 Number*
 */
#define LX_NUMBER(obj) ((Number*)obj)

/**
 * 强转一个 Object* 类型得指针成 String*
 */
#define LX_STRING(obj) ((String*)obj)

/**
 * 强转一个 Object* 类型得指针成 langXObjectRef*
 */
#define LX_OBJECT_REF(obj) ((langXObjectRef*)obj)

/**
 * 获取一个 Object* 类型指针， 指向得 langXObject对象得指针
 */
#define LX_OBJECT(obj) LX_OBJECT_REF(obj)->getRefObject()

/**
 * 获取一个对象得某个属性， 并把该属性转换成 number 类型指针
 */
#define OBJECT_NUMBER_MEMBER_PTR(object, mem) ((Number*)object->getMember(mem))

/**
 * 获取一个 Number* 得整形值  | 并不检测指针得有效性
 */
#define LX_NUMBER_INT_VALUE(object) ((Number*)object)->getIntValue()

/**
 * 获取一个 Number* 得双精度浮点值  | 并不检测指针得有效性
 */
#define NUMBER_DOUBLE_VALUE(object) ((Number*)object)->getDoubleValue()

/**
 * 设置一个 整形数字得值
 */
#define SET_NUMBER_VALUE(object, value) ((Number*)object)->setValue(value)

/**
 * 获取一个对象得某个属性， 并把该属性转换成 string 类型指针
 */
#define OBJECT_STRING_MEMBER_PTR(object, mem) ((String*)object->getMember(mem))

/**
 * 转换 str 成一个 String* , 然后尝试获取 const char* 类型得值  | 并不检测指针得有效性
 */
#define LX_STRING_VALUE(str) ((String*)str)->getValue()

/**
 * 设置一个 langXObjectRef 对象得 3rd 属性
 * obj 可以是一个 Object* 类型得指针参数
 */
#define LX_SET_OBJECT_REF_3RD(obj, _3rd) LX_OBJECT(obj)->set3rdObj(_3rd)

/**
 * 获取一个 langXObject 得 3rdObj 指针， 并把它强转成指定得类型
 */
#define LX_GET_OBJECT_REF_3RD(type, obj) ((type)LX_OBJECT(obj)->get3rdObj())





namespace langX {

    class langXObject;
    class langXObjectRef;
    class Number;
    class NullObject;
    class String;


    //  一些属性

    // 数字： 0
    extern Number* shortcutNumberZero;
    // 数字: 1
    extern Number* shortcutNumberOne;
    // 空对象
    extern NullObject* shortcutNullObject;
    // 空字符串
    extern String* shortcutEmptyString;


    // 一些函数

    /**
     * 从参数中 读取数字
     * @param args
     * @param index    参数索引 （0开始）
     * @param value    要获取的值
     */
    void readNumber(const X3rdArgs &args, int index, int *value);


    /**
     * 判断参数是否是一个 nullptr 或者 NullObject
     * @param obj
    * @return  true: nullptr or NullObject
    */
    bool isNull(Object *obj);

    /**
     * 把一个 x3rd args 转换成 一个数组对象
     * @param args
     * @param arrayObjRef
     */
    void x3rdArgsToArray(const X3rdArgs& args, XArray* arrayObjRef);

    /**
     * 从一个对象里面， 尝试获取到一个字符串得属性
     * @param object
     * @param memberName
     * @return
     */
    const char* getStringFromObject(langXObject* object, const char* memberName);

    /**
     * 从一个对象里面， 尝试获取到一个整形得 属性
     * @param object
     * @param memberName
     * @return
     */
    int getIntFromObject(langXObject* object, const char* memberName);

    /**
     *
     * @param object
     * @param memberName
     * @return
     */
    int getIntFromObject(langXObjectRef* object, const char* memberName);

    /**
     * 从一个对象里面， 尝试获取到一个 双精度浮点数得 属性
     * @param object
     * @param memberName
     * @return
     */
    double getDoubleFromObject(langXObject* object, const char* memberName);

    double getDoubleFromObject(langXObjectRef* object, const char* memberName);


    /**
     * 创建一个第三方函数
     * @param name
     * @param worker
     * @return
     */
    Function* create3rdFunc(const char *name, X3rdFuncWorker worker);

    /**
     * 将一个 langXObject 转成字符串， 可能会调用该对象的 toString() 方法
     * @param obj
     * @param offset
     * @param maxSize
     */
    void objToString(langX::Object * obj,char *, int offset, int maxSize);

    /**
     * 把 src 得内容复制给 dst
     * @param src
     * @param dst
     */
    void copyX3rdArgs(const X3rdArgs &src, X3rdArgs &dst);



}