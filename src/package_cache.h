#pragma once

#include <string>
#include <unordered_map>

// Place holder
std::string ReadPackage(const std::string& name);

class PackageCache {
public:
    std::string Get(const std::string& name);

private:
    std::unordered_map<std::string, std::string> entries_;
};