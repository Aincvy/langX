#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sstream>
#include "ExecNode.h"
#include "ExecNodeImpl.h"
#include "NodeCreator.h"
#include "Object.h"
#include "Number.h"
#include "StringType.h"
#include "../extern/y.tab.h"
#include "Allocator.h"
#include "Environment.h"
#include "ClassInfo.h"
#include "langXObject.h"
#include "langXObjectRef.h"
#include "XArray.h"
#include "Exception.h"
#include "XNameSpace.h"
#include "StackTrace.h"
#include "NullObject.h"

#include "langXThread.h"
#include "LogManager.h"
#include "Utils.h"
#include "langXCommon.h"

namespace langX {


    //  部分函数的声明

    // 执行字符串的内部函数
    Object* __execStringInnerFunc(langXThread *thread, Object *stringObj, const char* funcName, XArgsList *args, const char * remark);

    // 执行 类的函数调用
    void __realExecCLAXX_FUNC_CALL(langXThread *thread, Node *n, Object* object, const char* funcName, XArgsList *args, const char *remark);



    // 部分函数的实现

    // 根据数组信息获得结果， 返回的结果为一个 nullptr 或者复制好的结果
    Object *getValueFromArrayInfo(ArrayInfo *arrayInfo, NodeLink *nodeLink, langXThread *thread) {
        if (nodeLink->index == 0) {
            nodeLink->index = 1;
            bool flag = false;
            if (arrayInfo->objNode != nullptr) {
                thread->beginExecute(arrayInfo->objNode, true);
                flag = true;
            }
            //  计算数组的 索引节点
            if (arrayInfo->indexNode != nullptr) {
                Node *t = arrayInfo->indexNode;
                thread->beginExecute(t, true);
                flag = true;
            }

            if (flag) {
                nodeLink->backAfterExec = false;
                return nullptr;
            }
        }

        Object *obj = NULL;
        if (arrayInfo->name != NULL) {
            obj = getValue(arrayInfo->name);
        } else if (arrayInfo->objNode != NULL) {
            obj = arrayInfo->objNode->value;
        }

        if (obj == NULL) {
            thread->throwException(
                    newUnsupportedOperationException("left value is not array with array operator!")->addRef());
            return nullptr;
        }

        auto n = nodeLink->node;
        if (obj->getType() == OBJECT) {
            langXObjectRef *ref = (langXObjectRef *) obj;
            Function *func = ref->getFunction("operator[]");
            if (func) {

                Node *t = arrayInfo->indexNode;
                if (t->value == nullptr) {
                    thread->throwException(newException("error index !")->addRef());
                    return nullptr;
                }
                auto arg1 = t->value;

                // 执行操作符重载
                auto locationString = "<call by operator[]> "  + fileInfoString(n->fileinfo);
                return callFunction(thread, func, ref->getRefObject(), locationString.c_str(), 1, arg1);
            }
        }

        if (obj->getType() != XARRAY) {
            thread->throwException(
                    newUnsupportedOperationException("left value is not array with array operator!")->addRef());
            return nullptr;
        }

        Node *t = arrayInfo->indexNode;

        if (t->value == nullptr || t->value->getType() != NUMBER) {
            thread->throwException(newException("error array length !")->addRef());
            return nullptr;
        }

        auto index = ((Number *) t->value)->getIntValue();
        Allocator::free(t->value);
        t->value = nullptr;

        XArrayRef *ref = (XArrayRef *) obj;
        if (index < 0 || index >= ref->getLength()) {
            char tmp[1024] = {0};
            sprintf(tmp, "index %d,array length %d", index, ref->getLength());
            thread->throwException(newIndexOutOfBoundsException(tmp)->addRef());
            return nullptr;
        }

        Object *ret = ref->at(index);
        if (ret == nullptr) {
            // 内部异常
            thread->throwException(newInnerException(" array element is null... ")->addRef());
            return nullptr;
        }

        return ret->clone();
    }

    // 将节点的值更新到环境中
    void setValueToEnv2(const char *name, Object *val, Environment *env) {
        if (val == nullptr || name == nullptr || env == nullptr) {
            logger->error("setValueToEnv Node Args Error. \n");
            return;
        }

        Object *obj = env->getObject(name);
        if (obj == nullptr) {
            env->putObject(name, val);
        } else {
            if (obj->getType() != val->getType()) {
                logger->error("[Fatal] setValueToEnv %s left type not equal right.", name);
                return;
            }

            obj->update(val);
        }
    }

    /*
    将节点的值更新到当前环境中
    */
    void setValueToEnv(const char *name, Object *val) {
        setValueToEnv2(name, val, getState()->curThread()->getCurrentEnv());
    }

    /*
      执行这个节点的所有子节点
    */
    void doSubNodes(Node *n) {
        if (n == NULL) {
            return;
        }

        langXThread *thread = getState()->curThread();

        for (int i = 0; i < n->opr_obj->op_count; i++) {
            Node *run = n->opr_obj->op[i];
            if (run == nullptr) {
                continue;
            }

            NodeLink *nodeLink = thread->beginExecute(run);
            nodeLink->backAfterExec = true;
        }
    }

    // 做后缀操作符的 工作 也包括前缀操作符
    void doSuffixOperation(Node *n) {
        if (n == NULL) {
            return;
        }

        if (n->type == NODE_OPERATOR) {
            for (int i = 0; i < n->opr_obj->op_count; i++) {
                doSuffixOperation(n->opr_obj->op[i]);
            }
        } else if (n->type == NODE_VARIABLE && n->postposition != NULL) {
            setValueToEnv(n->var_obj->name, n->postposition);
            Allocator::free(n->postposition);
            n->postposition = NULL;
        }
    }

    void doSuffixOperationArgs(XArgsList *args) {
        if (args == NULL) {
            return;
        }

        for (int i = 0; i < args->index; i++) {
            doSuffixOperation(args->args[i]);
        }
    }

    // 状态继承， n 的所有子节点都会继承n的状态
    void stateExtends(Node *n) {
        if (n == nullptr) {
            return;
        }

        for (int i = 0; i < n->opr_obj->op_count; i++) {
            Node *tmp = n->opr_obj->op[i];
            tmp->state = n->state;

            if (tmp->type == NODE_OPERATOR) {
                if (tmp->opr_obj->opr == FUNC_CALL) {
                    // 参数
                    XArgsList *args = (XArgsList *) n->opr_obj->op[1]->ptr_u;
                    if (args != nullptr) {
                        for (size_t i = 0; i < args->index; i++) {
                            stateExtends(args->args[i]);
                        }
                    }
                }
            }
        }
    }

    //递归释放节点及子节点值的内存  | 会遍历所有节点， 发现值都会进行释放操作
    void recursiveFreeNodeValue(Node *n) {
        if (n == nullptr) {
            return;
        }

        if (n->value != nullptr) {
            Allocator::free(n->value);
            n->value = nullptr;
        }

        if (n->type == NODE_OPERATOR) {
            for (int i = 0; i < n->opr_obj->op_count; i++) {
                recursiveFreeNodeValue(n->opr_obj->op[i]);
            }
        }
    }

    // 释放数组信息
    void freeArrayInfo(ArrayInfo *arrayInfo) {
        if (arrayInfo == nullptr) {
            return;
        }
        recursiveFreeNodeValue(arrayInfo->objNode);
        recursiveFreeNodeValue(arrayInfo->indexNode);
    }

    /*
      释放当前节点的子节点的值 内存 | 只释放一层的值内存
    */
    void freeSubNodes(Node *n) {
        if (n == NULL) {
            return;
        }

        if (n->type != NODE_OPERATOR) {
            return;
        }

        for (int i = 0; i < n->opr_obj->op_count; i++) {
            if (n->opr_obj->op[i] == nullptr) {
                continue;
            }

            //printf("freeSubNodes: %d\n" , i);
            Allocator::free(n->opr_obj->op[i]->value);
            n->opr_obj->op[i]->value = nullptr;
        }
    }

