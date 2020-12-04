//
// Created by Aincvy(aincvy@gmail.com) on 2020/11/7.
//
// 实现基本的数学运算节点

#include <sstream>
#include "ExecNode.h"
#include "ExecNodeImpl.h"
#include "NodeCreator.h"
#include "Exception.h"
#include "Number.h"
#include "StringType.h"
#include "Allocator.h"
#include "langXObject.h"
#include "langXObjectRef.h"
#include "InnerFunction.h"
#include "LogManager.h"

namespace langX {


    void __realExec43(Node *n) {
        Node *n1 = n->opr_obj->op[0];
        Node *n2 = n->opr_obj->op[1];

        if (n1->value == nullptr || n2->value == nullptr) {
            getState()->curThread()->throwException(newArithmeticException("value is null on opr '+'!")->addRef());
            freeSubNodes(n);
            return;
        }

        // 子节点的值是为了计算当前结点的值， 如果当前结点的值 计算 结束， 则释放掉子节点值得内存
        // 子节点的值如果是一个常量， 则该值是一个 new 的内存， 如果是一个变量， 则该值是一个 clone 出现的对象
        Object *left = n1->value;
        Object *right = n2->value;

        if (left->getType() == NUMBER && right->getType() == NUMBER) {
            n->value = Allocator::allocateNumber(
                    ((Number *) left)->getDoubleValue() + ((Number *) right)->getDoubleValue());
        } else if (left != NULL && left->getType() == OBJECT) {
            langXObjectRef *ref1 = (langXObjectRef *) left;
            Function *func1 = ref1->getFunction("operator+");
            if (func1) {
                X3rdArgs _3rdArgs;
                memset(&_3rdArgs, 0, sizeof(X3rdArgs));
                _3rdArgs.args[0] = right;
                _3rdArgs.index = 1;
                n->value = callFunction(left, func1, &_3rdArgs);

                freeSubNodes(n);
                return;
            }
        } else if ((left != nullptr && left->getType() == STRING) || (right != NULL && right->getType() == STRING)) {
            // 字符串拼接
            std::stringstream ss;
            if (left == nullptr) {
                ss << "null";
            } else if (left->getType() == STRING) {
                ss << ((String *) left)->getValue();
            } else if (left->getType() == NUMBER) {
                ss << ((Number *) left)->getDoubleValue();
            } else if (left->getType() == NULLOBJECT) {
                ss << "null";
            } else if (left->getType() == FUNCTION) {
                ss << "function@[" << left->characteristic();
            } else if (left->getType() == OBJECT) {
                //ss << "object";
                char tmp[2048] = {0};
                objToString(left, tmp, 0, 2048);
                ss << tmp;
            } else {
                printf("error type in do add opr! \n");
                return;
            }

            if (right == nullptr) {
                ss << "null";
            } else if (right->getType() == STRING) {
                ss << ((String *) right)->getValue();
            } else if (right->getType() == NUMBER) {
                ss << ((Number *) right)->getDoubleValue();
            } else if (right->getType() == NULLOBJECT) {
                ss << "null";
            } else if (right->getType() == FUNCTION) {
                ss << "function@[" << right->characteristic();
            } else if (right->getType() == OBJECT) {
                char tmp[2048] = {0};
                objToString(right, tmp, 0, 2048);
                ss << tmp;
            } else {
                printf("error type in do add opr! \n");
                return;
            }

            n->value = Allocator::allocateString(ss.str().c_str());
        } else {
            getState()->curThread()->throwException(
                    newArithmeticException("args type error when do opr '+' .")->addRef());
        }

        freeSubNodes(n);
    }

    // +
    // 操作结果， 会将结果存储在当前节点中
    void __exec43(NodeLink *nodeLink) {

        Node *n = nodeLink->node;
        if (nodeLink->index == 0) {
            doSubNodes(n);
            nodeLink->index = 1;
        } else {
            logger->debug("node 43");

            __realExec43(n);
            nodeLink->backAfterExec = true;
        }
    }

