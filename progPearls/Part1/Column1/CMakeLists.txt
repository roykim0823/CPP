cmake_minimum_required(VERSION 2.8)
project(COLUMN1)

set(CMAKE_C_FLAGS "-g -Wall")
set(CMAKE_CXX_FLAGS "-g -Wall")
find_library(MATHLIB m)

add_executable(qsortints 	"src/qsortints.c")			# problem 1
add_executable(sortingints 	"src/sortingints.cpp")   	# problem 1
add_executable(bitsort 		"src/bitsort.c")   			# problem 2 and 3
add_executable(uniqueRandInt	"src/uniqueRandInt.c")   		# problem 4
add_executable(twoPhaseBitSort	"src/twoPhaseBitSort.c")   		# problem 5
add_executable(multiBitSort	"src/multiBitSort.c")   		# problem 6
add_executable(errorCheck	"src/errorCheck.c")   		# problem 7