    /* 如果这个变量不存在， 则new 一个放上去
       并且会放到当前的环境里面
       调用这个函数之后 会强制改写 left->value 的值

       0730 赋值给左值的值为 放入 Environment 里面的值的克隆
       0820 这个函数只会保证 左节点存在值， 并且值得类型和 右类型一样  这个函数在左值的产生环境中进行操作
    */
    void checkVarValue(Node *left, ObjectType rightType) {
        if (left == NULL) {
            return;
        }

        // 不是变量，也不是this 操作  就不做任何处理
        if (left->type != NODE_VARIABLE && !(left->type == NODE_OPERATOR && left->opr_obj->opr == KEY_THIS)) {
            return;
        }
        if (left->value != NULL) {
            // left 的value 是有值的
            if (left->value->getType() != rightType) {
                // 类型不一样
                // 先不管 left 原来指向的值
                Object *obj = left->value;
                Object *t = Allocator::allocate(rightType);
                t->setEmergeEnv(obj->getEmergeEnv());
                t->setConst(obj->isConst());
                t->setLocal(obj->isLocal());
                obj->getEmergeEnv()->putObject(left->var_obj->name, t);
                left->value = t;
            }

            return;
        }

        Object *obj = getState()->curThread()->getObject(left->var_obj->name);
        if (obj == NULL) {
            // 左值没声明过, 那么左值的产生环境就为 当前环境
            obj = Allocator::allocate(rightType);
            obj->setEmergeEnv(getState()->curThread()->getCurrentEnv());
            getState()->curThread()->putObject(left->var_obj->name, obj);
        } else {
            //  左值声明过
            if (obj->getType() != rightType) {
                Object *t = Allocator::allocate(rightType);
                // 变量的常量和local属性也不应该变化
                t->setLocal(obj->isLocal());
                t->setConst(obj->isConst());
                // 变量的产生环境不变
                t->setEmergeEnv(obj->getEmergeEnv());
                obj->getEmergeEnv()->putObject(left->var_obj->name, t);

                // 释放掉原值   0820  上面那条 putObject 语句执行结束之后， 好像就访问不到 obj 了 以后需要查看是为什么 TODO
                // 上述语句会调用 langXObject::setMember  ，这个函数会检查类型， 如果类型不一致， 会释放掉原有内存
                //Allocator::free(obj);

                // 赋值到新值
                obj = t;
            } else {
                obj = obj->clone();
            }
        }

        left->value = obj;
    }

    /* 检测一下节点是否存在 值， 如果不存在， 则运算他 */
    void checkValue(Node *node, langXThread *thread) {
        if (node == NULL) {
            return;
        }

        if (node->value == NULL) {
            thread->beginExecute(node, true);
        }
    }

    //  尝试吧这个节点的 值 转换成一个 布尔值。
    // 如果这个节点并没有被运算， 则会运算这个节点
    // 判断之后， 并不会释放这个节点的内存
    bool __tryConvertToBool(Node *n) {
        if (n == NULL) {
            return false;
        }

        //checkValue(n, getState()->curThread());      // 2017年11月30日 在外层确保值是有的吧
        if (n->value == NULL) {
            return false;
        }

        return n->value->isTrue();
    }


    // 尝试把 multiple_id 转换成一个 char*[]
    // param n:  MultipleId的最顶层的那个节点
    // param len:  返回的长度, -1表示 参数n 由问题
    char **convertMultipleId(Node *n, int *len) {
        if (n == nullptr || n->opr_obj == nullptr) {
            *len = -1;
            return nullptr;
        }

        auto opr_obj = n->opr_obj;

        // 计算有多少个元素
        auto count = 0;
        auto tmp = opr_obj;
        while (tmp != nullptr && tmp->opr == OPR_MULTIPLE_ID) {
            count++;

            if (tmp->op_count == 1) {
                // 到了底部
                break;
            }
            // 由语法文件得知， 第一个元素还是一个 OPR_MULTIPLE_ID 元素| 详情可见a.y文件
            tmp = tmp->op[0]->opr_obj;
        }

        // 给长度赋值
        *len = count;

        if (count == 0) {
            return nullptr;   // 0 个元素
        }

        // 申请内存
        auto result = (char **) calloc(count, sizeof(char *));

        // 复制 值
        auto index = 0;
        tmp = opr_obj;
        while (tmp != nullptr && tmp->opr == OPR_MULTIPLE_ID) {

            if (tmp->op_count == 1) {
                // 到了底部
                // 此处的1个元素是 变量声明的节点
                result[index++] = strdup(tmp->op[0]->var_obj->name);
                break;
            } else {
                // 取值
                // 由语法文件可知， 此处的第二个节点是一个 变量声明的节点
                auto var_obj = tmp->op[1]->var_obj;
                result[index++] = strdup(var_obj->name);
            }

            tmp = tmp->op[0]->opr_obj;
        }

        // 反转结果的数组
        for (int i = 0; i < count / 2; ++i) {
            char *t = result[i];
            result[i] = result[count - 1 - i];
            result[count - 1 - i] = t;
        }

        return result;
    }

    /**
     * 前缀循环赋值
     * @param argsList
     * @param node
     */
    void preLoopAssign(XArgsList *argsList, Node *node) {

        if (!node) {
            // 也许是无参数的调用
            return;
        }

        do {
            if (node->type != NodeType::NODE_OPERATOR) {
                // 非操作符
                break;
            }

            auto oprObj = node->opr_obj;
            if (oprObj->opr != OPR_ARGS_LIST) {
                // 非 node list 操作符
                break;
            }

            for (int i = 0; i < oprObj->op_count; ++i) {
                preLoopAssign(argsList, oprObj->op[i]);
            }

            // 当前的节点是一个 OPR_NODE_LIST， 不需要放入到 XArgsList 中， 所以这里直接 return
            return;
        } while (false);

        argsList->args[argsList->index++] = node;
    }

    /**
     * 尝试把语法描述文件里面的 参数相关的节点都提取出来  | 按照传入顺序
     * @param node
     * @return
     */
    XArgsList *convertArgsList(Node *node, ArgsList *argsList) {
        // 申请内存
        argsList->index = 0;

        // 前缀遍历， 赋值
        // 寻找到第一个 OPR_NODE_LIST 操作符
        preLoopAssign(argsList, node);

        return argsList;
    }


    // 释放 有 multipleId 节点转换出来的 char* 类型数组
    void freeMultipleIdResultArray(char **array, int len) {
        freeDoubleCharArray(array, len);
    }


    void __execBREAK(NodeLink *nodeLink, langXThread *thread) {
        if (!thread->isInLoop() && !thread->isInSwitch()) {
            getState()->curThread()->throwException(newUnsupportedOperationException("invalid break stmt.")->addRef());
            //printf("无效的BREAK 语句 ");
            return;
        }

        do {
            if (nodeLink == nullptr) {
                break;
            }

            Node *n = nodeLink->node;
            freeSubNodes(n);      //  释放节点的值的内存
            nodeLink = nodeLink->previous;
            thread->endExecute();

            if (n->type == NodeType::NODE_OPERATOR) {
                int opr = n->opr_obj->opr;
                if (opr == KEY_WHILE || opr == KEY_FOR || opr == KEY_SWITCH) {
                    // 找到了该节点
                    break;
                }
            }
        } while (true);

        thread->setBackInExec(true);
        if (thread->isInLoop()) {
            thread->setInLoop(false);
        } else {
            thread->setInSwitch(false);
        }
    }

