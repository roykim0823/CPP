cmake_minimum_required(VERSION 2.8)
project(Bridge)
#set(CMAKE_CXX_FLAGS "-std=c++1z -g -Wall")
set(CMAKE_CXX_FLAGS "-g -Wall")

include_directories(../../Foundation_Classes)
include_directories(include)
file(GLOB SRCS "src/*.cpp")

add_library(bridge SHARED ${SRCS})
