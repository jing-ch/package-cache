#include "package_cache.h"
#include "logger.h"
#include <fstream>
#include <sstream>

std::string ReadPackage(const std::string& name) {
    std::string path = "packages/" + name + ".txt";
    std::ifstream file(path);
    if (!file) {
        LogMessage("Failed to open package file: " + path);
        return "";
    }

    std::stringstream buffer;
    buffer << file.rdbuf();
    return buffer.str();
}