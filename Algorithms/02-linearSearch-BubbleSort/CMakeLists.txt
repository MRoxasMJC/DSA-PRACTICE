# Set the minimum required version of CMake
cmake_minimum_required(VERSION 3.15...4.1)

# Specify the C++ standard (optional, but recommended)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED True)

add_executable(
        main
        sortSearch.cpp
        testScoreAnalysis.cpp
)