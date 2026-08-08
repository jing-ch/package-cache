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

// constructor
PackageCache::PackageCache(size_t max_bytes) {
    max_bytes_ = max_bytes;
}

// returning a reference
const std::string& PackageCache::Get(const std::string& name) {
    auto it = entries_.find(name);
    if (it != entries_.end()) {
        // return from memory
        return it->second;
    } else {
        // find it from disk and store and return it
        entries_[name] = ReadPackage(name);
        current_bytes_ += entries_[name].size();

        EvictUntilUnderBudget();

        return entries_[name];
    }
}

void PackageCache::EvictUntilUnderBudget() {
    while (current_bytes_ > max_bytes_ && !entries_.empty()) {
        auto victim = entries_.begin();
        LogMessage("evicting: " + victim->first);
        current_bytes_ -= victim->second.size();
        entries_.erase(victim);
    }
}
