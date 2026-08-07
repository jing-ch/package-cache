#include "package_cache.h"
#include "logger.h"
#include <fstream>
#include <sstream>
#include <unordered_map>

std::string ReadPackage(const std::string& name) {
    std::string path = "packages/" + name + ".txt";
    std::ifstream file(path);
    if (!file) {
        LogMessage("Failed to open package file: " + path);
        return "";
    }
    
    LogMessage("loaded from disk: " + name);

    std::stringstream buffer;
    buffer << file.rdbuf();
    return buffer.str();
}


std::string PackageCache::Get(const std::string& name) {
    auto it = entries_.find(name);
    if (it != entries_.end()) {
        // return from memory
        return it->second;
    } else {
        // find it from disk and store and return it
        std::string content = ReadPackage(name);
        if (!content.empty()) {
            entries_[name] = content;
        }
        return content;
    }
    
}