    // -
    void __exec45(NodeLink *nodeLink) {
        Node *n = nodeLink->node;
        if (nodeLink->index == 0) {
            doSubNodes(n);
            nodeLink->index = 1;
            return;
        }

        Node *n1 = n->opr_obj->op[0];
        Node *n2 = n->opr_obj->op[1];

        if (n1->value == NULL || n2->value == NULL) {
            getState()->curThread()->throwException(newArithmeticException("value is null on opr '-'!")->addRef());
            freeSubNodes(n);
            return;
        }

        nodeLink->backAfterExec = true;

        Object *left = n1->value;
        Object *right = n2->value;
        if (left != NULL && left->getType() == OBJECT) {
            langXObjectRef *ref1 = (langXObjectRef *) left;
            Function *func1 = ref1->getFunction("operator-");
            if (func1) {
                X3rdArgs _3rdArgs;
                memset(&_3rdArgs, 0, sizeof(X3rdArgs));
                _3rdArgs.args[0] = right;
                _3rdArgs.index = 1;
                n->value = callFunction(left, func1, &_3rdArgs);

                freeSubNodes(n);
                return;
            }
        }
        if (n1->value->getType() != NUMBER || n2->value->getType() != NUMBER) {
            getState()->curThread()->throwException(newArithmeticException("type error on opr '-'!")->addRef());
            freeSubNodes(n);
            return;
        }

        n->value = Allocator::allocateNumber(
                ((Number *) n1->value)->getDoubleValue() - ((Number *) n2->value)->getDoubleValue());
        freeSubNodes(n);
    }


    // *
    void __exec42(NodeLink *nodeLink) {
        Node *n = nodeLink->node;
        if (nodeLink->index == 0) {
            doSubNodes(n);
            nodeLink->index = 1;
            return;
        }

        Node *n1 = n->opr_obj->op[0];
        Node *n2 = n->opr_obj->op[1];

        if (n1->value == NULL || n2->value == NULL) {
            getState()->curThread()->throwException(newArithmeticException("value is null on opr '*'!")->addRef());
            freeSubNodes(n);
            return;
        }

        nodeLink->backAfterExec = true;

        Object *left = n1->value;
        Object *right = n2->value;
        if (left != NULL && left->getType() == OBJECT) {
            langXObjectRef *ref1 = (langXObjectRef *) left;
            Function *func1 = ref1->getFunction("operator*");
            if (func1) {
                X3rdArgs _3rdArgs;
                memset(&_3rdArgs, 0, sizeof(X3rdArgs));
                _3rdArgs.args[0] = right;
                _3rdArgs.index = 1;
                n->value = callFunction(left, func1, &_3rdArgs);

                freeSubNodes(n);
                return;
            }
        }

        if (n1->value->getType() != NUMBER || n2->value->getType() != NUMBER) {
            getState()->curThread()->throwException(newArithmeticException("type error on opr '*'!")->addRef());
            freeSubNodes(n);
            return;
        }

        n->value = Allocator::allocateNumber(
                ((Number *) n1->value)->getDoubleValue() * ((Number *) n2->value)->getDoubleValue());
        freeSubNodes(n);
    }

    // /
    void __exec47(NodeLink *nodeLink) {
        Node *n = nodeLink->node;
        if (nodeLink->index == 0) {
            doSubNodes(n);
            nodeLink->index = 1;
            return;
        }

        Node *n1 = n->opr_obj->op[0];
        Node *n2 = n->opr_obj->op[1];

        if (n1->value == NULL || n2->value == NULL) {
            getState()->curThread()->throwException(newArithmeticException("value is null on opr '/'!")->addRef());
            freeSubNodes(n);
            return;
        }

        nodeLink->backAfterExec = true;

        Object *left = n1->value;
        Object *right = n2->value;
        if (left != NULL && left->getType() == OBJECT) {
            langXObjectRef *ref1 = (langXObjectRef *) left;
            Function *func1 = ref1->getFunction("operator/");
            if (func1) {
                X3rdArgs _3rdArgs;
                memset(&_3rdArgs, 0, sizeof(X3rdArgs));
                _3rdArgs.args[0] = right;
                _3rdArgs.index = 1;
                n->value = callFunction(left, func1, &_3rdArgs);

                freeSubNodes(n);
                return;
            }
        }

        if (n1->value->getType() != NUMBER || n2->value->getType() != NUMBER) {
            getState()->curThread()->throwException(newArithmeticException("type error on opr '/'!")->addRef());
            freeSubNodes(n);
            return;
        }

        double d2 = ((Number *) n2->value)->getDoubleValue();
        if (d2 == 0) {
            getState()->curThread()->throwException(newArithmeticException("/ by zero on opr '/'!")->addRef());
            freeSubNodes(n);
            return;
        }

        n->value = Allocator::allocateNumber(((Number *) n1->value)->getDoubleValue() / d2);
        freeSubNodes(n);
        nodeLink->backAfterExec = true;
    }


