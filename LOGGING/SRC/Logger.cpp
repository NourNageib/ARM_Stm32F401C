/************************************/
/*	Author	  :	Nour Abdel-aziz		*/
/*	SWC		  : logger_APP			*/
/*	Version	  :	1.1		  			*/
/*	Date	  :	Febraury 27, 2024	*/
/*	Last Edit :	Febraury 29, 2024	*/
/************************************/

#include "Logger.h"

Logger::Logger(const std::string& filename) : m_logFile(filename, std::ios_base::app) {}

void Logger::log(Severity severity, const std::string& message) {
    if (severity >= m_logLevel) {
        std::time_t now = std::time(nullptr);
        char timestamp[64];
        std::strftime(timestamp, sizeof(timestamp), "%Y-%m-%d %H:%M:%S", std::localtime(&now));

        m_logFile << "[" << timestamp << "] ";

        switch (severity) {
            case Severity::DEBUG:
                m_logFile << "[DEBUG] ";
                break;
            case Severity::INFO:
                m_logFile << "[INFO] ";
                break;
            case Severity::WARNING:
                m_logFile << "[WARNING] ";
                break;
            case Severity::ERROR:
                m_logFile << "[ERROR] ";
                break;
        }

        m_logFile << message << std::endl;
    }
}

void Logger::setLogLevel(Severity level) {
    m_logLevel = level;
}
