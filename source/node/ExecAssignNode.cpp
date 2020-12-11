//
// Created by Aincvy(aincvy@gmail.com) on 2020/11/7.
// 执行赋值语句相关的节点

#include <sstream>
#include "ExecNode.h"
#include "ExecNodeImpl.h"
#include "NodeCreator.h"
#include "Exception.h"
#include "Number.h"
#include "StringType.h"
#include "Allocator.h"
#include "ClassInfo.h"
#include "langXObject.h"
#include "langXObjectRef.h"
#include "../extern/y.tab.h"
#include "XArray.h"
#include "Environment.h"
#include "LogManager.h"
#include "langXCommon.h"

namespace langX{

    // 执行赋值语句的左值
    void __exec61LeftStep0(Node *left, langXThread *thread){

        if (left->type == NODE_ARRAY_ELE ) {
            // 执行节点， 获取数组信息
            auto arrayInfo = left->arr_obj;
            thread->beginExecute(arrayInfo->objNode , true);
            thread->beginExecute(arrayInfo->indexNode , true);
        } else if (left->type == NODE_VARIABLE) {

            // 如果是一个变量节点  id_expr, 执行后 获取该值的产生环境等
            thread->beginExecute(left, true);
        } else {

            // 此时应该是给一个对象的某个属性进行赋值
            // 此时执行左值节点的所有子节点即可
            doSubNodes(left);
        }
    }

    // 给数组元素， 赋值
    void __exec61ArrayValue(ArrayInfo *arrayInfo, Object *value){
        // 数组元素的索引
        auto index = ((Number*)arrayInfo->indexNode->value)->getIntValue();
        auto arrayRef = (XArrayRef*) arrayInfo->objNode->value;

        arrayRef->set(index, value);
    }

    // 新的赋值操作的实现
    void __realExec61(NodeLink *nodeLink, langXThread *thread){
        auto node = nodeLink->node;
        auto oprObj = node->opr_obj;
        // 左值
        auto left = oprObj->op[0];
        // 右值
        auto right = oprObj->op[1];

        if (nodeLink->index == 0) {
            // 第一阶段， 预处理部分的值
            nodeLink->index = 1;

            // 分情况对待左值
            __exec61LeftStep0(left, thread);

            // 执行右值节点， 获取赋值的值
            thread->beginExecute(right, true);
            return;
        }

        // 更新 index
        nodeLink->index = 2;

        // 第二阶段， 赋值阶段
        auto leftValue = left->value;
        auto rightValue = right->value ? right->value : Allocator::allocateNull() ;

        // 更新 右值的 前缀属性
        auto varDeclarePrefix = thread->getVarDeclarePrefix();
        if (varDeclarePrefix > 0) {
            // 存在 声明 限制符 的时候再更新前缀
            updateVariablePrefix(rightValue, varDeclarePrefix);
        }

        // 设置当前表达式的值
        node->value = rightValue->clone();

        if (left->type == NODE_ARRAY_ELE) {
            // 数组
            __exec61ArrayValue(left->arr_obj, right->value);
        } else if (left->type == NODE_VARIABLE) {
            // 变量

            // 检测 常量属性
            if (leftValue && leftValue->isConst())
            {
                char tmp[DEFAULT_MIN_CHAR_BUFF_SIZE] = { 0 };
                sprintf(tmp, "cannot change %s value, because it is a const value.", leftValue->getName());
                getState()->curThread()->throwException(newUnsupportedOperationException(tmp)->addRef());
                return;
            }

            // 赋值
            auto varName = left->var_obj->name;
            auto env = leftValue == nullptr ? thread->getCurrentEnv() : leftValue->getEmergeEnv();

            // 因为。。  直接执行 a = 1; 这样的语句的时候，  此处， a 的值是个NullObject ,但是没有经过声明， 他是没有产生环境的。
            // 所以需要 矫正成 当前的环境
            if (env == nullptr) {
                env = thread->getCurrentEnv();
            }

            env->putObject(varName, rightValue);
        }
        else {
            // 或者对象属性赋值
            // 此时， left 节点 分为两个部分，  object, id_expr
            auto objNode = left->opr_obj->op[0];
            auto varNameNode = left->opr_obj->op[1];
            auto varName = varNameNode->var_obj->name;

            auto object = objNode->value;
            if (object == nullptr) {
                thread->throwException(newException("[Inner Error] something is wrong... object is null on opr '=' "));
                return;
            }

            if (object->getType() != OBJECT) {
                logger->error("[Inner Error] object need be a object, on opr '='");
                thread->throwException(newException("[Inner Error] object need be a object, on opr '='"));
                return;
            }

            auto ref = (langXObjectRef*) object;
            auto func = ref->getFunction("operator=");
            if (func != nullptr) {
                langX::String nameStr(varName);

                // 执行操作符重载
                auto locationString = "<call by operator=> "  + fileInfoString(node->fileinfo);
                node->value = callFunction(thread, func, ref->getRefObject(), locationString.c_str(), 2, &nameStr, rightValue);

                return;
            }

            // 检测类里是否存在这个属性
            // todo 某个Empty 类可以忽略这个检测
            

            if (!ref->getClassInfo()->hasMember(varName)) {
                char tmp[DEFAULT_MIN_CHAR_BUFF_SIZE] = { 0 };
                sprintf(tmp, "cannot find member %s in class %s!", varName, ref->getClassInfo()->getName());
                thread->throwException(newNoClassMemberException(tmp)->addRef());
                return;
            }

            // 类的常量值检测

            // 正常的赋值操作
            ref->setMember(varName, rightValue);
        }

    }

