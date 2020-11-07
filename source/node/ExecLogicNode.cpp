//
// Created by Aincvy(aincvy@gmail.com) on 2020/11/7.
// 执行 逻辑判断相关的节点
#include <LogManager.h>
#include "ExecNode.h"
#include "ExecNodeImpl.h"
#include "YLlangX.h"
#include "Exception.h"
#include "Number.h"
#include "StringType.h"
#include "Allocator.h"
#include "ClassInfo.h"
#include "langXObject.h"
#include "langXObjectRef.h"
#include "InnerFunction.h"


namespace langX{

    // ! 取反
    void __exec33(NodeLink *nodeLink) {
        Node *n = nodeLink->node;
        if (nodeLink->index == 0) {
            doSubNodes(n);
            nodeLink->index = 1;
            return;
        }

        Node *n1 = n->opr_obj->op[0];
        if (n1->value == NULL)
        {
            getState()->curThread()->throwException(newArithmeticException("value is null on opr '-'!")->addRef());
            freeSubNodes(n);
            return;
        }

        Object * value = n1->value;
        n->value = Allocator::allocateNumber(value->isTrue() ? 0 : 1);

        freeSubNodes(n);
    }



    // 符号： >
    void __exec62(NodeLink *nodeLink) {
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
            getState()->curThread()->throwException(newArithmeticException("value is null on opr '>'!")->addRef());
            freeSubNodes(n);
            return;
        }
        if (n1->value->getType() != NUMBER || n2->value->getType() != NUMBER)
        {
            getState()->curThread()->throwException(newArithmeticException("type error on opr '>'!")->addRef());
            freeSubNodes(n);
            return;
        }

        double a = ((Number*)n1->value)->getDoubleValue();
        double b = ((Number*)n2->value)->getDoubleValue();

        if (a > b)
        {
            n->value = Allocator::allocateNumber(1);
        }
        else {
            n->value = Allocator::allocateNumber(0);
        }

