cmake_minimum_required(VERSION 3.3 FATAL_ERROR)

# Dependencies
# Boost
set(Boost_USE_STATIC_LIBS     ON) # only find static libs
set(Boost_USE_STATIC_RUNTIME OFF)
find_package(Boost REQUIRED COMPONENTS filesystem)

# Catch to CTest
include(ParseAndAddCatchTests)

# Library
add_library(moduleB
    STATIC
        src/B.cpp
)
add_library(CMakeExample::moduleB ALIAS moduleB)
target_include_directories(moduleB
    PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}/include        
)
target_link_libraries(moduleB
    PUBLIC
        CMakeExample::moduleA
    PRIVATE
        Boost::filesystem        
)

# Tests
add_executable(moduleB-unittest
    ${CMAKE_CURRENT_SOURCE_DIR}/test/main.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/test/B_unittest.cpp
)
target_link_libraries(moduleB-unittest
    PRIVATE
        Boost::filesystem
        Catch::Catch
        CMakeExample::moduleB
)
ParseAndAddCatchTests(moduleB-unittest)