    // 赋值操作 =
    void __exec61(NodeLink *nodeLink, langXThread *thread){
        __realExec61(nodeLink, thread);

        if (nodeLink->index == 2) {
            // 到了结束的时候
            auto node = nodeLink->node;
            doSuffixOperation(node);
            freeSubNodes(node);
            nodeLink->backAfterExec = true;
        }
    }

    void __execADD_EQ(NodeLink *nodeLink) {
        Node *n = nodeLink->node;
        if (nodeLink->index == 0) {
            doSubNodes(n);
            nodeLink->index = 1;
            return;
        }

        Node *n1 = n->opr_obj->op[0];
        Node *n2 = n->opr_obj->op[1];

        if (n1->value == NULL || n2->value == NULL)
        {
            getState()->curThread()->throwException(newArithmeticException("value is null on opr '+='!")->addRef());
            freeSubNodes(n);
            return;
        }

        // 字符串的 += 操作
        if (n1->value->getType() == STRING)
        {
            // 追加到一起去
            String *str1 = (String*)n1->value;
            std::string str2(str1->getStrValue());
            Object* obj = n2->value;
            if (obj->getType() == ObjectType::STRING) {
                str2.append(((String*)obj)->getStrValue());
            }
            else {
                char tmp[4096] = { 0 };
                getObjStringDesc(obj, tmp, 4096);
                str2.append(tmp);
            }
            n->value = Allocator::allocateString(str2.c_str());
        }
        else
        {
            if (n1->value->getType() != NUMBER || n2->value->getType() != NUMBER)
            {
                getState()->curThread()->throwException(newArithmeticException("type error on opr '+='!")->addRef());
                freeSubNodes(n);
                return;
            }

            n->value = Allocator::allocateNumber(
                    ((Number*)n1->value)->getDoubleValue() + ((Number*)n2->value)->getDoubleValue());
        }

        setValueToEnv(n1->var_obj->name, n->value);
        freeSubNodes(n);
        nodeLink->backAfterExec = true;
    }

