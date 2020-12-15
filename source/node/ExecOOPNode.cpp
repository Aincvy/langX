//
// Created by Aincvy(aincvy@gmail.com) on 2020/11/7.
//
// 面向对象相关的节点内容的执行
// 类的声明相关，   this 语句，  类或者对象的属性取出行为，  类或者对象的方法调用行为
// new, delete 语句

#include <LogManager.h>
#include "ExecNode.h"
#include "ExecNodeImpl.h"
#include "NodeCreator.h"
#include "Exception.h"
#include "Number.h"
#include "StringType.h"
#include "Allocator.h"
#include "ClassInfo.h"
#include "langXObject.h"
#include "Environment.h"
#include "XArray.h"
#include "XNameSpace.h"
#include "langXCommon.h"


namespace langX{

    void __execNEW(NodeLink *nodeLink, langXThread *thread) {
        Node *n = nodeLink->node;
        // new 一个对象
        nodeLink->backAfterExec = false;
        Node *argNode = n->opr_obj->op[1];
        if (nodeLink->index == 0) {
            nodeLink->index = 1;

            char *className = n->opr_obj->op[0]->var_obj->name;
            ClassInfo *classInfo = getState()->getClass(className);
            if (classInfo == nullptr)
            {
                thread->throwException(newClassNotFoundException(className)->addRef());
                return;
            }
            langXObject *object = classInfo->newObject();
            if (object == nullptr)
            {
                thread->throwException(newClassNotFoundException(className)->addRef());
                return;
            }

            langXObjectRef * objectRef = object->addRef();
            objectRef->setEmergeEnv(thread->getCurrentEnv());
            n->value = objectRef;

            doSubNodes(argNode);
            return;        // 先出去运算参数
        }
        else {
            langXObjectRef * objectRef = (langXObjectRef *)n->value;
            langXObject *object = objectRef->getRefObject();
            if (argNode != nullptr)
            {
                ArgsList args;
                convertArgsList(argNode, &args);
                object->callConstructor(&args, fileInfoString(n->fileinfo).c_str(), thread);
            }
            else {
                object->callConstructor(nullptr, fileInfoString(n->fileinfo).c_str(), thread);
            }
        }

        nodeLink->backAfterExec = true;
    }