    // 按位或  |
    void __exec124(NodeLink *nodeLink) {
        Node *n = nodeLink->node;
        if (nodeLink->index == 0) {
            doSubNodes(n);
            nodeLink->index = 1;
            return;
        }

        Node *n1 = n->opr_obj->op[0];
        Node *n2 = n->opr_obj->op[1];

        if (n1->value == NULL || n2->value == NULL) {
            getState()->curThread()->throwException(newArithmeticException("value is null on opr '|'!")->addRef());
            freeSubNodes(n);
            return;
        }
        if (n1->value->getType() != NUMBER || n2->value->getType() != NUMBER) {
            getState()->curThread()->throwException(newArithmeticException("type error on opr '|'!")->addRef());
            freeSubNodes(n);
            return;
        }

        int i1 = ((Number *) n1->value)->getIntValue();
        int i2 = ((Number *) n2->value)->getIntValue();
        int i3 = i1 | i2;

        n->value = Allocator::allocateNumber(i3);
        freeSubNodes(n);
        nodeLink->backAfterExec = true;
    }

    // 按位与  &
    void __exec38(NodeLink *nodeLink) {
        Node *n = nodeLink->node;
        if (nodeLink->index == 0) {
            doSubNodes(n);
            nodeLink->index = 1;
            return;
        }

        Node *n1 = n->opr_obj->op[0];
        Node *n2 = n->opr_obj->op[1];

        if (n1->value == NULL || n2->value == NULL) {
            getState()->curThread()->throwException(newArithmeticException("value is null on opr '&'!")->addRef());
            freeSubNodes(n);
            return;
        }
        if (n1->value->getType() != NUMBER || n2->value->getType() != NUMBER) {
            getState()->curThread()->throwException(newArithmeticException("type error on opr '&'!")->addRef());
            freeSubNodes(n);
            return;
        }

        int i1 = ((Number *) n1->value)->getIntValue();
        int i2 = ((Number *) n2->value)->getIntValue();
        int i3 = i1 & i2;

        n->value = Allocator::allocateNumber(i3);
        freeSubNodes(n);
        nodeLink->backAfterExec = true;
    }

    // 按位异或  ^
    void __exec94(NodeLink *nodeLink) {
        Node *n = nodeLink->node;
        if (nodeLink->index == 0) {
            doSubNodes(n);
            nodeLink->index = 1;
            return;
        }

        Node *n1 = n->opr_obj->op[0];
        Node *n2 = n->opr_obj->op[1];

        if (n1->value == NULL || n2->value == NULL) {
            getState()->curThread()->throwException(newArithmeticException("value is null on opr '^'!")->addRef());
            freeSubNodes(n);
            return;
        }
        if (n1->value->getType() != NUMBER || n2->value->getType() != NUMBER) {
            getState()->curThread()->throwException(newArithmeticException("type error on opr '^'!")->addRef());
            freeSubNodes(n);
            return;
        }

        int i1 = ((Number *) n1->value)->getIntValue();
        int i2 = ((Number *) n2->value)->getIntValue();
        int i3 = i1 ^i2;

        n->value = Allocator::allocateNumber(i3);
        freeSubNodes(n);
        nodeLink->backAfterExec = true;
    }

    // 按位取反  ~
    void __exec126(NodeLink *nodeLink) {
        Node *n = nodeLink->node;
        if (nodeLink->index == 0) {
            doSubNodes(n);
            nodeLink->index = 1;
            return;
        }

        Node *n1 = n->opr_obj->op[0];

        if (n1->value == NULL) {
            getState()->curThread()->throwException(newArithmeticException("value is null on opr '~'!")->addRef());
            freeSubNodes(n);
            return;
        }
        if (n1->value->getType() != NUMBER) {
            getState()->curThread()->throwException(newArithmeticException("type error on opr '~'!")->addRef());
            freeSubNodes(n);
            return;
        }

        int i1 = ((Number *) n1->value)->getIntValue();
        int i3 = ~i1;

        n->value = Allocator::allocateNumber(i3);
        freeSubNodes(n);
        nodeLink->backAfterExec = true;
    }

