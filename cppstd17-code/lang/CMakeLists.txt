cmake_minimum_required(VERSION 3.10)
project(basics)

set(CMAKE_CXX_FLAGS "-std=c++17 -O3 -Wall")
find_library(MATHLIB m)

include_directories(include)

file(GLOB ALL_SRCS "*/*.cpp")

# 2. Filter out files in ch03/
set(SRCS "") # Initialize a list for the source files we want to keep
foreach(src IN LISTS ALL_SRCS)
    # Check if the path contains 'ch03/'
    string(FIND "${src}" "ch03/" CH03_POS)

    # If CH03_POS is -1, it means 'ch03/' was NOT found, so we keep the file
    if(CH03_POS EQUAL -1)
        list(APPEND SRCS ${src})
    # else()
        # message(STATUS "Skipping file: ${src}") # Uncomment for debugging
    endif()
endforeach()

foreach(src IN LISTS SRCS)
#	message(STATUS "${src}")
	get_filename_component(filename ${src} NAME)
	string(REPLACE "." ";" temp ${filename})
	list(GET temp 0 target)
	add_executable(${target} ${src})
	list(APPEND TARGET_LIST ${target})
endforeach()

# ch03
add_executable(inlinethreadlocal ch03/inlinethreadlocal1.cpp ch03/inlinethreadlocal2.cpp)
