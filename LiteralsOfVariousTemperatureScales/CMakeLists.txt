cmake_minimum_required(VERSION 3.20)
project(IPv4Address)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

add_executable(temperatures Temperature.h TemperatureTest.cpp)
