cmake_minimum_required(VERSION 3.3 FATAL_ERROR)
project(cmake-example VERSION 0.1 LANGUAGES CXX)

# global compiler flags required for all libraries and executables
add_compile_options(-W -Wall -Werror -pedantic -Wunused -Wshadow)

# CCache
option(ENABLE_CCACHE "Enable CCache if available" ON)
find_program(CCACHE ccache)
if(CCACHE AND ENABLE_CCACHE)
    set_property(GLOBAL PROPERTY RULE_LAUNCH_COMPILE "${CCACHE}")
endif()

# CTest support
option(ENABLE_CTEST "Enable CTest" ON)
if (ENABLE_CTEST)
    include(CTest)
endif()

# Build modes
if (NOT CMAKE_BUILD_TYPE)
    set(CMAKE_BUILD_TYPE DEBUG CACHE STRING "Choose the type of build" FORCE)
endif()
set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -O0")
set(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS_RELEASE} -O3")

# Sanitizer
list(APPEND CMAKE_MODULE_PATH "${PROJECT_SOURCE_DIR}/external/cmake")
include(Sanitizer)

add_subdirectory(application)
add_subdirectory(external)
add_subdirectory(moduleA)
add_subdirectory(moduleB)