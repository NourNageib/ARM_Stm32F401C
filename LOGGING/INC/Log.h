#ifndef LOG_H
#define LOG_H

#include <string>

enum class LoggingLevel {
    INFO,
    WARNING,
    ERROR,
    CRITICAL
};

class Logger {
public:
    static void log(const std::string& message, LoggingLevel level = LoggingLevel::INFO);
};

#endif