    void __execSUB_EQ(NodeLink *nodeLink) {
        Node *n = nodeLink->node;
        if (nodeLink->index == 0) {
            doSubNodes(n);
            nodeLink->index = 1;
            return;
        }

        Node *n1 = n->opr_obj->op[0];
        Node *n2 = n->opr_obj->op[1];

        if (n1->value == NULL || n2->value == NULL)
        {
            getState()->curThread()->throwException(newArithmeticException("value is null on opr '-='!")->addRef());
            freeSubNodes(n);
            return;
        }
        if (n1->value->getType() != NUMBER || n2->value->getType() != NUMBER)
        {
            getState()->curThread()->throwException(newArithmeticException("type error on opr '-='!")->addRef());
            freeSubNodes(n);
            return;
        }

        n->value = Allocator::allocateNumber(((Number*)n1->value)->getDoubleValue() - ((Number*)n2->value)->getDoubleValue());

        setValueToEnv(n1->var_obj->name, n->value);
        freeSubNodes(n);
        nodeLink->backAfterExec = true;
    }

    void __execMUL_EQ(NodeLink *nodeLink) {
        Node *n = nodeLink->node;
        if (nodeLink->index == 0) {
            doSubNodes(n);
            nodeLink->index = 1;
            return;
        }

        Node *n1 = n->opr_obj->op[0];
        Node *n2 = n->opr_obj->op[1];

        if (n1->value == NULL || n2->value == NULL)
        {
            getState()->curThread()->throwException(newArithmeticException("value is null on opr '*='!")->addRef());
            freeSubNodes(n);
            return;
        }
        if (n1->value->getType() != NUMBER || n2->value->getType() != NUMBER)
        {
            getState()->curThread()->throwException(newArithmeticException("type error on opr '*='!")->addRef());
            freeSubNodes(n);
            return;
        }

        n->value = Allocator::allocateNumber(((Number*)n1->value)->getDoubleValue() * ((Number*)n2->value)->getDoubleValue());

        setValueToEnv(n1->var_obj->name, n->value);

        freeSubNodes(n);
    }

    void __execDIV_EQ(NodeLink *nodeLink) {
        Node *n = nodeLink->node;
        if (nodeLink->index == 0) {
            doSubNodes(n);
            nodeLink->index = 1;
            return;
        }

        Node *n1 = n->opr_obj->op[0];
        Node *n2 = n->opr_obj->op[1];

        if (n1->value == NULL || n2->value == NULL)
        {
            getState()->curThread()->throwException(newArithmeticException("value is null on opr '/='!")->addRef());
            freeSubNodes(n);
            return;
        }
        if (n1->value->getType() != NUMBER || n2->value->getType() != NUMBER)
        {
            getState()->curThread()->throwException(newArithmeticException("type error on opr '/='!")->addRef());
            freeSubNodes(n);
            return;
        }

        double d2 = ((Number*)n2->value)->getDoubleValue();
        if (d2 == 0)
        {
            getState()->curThread()->throwException(newArithmeticException("/ by zero on opr '/='!")->addRef());
            freeSubNodes(n);
            return;
        }

        n->value = Allocator::allocateNumber(((Number*)n1->value)->getDoubleValue() / ((Number*)n2->value)->getDoubleValue());

        setValueToEnv(n1->var_obj->name, n->value);
        freeSubNodes(n);
        nodeLink->backAfterExec = true;
    }

    void __execMOD_EQ(NodeLink *nodeLink) {
        Node *n = nodeLink->node;
        if (nodeLink->index == 0) {
            doSubNodes(n);
            nodeLink->index = 1;
            return;
        }

        Node *n1 = n->opr_obj->op[0];
        Node *n2 = n->opr_obj->op[1];

        if (n1->value == NULL || n2->value == NULL)
        {
            getState()->curThread()->throwException(newArithmeticException("value is null on opr '%='!")->addRef());
            freeSubNodes(n);
            return;
        }
        if (n1->value->getType() != NUMBER || n2->value->getType() != NUMBER)
        {
            getState()->curThread()->throwException(newArithmeticException("type error on opr '%='!")->addRef());
            freeSubNodes(n);
            return;
        }

        int i1 = ((Number*)n1->value)->getIntValue();
        int i2 = ((Number*)n2->value)->getIntValue();
        int i3 = i1 % i2;

        n->value = Allocator::allocateNumber(i3);

        setValueToEnv(n1->var_obj->name, n->value);
        freeSubNodes(n);
        nodeLink->backAfterExec = true;
    }


}