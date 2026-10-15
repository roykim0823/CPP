cmake_minimum_required(VERSION 3.10)
project(Inherit CXX)

set(CMAKE_CXX_STANDARD 17)			# ObjectCounter uses inline static members
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -g -Wall")

include_directories(${CMAKE_CURRENT_SOURCE_DIR})

# Chapter 21: Templates and Inheritance

# 21.1 The Empty Base Class Optimization (EBCO)
add_executable(empty 				"empty.cpp")
add_executable(ebco1 				"ebco1.cpp")
add_executable(ebco2 				"ebco2.cpp")

# 21.2 The Curiously Recurring Template Pattern (CRTP)
add_executable(countertest 			"countertest.cpp")
add_executable(equalitycomparable 	"equalitycomparable.cpp")
#add_executable(projectioniterator 	"projectioniterator.cpp")	# skeleton: IteratorFacade/ProjectionIterator not implemented
#add_executable(wrapper 			"wrapper.cpp")				# intentional compile error: foo(s) is not found via ADL

# 21.3 Mixins
add_executable(virtual 				"virtual.cpp")
