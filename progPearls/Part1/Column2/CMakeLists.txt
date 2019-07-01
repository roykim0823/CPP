cmake_minimum_required(VERSION 2.8)
project(COLUMN2)

set(CMAKE_C_FLAGS "-g -Wall")
set(CMAKE_CXX_FLAGS "-g -Wall")
find_library(MATHLIB m)

add_executable(rotate 	"src/rotate.c")			# problem 3
add_executable(rotate_nonAdj 	"src/rotate_nonAdj.c")			# problem 5

add_executable(encoder	"src/transpose.c")		# problem 7
#add_definitions("-DDECODE_VERSION")
add_executable(decoder	"src/transpose.c")		# problem 7
set_target_properties(decoder PROPERTIES COMPILE_DEFINITIONS "DECODE_VERSION=1")
add_executable(sign		"src/sign.c")			# Anagram
add_executable(squash	"src/squash.c")			# Anagram

set(CMAKE_C_FLAGS "-g -Wall")
