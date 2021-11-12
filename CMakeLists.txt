cmake_minimum_required(VERSION 3.20)
project(TheModernCppChallenge)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

add_subdirectory(IPv4Address)
add_subdirectory(Array2D)
add_subdirectory(LiteralsOfVariousTemperatureScales)

add_executable(TheModernCppChallenge main.cpp)

