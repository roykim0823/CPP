cmake_minimum_required(VERSION 2.8)
project(COLUMN1)

set(CMAKE_C_FLAGS "-g -Wall")
set(CMAKE_CXX_FLAGS "-std=c++11 -pg -Wall")
find_library(MATHLIB m)

add_executable(maxsum 	"src/maxsum.cpp")			# example