    void __execRETURN(NodeLink *nodeLink, langXThread *thread) {
        Node *n = nodeLink->node;

        nodeLink->backAfterExec = false;

        if (nodeLink->index == 0) {
            if (!thread->isInFunction()) {
                getState()->curThread()->throwException(
                        newUnsupportedOperationException("invalid return stmt.")->addRef());
                return;
            }

            // 确定返回值
            if (n->opr_obj->op_count <= 0) {
                n->value = NULL;
            } else {
                // 存在返回值
                Node *a = n->opr_obj->op[0];
                if (a == NULL) {
                    n->value = NULL;
                } else {
                    thread->beginExecute(a, true);
                }
            }

            nodeLink->index = 1;
            return;
        }

        Node *a = n->opr_obj->op[0];
        if (a == NULL) {
            n->value = NULL;
        } else {
            n->value = a->value->clone();
        }


        freeSubNodes(n);
        thread->setFunctionResult(n->value);
        Allocator::free(n->value);
        n->value = nullptr;
        thread->setBackInExec(true);
        nodeLink->backAfterExec = true;

        // 回退节点
        Node *funcRootNode = thread->getFuncRootNode();
        do {
            if (nodeLink == nullptr) {
                break;
            }

            Node *n = nodeLink->node;
            freeSubNodes(n);
            if (funcRootNode == n) {
                // 找到了该节点
                nodeLink->index = 1000;       // 函数已经获取到返回值
                break;
            }

            nodeLink = nodeLink->previous;
            thread->endExecute();
        } while (true);

#ifdef SHOW_DETAILS
        //printf("want back to %p,cmd %d \n", funcRootNode, funcRootNode == nullptr ? -1 : funcRootNode->opr_obj->opr);
        //if (nodeLink == nullptr)
        //{
        //	printf("after return back. nodeLink is null.\n");
        //}
        //else {
        //	Node *tmpNode1 = nodeLink->node;
        //	printf("after return back. on node %p cmd %d\n", tmpNode1, tmpNode1->type == NodeType::NODE_OPERATOR ? tmpNode1->opr_obj->opr : -1);
        //}
#endif
    }


    // 分号 ;
    void __exec59(NodeLink *nodeLink, langXThread *thread) {
        Node *n = nodeLink->node;

        nodeLink->backAfterExec = false;      //  这是一个复合性质的节点， 自己管理这个状态就好了
        int oprCount = n->opr_obj->op_count;
        if (oprCount <= 0) {
            // 在语法定义中 就没有子节点要执行， 直接返回把
            nodeLink->backAfterExec = true;
            return;
        }

        if (nodeLink->index < oprCount) {
            // 遍历节点
            Node *run = n->opr_obj->op[nodeLink->index];
            nodeLink->index++;
            if (run != NULL) {
                thread->beginExecute(run, true);
            }
            return;
        }

        doSuffixOperation(n);
        freeSubNodes(n);
        nodeLink->backAfterExec = true;
    }

    // 逗号表达式
    void __exec44(NodeLink *nodeLink, langXThread *thread) {
        // 操作和 分号表达式差不多应该， 这样应该就OK了。
        __exec59(nodeLink, thread);
    }


    void __execIF(NodeLink *nodeLink, langXThread *thread) {
        if (thread->getStackTraceTopStatus().stepIf % 2 == 0) {
            // 已经执行过一个 if 分支了， 剩下的都不需要执行
            nodeLink->backAfterExec = true;
            return;
        }

        Node *n = nodeLink->node;
        Node *n1 = n->opr_obj->op[0];
        if (nodeLink->index == 0) {
            thread->beginExecute(n1, true);
            nodeLink->index = 1;
            return;
        } else if (nodeLink->index == 1) {
            // 判断条件，确定 应该执行的点

            bool f = __tryConvertToBool(n1);

            if (f) {
                Node *a = n->opr_obj->op[1];
                if (a != nullptr) {
                    thread->beginExecute(a, true);
                }

                // 条件为真， 执行
                thread->getStackTraceTopStatus().stepIf++;
            }
            nodeLink->index = 2;
            return;
        }

        doSuffixOperation(n);
        // 清理掉 所有复制  值 占用的内存
        freeSubNodes(n);
        nodeLink->backAfterExec = true;
    }

    // 执行自增和自减语句
    void __execINC_DEC(NodeLink *nodeLink, langXThread *thread) {
        //
        auto node = nodeLink->node;

        // 先执行全部的子节点
        if (nodeLink->index == 0) {
            doSubNodes(node);
            nodeLink->index = 1;
            return;
        }

        auto oprObj = node->opr_obj;

        auto n1 = oprObj->op[0];
        auto n2 = oprObj->op[1];
        // 操作符的 int 值
        int oprNumber;
        // 要变化的值的对象
        Object *number;
        // 是否是前缀运算符
        bool prefix = false;

        if (n1->type == NodeType::NODE_CONSTANT_INTEGER) {
            // 前缀运算符
            oprNumber = n1->con_obj->iValue;
            number = n2->value;
            prefix = true;

        } else {
            // 这里是后缀运算符
            number = n1->value;
            oprNumber = n2->con_obj->iValue;
            prefix = false;
        }

        if (number == nullptr) {
            getState()->curThread()->throwException(
                    newArithmeticException("value is null on opr '++'/'--'!")->addRef());
            freeSubNodes(node);
            nodeLink->backAfterExec = true;
            return;
        }

        if (number->getType() == OBJECT) {
            // 这里是一个对象， 尝试调用方法
            // todo 这里可能有一个调用顺序的bug， 前缀运算符可能这样直接调用， 但是后缀可能要具体时候再进行调用
            auto funcName = oprNumber == INC_OP ? "operator++" : "operator--";
            auto ref = (langXObjectRef *) number;
            auto func = ref->getFunction(funcName);
            if (func) {
                // 执行操作符重载
                auto locationString = "<call by " + std::string(funcName) + ">" + fileInfoString(node->fileinfo);
                node->value = callFunction(thread, func, ref->getRefObject(), locationString.c_str(), 0);

            } else {
                // 不存在该方法
                char tmp[DEFAULT_CHAR_BUFFER_SIZE];
                sprintf(tmp, "value is object, buf do not override function %s", funcName);
                getState()->curThread()->throwException(newArithmeticException(tmp)->addRef());
            }

            freeSubNodes(node);
            nodeLink->backAfterExec = true;
            return;
        }

        auto tmpValue = ((Number *) number)->getDoubleValue();
        if (oprNumber == INC_OP) {

            tmpValue += 1;
        } else if (oprNumber == DEC_OP) {
            tmpValue -= 1;
        }

        if (prefix) {
            // 前缀
            node->value = Allocator::allocateNumber(tmpValue);
            n2->postposition = node->value->clone();
        } else {
            // 后缀
            node->value = number->clone();
            n1->postposition = Allocator::allocateNumber(tmpValue);
        }

        freeSubNodes(node);
        nodeLink->backAfterExec = true;
    }

    // 开始一个新的 if 系列语句
    void __execSTART_IF(NodeLink *nodeLink, langXThread *thread) {
        // 开始新的执行
        auto &status = thread->getStackTraceTopStatus();

        if (nodeLink->index == 0) {
            nodeLink->index = 1;

            // 奇数 + 2， 偶数 + 1 ,确保执行后是个奇数
            status.stepIf += status.stepIf % 2 == 0 ? 1 : 2;

            // 执行节点
            nodeLink->backAfterExec = false;
            auto oprObj = nodeLink->node->opr_obj;
            thread->beginExecute(oprObj->op[0]);
            return;
        }

        // 还原 step
        status.stepIf -= min(status.stepIf, status.stepIf % 2 == 0 ? (short) 3 : (short) 2);

        nodeLink->backAfterExec = true;
    }

    // IF - LESE 语句
    void __execIF_ELSE(NodeLink *nodeLink, langXThread *thread) {
        if (thread->getStackTraceTopStatus().stepIf % 2 == 1) {
            // 一个 if 分支都没有执行， 进行判断
            auto oprObj = nodeLink->node->opr_obj;

            if (nodeLink->index == 0) {
                nodeLink->index = 1;
                // 执行 if 节点
                auto ifNode = oprObj->op[0];
                thread->beginExecute(ifNode, true);
                return;
            } else if (nodeLink->index == 1) {
                nodeLink->index = 2;

                auto elseNode = oprObj->op[1];
                // 在语法文件里面， 此处的else 节点可能是没有的 | 整个语句是存在else 语句的，但是当前节点可能是没有的，但是会有一个节点存在
                if (elseNode != nullptr) {
                    thread->beginExecute(elseNode);
                    return;
                }
            } else {
                // else node 已经执行过一次了， 这里跳出即可
                // 因为语法描述文件的逻辑， 上述的elseNode 可能是一个 if 语句（ 在 else if(xx = 1) 的情况下。 ）

            }
        }

        auto n = nodeLink->node;
        doSuffixOperation(n);
        // 清理掉 所有复制  值 占用的内存
        freeSubNodes(n);
        nodeLink->backAfterExec = true;

    }

