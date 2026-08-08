#include "package_cache.h"
#include "logger.h"
#include <iostream>
#include <chrono>

void TimedLoad(PackageCache& cache, const std::string& name);

int main() {
    PackageCache cache(250 * 1024 * 1024);

    const std::string& numpy = cache.Get("numpy");
    std::cout << "numpy size right after load: " << numpy.size() << std::endl;

    const std::string& pandas = cache.Get("pandas");
    std::cout << "pandas size right after load: " << pandas.size() << std::endl;

    cache.Get("scipy");
    cache.Get("torch");
    cache.Get("bigpkg");

    // at this point numpy cached should be evicted

    std::cout << "numpy size after eviction: " << numpy.size() << std::endl;
    std::cout << "pandas size after eviction: " << pandas.size() << std::endl;

    return 0;
}

void TimedLoad(PackageCache& cache, const std::string& name) {
    auto start = std::chrono::steady_clock::now();
    std::string contents = cache.Get(name);
    auto end = std::chrono::steady_clock::now();
    auto ms = std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count();

    std::cout << contents.size() << " bytes in " << ms << " ms" << std::endl;
}

