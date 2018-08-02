cmake_minimum_required(VERSION 3.5)
project(LinkedList)


include_directories(include)
file(GLOB SRC "src/*.cpp")

add_executable(tests ${SRC})