    // else 节点的执行情况
    void __execELSE(NodeLink *nodeLink, langXThread *thread) {
        if (nodeLink->index == 0) {
            // 首次执行
            nodeLink->index = 1;
            thread->getStackTraceTopStatus().stepIf++;   // 直接 + 1
            nodeLink->backAfterExec = true;      // 直接 back

            // 执行新的节点
            thread->beginExecute(nodeLink->node->opr_obj->op[0], true);
        }

        // 当第二次执行这个节点的时候， 什么都不做。

    }

    void __execWHILE(NodeLink *nodeLink, langXThread *thread) {
        Node *n = nodeLink->node;
        nodeLink->backAfterExec = false;

        // 先执行条件 节点 ,然后判断条件 节点的值， 然后释放条件 节点的内存
        // 循环执行结束 ， 释放掉  所有节点值 的内存
        Node *conNode = n->opr_obj->op[0];
        Node *run = n->opr_obj->op[1];
        if (!nodeLink->flag) {
            thread->setInLoop(true);
            nodeLink->flag = true;
        }
        if (nodeLink->index == 0) {
            // 需要计算条件节点
            thread->beginExecute(conNode, true);
            nodeLink->index = 1;
            return;
        } else if (nodeLink->index == 1) {
            // 已经计算了条件节点
            if (__tryConvertToBool(conNode)) {
                doSuffixOperation(conNode);
                thread->beginExecute(run, true);
                nodeLink->index = 2;
            } else {
                doSuffixOperation(conNode);
                thread->setInLoop(false);
                nodeLink->backAfterExec = true;
                freeSubNodes(n);
            }

            // 重置条件节点的值
            Allocator::free(conNode->value);
            conNode->value = NULL;
        } else if (nodeLink->index == 2) {
            // 循环内部的节点已经执行完毕， 现在做一些后续操作
            freeSubNodes(run);
            recursiveFreeNodeValue(run);
            nodeLink->index = 0;    //
        }
    }

    void __execFOR(NodeLink *nodeLink, langXThread *thread) {
        nodeLink->backAfterExec = false;

        Node *n = nodeLink->node;
        if (!nodeLink->flag) {
            thread->setInLoop(true);
            nodeLink->flag = true;
        }

        Node *conNode = n->opr_obj->op[1];
        // 后置节点
        Node *sNode = n->opr_obj->op[2];
        // 要执行的节点
        Node *run = n->opr_obj->op[3];
        if (nodeLink->index == 0) {
            // 要求计算初始节点的值
            thread->beginExecute(n->opr_obj->op[0], true);
            nodeLink->index = 1;
        } else if (nodeLink->index == 1) {
            thread->beginExecute(conNode, true);    // 执行条件节点
            nodeLink->index = 2;
        } else if (nodeLink->index == 2) {
            // 判定条件
            doSuffixOperation(conNode);
            if (__tryConvertToBool(conNode)) {
                // 满足条件，执行后续的节点
                thread->beginExecute(run, true);
                nodeLink->index = 3;
            } else {
                // 不满足条件， 退出循环
                thread->setInLoop(false);
                nodeLink->backAfterExec = true;
                freeSubNodes(n);
            }
            Allocator::free(conNode->value);
            conNode->value = NULL;
        } else if (nodeLink->index == 3) {
            // 重置run节点的状态
            recursiveFreeNodeValue(run);

            // 执行后置节点
            thread->beginExecute(sNode, true);
            nodeLink->index = 4;
        } else if (nodeLink->index == 4) {
            // 对后置节点进行收尾，然后准备执行条件判定节点
            doSuffixOperation(sNode);
            freeSubNodes(sNode);
            Allocator::free(sNode->value);
            sNode->value = nullptr;

            nodeLink->index = 1;
        }
    }

    void __execSWITCH(NodeLink *nodeLink, langXThread *thread) {
        Node *n = nodeLink->node;

        nodeLink->backAfterExec = false;

        Node *id_expr = n->opr_obj->op[0];
        if (nodeLink->index == 0) {
            // 运算id表达式
            thread->beginExecute(id_expr, true);
            nodeLink->index = 1;
            return;
        }

        if (id_expr->value == NULL) {
            thread->throwException(newUnsupportedOperationException("null condition value in switch()!")->addRef());
            return;
        }

        if (!nodeLink->flag) {
            thread->setInSwitch(true);
            nodeLink->flag = true;
        }

        if (nodeLink->index == 1) {
            nodeLink->index = 2;

            char tmp[1024] = {0};
            Object *obj = id_expr->value;
            if (obj->getType() == ObjectType::NUMBER) {
                Number *number = (Number *) obj;
                if (number->isInteger()) {
                    // 正数
                    sprintf(tmp, "%d", number->getIntValue());
                } else {
                    sprintf(tmp, "%f", number->getDoubleValue());
                }
            } else if (obj->getType() == ObjectType::STRING) {
                String *str = (String *) obj;
                sprintf(tmp, "%s", str->getValue());
            }

            SwitchInfo *switchInfo = (SwitchInfo *) n->ptr_u;
            auto it = switchInfo->keyIndexMap.find(tmp);
            if (it == switchInfo->keyIndexMap.end()) {
                // 未找到  执行default
                thread->beginExecute(switchInfo->defaultNode, true);
            } else {
                // 找到
                thread->beginExecute(switchInfo->caseList[it->second], true);
            }

            return;
        }

        thread->setInSwitch(false);
        nodeLink->backAfterExec = true;
    }

    void __execCASE_LIST(NodeLink *nodeLink, langXThread *thread) {
        // 2017年12月8日  switch 内处理这些事情
        nodeLink->backAfterExec = true;
    }

    void __execCASE(NodeLink *nodeLink, langXThread *thread) {
        // 2017年12月8日  switch 内处理这些事情
        nodeLink->backAfterExec = true;
    }

    void __execDefault(NodeLink *nodeLink, langXThread *thread) {
        Node *n = nodeLink->node;

        if (nodeLink->index == 0) {
            thread->beginExecute(n->opr_obj->op[0], true);
            nodeLink->index = 1;
        } else {
            freeSubNodes(n);
        }
    }

    // 计算参数列表
    void __execARGS_LIST(NodeLink *nodeLink, langXThread *thread) {

        if (nodeLink->index == 0) {
            nodeLink->index = 1;
            doSubNodes(nodeLink->node);
            return;
        }

        doSuffixOperation(nodeLink->node);
        nodeLink->backAfterExec = true;
    }

