add_library(uuid SHARED)
add_library(uuid-static STATIC)

set_target_properties(uuid PROPERTIES WINDOWS_EXPORT_ALL_SYMBOLS ON)

target_include_directories(uuid INTERFACE ${CMAKE_CURRENT_LIST_DIR})
target_include_directories(uuid-static INTERFACE ${CMAKE_CURRENT_LIST_DIR})

target_sources(uuid PRIVATE TimestampHandler.cpp Uuid.cpp)
target_sources(uuid-static PRIVATE $<TARGET_OBJECTS:uuid>)