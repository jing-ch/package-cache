#include "logger.h"
#include <iostream>

void LogMessage(const std::string& message) {
    std::cout << "[LOG] " << message << std::endl;
}