

include_directories(${PROJECT_SOURCE_DIR}/open_source)

file(GLOB_RECURSE SRCS *.cpp)
file(GLOB_RECURSE HDRS *.h)

set(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/build/bin)

add_executable(leetcode_training
    main.cpp
    ${PROJECT_SOURCE_DIR}/open_source/gmock-gtest-all.cc
    ${SRCS}
    ${HDRS}
)

target_link_libraries(leetcode_training -lpthread)
