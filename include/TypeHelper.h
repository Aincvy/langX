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

namespace langX {

    class langXObject;

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