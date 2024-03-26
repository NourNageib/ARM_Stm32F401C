#include "Log.h"

int main() {
    // Example usage
    Logger::log("This is an informational message", LoggingLevel::INFO);
    Logger::log("This is a warning message", LoggingLevel::WARNING);
    Logger::log("This is an error message", LoggingLevel::ERROR);
    Logger::log("This is a critical message", LoggingLevel::CRITICAL);

    return 0;
}