    // 执行一个函数
    void __execFUNC_CALL(NodeLink *nodeLink, langXThread *thread) {
        Node *n = nodeLink->node;
        auto oprObj = n->opr_obj;
        auto objNode = oprObj->op[0];
        auto argsNode = oprObj->op[1];

        // 检测 obj 节点是否是一个 CLAXX_MEMBER 节点
        // 如果该节点是的话， 则说明是一个类的函数调用， 则使用不一样的处理方法
        auto isClassFuncCall = objNode->opr_obj != nullptr && objNode->opr_obj->opr == CLAXX_MEMBER;

        if (nodeLink->index == 0) {
            // 对参数的值进行运算
            if (isClassFuncCall) {
                // 类的函数调用

                // 执行节点， 以获取类对象
                doSubNodes(objNode);

                // 执行参数节点
                if (argsNode != nullptr) {
                    thread->beginExecute(argsNode, true);
                }
            } else {
                // 常规的函数调用
                doSubNodes(n);
            }
            nodeLink->index = 1;
            return;
        }

        // 备注和 参数列表
        auto remarkString = fileInfoString(n->fileinfo);
        auto remark = remarkString.c_str();

        // 使用自动释放内存的 argsList
        XArgsList argsList;
        convertArgsList(argsNode, &argsList);
        auto args = &argsList;

        // 获取函数， 以及执行其他类型的函数
        auto funcObj = objNode->value;
        do {
            if (isClassFuncCall) {
                // 类的函数调用， 把 funcObj 调整成类函数
                // 目前 funcObj 的值应该是一个 nullptr 。。

                // 这是一个对象节点
                auto tmpObj = objNode->opr_obj->op[0]->value;
                // 函数的名字
                auto funcName = objNode->opr_obj->op[1]->var_obj->name;

                __realExecCLAXX_FUNC_CALL(thread, n, tmpObj, funcName, args, remark);

                if (funcObj != nullptr) {
                    //
                    logger->error("in here, funcObj should be nullptr ..  ");
                    funcObj = nullptr;
                }
            }

        } while (false);

        // 执行函数
        if (funcObj != nullptr) {

            if (funcObj->getType() == FUNCTION) {
                auto *f = (FunctionRef *) funcObj;

                // n->value = f->call(args, remark);
                n->value = callFunction(thread, f, args, remark);

            } else if (funcObj->getType() == STRING) {
                String *n1Str = (String *) funcObj;
                auto tmpFuncName = n1Str->getValue();
                auto varName = objNode->var_obj ? objNode->var_obj->name : "[array,do not know name]";

                auto func = thread->getFunction(tmpFuncName);
                if (func == nullptr) {
                    // 并没有找到函数
                    char buf[DEFAULT_MIN_CHAR_BUFF_SIZE];
                    sprintf(buf, "[%s by var name %s]", tmpFuncName, varName);
                    thread->throwException(newFunctionNotFoundException(buf));
                } else {
                    // 执行函数
                    std::string str = "call function ";
                    str += tmpFuncName;
                    str += " by var ";
                    str += varName;
                    str += " ";
                    str += remark;

                    n->value = callFunction(thread, func, args, remark);
                }

            } else {
                // 类型错误
                thread->throwException(newTypeErrorException("type error, object is not a function"));
            }

        } else {
            if (!isClassFuncCall) {
                // function not found ..
                thread->throwException(newFunctionNotFoundException("[don't know function name ...]"));
            }
        }

        doSuffixOperationArgs(args);
        freeSubNodes(n);
        nodeLink->backAfterExec = true;
    }


    void __execCLAXX_BODY(NodeLink *nodeLink) {
        Node *n = nodeLink->node;
        if (nodeLink->index == 0) {
            doSubNodes(n);
            nodeLink->index = 1;
            return;
        }

        freeSubNodes(n);
        nodeLink->backAfterExec = true;
    }

    // 变量声明
    void __execVAR_DECLARE(NodeLink *nodeLink, langXThread *thread) {

        // 新版本的逻辑
        if (nodeLink->index == 0) {
            nodeLink->index = 1;

            // 0: 前缀修饰，  1: 变量名列表或者数组列表
            auto node = nodeLink->node;
            auto opr_obj = node->opr_obj;
            auto prefixNode = opr_obj->op[0];
            auto prefix = prefixNode == nullptr ? 0 : prefixNode->con_obj->iValue;
            auto varListNode = opr_obj->op[1];

            getState()->curThread()->setVarDeclarePrefix(prefix);

            // exec var node
            doSubNodes(varListNode);
        } else {
            // 还原状态
            getState()->curThread()->setVarDeclarePrefix(-1);

            nodeLink->backAfterExec = true;
        }

    }


    // 执行字符串的内部函数
    Object* __execStringInnerFunc(langXThread *thread, Object *stringObj, const char* funcName, XArgsList *args, const char * remark) {
        auto stringClass = getState()->getNameSpace("langX.extend")->getClass("String");
        auto func = stringClass->getFunction(funcName);
        if (func != nullptr) {
            // 处理下参数
            FunctionRef ref(func);
            ref.setObject(nullptr);

            X3rdArgs _3rdArgs;
            _3rdArgs.index = 1 + args->index;
            _3rdArgs.args[0] = stringObj;
            for (int i = 0; i < args->index; ++i) {
                _3rdArgs.args[i + 1] = args->args[i]->value;
            }

            return callFunction(thread, func, &_3rdArgs, remark);

        } else {
            // 未找到函数， 丢个异常
            char tmp[DEFAULT_MIN_CHAR_BUFF_SIZE];
            sprintf(tmp, "no function %s for String", funcName);
            thread->throwException(newFunctionNotFoundException(tmp));
        }

        return nullptr;
    }


    void __execCLASS_FUNC_CALL(NodeLink *nodeLink, langXThread *thread) {
        Node *n = nodeLink->node;
        Node *objNode = n->opr_obj->op[0];
        if (nodeLink->index == 0) {
            doSubNodes(n);
            nodeLink->index = 1;
            return;
        } else if (nodeLink->index == 1) {
            // 子节点都已经成功执行结束了
            do {
                if (objNode->value == nullptr) {
                    thread->throwException(
                            newTypeErrorException("left value is not class object!It's a null value.")->addRef());
                    break;
                }

                if (objNode->value->getType() != OBJECT) {
                    thread->throwException(newTypeErrorException("left value is not class object !")->addRef());
                    break;
                }

                // 根据语法解析文件可知， 第二个节点为 函数名， 第三个节点为 参数节点
                auto oprObj = n->opr_obj;
                Node *funcNameNode = oprObj->op[1];
                auto argsNode = oprObj->op[2];
                auto funcName = funcNameNode->var_obj->name;

                // 获取当前的脚本未知
                std::string remark = fileInfoString(n->fileinfo);
                // 使用自动释放内存的 参数列表
                ArgsList args;
                convertArgsList(argsNode, &args);

                __realExecCLAXX_FUNC_CALL(thread, n, objNode->value, funcName, &args, remark.c_str());

            } while (false);
        }

        freeSubNodes(n);
        nodeLink->backAfterExec = true;
    }

    void __realExecCLAXX_FUNC_CALL(langXThread *thread, Node *n, Object* object, const char* funcName, XArgsList *args, const char *remark){
        if (object->getType() == STRING) {
            n->value = __execStringInnerFunc(thread, object, funcName, args, remark);
            return;
        }

        auto objectRef = (langXObjectRef *) object;

        // 搜索函数
        auto func = objectRef->getFunction(funcName);
        if (func == nullptr) {
            // 不含有该函数， 检测属性
            auto member = objectRef->getMember(funcName);
            if (member == nullptr || member->getType() != ObjectType::FUNCTION) {
                // 不存在该属性或者 该属性的值不是一个函数， 丢个异常出去
                thread->throwException(newNoClassFunctionException(funcName));
            }else{
                // 存在该属性， 并且，该属性是一个函数 。
                // 然后执行那个函数索引， 以获取执行结果
                auto functionRef = (FunctionRef*) member;
                n->value = callFunction(thread, functionRef, args, remark);
            }
            return;
        }

        // call func ..
        n->value = callFunction(thread, func, args, objectRef->getRefObject(), remark);
    }

    void __execRESTRICT(NodeLink *nodeLink, langXThread *thread) {
        Node *n = nodeLink->node;
        // 对当前环境进行限定， 限定后，不去搜索父级环境内容

        if (n->opr_obj->op_count <= 0) {
            thread->getCurrentEnv()->setRestrict(true);
            thread->getCurrentEnv()->setClose(true);
        } else {
            Node *n1 = n->opr_obj->op[0];
            if (nodeLink->index == 0) {
                thread->beginExecute(n1, true);
                nodeLink->index = 1;
                return;
            } else {
                bool f = __tryConvertToBool(n1);
                thread->getCurrentEnv()->setRestrict(f);
                thread->getCurrentEnv()->setClose(f);
            }

            freeSubNodes(n);
        }

        nodeLink->backAfterExec = true;
    }


    // 执行 try {}
    void __execXTRY(NodeLink *nodeLink, langXThread *thread) {
        Node *n = nodeLink->node;

        if (nodeLink->index == 0) {
            nodeLink->index = 1;
            TryEnvironment *tryEnv = new TryEnvironment();
            tryEnv->setCatchNode(n->opr_obj->op[1]);    // 设置catch 节点
            thread->newEnv(tryEnv);
            thread->beginExecute(n->opr_obj->op[0], true);
            nodeLink->tryEnv = tryEnv;     // 设置环境到节点是上
            return;
        }

        if (nodeLink->index == 1) {
            thread->backEnv();
        }

        nodeLink->backAfterExec = true;
    }

