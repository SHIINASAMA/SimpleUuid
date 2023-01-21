cmake_minimum_required(VERSION 3.14)

project(SimpleUuid VERSION 0.1.3)

set(CMAKE_C_STANDARD 11)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

option(UUID_BUILD_TEST "build the unit test for uuid lib" OFF)

add_subdirectory(SimpleUuid)

if (UUID_BUILD_TEST)
    find_package(GTest CONFIG REQUIRED)
    enable_testing()
    add_subdirectory(test)
endif ()