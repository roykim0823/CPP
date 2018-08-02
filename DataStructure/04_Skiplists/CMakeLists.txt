cmake_minimum_required(VERSION 3.5)
project(SkipLists)

set(CMAKE_CXX_FLAGS "-g -Wall")
include_directories(include)
file(GLOB SRC "src/*.cpp")

add_executable(tests ${SRC})
