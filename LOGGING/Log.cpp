#include "Log.h"
#include <iostream>
#include <fstream>
#include <chrono>
#include <ctime>

void Logger::log(const std::string& message, LoggingLevel level) {
    // Get current time with a timestamp
    auto now = std::chrono::system_clock::now();
    std::time_t now_time = std::chrono::system_clock::to_time_t(now);
    std::string timestamp = std::ctime(&now_time);

    // Open log file in append mode
    std::ofstream logfile("project_loggig.txt", std::ios::app);
    
    // Log message with timestamp
    if (logfile.is_open()) {
        logfile << "(" << timestamp.substr(0, timestamp.length() - 1) << ") ";

        // Filter logging messages based on critical level
        switch (level) {
            case LoggingLevel::INFO:
                logfile << "[INFO] ";
                break;
            case LoggingLevel::WARNING:
                logfile << "[WARNING] ";
                break;
            case LoggingLevel::ERROR:
                logfile << "[ERROR] ";
                break;
            case LoggingLevel::CRITICAL:
                logfile << "[CRITICAL] ";
                break;
            default:
                break;
        }

        logfile << message << std::endl;
        logfile.close();
    } else {
        std::cerr << "Failed to open log file !!" << std::endl;
    }
}
