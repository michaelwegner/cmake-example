cmake_minimum_required(VERSION 3.3 FATAL_ERROR)

# Catch
add_library(Catch INTERFACE)
add_library(Catch::Catch ALIAS Catch)
target_include_directories(Catch
    INTERFACE
        ${CMAKE_CURRENT_SOURCE_DIR}
)
target_compile_features(Catch
    INTERFACE
        cxx_noexcept
)
