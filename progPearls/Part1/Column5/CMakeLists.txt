cmake_minimum_required(VERSION 2.8)
project(COLUMN5)

set(CMAKE_C_FLAGS "-g -Wall")
set(CMAKE_CXX_FLAGS "-g -Wall")
find_library(MATHLIB m)

add_executable(search 	"src/search.c")			
