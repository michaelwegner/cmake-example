cmake_minimum_required(VERSION 3.3 FATAL_ERROR)

add_executable(list-dir
    ${CMAKE_CURRENT_SOURCE_DIR}/main.cpp
)
target_link_libraries(list-dir
    PRIVATE
        CMakeExample::moduleB
)