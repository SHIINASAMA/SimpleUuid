cmake_minimum_required(VERSION 3.14)

cmake_policy(SET CMP0048 NEW)
option(UUID_BUILD_TEST "build the unit test for uuid lib" OFF)
if (UUID_BUILD_TEST)
    if (NOT DEFINED VCPKG_MANIFEST_FEATURES)
        message(STATUS "Auto append features: tests")
        set(VCPKG_MANIFEST_FEATURES "tests")
    else ()
        list(FIND VCPKG_MANIFEST_FEATURES "tests" index)
        if (index EQUAL -1)
            message(STATUS "Auto append features: tests")
            list(APPEND VCPKG_MANIFEST_FEATURES "tests")
        endif ()
    endif ()
endif ()

project(SimpleUuid VERSION 0.1.5)

set(CMAKE_C_STANDARD 11)
set(CMAKE_CXX_STANDARD 17)

add_subdirectory(SimpleUuid)

if (UUID_BUILD_TEST)
    find_package(GTest CONFIG REQUIRED)
    enable_testing()
    add_subdirectory(test)
endif ()