    void __execCLAXX_MEMBER(NodeLink *nodeLink, langXThread *thread) {
        Node *n = nodeLink->node;
        Node *n1 = n->opr_obj->op[0];
        nodeLink->backAfterExec = false;
        if (nodeLink->index == 0) {
            //  执行节点1， 获得 类对象
            thread->beginExecute(n1, true);
            nodeLink->index = 1;
            return;
        }

        if (n1->value == nullptr)
        {
            char tmp[100] = { 0 };
            sprintf(tmp, "left value %s is not class object or array  !\n", n1->var_obj->name);
            thread->throwException(newTypeErrorException(tmp)->addRef());
            freeSubNodes(n);
            return;
        }

        char *memberName = n->opr_obj->op[1]->var_obj->name;

        nodeLink->backAfterExec = true;
        //    先处理数组和字符串的情况
        if (n1->value->getType() == XARRAY)
        {
            XArrayRef *arrayRef = (XArrayRef*)n1->value;
            // 如果是数组， 则执行
            if (strcmp(memberName, "length") == 0)
            {
                // array.length.
                n->value = Allocator::allocateNumber(arrayRef->getLength());
            }
            else {
                char tmp[DEFAULT_MIN_CHAR_BUFF_SIZE] = { 0 };
                sprintf(tmp, "no member %s in array type.", memberName);
                thread->throwException(newNoClassMemberException(tmp)->addRef());
            }

            freeSubNodes(n);
            return;
        }
        else if (n1->value->getType() == STRING) {
            String * str = (String*)n1->value;
            if (strcmp(memberName, "length") == 0)
            {
                // string.length.
                n->value = Allocator::allocateNumber(str->size());
            }
            else {
                char tmp[DEFAULT_MIN_CHAR_BUFF_SIZE] = { 0 };
                sprintf(tmp, "no member %s in string.", memberName);
                thread->throwException(newNoClassMemberException(tmp)->addRef());
            }

            freeSubNodes(n);
            return;
        }

        //  处理 object 的情况
        if (n1->value->getType() != OBJECT)
        {
            thread->throwException(newTypeErrorException("left value is not a object.")->addRef());
            freeSubNodes(n);
            return;
        }

        langXObjectRef* objectRef = (langXObjectRef*)n1->value;

        // set ptr_u first,  等号的处理部分会用这个属性
        if (n->ptr_u != nullptr)
        {
            delete ((langXObjectRef*)n->ptr_u);
            n->ptr_u = nullptr;
        }
        n->ptr_u = objectRef->clone();

        Function *func1 = objectRef->getFunction("operator.");
        if (func1)
        {
            String tmpStr(memberName);

            // 执行操作符重载
            auto locationString = "<call by operator.> " + fileInfoString(n->fileinfo);
            n->value = callFunction(thread, func1, objectRef->getRefObject(), locationString.c_str(), 1, &tmpStr);

            freeSubNodes(n);
            return;
        }

        Object *t = objectRef->getMember(memberName);
        FunctionRef *fr = nullptr;
        if (t == nullptr || t->isLocal())
        {
            // 变量未找到， 或者变量是一个local

            // check 函数  回头再check
            Function *func = objectRef->getFunction(memberName);
            if (func != nullptr)
            {
                fr = Allocator::allocateFunctionRef(func);
                fr->setObject(objectRef->getRefObject());
                fr->setEmergeEnv(getState()->curThread()->getCurrentEnv());
                t = fr;
            }
            else {
                char tmp[100] = { 0 };
                sprintf(tmp, "no member %s in class %s.", memberName, objectRef->getClassInfo()->getName());
                thread->throwException(newNoClassMemberException(tmp)->addRef());
                freeSubNodes(n);
                return;
            }
        }
        n->value = t->clone();

        // 清理函数指针
        if (fr != nullptr) {
            Allocator::freeFunctionRef(fr);
            fr = nullptr;
            t = nullptr;
        }

        freeSubNodes(n);
    }



    // 执行 this  关键字， 获取当前对象
    void __execTHIS(NodeLink *nodeLink, langXThread *thread) {
        Node *n = nodeLink->node;

        Environment * env = thread->getNearestObjectEnv();
        if (!env)
        {
            thread->throwException(newUnsupportedOperationException("invalid this stmt! cannot find the object on use this!")->addRef());
            return;
        }

        auto objEnv = (ObjectBridgeEnv*)env;
        n->value = objEnv->getEnvObject()->addRef();
    }


    void __execSCOPE(NodeLink *nodeLink, langXThread *thread) {
        Node *n = nodeLink->node;

        char *className = n->opr_obj->op[0]->var_obj->name;
        ClassInfo *classInfo = getState()->getClass(className);
        if (classInfo == nullptr)
        {
            thread->throwException(newClassNotFoundException(className)->addRef());
            return;
        }

        char *memberName = n->opr_obj->op[1]->var_obj->name;
        Object *tmp = classInfo->getMember(memberName);
        FunctionRef *ref = nullptr;
        if (tmp == nullptr || tmp->isLocal())
        {
            Function * func = classInfo->getFunction(memberName);
            if (func == nullptr)
            {
                char tmpMsg[DEFAULT_MIN_CHAR_BUFF_SIZE] = {0 };
                sprintf(tmpMsg, "no member %s in class %s.", memberName, className);
                thread->throwException(newNoClassMemberException(tmpMsg)->addRef());
                return;
            }

            ref = Allocator::allocateFunctionRef(func);
            ref->setClassInfo(classInfo);
            ref->setEmergeEnv(getState()->curThread()->getCurrentEnv());
            tmp = ref;
        }

        n->value = tmp->clone();
        nodeLink->backAfterExec = true;

        // 释放内存
        if (ref != nullptr) {
            Allocator::freeFunctionRef(ref);
            ref = nullptr;
        }

    }