    // 包含其他文件
    void __execINCLUDE(NodeLink *nodeLink, langXThread *thread) {
        Node *n = nodeLink->node;


        char *tmp = n->opr_obj->op[0]->con_obj->sValue;

        char *filename = strndup(tmp + 1, strlen(tmp) - 2);

        char tmpMsg[1024] = {0};
        sprintf(tmpMsg, "require file %s  %s", filename, fileInfoString(n->fileinfo).c_str());
        thread->getStackTrace().newFrame(nullptr, nullptr, tmpMsg);

        includeFile(filename);
        free(filename);

        thread->getStackTrace().popFrame();
        nodeLink->backAfterExec = true;
    }

    // 执行 require 其他文件
    void __execREQUIRE(NodeLink *nodeLink, langXThread *thread) {
        Node *n = nodeLink->node;

        char *tmp = n->opr_obj->op[0]->con_obj->sValue;

        char *filename = strndup(tmp + 1, strlen(tmp) - 2);

        char tmpMsg[1024] = {0};
        sprintf(tmpMsg, "require file %s  %s", filename, fileInfoString(n->fileinfo).c_str());
        thread->getStackTrace().newFrame(nullptr, nullptr, tmpMsg);

        requireFile(filename);
        free(filename);
        
        thread->getStackTrace().popFrame();
        nodeLink->backAfterExec = true;
    }

    void __execREQUIRE_ONCE(NodeLink *nodeLink, langXThread *thread) {
        Node *n = nodeLink->node;

        char *tmp = n->opr_obj->op[0]->con_obj->sValue;

        char *filename = strndup(tmp + 1, strlen(tmp) - 2);

        // 未执行过的文件
        char tmpMsg[1024] = {0};
        sprintf(tmpMsg, "require file %s  %s", filename, fileInfoString(n->fileinfo).c_str());
        thread->getStackTrace().newFrame(nullptr, nullptr, tmpMsg);

        requireOnceFile(filename);
        free(filename);

        thread->getStackTrace().popFrame();
        nodeLink->backAfterExec = true;
    }


    //  continue 关键字
    void __execCONTINUE(NodeLink *nodeLink, langXThread *thread) {
        if (!thread->isInLoop()) {
            getState()->curThread()->throwException(
                    newUnsupportedOperationException("invalid continue stmt.")->addRef());

            return;
        }

        //
        do {
            if (nodeLink == nullptr) {
                break;
            }

            Node *n = nodeLink->node;
            freeSubNodes(n);
            if (n->type == NodeType::NODE_OPERATOR) {
                int opr = n->opr_obj->opr;
                if (opr == KEY_WHILE || opr == KEY_FOR) {
                    // 找到了该节点
                    if (opr == KEY_WHILE) {
                        // 跳到判定条件的地方
                        nodeLink->index = 2;
                    } else if (opr == KEY_FOR) {
                        // 跳到后置节点的地方
                        nodeLink->index = 3;
                    }
                    break;
                }
            }

            nodeLink = nodeLink->previous;
            thread->endExecute();
        } while (true);

        thread->setBackInExec(true);
    }

    // node list  挨个执行子节点即可
    void __execNODE_LIST(NodeLink *nodeLink, langXThread *thread) {
        __exec59(nodeLink, thread);
    }


    /**
     * 声明一个函数
     * @param nodeLink
     * @param thread
     */
    void __execFUNC_OP(NodeLink *nodeLink, langXThread *thread) {
        // 当前节点只执行一遍就可以了 。。
        nodeLink->backAfterExec = true;

        auto rootNode = nodeLink->node;
        auto oprObj = rootNode->opr_obj;
        // 函数的名字
        auto nameNode = oprObj->op[0];
        // 函数的参数
        auto paramNode = oprObj->op[1];
        // 函数的执行内容
        auto blockNode = oprObj->op[2];

        //
        auto funcName = nameNode == nullptr ? nullptr : nameNode->var_obj->name;

        // 获取参数列表
        ParamsList *paramsList = (ParamsList *) calloc(1, sizeof(ParamsList));
        if (paramNode != nullptr) {
            // 存在参数列表
            int len;
            auto list = convertMultipleId(paramNode, &len);
            if (len > 0) {
                // 存在参数列表
                for (int i = 0; i < len; ++i) {
                    paramsList->args[i] = strdup(list[i]);
                }
            }
            paramsList->index = len;

            // free
            freeMultipleIdResultArray(list, len);
            len = 0;
        }

        // 建立函数对象
        blockNode->freeOnExecuted = false;
        auto func = funcName == nullptr ? new Function(blockNode) : new Function(funcName, blockNode);
        // 设置函数的参数
        func->setParamsList(paramsList);

        // 把函数放入环境中
        if (!func->hasName()) {
            // 匿名函数
            //  2017年12月3日   当运算一个匿名函数的时候， 就把改该节点的值 做成一个函数指针指向这个匿名函数
            rootNode->value = Allocator::allocateFunctionRef(func);
            return;
        }

        auto currentEnv = thread->getCurrentEnv();
        auto oldFunc = currentEnv->getFunctionSelf(func->getName());
        // 如果在类环境里面 声明函数，则判断函数是否是父类得
        bool checkFlag = true;
        if (currentEnv->getType() == EnvironmentType::TClassBridgeEnv) {
            auto clz = ((ClassBridgeEnv *) currentEnv)->getEnvClass();
            checkFlag = clz->hasFunction(funcName);    // 存在该函数就检测， 不存在就不检测
        }

        // 检测函数是否被重复声明了
        if (oldFunc != nullptr && checkFlag) {
            char tmp[100] = {0};
            sprintf(tmp, "function %s already declared.", func->getName());
            thread->throwException(newRedeclarationException(tmp)->addRef());
            delete func;
            rootNode->value = nullptr;
            return;
        }

        //函数的产生环境可能在类内部
        //func->setEmergeEnv(getState()->curThread()->getCurrentEnv());
        Environment *env = getState()->getScriptOrNSEnv();
        if (env != nullptr && env->getType() == EnvironmentType::TScriptEnvironment) {
            func->setScriptEnv((ScriptEnvironment *) env);
        }
        currentEnv->putFunction(func->getName(), func);

    }

    /**
     * 执行 类声明
     * @param nodeLink
     * @param thread
     */
    void __execCLASS_DECLARE(NodeLink *nodeLink, langXThread *thread) {
        // 本节点只执行1次
        nodeLink->backAfterExec = true;

        //
        auto oprObj = nodeLink->node->opr_obj;
        auto prefixNode = oprObj->op[0];
        auto nameNode = oprObj->op[1];
        auto suffixNode = oprObj->op[2];
        auto bodyNode = oprObj->op[3];

        // 获取实质的前缀值
        auto prefix = prefixNode->con_obj->iValue;
        // 获取类名
        auto name = nameNode->var_obj->name;
        // 获取继承的类型
        char **extends = nullptr;
        // 继承的类有多少个
        int extendsLen = 0;
        if (suffixNode != nullptr) {
            // 由于语法文件可知 suffixNode 是一个继承节点
            auto listNode = suffixNode->opr_obj->op[0];
            extends = convertMultipleId(listNode, &extendsLen);
        }

        // todo add more extends ...
        auto state = getState();
        auto clzInfo = new ClassInfo(name);
        if (extendsLen > 0) {
            auto parentName = strdup(extends[0]);
            auto parentClz = state->getClass(parentName);
            if (parentClz == nullptr) {
                // throw exception..
                char tmp[100] = {0};
                sprintf(tmp, "Class %s not found.", parentName);
                thread->throwException(newClassNotFoundException(tmp)->addRef());
                delete clzInfo;
                return;
            }

            clzInfo->setParent(parentClz);
        }

        // free
        freeMultipleIdResultArray(extends, extendsLen);
        extendsLen = 0;

        // 执行 classBody 节点， 以满足变量和函数的声明
        if (bodyNode != nullptr) {
            logger->debug("will do class %s body node", name);
            auto *env = clzInfo->getClassEnv();
            thread->newEnv(env);
            thread->beginExecute(bodyNode, true);
            __execNode(nullptr, bodyNode);     // 立即处理掉这个节点，但是也仅仅只是处理 到 这个节点
            thread->backEnv(false);

            logger->debug("class %s body node done.", name);
        }

        // 关于类前缀的判断和应用
        auto classAuto = prefix == KEY_AUTO;
        auto oldClassInfo = getState()->curThread()->getCurrentEnv()->getClassSelf(clzInfo->getName());
        if (!classAuto) {
            if (oldClassInfo != nullptr) {
                char tmp[100] = {0};
                sprintf(tmp, "class %s already declared.", clzInfo->getName());
                getState()->curThread()->throwException(newRedeclarationException(tmp)->addRef());
                delete clzInfo;
                return;
            }
        } else {
            //  自动填充
            if (oldClassInfo != nullptr) {
                oldClassInfo->expand(clzInfo);
                delete clzInfo;
                return;
            }
        }

        getState()->regClass(clzInfo);
    }

