#pragma once

#include <string>
#include <unordered_map>

// Place holder
std::string ReadPackage(const std::string& name);

class PackageCache {
public:
    explicit PackageCache(size_t max_bytes);

    // returning a reference
    const std::string& Get(const std::string& name);

private:
    void EvictUntilUnderBudget();

    std::unordered_map<std::string, std::string> entries_;
    size_t current_bytes_ = 0;
    size_t max_bytes_;
};