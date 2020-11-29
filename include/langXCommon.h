//
// Created by Yo Hello on 2020/10/9.
//
// 主要用于预定义一些内容
//
#pragma once

// yacc debug 标识
#define YYDEBUG 1

// langX 的版本
#define LANGX_VERSION "0.2.1"


// FE:  function extend   函数的扩展内容
// 可变参数的数量 名字
#define FE_KEY_VARIABLE_COUNT "$_"
// 可变参数取值的 前缀名字
#define FE_KEY_VARIABLE_PREFIX "$"

// 上一个函数的执行结果
#define FE_KEY_PREV_RESULT "$?"

// 线程环境深度的初始值
#define THREAD_ENV_DEEP_INITIAL 1

// 默认情况下的字符串缓冲区大小
#define DEFAULT_CHAR_BUFFER_SIZE 1024
