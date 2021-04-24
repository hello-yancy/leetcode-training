
include_directories(${PROJECT_SOURCE_DIR}/open_source)

file(GLOB SRC_LST "${PROJECT_SOURCE_DIR}/src/*.cpp")

set(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/build/bin)

add_executable(leetcode_training
    ${PROJECT_SOURCE_DIR}/open_source/gmock-gtest-all.cc
    ${SRC_LST}
)
