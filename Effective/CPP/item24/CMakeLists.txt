cmake_minimum_required(VERSION 2.8)
project(item02)

set(CMAKE_CXX_FLAGS "-std=c++1z -g -Wall")
#set(CMAKE_CXX_FLAGS "-std=c++11 -g -Wall")

include_directories(include)
add_executable(non_member_func src/main.cpp src/Rational.cpp)
