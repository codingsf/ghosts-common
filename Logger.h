#ifndef LOGGER_H
#define LOGGER_H

#include "ghosts-common_global.h"

#include <string>

class GHOSTSCOMMONSHARED_EXPORT Logger
{
public:
    enum LogLevel {
        Error = 0,
        Warning = 1,
        Info = 2,
        Debug = 3
    };
    
    static void setLogLevel(LogLevel level);
    static LogLevel logLevel();
    
    static void error(const std::string &message);
    static void warning(const std::string &message);
    static void info(const std::string &message);
    static void debug(const std::string &message);
    
private:
    static LogLevel m_logLevel;
    
    static void printLocalTime();
};

#endif // LOGGER_H
