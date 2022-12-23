cmake_minimum_required(VERSION 3.14)

project(uuid VERSION 0.1)

set(CMAKE_C_STANDARD 11)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(LIBRARY_OUTPUT_PATH ${CMAKE_BINARY_DIR}/target)
set(EXECUTABLE_OUTPUT_PATH ${CMAKE_BINARY_DIR}/target)

option(UUID_BUILD_TEST "build the unit test for uuid lib" OFF)

add_subdirectory(uuid)

if (UUID_BUILD_TEST)
    add_subdirectory(test)
endif ()