cc_library(
    name = "uuid",
    srcs = [
        "src/TimestampHandler.cpp",
        "src/Uuid.cpp",
    ],
    hdrs = [
        "include/SimpleUuid/TimestampHandler.h",
        "include/SimpleUuid/Uuid.h",
    ],
    copts = select({
        "@platforms//os:windows": [
            "/std:c++17",
            "/utf-8",
        ],
        "//conditions:default": [
            "-std=c++17",
        ],
    }),
    includes = [
        "include",
    ],
    visibility = ["//visibility:public"],
)
