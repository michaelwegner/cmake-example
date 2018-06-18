cmake_minimum_required(VERSION 3.3 FATAL_ERROR)

# Catch to CTest
include(ParseAndAddCatchTests)

# Library
add_library(moduleA
    STATIC
        src/A.cpp
)
add_library(CMakeExample::moduleA ALIAS moduleA)
target_include_directories(moduleA
    PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}/include
)
target_compile_features(moduleA
    INTERFACE
        cxx_rvalue_references
    PRIVATE
        cxx_std_11
)

# Tests
add_executable(moduleA-unittest    
    ${CMAKE_CURRENT_SOURCE_DIR}/test/main.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/test/A_unittest.cpp
)
target_link_libraries(moduleA-unittest
    PRIVATE
        CMakeExample::moduleA
        Catch::Catch
)
ParseAndAddCatchTests(moduleA-unittest)