/************************************************************************************//**
 *  @file       LogManager.cpp
 *
 *  @brief      Brief descriptinon of LogManager.cpp
 *
 *  @date       2018-02-27 15:42
 *
 ***************************************************************************************/

#include <log4cpp/PropertyConfigurator.hh>

#include "LogManager.h"
#include "langXCommon.h"
#include "Utils.h"

// 简略的 va 形式
#define LOG_VA_WORKER(msg, level) \
va_list ap;                 \
va_start(ap,msg);           \
vLog(level, msg, ap);       \
va_end(ap)


namespace langX {

    Logger *logger = nullptr;
    Logger *nodeLogger = nullptr;
    Logger *moduleLogger = nullptr;

    const char *getLoggerLevelString(LoggerLevel level) {

        switch (level) {
            case TRACE:
                return "TRACE";
            case DEBUG:
                return "DEBUG";
            case INFO:
                return "INFO";
            case WARN:
                return "WARN";
            case ERROR:
                return "ERROR";
            case FATAL:
                return "FATAL";
        }

        return "";
    }


    LogManager::LogManager() {
		this->m_category = nullptr;
	};

	LogManager::~LogManager() {
		// 析构函数

	};

	void LogManager::init(const char *path) {
		log4cpp::PropertyConfigurator::configure(path);
		log4cpp::Category& root = log4cpp::Category::getInstance("console");
		this->m_category = &root;
		langX::logger = new Logger(this->m_category, "");

		// node
		auto & tmp = log4cpp::Category::getInstance("node");
		this->m_nodeCategory = &tmp;
        langX::nodeLogger = new Logger(this->m_nodeCategory, "");

        auto & module = log4cpp::Category::getInstance("module");
        this->m_moduleCategory = & module;
        langX::moduleLogger = new Logger(this->m_moduleCategory, "");

	}

    Logger *LogManager::requireNewModuleLogger() {
	    auto tmp = new Logger();
	    tmp->setLogger(this->m_moduleCategory);
        return tmp;
    }


    Logger::Logger() {

    }

    Logger::~Logger() {

    }


    Logger::Logger(log4cpp::Category *logger, const char *prefix) {
        this->m_logger = logger;
        this->m_prefix = prefix;
    }

    void Logger::trace(const char *msg, ...) {
        LOG_VA_WORKER(msg, LoggerLevel::TRACE);
    }

    void Logger::debug(const char *msg, ...) {
        LOG_VA_WORKER(msg, LoggerLevel::DEBUG);
    }

    void Logger::info(const char *msg, ...) {
        LOG_VA_WORKER(msg, LoggerLevel::INFO);
    }

    void Logger::warn(const char *msg, ...) {
        LOG_VA_WORKER(msg, LoggerLevel::WARN);
    }

    void Logger::error(const char *msg, ...) {
        LOG_VA_WORKER(msg, LoggerLevel::ERROR);
    }

    void Logger::fatal(const char *msg, ...) {
        LOG_VA_WORKER(msg, LoggerLevel::FATAL);
    }

    void Logger::vLog(LoggerLevel loggerLevel, const char *msg, va_list ap) {
        RETURN_IF_NULL(m_logger);

        auto levelString = "";
        if (loggerLevel == LoggerLevel::TRACE) {
            levelString = getLoggerLevelString(loggerLevel);
        }

        auto prefix = this->m_prefix;
        if (prefix == nullptr) {
            prefix = "NO-PREFIX";
        }

        // 调整输出的消息
        char buf[DEFAULT_CHAR_BUFFER_SIZE] = { 0 };

        if (isEmpty(levelString)) {
            if (isEmpty(prefix)) {
                sprintf(buf, "%s", msg);        // 无prefix ,无 level string ， 就简单的输出了把
            } else {
                sprintf(buf, "[%s] %s", prefix, msg);
            }
        } else {
            sprintf(buf, "[%s] [%s] %s", prefix, levelString, msg);
        }

        // 输出消息
        switch (loggerLevel) {
            case TRACE:
                m_logger->logva(log4cpp::Priority::NOTICE, buf, ap);
                break;
            case DEBUG:
                m_logger->logva(log4cpp::Priority::DEBUG, buf, ap);
                break;
            case INFO:
                m_logger->logva(log4cpp::Priority::INFO, buf, ap);
                break;
            case WARN:
                m_logger->logva(log4cpp::Priority::WARN, buf, ap);
                break;
            case ERROR:
                m_logger->logva(log4cpp::Priority::ERROR, buf, ap);
                break;
            case FATAL:
                m_logger->logva(log4cpp::Priority::FATAL, buf, ap);
                break;
        }
    }


    const char *Logger::getPrefix() {
        return this->m_prefix;
    }

    void Logger::setPrefix(const char* prefix) {
        this->m_prefix = prefix;
    }

    void Logger::setLogger(log4cpp::Category *logger) {
        this->m_logger = logger;
    }

    log4cpp::Category *Logger::getLogger() {
        return this->m_logger;
    }



}