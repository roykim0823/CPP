cmake_minimum_required(VERSION 3.10)
project(basics)

set(CMAKE_CXX_FLAGS "-std=c++17 -O3 -Wall")
find_library(MATHLIB m)

include_directories(include)

file(GLOB ALL_SRCS "*/*.cpp")

foreach(src IN LISTS ALL_SRCS)
#	message(STATUS "${src}")
	get_filename_component(filename ${src} NAME)
	string(REPLACE "." ";" temp ${filename})
	list(GET temp 0 target)
	add_executable(${target} ${src})
	list(APPEND TARGET_LIST ${target})
endforeach()