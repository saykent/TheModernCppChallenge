cmake_minimum_required(VERSION 3.20)
project(IPv4Address)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

add_executable(ipv4Test IPv4Address.cpp IPv4Test.cpp)
add_executable(ipv4RangeTest IPv4Address.cpp IPv4RangeTest.cpp)