    /**
     * 更新变量的前缀  | 换句话说就是应用变量的前缀
     * @param object 变量值的引用
     * @param prefix 前缀
     */
    void updateVariablePrefix(Object *object, int prefix) {
        // check prefix
        if (prefix == KEY_CONST) {
            object->setConst(true);
        } else if (prefix == KEY_LOCAL) {
            object->setLocal(true);
        }

    }

    /**
     * 变量节点的处理
     * @param node
     * @param thread
     */
    void __execNodeVariableWork(Node *node, langXThread *thread) {
        // 变量名字
        auto varName = node->var_obj->name;
        auto varDeclarePrefix = thread->getVarDeclarePrefix();
        if (varDeclarePrefix >= 0) {
            // 这里应该声明变量 , 或者是给已经存在得变量添加限定。
            // 注意： 在给已经存在得变量添加限制得时候， 只能给当前环境得对象添加限制
            auto env = thread->getCurrentEnv();
            auto value = env->getObjectSelf(varName);

            // logger->debug("try declare var %s, prefix: %d", varName, varDeclarePrefix);

            // 存在旧值， 则使用旧值， 否则使用null
            if (value != nullptr) {
                // 存在值， 只更新前缀即可
                updateVariablePrefix(value, varDeclarePrefix);
            } else {
                // 默认情况下， 都初始化成null对象， 然后设置产生环境为当前的环境
                NullObject nullObject;
                nullObject.setEmergeEnv(thread->getCurrentEnv());

                auto p = &nullObject;
                updateVariablePrefix(p, varDeclarePrefix);

                env->putObject(varName, p);
            }

        } else {
            // 这里应该是获取变量的值
            // 协调程序， 使变量的 obj 处于赋值状态
            if (node->value == nullptr) {
                Object *obj = getValue(varName);

                if (obj == nullptr) {

                    // find function.
                    Function *func = thread->getFunction(varName);
                    if (func != nullptr) {
                        node->value = Allocator::allocateFunctionRef(func);
                    } else {
                        node->value = Allocator::allocateNull();
                    }
                } else {
                    // 变量值 为 一个 copy
                    node->value = obj->clone();
                }

                // 注意， 如果这里是一个函数引用， 或者是一个null的话， 变量的产生环境是无值的
            }
        }
    }


