//
// Created by Aincvy on 2020/11/25.
//
// 因为 String 字符串类型并没有对应的ClassInfo 类型， 所以本类的实现采用参数的形式
// 在脚本里面可以使用 String::isEmpty(str) 类似的方式调用本类的方法
// 如果使用c++ 调用本文件的方法，则需要把 字符串对象封装成参数传递过来。

#include "RegObjects.h"
#include "ClassInfo.h"
#include "TypeHelper.h"
#include "StringType.h"
#include "Allocator.h"
#include "Number.h"
#include "XNameSpace.h"
#include "XArray.h"

namespace langX{

    /**
     * 判断字符串是否是一个空的字符串 或者null
     * @param func
     * @param args
     * @return
     */
    Object * langX_langXString_isEmpty(X3rdFunction *func, const X3rdArgs &args){
        if (args.index <= 0) {
            // 无参数
            return nullptr;
        }

        auto a = args.args[0];
        if (a == nullptr || a->getType() == NULLOBJECT) {
            return Allocator::allocateNumber(1);     // null 视为空字符串
        }

        if (a->getType() == STRING) {
            // 是一个字符串
            auto str = (String*) a;
            return str->isEmpty() ? Allocator::allocateNumber(1) : Allocator::allocateNumber(0);
        }

        return nullptr;
    }

    /**
     * 获取字符串的长度
     * @param func
     * @param args
     * @return
     */
    Object * langX_langXString_length(X3rdFunction *func, const X3rdArgs &args){
        if (args.index <= 0) {
            // 无参数
            return Allocator::allocateNumber(0);
        }

        auto a = args.args[0];
        if (a->getType() == STRING) {
            auto str = (String*) a;
            return Allocator::allocateNumber(str->size());
        }

        return Allocator::allocateNumber(0);
    }

    /**
     * 截取字符串
     * @param func
     * @param args
     * @return
     */
    Object * langX_langXString_subString(X3rdFunction *func, const X3rdArgs &args){
        if (args.index < 2) {
            // 参数不足
            return nullptr;
        }

        auto a = args.args[0];
        if (a->getType() == STRING) {
            // 是一个字符串
            auto str = (String*) a;

            int index = -1, len = -1;
            Object *b = args.args[1];
            if (b && b->getType() == NUMBER)
            {
                index = ((Number*)b)->getIntValue();
            }

            b = args.args[2];
            if (b && b->getType() == NUMBER)
            {
                len = ((Number*)b)->getIntValue();
            }

            if (index == -1)
            {
                return Allocator::allocate(NULLOBJECT);
            }

            if (len == -1)
            {
                return Allocator::allocateString(str->subStr(index).c_str());
            }

            return Allocator::allocateString(str->subStr(index, len).c_str());
        }

        return nullptr;
    }

    /**
     * 检测字符串是否包含另外 一个字符串
     * @param func
     * @param args
     * @return
     */
    Object * langX_langXString_contains(X3rdFunction *func, const X3rdArgs &args){
        if (args.index < 2) {
            // 参数不足
            return nullptr;
        }

        auto a = args.args[0];
        if (a->getType() == STRING) {
            // 是一个字符串
            auto str = (String *) a;

            auto b = args.args[1];
            if (b && b->getType() == STRING) {
                if (str->contains(((String *) b)->getValue())) {
                    return Allocator::allocateNumber(1);
                }

                return Allocator::allocateNumber(0);
            }
        }

        return nullptr;
    }

    /**
     * 字符串在另外一个字符串的未知
     * @param func
     * @param args
     * @return
     */
    Object *langX_langXString_indexOf(X3rdFunction *func, const X3rdArgs &args){


        if (args.index < 2) {
            // 参数不足
            return nullptr;
        }

        auto a = args.args[0];
        if (a->getType() == STRING) {
            // 是一个字符串
            auto str = (String *) a;

            auto b = args.args[1];
            if (b && b->getType() == STRING) {
                int i = str->indexOf(((String*)b)->getValue());
                return Allocator::allocateNumber(i);
            }
        }

        return nullptr;
    }

