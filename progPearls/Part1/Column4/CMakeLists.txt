cmake_minimum_required(VERSION 2.8)
project(COLUMN4)

set(CMAKE_C_FLAGS "-g -Wall")
set(CMAKE_CXX_FLAGS "-g -Wall")
find_library(MATHLIB m)

add_executable(2 	"src/2.c")			
add_executable(3 	"src/3.c")			
add_executable(4 	"src/4.c")			
add_executable(7 	"src/7.c")			
add_executable(8 	"src/8.c")			
add_executable(11 	"src/11.c")			