    // 向左移位
    void __execLEFT_SHIFT(NodeLink *nodeLink) {
        Node *n = nodeLink->node;
        if (nodeLink->index == 0) {
            doSubNodes(n);
            nodeLink->index = 1;
            return;
        }

        Node *n1 = n->opr_obj->op[0];
        Node *n2 = n->opr_obj->op[1];

        if (n1->value == NULL || n2->value == NULL) {
            getState()->curThread()->throwException(newArithmeticException("value is null on opr '<<'!")->addRef());
            freeSubNodes(n);
            return;
        }

        nodeLink->backAfterExec = true;

        Object *left = n1->value;
        Object *right = n2->value;
        if (left != NULL && left->getType() == OBJECT) {
            langXObjectRef *ref1 = (langXObjectRef *) left;
            Function *func1 = ref1->getFunction("operator<<");
            if (func1) {
                X3rdArgs _3rdArgs;
                memset(&_3rdArgs, 0, sizeof(X3rdArgs));
                _3rdArgs.args[0] = right;
                _3rdArgs.index = 1;
                n->value = callFunction(left, func1, &_3rdArgs);

                freeSubNodes(n);
                return;
            }
        }

        if (n1->value->getType() != NUMBER || n2->value->getType() != NUMBER) {
            getState()->curThread()->throwException(newArithmeticException("type error on opr '<<'!")->addRef());
            freeSubNodes(n);
            return;
        }

        int i1 = ((Number *) n1->value)->getIntValue();
        int i2 = ((Number *) n2->value)->getIntValue();
        int i3 = i1 << i2;

        n->value = Allocator::allocateNumber(i3);
        freeSubNodes(n);
    }

    // 向右移位
    void __execRIGHT_SHIFT(NodeLink *nodeLink) {
        Node *n = nodeLink->node;
        if (nodeLink->index == 0) {
            doSubNodes(n);
            nodeLink->index = 1;
            return;
        }

        Node *n1 = n->opr_obj->op[0];
        Node *n2 = n->opr_obj->op[1];

        if (n1->value == NULL || n2->value == NULL) {
            getState()->curThread()->throwException(newArithmeticException("value is null on opr '>>'!")->addRef());
            freeSubNodes(n);
            return;
        }

        nodeLink->backAfterExec = true;

        Object *left = n1->value;
        Object *right = n2->value;
        if (left != NULL && left->getType() == OBJECT) {
            langXObjectRef *ref1 = (langXObjectRef *) left;
            Function *func1 = ref1->getFunction("operator>>");
            if (func1) {
                X3rdArgs _3rdArgs;
                memset(&_3rdArgs, 0, sizeof(X3rdArgs));
                _3rdArgs.args[0] = right;
                _3rdArgs.index = 1;
                n->value = callFunction(left, func1, &_3rdArgs);

                freeSubNodes(n);
                return;
            }
        }

        if (n1->value->getType() != NUMBER || n2->value->getType() != NUMBER) {
            getState()->curThread()->throwException(newArithmeticException("type error on opr '>>'!")->addRef());
            freeSubNodes(n);
            return;
        }

        int i1 = ((Number *) n1->value)->getIntValue();
        int i2 = ((Number *) n2->value)->getIntValue();
        int i3 = i1 >> i2;

        n->value = Allocator::allocateNumber(i3);
        freeSubNodes(n);
    }

    //  取模运算 %
    void __exec37(NodeLink *nodeLink) {
        Node *n = nodeLink->node;
        if (nodeLink->index == 0) {
            doSubNodes(n);
            nodeLink->index = 1;
            return;
        }

        Node *n1 = n->opr_obj->op[0];
        Node *n2 = n->opr_obj->op[1];

        if (n1->value == NULL || n2->value == NULL) {
            getState()->curThread()->throwException(newArithmeticException("value is null on opr '%'!")->addRef());
            freeSubNodes(n);
            return;
        }

        nodeLink->backAfterExec = true;

        Object *left = n1->value;
        Object *right = n2->value;
        if (left != NULL && left->getType() == OBJECT) {
            langXObjectRef *ref1 = (langXObjectRef *) left;
            Function *func1 = ref1->getFunction("operator%");
            if (func1) {
                X3rdArgs _3rdArgs;
                memset(&_3rdArgs, 0, sizeof(X3rdArgs));
                _3rdArgs.args[0] = right;
                _3rdArgs.index = 1;
                n->value = callFunction(left, func1, &_3rdArgs);

                freeSubNodes(n);
                return;
            }
        }

        if (n1->value->getType() != NUMBER || n2->value->getType() != NUMBER) {
            getState()->curThread()->throwException(newArithmeticException("type error on opr '%'!")->addRef());
            freeSubNodes(n);
            return;
        }

        int i1 = ((Number *) n1->value)->getIntValue();
        int i2 = ((Number *) n2->value)->getIntValue();
        int i3 = i1 % i2;

        n->value = Allocator::allocateNumber(i3);
        freeSubNodes(n);
    }