    /**
     * 替换字符串的实际实现未知
     * @param args
     * @param first   true 只替换第一个， false 全部替换
     * @return
     */
    Object *langXString_replace(const X3rdArgs &args, bool first){
        if (args.index < 3) {
            // 参数不足
            return nullptr;
        }

        auto a = args.args[0];
        if (a && a->getType() == STRING) {
            auto str = (String *) a;

            auto b = args.args[1];
            auto c = args.args[2];
            if (b && c && b->getType() == STRING && c->getType() == STRING) {
                // 都是字符串
                auto str1 = (String*)b;
                auto str2 = (String*)c;

                auto tmp = first ? str->replaceFirst(str1->getValue(), str2->getValue())
                        : str->replace(str1->getValue(), str2->getValue());
                return Allocator::allocateString(tmp.c_str());
            }
        }

        return nullptr;
    }

    /**
     * 替换字符串
     * @param func
     * @param args
     * @return
     */
    Object *langX_langXString_replace(X3rdFunction *func, const X3rdArgs &args){
        return langXString_replace(args, false);
    }

    /**
     * 只替换 函数的第一个字符串
     * @param func
     * @param args
     * @return
     */
    Object *langX_langXString_replaceFirst(X3rdFunction *func, const X3rdArgs &args){
        return langXString_replace(args, true);
    }

    /**
     * 切分字符串
     * @param func
     * @param args
     * @return
     */
    Object *langX_langXString_split(X3rdFunction *func, const X3rdArgs &args){
        if (args.index < 2) {
            // 参数不足
            return nullptr;
        }

        auto a = args.args[0];
        if (a && a->getType() == STRING) {
            auto str = (String *) a;

            auto b = args.args[1];
            if (b->getType() == STRING) {
                std::vector<std::string> vector1 = str->split(((String*)b)->getValue());

                XArray *array1 = Allocator::allocateArray(vector1.size());
                int index = 0;
                for (auto i = vector1.begin(); i != vector1.end(); i++)
                {
                    array1->set(index++, Allocator::allocateString(((*i).c_str())));
                }

                return array1->addRef();
            }
        }

        return nullptr;
    }

    /**
     * 转换成小写
     * @param func
     * @param args
     * @return
     */
    Object *langX_langXString_lowerCase(X3rdFunction *func, const X3rdArgs &args){
        if (args.index < 1) {
            // 参数不足
            return nullptr;
        }

        auto a = args.args[0];
        if (a && a->getType() == STRING) {
            auto str = (String *) a;

            return Allocator::allocateString(str->lowerCase().c_str());
        }

        return nullptr;
    }

    /**
     * 转换成大写
     * @param func
     * @param args
     * @return
     */
    Object *langX_langXString_upperCase(X3rdFunction *func, const X3rdArgs &args){
        if (args.index < 1) {
            // 参数不足
            return nullptr;
        }

        auto a = args.args[0];
        if (a && a->getType() == STRING) {
            auto str = (String *) a;

            return Allocator::allocateString(str->upperCase().c_str());
        }

        return nullptr;
    }


    // 注册类
    ClassInfo *regStringClass(langXState *state) {

        auto info = new ClassInfo("String");
        info->addFunction("isEmpty", create3rdFunc("isEmpty", langX_langXString_isEmpty));
        info->addFunction("length", create3rdFunc("length", langX_langXString_length));
        info->addFunction("subString", create3rdFunc("subString", langX_langXString_subString));
        info->addFunction("contains", create3rdFunc("contains", langX_langXString_contains));
        info->addFunction("indexOf", create3rdFunc("indexOf", langX_langXString_indexOf));
        info->addFunction("replace", create3rdFunc("replace", langX_langXString_replace));
        info->addFunction("replaceFirst", create3rdFunc("replaceFirst", langX_langXString_replaceFirst));
        info->addFunction("split", create3rdFunc("split", langX_langXString_split));
        info->addFunction("lowerCase", create3rdFunc("lowerCase", langX_langXString_lowerCase));
        info->addFunction("upperCase", create3rdFunc("upperCase", langX_langXString_upperCase));

        state->getNameSpace("langX.extend")->putClass(info);

        return info;
    }


}