    /**
     * 执行一个 获取数组元素 / 数组声明的节点
     * @param node
     * @param thread  执行的线程
     */
    void __execNodeArrayElementWork(Node *node, NodeLink *nodeLink, langXThread *thread) {
        ArrayInfo *arrayInfo = node->arr_obj;

        auto varDeclarePrefix = thread->getVarDeclarePrefix();
        if (varDeclarePrefix >= 0) {
            // 数组声明的节点
            if (nodeLink->index == 0) {
                nodeLink->index++;
                // 计算数组的长度
                if (arrayInfo->indexNode != nullptr) {
                    Node *t = arrayInfo->indexNode;
                    thread->beginExecute(t, true);
                    return;
                }
            }

            // 声明
            auto arrayName = arrayInfo->name;
            auto len = 0;
            if (arrayInfo->indexNode != nullptr) {
                // 存在了值
                Node *t = arrayInfo->indexNode;

                if (t->value == nullptr || t->value->getType() != NUMBER) {
                    thread->throwException(newException("error array length !")->addRef());
                    return;
                }

                len = ((Number *) t->value)->getIntValue();
                // Allocator::free(t->value);
                // t->value = nullptr;
            }

            XArray *array = Allocator::allocateArray(len);
            auto ref = array->addRef();
            ref->setEmergeEnv(thread->getCurrentEnv());
            updateVariablePrefix(ref, varDeclarePrefix);

            setValueToEnv(arrayName, ref);

            // freeArrayInfo(arrayInfo);
        } else {
            // 获取数组的节点

            if (nodeLink->index == 0) {
                // 获取一些参数值
                Object *tmpValue = getValueFromArrayInfo(arrayInfo, nodeLink, thread);
                if (tmpValue != nullptr) {
                    // 可能上面的执行中没需要参数，一次就成功了，直接将值处理了就好
                    node->value = tmpValue;

                } else {
                    return;
                }
            } else {
                node->value = getValueFromArrayInfo(arrayInfo, nodeLink, thread);

            }
        }

        freeArrayInfo(arrayInfo);
        nodeLink->backAfterExec = true;
    }

/*
	 * 执行节点，  节点的结果 将 放在  Node.value 上
	 * 这是一个 Object 类型的指针    07-24
	 * 由 void __execNode(Node *node)    修改为  __realExecNode()       2017年11月26日
	 */
    void __realExecNode(NodeLink *nodeLink, langXThread *thread) {
        if (nodeLink == nullptr || nodeLink->node == nullptr) {
            return;
        }

        //  设置当前节点在执行结束后  会回收， 下面的 switch  开始前会重置状态
        bool nodeLinkBackAfterExec = nodeLink->backAfterExec;
        nodeLink->backAfterExec = true;

        Node *node = nodeLink->node;

        if (node->type == NODE_VARIABLE) {
            __execNodeVariableWork(node, thread);
            return;
        } else if (node->type == NODE_CONSTANT_NUMBER) {
            // logger->debug("__execNode NODE_CONSTANT_NUMBER: %.4f", node->con_obj->dValue);
            node->value = Allocator::allocateNumber(node->con_obj->dValue);
            return;
        } else if (node->type == NODE_CONSTANT_INTEGER) {
            // logger->debug("__execNode NODE_CONSTANT_INTEGER: %d", node->con_obj->iValue);
            node->value = Allocator::allocateNumber(node->con_obj->iValue);
            return;
        } else if (node->type == NODE_CONSTANT_STRING) {
            //  因为匹配出的字符串是带有 双引号的， 现在要去掉这个双引号
            char *tmp = strndup(node->con_obj->sValue + 1, strlen(node->con_obj->sValue) - 2);
            node->value = Allocator::allocateString(tmp);
            free(tmp);

            return;
        }else if (node->type == NODE_CLASS) {
            // 类
            if (node->ptr_u == NULL) {
                return;
            }
            ClassInfo *cinfo = (ClassInfo *) node->ptr_u;

            cinfo->setLocal(node->state.isLocal);

            if (!node->state.classAuto) {
                if (getState()->curThread()->getCurrentEnv()->getClassSelf(cinfo->getName()) != NULL) {
                    char tmp[100] = {0};
                    sprintf(tmp, "class %s already declared.", cinfo->getName());
                    getState()->curThread()->throwException(newRedeclarationException(tmp)->addRef());
                    delete cinfo;
                    node->ptr_u = NULL;
                    return;
                }
            } else {
                //  自动填充
                ClassInfo *c1 = getState()->curThread()->getCurrentEnv()->getClass(cinfo->getName());
                if (c1 != NULL) {
                    c1->expand(cinfo);
                    delete cinfo;
                    node->ptr_u = NULL;
                    return;
                }
            }

            getState()->regClass(cinfo);
            node->ptr_u = NULL;

            return;
        } else if (node->type == NODE_NULL) {
            node->value = Allocator::allocate(NULLOBJECT);
            return;
        } else if (node->type == NODE_ARRAY_ELE) {
            __execNodeArrayElementWork(node, nodeLink, thread);
            return;
        }

        if (node->type != NODE_OPERATOR) {
            char tmp[100] = {0};
            sprintf(tmp, "unknown type: %d", node->type);
            getState()->curThread()->throwException(newException(tmp)->addRef());
            return;
        }

        nodeLink->backAfterExec = nodeLinkBackAfterExec;

        nodeLogger->debug("will execute opr: %d", node->opr_obj->opr);

        switch (node->opr_obj->opr) {
            case '+':
                __exec43(nodeLink, thread);
                break;
            case '-':
                __exec45(nodeLink, thread);
                break;
            case '*':
                __exec42(nodeLink, thread);
                break;
            case '/':
                __exec47(nodeLink, thread);
                break;
            case '%':
                __exec37(nodeLink, thread);
                break;
            case '=':
                __exec61(nodeLink, thread);
                break;
            case ';':
                __exec59(nodeLink, thread);
                break;
            case '>':
                __exec62(nodeLink);
                break;
            case '<':
                __exec60(nodeLink);
                break;
            case '&':
                __exec38(nodeLink, thread);
                break;
            case '|':
                __exec124(nodeLink, thread);
                break;
            case '^':
                __exec94(nodeLink, thread);
                break;
            case '~':
                __exec126(nodeLink, thread);
                break;
            case '!':
                __exec33(nodeLink);
                break;
            case UMINUS:
                __execUMINUS(nodeLink, thread);
                break;
            case INC_OP:
                __execINC_OP(nodeLink, thread);
                break;
            case DEC_OP:
                __execDEC_OP(nodeLink, thread);
                break;
            case ADD_EQ:
                __execADD_EQ(nodeLink);
                break;
            case SUB_EQ:
                __execSUB_EQ(nodeLink);
                break;
            case MUL_EQ:
                __execMUL_EQ(nodeLink);
                break;
            case DIV_EQ:
                __execDIV_EQ(nodeLink);
                break;
            case MOD_EQ:
                __execMOD_EQ(nodeLink);
                break;
            case LE_OP:
                __execLE_OP(nodeLink);
                break;
            case GE_OP:
                __execGE_OP(nodeLink);
                break;
            case EQ_OP:
                __execEQ_OP(nodeLink, nullptr);
                break;
            case NE_OP:
                __execNE_OP(nodeLink, nullptr);
                break;
            case AND_OP:
                __execOPAND(nodeLink);
                break;
            case OR_OP:
                __execOPOR(nodeLink);
                break;
            case KEY_IF:
                __execIF(nodeLink, thread);
                break;
            case KEY_WHILE:
                __execWHILE(nodeLink, thread);
                break;
            case KEY_FOR:
                __execFOR(nodeLink, thread);
                break;
            case FUNC_CALL:
                __execFUNC_CALL(nodeLink, thread);
                break;
            case KEY_BREAK:
                __execBREAK(nodeLink, thread);
                break;
            case KEY_RETURN:
                __execRETURN(nodeLink, thread);
                break;
            case KEY_SWITCH:
                __execSWITCH(nodeLink, thread);
                break;
            case CASE_LIST:
                __execCASE_LIST(nodeLink, thread);
                break;
            case KEY_CASE:
                __execCASE(nodeLink, thread);
                break;
            case KEY_DEFAULT:
                __execDefault(nodeLink, thread);
                break;
            case KEY_NEW:
                __execNEW(nodeLink, thread);
                break;
            case KEY_DELETE:
                __execDELETE(nodeLink, thread);
                break;
            case CLAXX_BODY:
                __execCLAXX_BODY(nodeLink);
                break;
            case CLAXX_MEMBER:
                __execCLAXX_MEMBER(nodeLink, thread);
                break;
            case CLAXX_FUNC_CALL:
                __execCLASS_FUNC_CALL(nodeLink, thread);
                break;
            case VAR_DECLARE:
                __execVAR_DECLARE(nodeLink, thread);
                break;
            case KEY_RESTRICT:
                __execRESTRICT(nodeLink, thread);
                break;
            case KEY_THIS:
                __execTHIS(nodeLink, thread);
                break;
            case KEY_TRY:
                __execXTRY(nodeLink, thread);
                break;
            case LEFT_SHIFT:
                __execLEFT_SHIFT(nodeLink, thread);
                break;
            case RIGHT_SHIFT:
                __execRIGHT_SHIFT(nodeLink, thread);
                break;
            case KEY_IS:
                __execXIS(nodeLink, thread);
                break;
            case SCOPE:
                __execSCOPE(nodeLink, thread);
                break;
            case KEY_REQUIRE:
                __execREQUIRE(nodeLink, thread);
                break;
            case KEY_REQUIRE_ONCE:
                __execREQUIRE_ONCE(nodeLink, thread);
                break;
            case KEY_INCLUDE:
                __execINCLUDE(nodeLink, thread);
                break;
            case KEY_REF:
                __execREF(nodeLink);
                break;
            case KEY_CONTINUE:
                __execCONTINUE(nodeLink, thread);
                break;
            case OPR_NODE_LIST:
                __execNODE_LIST(nodeLink, thread);
                break;
            case OPR_GET_NAME_SPACE:
                __execGET_NAME_SPACE(nodeLink, thread);
                break;
            case OPR_CHANGE_NAME_SPACE:
                __execCHANGE_NAME_SPACE(nodeLink, thread);
                break;
            case FUNC_OP:
                __execFUNC_OP(nodeLink, thread);
                break;
            case OPR_CLASS_DECLARE:
                __execCLASS_DECLARE(nodeLink, thread);
                break;
            case OPR_IF_ELSE:
                __execIF_ELSE(nodeLink, thread);
                break;
            case KEY_ELSE:
                __execELSE(nodeLink, thread);
                break;
            case OPR_START_IF:
                __execSTART_IF(nodeLink, thread);
                break;
            case OPR_INC_DEC:
                __execINC_DEC(nodeLink, thread);
                break;
            case OPR_ARGS_LIST:
                __execARGS_LIST(nodeLink, thread);
                break;
            default:
                nodeLink->backAfterExec = true;
                logger->error("unknown opr: %d, jump.", node->opr_obj->opr);
                break;
        }
    }

    void __execNode(Node *node) {
        __execNode(node, nullptr);
    }

    void __execNode(Node *node, Node *limitNode) {
        langXThread *thread = getState()->curThread();
        if (node != nullptr) {
            // 如果没给参数， 就暂时进入一个循环做一些事情
            thread->initRootNode(node);
        }

        Node *lastExecNode = nullptr;
        NodeLink *curLink = nullptr;
        while ((curLink = thread->getCurrentExecute()) != nullptr) {
            //  程序没还有结束
            lastExecNode = curLink->node;

            __realExecNode(curLink, thread);     // 将原来的内容丢到一个新的方法里面
            if (thread->isBackInExec()) {
                // 上面方法可能会将  curLink 指向的位置内存被删除， 判定下两个值是否一致， 不一致则重新执行
                thread->setBackInExec(false);
                NodeLink *tmpNodeLink = thread->getCurrentExecute();
                if (tmpNodeLink == nullptr) {
                    break;            // 栈顶已经没有元素
                }
                if (tmpNodeLink != curLink) {
                    // tmpNodeLink 是最新的数据
                    if (tmpNodeLink->node == limitNode) {
                        // 强制跳跃到 限制节点了， 直接退出循环
                        thread->endExecute();
                        break;
                    }

                    continue;
                }
            }

            if (curLink->next == nullptr && curLink->backAfterExec) {
                // will end execute .
                Node *tmpNode = curLink->node;
                thread->endExecute();

                if (tmpNode == limitNode) {
                    break;
                }
            }
        }

        // 处理下一些后续的操作
        if (lastExecNode) {
            doSuffixOperation(lastExecNode);
            lastExecNode = nullptr;
        }

    }
}