    // 引入命名空间或者类
    void __execREF(NodeLink *nodeLink) {
        Node *n = nodeLink->node;

        if (nodeLink->index == 0) {
            nodeLink->index = 1;
            doSubNodes(n);
            return;
        }

        //  深度为1 的环境为一个 脚本环境 或者命名空间环境。
        Environment *env = getState()->getScriptOrNSEnv();
        if (env == nullptr)
        {
            // error.
            getState()->curThread()->throwException(newUnsupportedOperationException("cannot ref operation now!")->addRef());
            return;
        }

        EnvironmentType eType = env->getType();
        if (eType != TScriptEnvironment
            && eType != TXNameSpaceEnvironment)
        {
            getState()->curThread()->throwException(newUnsupportedOperationException("cannot ref not inner a script or namespace! check are you ok?")->addRef());
            return;
        }


        auto nsNode = n->opr_obj->op[0];
        auto space = (XNameSpace*) nsNode->ptr_u;

        // reset ...
        nsNode->ptr_u = nullptr;

        // some check ...
        if (space == nullptr)
        {
            //  error.  cannot find the namespace.
            logger->error("something wrong, cannot find namespace ..") ;
            // return;
        }

        XNameSpace *retSpace = space;

        if (eType == TScriptEnvironment)
        {
            ScriptEnvironment *scriptEnv = (ScriptEnvironment*)env;
            if (retSpace != nullptr)
            {
                scriptEnv->addNameSpace(retSpace);
            }
        }
        else if (eType == TXNameSpaceEnvironment)
        {
            XNameSpaceEnvironment *nsEnv = (XNameSpaceEnvironment*)env;
            if (retSpace != nullptr)
            {
                nsEnv->getNameSpace()->addRefNamespace(retSpace);
            }
        }

        nodeLink->backAfterExec = true;
    }


    void __execDELETE(NodeLink *nodeLink, langXThread *thread){

        // todo delete opr
        logger->info("delete opr is not impl now.");

    }

    void __execGET_NAME_SPACE(NodeLink *nodeLink, langXThread *thread){
        if (nodeLink->index == 0) {
            nodeLink->index = 1;
            doSubNodes(nodeLink->node);
            return;
        }

        auto node = nodeLink->node;
        auto opr_obj = node->opr_obj;

        // 由 a.y语法文件得知， 第二个元素是一个 子命名空间的名字
        auto name = opr_obj->op[1]->var_obj->name;
        auto oldSpaceNode = opr_obj->op[0];
        XNameSpace * nameSpace = nullptr;
        // 如果找不到命名空间， 是否创建它？
        auto createNameSpace = thread->getStackTraceTopStatus().createNameSpace;

        if (oldSpaceNode == nullptr) {
            // 直接从 全局空间中获取
            nameSpace = createNameSpace ? getState()->singleGetNameSpaceOrCreate(name) : getState()->singleGetNameSpace(name);
        } else {
            // 从前一个命名空间中获取新的值
            auto firstSon = opr_obj->op[0];

            // 从先前的空间中再尝试获取子空间
            auto prevNamespace = (XNameSpace*) firstSon->ptr_u;
            nameSpace = createNameSpace ?
                    prevNamespace->getNameSpaceWithCreate(name) :
                    prevNamespace->getNameSpace(name);

            firstSon->ptr_u = nullptr;    // reset field.
        }

        // 检测指定的命名空间是否存在
        if (nameSpace == nullptr) {
            char buf[1024];
            sprintf(buf, "namespace %s not found", name);
            thread->throwException(newNamespaceNotFoundException(buf)->addRef());
            return;
        }

        node->ptr_u = nameSpace;
    }


    void __execCHANGE_NAME_SPACE(NodeLink *nodeLink, langXThread *thread){
        if (nodeLink->index == 0) {
            nodeLink->index = 1;

            // 标记当前需要创建命名空间
            thread->getStackTraceTopStatus().createNameSpace = true;

            doSubNodes(nodeLink->node);
            return;
        }

        // 取消需要创建命名空间的标记
        thread->getStackTraceTopStatus().createNameSpace = false;

        auto nsNode = nodeLink->node->opr_obj->op[0];
        auto ns = (XNameSpace*) nsNode->ptr_u;
        if (ns == nullptr) {
            // something wrong ...
            logger->error("something wrong, cannot get namespace..");
        }

        // change ?
        getState()->changeNameSpace(ns);
        nodeLink->backAfterExec = true;

        // reset
        nsNode->ptr_u = nullptr;
    }



}