        doSuffixOperation(n);
        freeSubNodes(n);
        nodeLink->backAfterExec = true;
    }

    // 大于等于
    void __execGE_OP(NodeLink *nodeLink) {
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
            getState()->curThread()->throwException(newArithmeticException("value is null on opr '>='!")->addRef());
            freeSubNodes(n);
            return;
        }
        if (n1->value->getType() != NUMBER || n2->value->getType() != NUMBER)
        {
            getState()->curThread()->throwException(newArithmeticException("type error on opr '>='!")->addRef());
            freeSubNodes(n);
            return;
        }

        double a = ((Number*)n1->value)->getDoubleValue();
        double b = ((Number*)n2->value)->getDoubleValue();

        if (a >= b)
        {
            n->value = Allocator::allocateNumber(1);
        }
        else {
            n->value = Allocator::allocateNumber(0);
        }

        doSuffixOperation(n);
        freeSubNodes(n);
        nodeLink->backAfterExec = true;
    }

    // 符号： <
    void __exec60(NodeLink *nodeLink) {
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
            getState()->curThread()->throwException(newArithmeticException("value is null on opr '<'!")->addRef());
            freeSubNodes(n);
            return;
        }
        if (n1->value->getType() != NUMBER || n2->value->getType() != NUMBER)
        {
            getState()->curThread()->throwException(newArithmeticException("type error on opr '<'!")->addRef());
            freeSubNodes(n);
            return;
        }

        double a = ((Number*)n1->value)->getDoubleValue();
        double b = ((Number*)n2->value)->getDoubleValue();

        if (a < b)
        {
            n->value = Allocator::allocateNumber(1);
        }
        else {
            n->value = Allocator::allocateNumber(0);
        }

        doSuffixOperation(n);
        freeSubNodes(n);
        nodeLink->backAfterExec = true;
    }

    // 小于等于
    void __execLE_OP(NodeLink *nodeLink) {
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
            getState()->curThread()->throwException(newArithmeticException("value is null on opr '<='!")->addRef());
            freeSubNodes(n);
            return;
        }
        if (n1->value->getType() != NUMBER || n2->value->getType() != NUMBER)
        {
            getState()->curThread()->throwException(newArithmeticException("type error on opr '<='!")->addRef());
            freeSubNodes(n);
            return;
        }

        double a = ((Number*)n1->value)->getDoubleValue();
        double b = ((Number*)n2->value)->getDoubleValue();

        if (a <= b)
        {
            n->value = Allocator::allocateNumber(1);
        }
        else {
            n->value = Allocator::allocateNumber(0);
        }

        doSuffixOperation(n);
        freeSubNodes(n);
        nodeLink->backAfterExec = true;
    }

    // 等于
    void __execEQ_OP(NodeLink *nodeLink) {
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
            getState()->curThread()->throwException(newArithmeticException("value is null on opr '=='!")->addRef());
            freeSubNodes(n);
            return;
        }

        Object * left = n1->value;
        Object * right = n2->value;

        if (left->getType() == NULLOBJECT)
        {
            if (right->getType() == NULLOBJECT)
            {
                n->value = Allocator::allocateNumber(1);
            }
            else {
                n->value = Allocator::allocateNumber(0);
            }
        }
        else if (left->getType() == NUMBER)
        {
            if (n2->value->getType() == NUMBER)
            {
                double a = ((Number*)n1->value)->getDoubleValue();
                double b = ((Number*)n2->value)->getDoubleValue();
                logger->debug("eq op: a: %.4f, b: %.4f", a, b);

                if (a == b)
                {
                    n->value = Allocator::allocateNumber(1);
                }
                else {
                    n->value = Allocator::allocateNumber(0);
                }
            }
            else {
                n->value = Allocator::allocateNumber(0);
            }
        }
        else if (left->getType() == STRING)
        {
            if (n2->value->getType() == STRING)
            {
                // 字符串比较
                const char * a = ((String*)n1->value)->getValue();
                const char * b = ((String*)n2->value)->getValue();
                // logger->debug("a: %s,b: %s",a,b);

                if (strcmp(a, b) == 0)
                {
                    n->value = Allocator::allocateNumber(1);
                }
                else {
                    n->value = Allocator::allocateNumber(0);
                }
            }
            else {
                n->value = Allocator::allocateNumber(0);
            }
        }
        else if (left->getType() == OBJECT) {
            langXObjectRef * ref1 = (langXObjectRef*)left;
            Function *func1 = ref1->getFunction("operator==");
            if (func1)
            {
                X3rdArgs _3rdArgs;
                memset(&_3rdArgs, 0, sizeof(X3rdArgs));
                _3rdArgs.args[0] = right;
                _3rdArgs.index = 1;
                n->value = callFunction(left, func1, &_3rdArgs);

                freeSubNodes(n);
                nodeLink->backAfterExec = true;
                return;
            }

            // check 描述字符串
            if (right && right->getType() == OBJECT)
            {
                langXObjectRef * ref2 = (langXObjectRef*)right;
                if (strcmp(ref1->characteristic(), ref2->characteristic()) == 0)
                {
                    n->value = Allocator::allocateNumber(1);
                }
                else {
                    n->value = Allocator::allocateNumber(0);
                }
            }
            else if (right->getType() == NULLOBJECT || right->getType() == XARRAY)
            {
                n->value = Allocator::allocateNumber(0);
            }
            else {
                getState()->curThread()->throwException(newArithmeticException("type error on opr '=='! only can number or string!")->addRef());
                n->value = Allocator::allocateNumber(0);
            }
        }
        else if (left->getType() == XARRAY)
        {
            // 数组
            if (right && right->getType() == OBJECT)
            {
                n->value = Allocator::allocateNumber(0);
            }
            else if (right->getType() == NULLOBJECT)
            {
                n->value = Allocator::allocateNumber(0);
            }
            else if (right->getType() == XARRAY)
            {
                if (strcmp(left->characteristic(), right->characteristic()) == 0)
                {
                    n->value = Allocator::allocateNumber(1);
                }
                else {
                    n->value = Allocator::allocateNumber(0);
                }
            }
            else {
                getState()->curThread()->throwException(newArithmeticException("type error on opr '=='! only can number or string!")->addRef());
                n->value = Allocator::allocateNumber(0);
            }
        }
        else {
            //printf("类型不同，无法比较");
            getState()->curThread()->throwException(newArithmeticException("type error on opr '=='! only can number or string!")->addRef());
            n->value = Allocator::allocateNumber(0);
        }

        doSuffixOperation(n);
        freeSubNodes(n);
        nodeLink->backAfterExec = true;
    }

    // 不等于
    void __execNE_OP(NodeLink *nodeLink) {
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
            getState()->curThread()->throwException(newArithmeticException("value is null on opr '!='!")->addRef());
            freeSubNodes(n);
            return;
        }

        Object * left = n1->value;
        Object * right = n2->value;

        if (left->getType() == NULLOBJECT)
        {
            if (right->getType() == NULLOBJECT)
            {
                n->value = Allocator::allocateNumber(0);
            }
            else {
                n->value = Allocator::allocateNumber(1);
            }
        }
        else
        if (left->getType() == NUMBER)
        {
            if (n2->value->getType() == NUMBER)
            {
                double a = ((Number*)n1->value)->getDoubleValue();
                double b = ((Number*)n2->value)->getDoubleValue();

                if (a != b)
                {
                    n->value = Allocator::allocateNumber(1);
                }
                else {
                    n->value = Allocator::allocateNumber(0);
                }
            }
            else {
                n->value = Allocator::allocateNumber(1);
            }
        }
        else if (left->getType() == STRING)
        {
            // 左侧类型为字符串
            if (n2->value->getType() == STRING)
            {
                // 如果右侧类型也为字符串

                // 字符串比较
                const char * a = ((String*)n1->value)->getValue();
                const char * b = ((String*)n2->value)->getValue();

                if (strcmp(a, b) != 0)
                {
                    n->value = Allocator::allocateNumber(1);
                }
                else {
                    n->value = Allocator::allocateNumber(0);
                }
            }
            else {
                n->value = Allocator::allocateNumber(1);
            }
        }
        else if (left->getType() == OBJECT) {
            langXObjectRef * ref1 = (langXObjectRef*)left;
            Function *func1 = ref1->getFunction("operator!=");
            if (func1)
            {
                X3rdArgs _3rdArgs;
                memset(&_3rdArgs, 0, sizeof(X3rdArgs));
                _3rdArgs.args[0] = right;
                _3rdArgs.index = 1;
                n->value = callFunction(left, func1, &_3rdArgs);

                freeSubNodes(n);
                nodeLink->backAfterExec = true;
                return;
            }

            // check 描述字符串
            if (right && right->getType() == OBJECT)
            {
                langXObjectRef * ref2 = (langXObjectRef*)right;
                if (strcmp(ref1->characteristic(), ref2->characteristic()) == 0)
                {
                    n->value = Allocator::allocateNumber(0);
                }
                else {
                    n->value = Allocator::allocateNumber(1);
                }
            }
            else if (right->getType() == NULLOBJECT || right->getType() == XARRAY)
            {
                n->value = Allocator::allocateNumber(1);
            }
            else {
                getState()->curThread()->throwException(newArithmeticException("type error on opr '=='! only can number or string!")->addRef());
                n->value = Allocator::allocateNumber(0);
            }
        }
        else if (left->getType() == XARRAY)
        {
            // 数组
            if (right->getType() == OBJECT)
            {
                n->value = Allocator::allocateNumber(1);
            }
            else if (right->getType() == NULLOBJECT)
            {
                n->value = Allocator::allocateNumber(1);
            }
            else if (right->getType() == XARRAY)
            {
                if (strcmp(left->characteristic(), right->characteristic()) == 0)
                {
                    n->value = Allocator::allocateNumber(0);
                }
                else {
                    n->value = Allocator::allocateNumber(1);
                }
            }
            else {
                getState()->curThread()->throwException(newArithmeticException("type error on opr '=='! only can number or string!")->addRef());
                n->value = Allocator::allocateNumber(0);
            }
        }
        else {
            //printf("类型不同，无法比较");
            getState()->curThread()->throwException(newArithmeticException("type error on opr '!='! only can number or string!")->addRef());
            n->value = Allocator::allocateNumber(0);
        }

        doSuffixOperation(n);
        freeSubNodes(n);
        nodeLink->backAfterExec = true;
    }


    void __execOPAND(NodeLink *nodeLink) {
        Node *n = nodeLink->node;
        if (nodeLink->index == 0) {
            doSubNodes(n);
            nodeLink->index = 1;
            return;
        }

        stateExtends(n);
        bool f = __tryConvertToBool(n->opr_obj->op[0]);
        if (getState()->curThread()->isInException())
        {
            freeSubNodes(n);
            return;
        }
        if (f)
        {
            n->value = __tryConvertToBool(n->opr_obj->op[1]) ? n->value = Allocator::allocateNumber(1) : n->value = Allocator::allocateNumber(0);
        }
        else {
            n->value = Allocator::allocateNumber(0);
        }

        freeSubNodes(n);
        nodeLink->backAfterExec = true;
    }

    void __execOPOR(NodeLink *nodeLink) {
        Node *n = nodeLink->node;
        if (nodeLink->index == 0) {
            doSubNodes(n);
            nodeLink->index = 1;
            return;
        }

        stateExtends(n);
        bool f = __tryConvertToBool(n->opr_obj->op[0]);
        if (getState()->curThread()->isInException())
        {
            freeSubNodes(n);
            return;
        }

        if (f)
        {
            n->value = Allocator::allocateNumber(1);
        }
        else {
            n->value = __tryConvertToBool(n->opr_obj->op[1]) ? n->value = Allocator::allocateNumber(1) : n->value = Allocator::allocateNumber(0);
        }

        freeSubNodes(n);
        nodeLink->backAfterExec = true;
    }


    //  类型判断语句， 返回一个 true/false
    void __execXIS(NodeLink *nodeLink, langXThread *thread) {
        Node *n = nodeLink->node;
        Node *n1 = n->opr_obj->op[0];
        Node *n2 = n->opr_obj->op[1];

        if (nodeLink->index == 0) {
            thread->beginExecute(n1, true);
            nodeLink->index = 1;
            return;
        }

        if (n1->value == NULL)
        {
            n->value = Allocator::allocateNumber(0);
        }
        else {
            //UNKNOWN=100, NUMBER , STRING, FUNCTION, OBJECT , NULLOBJECT ,XARRAY
            int i = 0;
            char *type = n2->var_obj->name;
            switch (n1->value->getType())
            {
                case NUMBER:
                    if (strcmp(type, "Number") == 0)
                    {
                        i = 1;
                    }
                    break;
                case STRING:
                    if (strcmp(type, "String") == 0)
                    {
                        i = 1;
                    }
                    break;
                case FUNCTION:
                    if (strcmp(type, "Function") == 0)
                    {
                        i = 1;
                    }
                    break;
                case OBJECT:

                    if (((langXObjectRef*)n1->value)->getClassInfo()->isInstanceOf(type))
                    {
                        i = 1;
                    }
                    break;
                case NULLOBJECT:
                    if (strcmp(type, "Null") == 0)
                    {
                        i = 1;
                    }
                    break;
                case XARRAY:
                    if (strcmp(type, "Array") == 0)
                    {
                        i = 1;
                    }
                    break;
                default:
                    break;
            }

            n->value = Allocator::allocateNumber(i);
        }

        freeSubNodes(n);
        nodeLink->backAfterExec = true;
    }

}