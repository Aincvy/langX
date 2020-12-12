/*************************************************************************************//**
 *  @file       LogManager.h
 *
 *  @brief      Brief description of LogManager.h
 *
 *  @date       2018-02-27 15:35
 *         
 **************************************************************************************/


#ifndef LOGMANAGER_H
#define LOGMANAGER_H

#include <stdarg.h>
#include <log4cpp/Category.hh>

namespace langX {


    class Logger;

    class LogManager {

    public:

        LogManager();

        ~LogManager();

        // 初始化日志管理器
        void init(const char *);

        /**
         * 申请一个用于输出 module 类型的日志对象
         * 返回的对象是一个new出来的对象， 接收者应该自行管理接收到的对象
         * @return
         */
        Logger * requireNewModuleLogger();

    private:
        // 默认的日志输出
        log4cpp::Category *m_category;
        // 节点日志的内容
        log4cpp::Category *m_nodeCategory;
        // 模块的日志
        log4cpp::Category *m_moduleCategory;

    };


    /**
     * 日志级别
     */
    enum LoggerLevel{
        // 跟踪
        TRACE,
        // 调试
        DEBUG,
        // 信息
        INFO,
        // 警告
        WARN,
        // 错误
        ERROR,
        // 致命
        FATAL,
    };

    /**
     * 日志类， 用于输出一些日志消息
     */
    class Logger {

    public:
        // 构造方法
        Logger();
        // 解构方法
        ~Logger();

        /**
         * 使用一个 log4cpp 的logger 和前缀初始化当前的logger
         * @param logger
         * @param prefix
         */
        Logger(log4cpp::Category *logger, const char *prefix);


        /**
         * trace 级别的日志
         * @param msg
         * @param ...
         */
        void trace(const char* msg, ...);

        /**
         * debug 级别的日志
         * @param msg
         * @param ...
         */
        void debug(const char* msg, ...);

        /**
         * info 级别的日志
         * @param msg
         * @param ...
         */
        void info(const char* msg, ...);

        /**
         * 警告级别的日志
         * @param msg
         * @param ...
         */
        void warn(const char* msg, ...);

        /**
         * 错误级别的日志
         * @param msg
         * @param ...
         */
        void error(const char* msg, ...);

        /**
         * 致命级别的错误
         * @param msg
         * @param ...
         */
        void fatal(const char* msg, ...);

        /**
         * 打印日志
         * @param loggerLevel
         * @param msg
         * @param ap
         */
        void vLog(LoggerLevel loggerLevel, const char* msg, va_list ap);

        /**
         * 获取当前日志对象的前缀
         * @return
         */
        const char * getPrefix();

        /**
         * 设置当前日志对象的前缀
         */
        void setPrefix(const char *);

        /**
        * 设置一个logger
        * @param logger
        */
        void setLogger(log4cpp::Category *logger);

        /**
         * 获取一个logger
         * @return
         */
        log4cpp::Category* getLogger();

    private:

        // 私有方法

        // 私有变量
        log4cpp::Category *m_logger = nullptr;

        // 日志的前缀
        const char* m_prefix = nullptr;
    };


    // 日志变量

    extern Logger *logger;
    extern Logger *nodeLogger;
    extern Logger *moduleLogger;

    // 其他的函数
    const char * getLoggerLevelString(LoggerLevel level);

};


#endif /* !LOGMANAGER_H */

