add_library(uuid SHARED)
add_library(uuid-static STATIC)

add_library(SimpleUuid::uuid ALIAS uuid)
add_library(SimpleUuid::uuid-static ALIAS uuid-static)

set_target_properties(uuid PROPERTIES WINDOWS_EXPORT_ALL_SYMBOLS ON)
if (WIN32)
    target_compile_options(uuid PRIVATE /utf-8)
    target_compile_options(uuid-static PRIVATE /utf-8)
endif ()

target_include_directories(
        uuid
        PUBLIC
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
        $<INSTALL_INTERFACE:include>
)

target_include_directories(
        uuid-static
        PUBLIC
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
        $<INSTALL_INTERFACE:include>
)

target_sources(uuid PRIVATE src/TimestampHandler.cpp src/Uuid.cpp)
target_sources(uuid-static PRIVATE $<TARGET_OBJECTS:uuid>)

include(GNUInstallDirs)
include(CMakePackageConfigHelpers)
configure_package_config_file(
        ${PROJECT_SOURCE_DIR}/cmake/SimpleUuidConfig.cmake.in
        ${PROJECT_BINARY_DIR}/SimpleUuidConfig.cmake
        INSTALL_DESTINATION lib/cmake/SimpleUuid
)

# export targets
install(TARGETS uuid uuid-static
        EXPORT SimpleUuidTargets
        RUNTIME DESTINATION bin
        LIBRARY DESTINATION lib
        ARCHIVE DESTINATION lib
        PUBLIC_HEADER DESTINATION include
        )

# install header files
install(DIRECTORY "${CMAKE_CURRENT_LIST_DIR}/include/SimpleUuid" DESTINATION "${CMAKE_INSTALL_INCLUDEDIR}")

# copy config
install(
        FILES ${PROJECT_BINARY_DIR}/SimpleUuidConfig.cmake
        DESTINATION lib/cmake/SimpleUuid
)

# copy debug config
install(
        FILES ${PROJECT_BINARY_DIR}/SimpleUuidConfig.cmake
        DESTINATION debug/lib/cmake/SimpleUuid
)

# copy export target
install(
        EXPORT SimpleUuidTargets
        DESTINATION ${CMAKE_INSTALL_LIBDIR}/cmake/SimpleUuid
        NAMESPACE SimpleUuid::
)