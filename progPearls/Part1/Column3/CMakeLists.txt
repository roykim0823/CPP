cmake_minimum_required(VERSION 2.8)
project(COLUMN3)

set(CMAKE_C_FLAGS "-g -Wall")
set(CMAKE_CXX_FLAGS "-g -Wall")
find_library(MATHLIB m)

add_executable(tax 	"src/tax.c")			# problem 1
add_executable(series 	"src/series.c")			# problem 2
add_executable(banner 	"src/banner.c")			# problem 3
add_executable(date 	"src/date.c")			# problem 4
add_executable(hyphenate 	"src/hyphenate.c")			# problem 5
add_executable(formLetterGen 	"src/formLetterGen.c")			# problem 6
add_executable(sevenSegment 	"src/sevenSegment.c")			# problem 8