    // 自增运算符 ++
    void __execINC_OP(NodeLink *nodeLink) {
        Node *n = nodeLink->node;
        if (nodeLink->index == 0) {
            doSubNodes(n);
            nodeLink->index = 1;
            return;
        }

        Node *n1 = n->opr_obj->op[0];

        if (n1 == NULL) {
            getState()->curThread()->throwException(newArithmeticException("node is null on opr '++'!")->addRef());
            freeSubNodes(n);
            return;
        }

        if (n1->value == NULL) {
            getState()->curThread()->throwException(newArithmeticException("value is null on opr '++'!")->addRef());
            freeSubNodes(n);
            return;
        }

        nodeLink->backAfterExec = true;

        Object *left = n1->value;
        if (left != NULL && left->getType() == OBJECT) {
            langXObjectRef *ref1 = (langXObjectRef *) left;
            Function *func1 = ref1->getFunction("operator++");
            if (func1) {
                X3rdArgs _3rdArgs;
                memset(&_3rdArgs, 0, sizeof(X3rdArgs));
                _3rdArgs.index = 0;
                n->value = callFunction(left, func1, &_3rdArgs);

                freeSubNodes(n);
                return;
            }
        }

        if (n1->value->getType() != NUMBER) {
            getState()->curThread()->throwException(newArithmeticException("value is null on opr '++'!")->addRef());
            freeSubNodes(n);
            return;
        }

        if (!n->state.isSuffix) {
            // 前缀自增
            n->value = Allocator::allocateNumber(((Number *) n1->value)->getDoubleValue() + 1);
            n1->postposition = n->value->clone();
        } else {
            //  后缀自增
            n->value = n1->value->clone();
            n1->postposition = Allocator::allocateNumber(((Number *) n1->value)->getDoubleValue() + 1);
        }

        freeSubNodes(n);
    }

    // 自减运算符 --
    void __execDEC_OP(NodeLink *nodeLink) {
        Node *n = nodeLink->node;
        if (nodeLink->index == 0) {
            doSubNodes(n);
            nodeLink->index = 1;
            return;
        }

        /*
         * 后置值 被加到 变量身上， 而非 ++/-- 操作符身上了。
         */

        Node *n1 = n->opr_obj->op[0];
        if (n1 == NULL) {
            getState()->curThread()->throwException(newArithmeticException("node is null on opr '--'!")->addRef());
            freeSubNodes(n);
            return;
        }

        if (n1->value == NULL) {
            getState()->curThread()->throwException(newArithmeticException("value is null on opr '--'!")->addRef());
            freeSubNodes(n);
            return;
        }

        nodeLink->backAfterExec = true;

        Object *left = n1->value;
        if (left != NULL && left->getType() == OBJECT) {
            langXObjectRef *ref1 = (langXObjectRef *) left;
            Function *func1 = ref1->getFunction("operator--");
            if (func1) {
                X3rdArgs _3rdArgs;
                memset(&_3rdArgs, 0, sizeof(X3rdArgs));
                _3rdArgs.index = 0;
                n->value = callFunction(left, func1, &_3rdArgs);

                freeSubNodes(n);
                return;
            }
        }

        if (n1->value->getType() != NUMBER) {
            getState()->curThread()->throwException(newArithmeticException("value is null on opr '++'!")->addRef());
            freeSubNodes(n);
            return;
        }

        if (!n->state.isSuffix) {
            // 前缀自减
            n->value = Allocator::allocateNumber(((Number *) n1->value)->getDoubleValue() - 1);
            n1->postposition = n->value->clone();
        } else {
            //  后缀自减
            n->value = n1->value->clone();
            n1->postposition = Allocator::allocateNumber(((Number *) n1->value)->getDoubleValue() - 1);
        }

        freeSubNodes(n);
    }


    void __execUMINUS(NodeLink *nodeLink) {
        Node *n = nodeLink->node;
        if (nodeLink->index == 0) {
            doSubNodes(n);
            nodeLink->index = 1;
            return;
        }

        Node *n1 = n->opr_obj->op[0];

        if (n1->value == NULL) {
            getState()->curThread()->throwException(newArithmeticException("value is null on opr '-'!")->addRef());
            freeSubNodes(n);
            return;
        }
        if (n1->value->getType() != NUMBER) {
            getState()->curThread()->throwException(
                    newArithmeticException("type error on opr '-'! only can number!")->addRef());
            freeSubNodes(n);
            return;
        } else {
            n->value = Allocator::allocateNumber(-((Number *) n1->value)->getDoubleValue());
        }

        freeSubNodes(n);
        nodeLink->backAfterExec = true;
    }


}