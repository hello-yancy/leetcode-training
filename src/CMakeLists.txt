cmake_minimum_required(VERSION 3.10)

include_directories(${PROJECT_SOURCE_DIR}/open_source)

file(GLOB_RECURSE SRCS ${PROJECT_SOURCE_DIR}/src *.cpp)
file(GLOB_RECURSE HDRS ${PROJECT_SOURCE_DIR}/src *.h)

set(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/build/bin)

add_executable(leetcode_training
    ${PROJECT_SOURCE_DIR}/open_source/gmock-gtest-all.cc
    ${HDRS}
    ${SRCS}
)

target_link_libraries(leetcode_training -lpthread)
