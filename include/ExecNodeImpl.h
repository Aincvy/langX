//
// Created by Aincvy(aincvy@gmail.com) on 2020/11/7.
//

#pragma once

#include "Object.h"
#include "langXThread.h"
#include "NodeCreator.h"

namespace langX {

    // +
// 操作结果， 会将结果存储在当前节点中
    void __exec43(NodeLink *nodeLink);


// -
    void __exec45(NodeLink *nodeLink);

// *
    void __exec42(NodeLink *nodeLink);

// /
    void __exec47(NodeLink *nodeLink);

//  取模运算 %
    void __exec37(NodeLink *nodeLink);


// 按位或  |
    void __exec124(NodeLink *nodeLink);

// 按位与  &
    void __exec38(NodeLink *nodeLink);

// 按位异或  ^
    void __exec94(NodeLink *nodeLink);

// 按位取反  ~
    void __exec126(NodeLink *nodeLink);

// 向左移位
    void __execLEFT_SHIFT(NodeLink *nodeLink);

// 向右移位
    void __execRIGHT_SHIFT(NodeLink *nodeLink);


// 自增运算符 ++
    void __execINC_OP(NodeLink *nodeLink);

// 自减运算符 --
    void __execDEC_OP(NodeLink *nodeLink);


    // 赋值操作 =
    void __exec61(NodeLink *nodeLink, langXThread *thread);

    void __NEW_exec61(NodeLink *nodeLink, langXThread *thread);

    void __execADD_EQ(NodeLink *nodeLink);

    void __execSUB_EQ(NodeLink *nodeLink);

    void __execMUL_EQ(NodeLink *nodeLink);

    void __execDIV_EQ(NodeLink *nodeLink);

    void __execMOD_EQ(NodeLink *nodeLink);


// 中断操作


    void __execBREAK(NodeLink *nodeLink, langXThread *thread);

    void __execRETURN(NodeLink *nodeLink, langXThread *thread);

//  continue 关键字
    void __execCONTINUE(NodeLink *nodeLink, langXThread *thread);


// 分号 ;
    void __exec59(NodeLink *nodeLink, langXThread *thread);

// 逗号表达式
    void __exec44(NodeLink *nodeLink, langXThread *thread);


// 符号： >
    void __exec62(NodeLink *nodeLink);

// 大于等于
    void __execGE_OP(NodeLink *nodeLink);

// 符号： <
    void __exec60(NodeLink *nodeLink);

// 小于等于
    void __execLE_OP(NodeLink *nodeLink);

// 等于
    void __execEQ_OP(NodeLink *nodeLink);

// 不等于
    void __execNE_OP(NodeLink *nodeLink);

    void __execOPAND(NodeLink *nodeLink);

    void __execOPOR(NodeLink *nodeLink);

//  类型判断语句， 返回一个 true/false
    void __execXIS(NodeLink *nodeLink, langXThread *thread);

    // ! 取反
    void __exec33(NodeLink *nodeLink);


    void __execIF(NodeLink *nodeLink, langXThread *thread);

    void __execWHILE(NodeLink *nodeLink, langXThread *thread);

    void __execFOR(NodeLink *nodeLink, langXThread *thread);

    void __execSWITCH(NodeLink *nodeLink, langXThread *thread);

    void __execCASE_LIST(NodeLink *nodeLink, langXThread *thread);

    void __execCASE(NodeLink *nodeLink, langXThread *thread);

    void __execDefault(NodeLink *nodeLink, langXThread *thread);

    void __execUMINUS(NodeLink *nodeLink);

    void __execFUNC_CALL(NodeLink *nodeLink, langXThread *thread);


    void __execNEW(NodeLink *nodeLink, langXThread *thread);

    /**
     * 执行 删除节点
     * @param nodeLink
     * @param thread
     */
    void __execDELETE(NodeLink *nodeLink, langXThread *thread);

    void __execCLAXX_BODY(NodeLink *nodeLink);

// 变量声明
    void __execVAR_DECLAR(NodeLink *nodeLink, langXThread *thread);

    void __execCLAXX_MEMBER(NodeLink *nodeLink, langXThread *thread);

    void __execCLASS_FUNC_CALL(NodeLink *nodeLink, langXThread *thread);

// 执行 this.xxx
    void __execTHIS(NodeLink *nodeLink, langXThread *thread);

    void __execSCOPE(NodeLink *nodeLink, langXThread *thread);

    /**
     * 获取一个 命名空间
     * @param nodeLink
     * @param thread
     */
    void __execGET_NAME_SPACE(NodeLink *nodeLink, langXThread *thread);

    /**
     * 修改命名空间
     * @param nodeLink
     * @param thread
     */
    void __execCHANGE_NAME_SPACE(NodeLink *nodeLink, langXThread *thread);


    void __execRESTRICT(NodeLink *nodeLink, langXThread *thread);


// 执行 try {}
    void __execXTRY(NodeLink *nodeLink, langXThread *thread);


// 引入命名空间或者类
    void __execREF(NodeLink *nodeLink);

//  常量限制
    void __execCONST(NodeLink *nodeLink, langXThread *thread);




    // node 相关的内容

    /*
	  执行这个节点的所有子节点
	*/
    void doSubNodes(Node *n);

    /*
	  释放当前节点的子节点的值 内存 | 只释放一层的值内存
	*/
    void freeSubNodes(Node *n);

    /* 检测一下节点是否存在 值， 如果不存在， 则运算他 */
    void checkValue(Node * node, langXThread *thread);

    /* 如果这个变量不存在， 则new 一个放上去
	   并且会放到当前的环境里面
	   调用这个函数之后 会强制改写 left->value 的值

	   0730 赋值给左值的值为 放入 Environment 里面的值的克隆
	   0820 这个函数只会保证 左节点存在值， 并且值得类型和 右类型一样  这个函数在左值的产生环境中进行操作
	*/
    void checkVarValue(Node *left, ObjectType rightType);

    /*
	将节点的值更新到当前环境中
	*/
    void setValueToEnv(const char*name, Object *val);

    // 将节点的值更新到环境中
    void setValueToEnv2(const char*name, Object *val, Environment *env);

    // 做后缀操作符的 工作 也包括前缀操作符
    void doSuffixOperation(Node *n);

    //  尝试吧这个节点的 值 转换成一个 布尔值。
    // 如果这个节点并没有被运算， 则会运算这个节点
    // 判断之后， 并不会释放这个节点的内存
    bool __tryConvertToBool(Node *n);


    // 状态继承， n 的所有子节点都会继承n的状态
    void stateExtends(Node *n);

    void doSuffixOperationArgs(XArgsList *args);


    // 尝试把 multiple_id 转换成一个 char*[]
    // param n:  MultipleId的最顶层的那个节点
    // param len:  返回的长度, -1表示 参数n 由问题
    char**  convertMultipleId(Node *n, int* len);

    // 释放 有 multipleId 节点转换出来的 char* 类型数组
    void freeMultipleIdResultArray(char **array, int len);


    /**
     * 更新变量的前缀  | 换句话说就是应用变量的前缀
     * @param object 变量值的引用
     * @param prefix 前缀
     */
    void updateVariablePrefix(Object *object, int prefix);



}


