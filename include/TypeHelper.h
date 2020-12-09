//
// Created by Aincvy(aincvy@gmail.com) on 2020/12/9.
//

#pragma once

#include "Object.h"

namespace langX{

    /**
     * 从参数中 读取数字
     * @param args
     * @param index    参数索引 （0开始）
     * @param value    要获取的值
     */
    void readNumber(const X3rdArgs &args, int index, int *value);

}