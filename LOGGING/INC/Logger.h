/************************************/
/*	Author	  :	Nour Abdel-aziz		*/
/*	SWC		  : logger_APP			*/
/*	Version	  :	1.1		  			*/
/*	Date	  :	Febraury 27, 2024	*/
/*	Last Edit :	Febraury 29, 2024	*/
/************************************/
#ifndef LOGGER_H
#define LOGGER_H

#include <fstream>
#include <ctime>
#include <string>

enum class Severity {
    DEBUG,
    INFO,
    WARNING,
    ERROR
};

class Logger {
public:
    Logger(const std::string& filename);

    void log(Severity severity, const std::string& message);

    void setLogLevel(Severity level);

private:
    std::ofstream m_logFile;
    Severity m_logLevel = Severity::INFO;
};

#endif // LOGGER_H
