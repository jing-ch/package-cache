#include "package_cache.h"
#include "logger.h"
#include <iostream>

int main() {
    PackageCache cache;
    std::cout << cache.Get("numpy") << std::endl;
    std::cout << cache.Get("numpy") << std::endl;
    std::cout << cache.Get("numpy") << std::endl;
    return 0;
}

