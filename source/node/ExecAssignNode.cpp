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
#include "InnerFunction.h"
#include "../extern/y.tab.h"
#include "XArray.h"

namespace langX{


    // 赋值操作 =
    void __exec61(NodeLink *nodeLink, langXThread *thread) {
        Node *n = nodeLink->node;
        //printf("__exec61 start\n");
        Node *left = n->opr_obj->op[0];

        langXObjectRef *objectRef = NULL;
        ArrayInfo *arrayInfo = NULL;

        if (left->type == NODE_OPERATOR)
        {
            if (left->opr_obj->opr == CLAXX_MEMBER)
            {
                if (nodeLink->index == 0) {
                    thread->beginExecute(left, true);
                    nodeLink->index = 1;
                    return;
                }
            }
            else if (left->opr_obj->opr == THIS)
            {
                if (nodeLink->index == 0) {
                    thread->beginExecute(left, true);
                    nodeLink->index = 1;
                    return;
                }
            }
            else {
                //printf("left not the CLAXX_MEMBER! \n");
                getState()->curThread()->throwException(newException("left not the CLAXX_MEMBER!")->addRef());
                freeSubNodes(n);
                return;
            }
        }
        else if (left->type == NODE_ARRAY_ELE)
        {
            arrayInfo = left->arr_obj;
        }
        else {
            if (left->type != NODE_VARIABLE)
            {
                //printf("left not the NODE_VARIABLE\n");
                getState()->curThread()->throwException(newTypeErrorException("left not the NODE_VARIABLE")->addRef());
                freeSubNodes(n);
                return;
            }
        }

        if (nodeLink->index == 0) {
            nodeLink->index = 1;
        }

        Node *right = n->opr_obj->op[1];
        //   要把右侧的值检出， 然后对比类型，更新左侧的值
        if (nodeLink->index == 1) {
            checkValue(right, thread);
            nodeLink->index = 2;
            return;
        }

        // 赋值操作的结果 为 右值的结果
        if (right->value == NULL)
        {
            // 判断是否是函数
            if (right->type == NODE_VARIABLE)
            {
                Function *func = thread->getFunction(right->var_obj->name);
                if (func != nullptr)
                {
                    FunctionRef * f = Allocator::allocateFunctionRef(func);
                    f->setEmergeEnv(thread->getCurrentEnv());
                    right->value = f;
                }
            }

            if (right->value == NULL)
            {
                right->value = Allocator::allocate(NULLOBJECT);
            }
        }

        // 尝试获取下左值是否是一个对象
        if (left->type == NODE_OPERATOR)
        {
            if (left->opr_obj->opr == CLAXX_MEMBER)
            {
                objectRef = (langXObjectRef *)left->ptr_u;
                left->ptr_u = NULL;
            }
        }

        ObjectType rightType = right->value->getType();
        if (objectRef == NULL && arrayInfo == NULL)
        {
            checkVarValue(left, rightType);

            if (left->value->isConst())
            {
                char tmp[1024] = { 0 };
                sprintf(tmp, "cannot change %s value, because it is a const value.", left->value->getName());
                getState()->curThread()->throwException(newUnsupportedOperationException(tmp)->addRef());
                return;
            }

            left->value->update(right->value);

            // 释放右值的内存
            Allocator::free(right->value);
            right->value = NULL;

            // 更新值到 Environment
            setValueToEnv2(left->var_obj->name, left->value, left->value->getEmergeEnv());

            n->value = Allocator::copy(left->value);
            // 左值是指向 Environment 内的内存的复制， 需要释放
            Allocator::free(left->value);
            left->value = NULL;
        }
        else if (arrayInfo != NULL)
        {
            Object *obj = NULL;
            if (arrayInfo->name != NULL)
            {
                obj = getValue(arrayInfo->name);
            }
            else if (arrayInfo->objNode != NULL)
            {
                if (nodeLink->index == 2) {
                    thread->beginExecute(arrayInfo->objNode, true);
                    nodeLink->index = 3;
                    return;
                }
                else {
                    obj = arrayInfo->objNode->value;
                }
            }

            if (obj == NULL || obj->getType() != XARRAY)
            {
                getState()->curThread()->throwException(newUnsupportedOperationException("left value is not array with array operator!")->addRef());
                freeSubNodes(n);
                return;
            }

            // 强制更新index的值
            if (nodeLink->index == 2) {
                nodeLink->index = 3;
            }

            int index = arrayInfo->index;
            if (arrayInfo->indexNode != NULL)
            {
                Node *t = arrayInfo->indexNode;
                if (nodeLink->index == 3) {
                    thread->beginExecute(t, true);
                    nodeLink->index = 4;
                    return;
                }

                if (t->value == NULL || t->value->getType() != NUMBER)
                {
                    getState()->curThread()->throwException(newException("error array length!")->addRef());
                    freeSubNodes(n);
                    return;
                }

                index = ((Number*)t->value)->getIntValue();
                Allocator::free(t->value);
                t->value = NULL;
            }

            XArrayRef *ref = (XArrayRef*)obj;
            ref->set(index, right->value);
            Allocator::free(right->value);
            right->value = NULL;

            n->value = Allocator::copy(right->value);
        }
        else {
            // 这里的Left 已经被执行过了
            char * name = left->opr_obj->op[1]->var_obj->name;

            do {
                // 判定一下操作符 = 是否进行重载了
                // 操作符= 重载的结果是 属性赋值， 而非当前对象
                Function *func1 = objectRef->getFunction("operator=");
                if (func1)
                {
                    X3rdArgs _3rdArgs;
                    memset(&_3rdArgs, 0, sizeof(X3rdArgs));
                    langX::String str1(name);
                    _3rdArgs.args[0] = &str1;
                    _3rdArgs.args[1] = right->value;
                    _3rdArgs.index = 2;
                    n->value = callFunction(objectRef, func1, &_3rdArgs);

                    freeSubNodes(n);
                    break;
                }

                // 属性的正常赋值
                if (!objectRef->getClassInfo()->hasMember(name))
                {
                    char tmp[100] = { 0 };
                    sprintf(tmp, "cannot find member %s in class %s!", name, objectRef->getClassInfo()->getName());
                    getState()->curThread()->throwException(newNoClassMemberException(tmp)->addRef());
                }
                else {
                    if (left->value != NULL && left->value->isConst())
                    {
                        char tmp[1024] = { 0 };
                        sprintf(tmp, "cannot change %s value, because it is a const value.", left->value->getName());
                        getState()->curThread()->throwException(newUnsupportedOperationException(tmp)->addRef());
                        return;
                    }

                    objectRef->setMember(name, right->value);
                    n->value = Allocator::copy(right->value);
                }
            } while (false);

            Allocator::free(right->value);
            right->value = NULL;

            delete objectRef;
            objectRef = NULL;
        }

        nodeLink->backAfterExec = true;
        doSuffixOperation(n);
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