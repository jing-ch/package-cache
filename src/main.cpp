#include "package_cache.h"
#include "logger.h"
#include <iostream>
#include <chrono>

void TimedLoad(PackageCache& cache, const std::string& name);

int main() {
    PackageCache cache;

    TimedLoad(cache, "bigpkg");
    TimedLoad(cache, "bigpkg");
    TimedLoad(cache, "bigpkg");
    TimedLoad(cache, "bigpkg");

    return 0;
}

void TimedLoad(PackageCache& cache, const std::string& name) {
    auto start = std::chrono::steady_clock::now();
    std::string contents = cache.Get(name);
    auto end = std::chrono::steady_clock::now();
    auto ms = std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count();

    std::cout << contents.size() << " bytes in " << ms << " ms" << std::endl;
}

