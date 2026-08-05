cmake_minimum_required(VERSION 3.20)
project(package_cache CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_library(pkgcache src/package_cache.cpp src/logger.cpp)
target_include_directories(pkgcache PUBLIC src)

add_executable(demo src/main.cpp)
target_link_libraries(demo PRIVATE pkgcache)