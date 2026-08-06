#include "package_cache.h"
#include "logger.h"
#include <iostream>

int main() {
    std::cout << ReadPackage("numpy") << std::endl;
    std::cout << ReadPackage("something_random") << std::endl;
    return 0;
}

