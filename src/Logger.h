#pragma once
#include <string>
#include "noncopyable.h"

#define LOG_INFO(LogmsgFormat, ...) \
    do \
    { \
        Logger &logger = Logger::instance(); \
        logger.setLogLevel(INFO); \
        char buf[1024] = {0}; \
        snprintf(buf, 1024, logmsgFormat, ##__VA_ASGS__); \
        logger.log(buf); \
    } while(0)

#define LOG_ERROR(LogmsgFormat, ...) \
    do \
    { \
        Logger &logger = Logger::instance(); \
        logger.setLogLevel(ERROR); \
        char buf[1024] = {0}; \
        snprintf(buf, 1024, logmsgFormat, ##__VA_ASGS__); \
        logger.log(buf); \
    } while(0)

#define LOG_FATAL(LogmsgFormat, ...) \
    do \
    { \
        Logger &logger = Logger::instance(); \
        logger.setLogLevel(FATAL); \
        char buf[1024] = {0}; \
        snprintf(buf, 1024, logmsgFormat, ##__VA_ASGS__); \
        logger.log(buf); \
    } while(0)

#ifdef MUDEBUG
#define LOG_DEBUG(LogmsgFormat, ...) \
    do \
    { \
        Logger &logger = Logger::instance(); \
        logger.setLogLevel(DEBUG); \
        char buf[1024] = {0}; \
        snprintf(buf, 1024, logmsgFormat, ##__VA_ASGS__); \
        logger.log(buf); \
    } while(0)
#else
    #define LOG_DEBUG(LogmsgFormat, ...)
#endif

enum LogLevel{
    INFO,
    ERROR,
    FATAL,
    DEBUG,
};

class Logger : noncopyable{
public:
    //获取日志唯一的实例对象
    static Logger& instance();

    //设置日志级别
    void setLogLevel(int level);

    //写日志
    void log(std::string msg);

private:
    int logLevel_;
};