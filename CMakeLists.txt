cmake_minimum_required(VERSION 4.4.4)
project(Test)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON CACHE BOOL "" FORCE)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON CACHE BOOL "" FORCE)



list(APPEND CMAKE_PREFIX_PATH "C:/vcpkg/installed/x64-mingw-static")
set(ZLIB_LIBRARY "C:/vcpkg/installed/x64-mingw-static/lib/libzs.a")
find_package(cpr CONFIG REQUIRED)



add_executable(test_app ${CMAKE_CURRENT_SOURCE_DIR}/source/main.cpp)
target_link_libraries(test_app PRIVATE cpr::cpr)
target_link_options(test_app PRIVATE -static)