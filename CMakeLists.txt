cmake_minimum_required(VERSION 3.20)
project(CppWorkshops)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

add_subdirectory(IPv4Address)

add_executable(CppWorkshops main.cpp)

