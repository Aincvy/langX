//
// Created by Aincvy(aincvy@gmail.com) on 2020/11/7.
//
// 面向对象相关的节点内容的执行
// 类的声明相关，   this 语句，  类或者对象的属性取出行为，  类或者对象的方法调用行为
// new, delete 语句

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
#include "Environment.h"
#include "XArray.h"
#include "XNameSpace.h"

namespace langX{

    void __execNEW(NodeLink *nodeLink, langXThread *thread) {
        Node *n = nodeLink->node;
        // new 一个对象
        nodeLink->backAfterExec = false;
        Node *argNode = n->opr_obj->op[1];
        if (nodeLink->index == 0) {
            nodeLink->index = 1;

            char *className = n->opr_obj->op[0]->var_obj->name;
            ClassInfo *claxxInfo = getState()->getClass(className);
            if (claxxInfo == NULL)
            {
                thread->throwException(newClassNotFoundException(className)->addRef());
                return;
            }
            langXObject *object = claxxInfo->newObject();
            if (object == NULL)
            {
                thread->throwException(newClassNotFoundException(className)->addRef());
                return;
            }
            langXObjectRef * objectRef = object->addRef();
            objectRef->setEmergeEnv(thread->getCurrentEnv());
            n->value = objectRef;

            if (argNode != NULL)
            {
                XArgsList *args = (XArgsList *)argNode->ptr_u;
                object->callConstructor(args, fileInfoString(n->fileinfo).c_str(), nodeLink, thread);
            }
            else {
                object->callConstructor(nullptr, fileInfoString(n->fileinfo).c_str(), nodeLink, thread);
            }

            return;        // 先出去运算参数
        }
        else {
            langXObjectRef * objectRef = (langXObjectRef *)n->value;
            langXObject *object = objectRef->getRefObject();
            if (argNode != NULL)
            {
                XArgsList *args = (XArgsList *)argNode->ptr_u;
                object->callConstructor(args, fileInfoString(n->fileinfo).c_str(), nodeLink, thread);
            }
            else {
                object->callConstructor(nullptr, fileInfoString(n->fileinfo).c_str(), nodeLink, thread);
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

        if (n1->value == NULL)
        {
            //printf("left value %s is not class object or array  !\n", n1->var_obj->name);
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
                char tmp[100] = { 0 };
                sprintf(tmp, "no member %s in array.", memberName);
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
                char tmp[100] = { 0 };
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
        if (n->ptr_u != NULL)
        {
            delete ((langXObjectRef*)n->ptr_u);
            n->ptr_u = NULL;
        }
        n->ptr_u = objectRef->clone();

        Function *func1 = objectRef->getFunction("operator.");
        if (func1)
        {
            X3rdArgs _3rdArgs;
            memset(&_3rdArgs, 0, sizeof(X3rdArgs));
            String astr(memberName);
            _3rdArgs.args[0] = &astr;
            _3rdArgs.index = 1;
            n->value = callFunction(objectRef, func1, &_3rdArgs);

            freeSubNodes(n);
            return;
        }

        Object *t = objectRef->getMember(memberName);
        if (t == NULL || (t != NULL && t->isLocal()))
        {
            // 变量未找到， 或者变量是一个local

            // check 函数  回头再check
            Function *func = objectRef->getFunction(memberName);
            if (func != nullptr)
            {
                FunctionRef *fr = Allocator::allocateFunctionRef(func);
                fr->setObj(objectRef->getRefObject());
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

        freeSubNodes(n);
    }



    // 执行 this.xxx
    void __execTHIS(NodeLink *nodeLink, langXThread *thread) {
        Node *n = nodeLink->node;
        Node *n1 = n->opr_obj->op[0];
        nodeLink->backAfterExec = false;

        if (nodeLink->index == 0) {
            Environment * env = thread->getNearestObjectEnv();
            if (!env)
            {
                thread->throwException(newUnsupportedOperationException("invalid this stmt! cannot find the object on use this!")->addRef());
                return;
            }

            ObjectBridgeEnv *objEnv = (ObjectBridgeEnv*)env;
            if (n->opr_obj->op_count <= 0)
            {
                // no args.  获得自己就好了
                n->value = objEnv->getEnvObject()->addRef();
                nodeLink->backAfterExec = true;
                return;
            }

            thread->newEnvByBridge(env);

            langXObject *thisObj = objEnv->getEnvObject();

            // 如果重复调用这个节点，则释放之前产生的内存 ， 以防内存泄漏
            if (n->var_obj != NULL)
            {
                if (n->var_obj->name != NULL)
                {
                    free(n->var_obj->name);
                    n->var_obj->name = NULL;
                }

                free(n->var_obj);
                n->var_obj = NULL;
            }

            //  产生变量的名字
            n->var_obj = (Variable*)calloc(1, sizeof(Variable));
            if (n1->type == NODE_VARIABLE)
            {
                n->var_obj->name = strdup(n1->var_obj->name);
                if (!thisObj->hasMember(n->var_obj->name))
                {
                    // 没有那个成员
                    char tmp[100] = { 0 };
                    sprintf(tmp, "no class member %s in class %s!", n->var_obj->name, thisObj->getClassName());
                    thread->throwException(newNoClassMemberException(tmp)->addRef());
                    free(n->var_obj->name);
                    free(n->var_obj);
                    n->var_obj = NULL;
                    return;
                }
            }
            else if (n1->type == NODE_OPERATOR)
            {
                // 语法解释器并没有实现这部分， 所以暂时先不管。
                n->var_obj->name = strdup(n1->opr_obj->op[1]->var_obj->name);
            }

            thread->beginExecute(n1, true);
            nodeLink->index = 1;
            return;
        }

        if (n1->value == NULL)
        {
            //printf("error in __execTHIS, n1->value == NULL");
            thread->throwException(newException("error in __execTHIS, n1->value == NULL")->addRef());
        }
        else {
            n->value = n1->value->clone();
        }

        thread->backEnv();
        freeSubNodes(n);
        nodeLink->backAfterExec = true;
    }



    void __execSCOPE_FUNC_CALL(NodeLink *nodeLink, langXThread *thread) {
        Node *n = nodeLink->node;

        nodeLink->backAfterExec = false;      // 函数需要执行两次 才会获取到结果

        // 根据语法文件可知 n1 是一个SCOPE 类型
        Node *n1 = n->opr_obj->op[0];
        ClassInfo *claxxInfo = nullptr;
        char *className = n1->opr_obj->op[0]->var_obj->name;
        char *memberName = n1->opr_obj->op[1]->var_obj->name;
        NodeLink *putNodeLink = nullptr;
        const char *remark = fileInfoString(n->fileinfo).c_str();

        if (nodeLink->index == 0) {
            // 进行一些检测和处理参数
            nodeLink->index = 1;
            putNodeLink = newNodeLink(nullptr, n);
            nodeLink->ptr_u = putNodeLink;

            claxxInfo = getState()->getClass(className);
            if (claxxInfo == NULL)
            {
                thread->throwException(newClassNotFoundException(className)->addRef());
                return;
            }

            Function *t = claxxInfo->getFunction(memberName);
            if (t == NULL)
            {
                char tmp[100] = { 0 };
                sprintf(tmp, "no function %s in class %s.", memberName, className);
                thread->throwException(newNoClassMemberException(tmp)->addRef());
                return;
            }

            ClassBridgeEnv *env = new ClassBridgeEnv(claxxInfo);
            getState()->curThread()->newEnv(env);

            // 根据语法解析文件得知， 第二个节点为参数节点
            XArgsList *args = (XArgsList *)n->opr_obj->op[1]->ptr_u;
            callFunc(t, args, remark, putNodeLink);        // 首次执行 确定参数
            return;
        }
        else {
            putNodeLink = (NodeLink*)nodeLink->ptr_u;
        }

        claxxInfo = getState()->getClass(className);
        Function *t = claxxInfo->getFunction(memberName);

        // 根据语法解析文件得知， 第二个节点为参数节点
        XArgsList *args = (XArgsList *)n->opr_obj->op[1]->ptr_u;
        n->value = callFunc(t, args, remark, putNodeLink);

        doSuffixOperationArgs(args);
        n1->value = NULL;

        getState()->curThread()->backEnv();
        nodeLink->backAfterExec = true;
    }



    void __execSCOPE(NodeLink *nodeLink, langXThread *thread) {
        Node *n = nodeLink->node;

        char *className = n->opr_obj->op[0]->var_obj->name;
        ClassInfo *claxxInfo = getState()->getClass(className);
        if (claxxInfo == NULL)
        {
            thread->throwException(newClassNotFoundException(className)->addRef());
            return;
        }

        char *memberName = n->opr_obj->op[1]->var_obj->name;
        Object *t = claxxInfo->getMember(memberName);
        if (t == NULL || (t != NULL && t->isLocal()))
        {
            Function * tf = claxxInfo->getFunction(memberName);
            if (tf == NULL)
            {
                char tmp[100] = { 0 };
                sprintf(tmp, "no member %s in class %s.", memberName, className);
                thread->throwException(newNoClassMemberException(tmp)->addRef());
                return;
            }

            FunctionRef *fr = Allocator::allocateFunctionRef(tf);
            fr->setClaxx(claxxInfo);
            fr->setEmergeEnv(getState()->curThread()->getCurrentEnv());
            t = fr;
        }

        n->value = t->clone();
        nodeLink->backAfterExec = true;
    }


    // 引入命名空间或者类
    void __execREF(NodeLink *nodeLink) {
        Node *n = nodeLink->node;

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

        char *namespaceName = n->opr_obj->op[0]->con_obj->sValue;

        std::string str = std::string(namespaceName);
        XNameSpace *space = NULL;
        bool flag = true;

        auto dotIndex = str.find_first_of(".");

        while (dotIndex != std::string::npos)
        {
            std::string f = str.substr(0, dotIndex);
            str = str.substr(dotIndex + 1);
            dotIndex = str.find_first_of(".");

            // f is namespace name
            if (flag)
            {
                space = getState()->singleGetNameSpace(f.c_str());
                if (space == NULL)
                {
                    break;
                }

                flag = false;
            }
            else {
                space = space->getNameSpace(f.c_str());
                if (space == NULL)
                {
                    break;
                }
            }
        }

        if (flag)
        {
            space = getState()->singleGetNameSpace(str.c_str());
        }

        if (space == NULL)
        {
            //  error.  cannot find the namespace.
            char tmp[1024] = { 0 };
            sprintf(tmp, "cannot find namespace %s.", namespaceName);
            getState()->curThread()->throwException(newException(tmp)->addRef());
            return;
        }

        XNameSpace *retSpace = nullptr;
        ClassInfo *retClass = nullptr;

        if (flag)
        {
            //  str 是用掉了已经

            retSpace = space;
        }
        else {
            ClassInfo *c = space->getClass(str.c_str());
            if (c != NULL)
            {
                // 添加类
                retClass = c;
            }
            else {
                space = space->getNameSpace(str.c_str());

                if (space == NULL)
                {
                    //  error.  cannot find the namespace.
                    char tmp[1024] = { 0 };
                    sprintf(tmp, "cannot find namespace %s.", namespaceName);
                    getState()->curThread()->throwException(newException(tmp)->addRef());
                    return;
                }
                retSpace = space;
            }
        }

        if (eType == TScriptEnvironment)
        {
            ScriptEnvironment *scriptEnv = (ScriptEnvironment*)env;
            if (retSpace != nullptr)
            {
                scriptEnv->addNameSpace(retSpace);
            }
            if (retClass != nullptr)
            {
                scriptEnv->addClassInfo(retClass);
            }

        }
        else if (eType == TXNameSpaceEnvironment)
        {
            XNameSpaceEnvironment *nsEnv = (XNameSpaceEnvironment*)env;
            if (retSpace != nullptr)
            {
                nsEnv->getNameSpace()->addRefNamespace(retSpace);
            }
            if (retClass != nullptr)
            {
                nsEnv->putClass(retClass->getName(), retClass);
            }
        }

        nodeLink->backAfterExec = true;
    }



}