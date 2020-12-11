//
// Created by Aincvy(aincvy@gmail.com) on 2020/12/9.
//

#pragma once

#include "Object.h"

namespace langX {

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

}