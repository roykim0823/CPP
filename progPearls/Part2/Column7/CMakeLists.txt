cmake_minimum_required(VERSION 2.8)
project(COLUMN7)

set(CMAKE_C_FLAGS "-g -Wall")
set(CMAKE_CXX_FLAGS "-std=c++11 -pg -Wall")
find_library(MATHLIB m)

add_executable(timemod0 	"src/timemod0.cpp")			# example
