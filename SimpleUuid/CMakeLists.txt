add_library(Uuid)

set_target_properties(Uuid PROPERTIES WINDOWS_EXPORT_ALL_SYMBOLS ON)
if (${MSVC})
    target_compile_options(Uuid PRIVATE /utf-8)
endif ()

target_include_directories(
        Uuid
        PUBLIC
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
        $<INSTALL_INTERFACE:include>
)

target_sources(Uuid PRIVATE src/TimestampHandler.cpp src/Uuid.cpp)

set_target_properties(
        Uuid
        PROPERTIES
        OUTPUT_NAME "sese.uuid"
        PREFIX ""
)

include(GNUInstallDirs)
include(CMakePackageConfigHelpers)
configure_package_config_file(
        ${PROJECT_SOURCE_DIR}/cmake/SimpleUuidConfig.cmake.in
        ${PROJECT_BINARY_DIR}/SimpleUuidConfig.cmake
        INSTALL_DESTINATION lib/cmake/SimpleUuid
)

# export targets
install(TARGETS Uuid
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
        NAMESPACE Sese::
)