cmake_minimum_required(VERSION 2.8)
project(Basics)

set(CMAKE_CXX_FLAGS "-std=c++1z -g -Wall")
find_library(MATHLIB m)

include_directories(include)
file(GLOB SRCS "src/*.cpp")

#foreach(src IN LISTS SRCS)
#	get_filename_component(filename ${src} NAME)
#	string(REPLACE "." ";" temp ${filename})
#	list(GET temp 0 target)
#	#message(STATUS "${target}")
#	add_executable(${target} ${src})
#endforeach()

# Chapter 1
add_executable(max1 		"src/max1.cpp")
add_executable(max2 		"src/max2.cpp")
add_executable(max3val 		"src/max3val.cpp")
add_executable(max3ref 		"src/max3ref.cpp")
add_executable(max4 		"src/max4.cpp")

# Chapter 2
add_executable(stack1test "src/stack1test.cpp")
add_executable(stack3test "src/stack3test.cpp")

# Chapter 3
add_executable(stacknontype "src/stacknontype.cpp")
add_executable(stackauto "src/stackauto.cpp") 	
add_executable(message "src/message.cpp") 	

# Chapter 4
add_executable(varprint1 "src/varprint1.cpp")
add_executable(varprint2 "src/varprint2.cpp")
add_executable(foldtraverse "src/foldtraverse.cpp")
add_executable(varusing "src/varusing.cpp")

# Chapter 6: Move Semantics
add_executable(move1 					"src/move1.cpp")
add_executable(move2 					"src/move2.cpp") 	
add_executable(specialmemtmpl1 			"src/specialmemtmpl1.cpp") 	
add_executable(specialmemtmpl2 			"src/specialmemtmpl2.cpp") 	
add_executable(specialmemtmpl3 			"src/specialmemtmpl3.cpp") 	

# Chapter 7: By value or by Reference?
add_executable(cref			"src/cref.cpp")

# Chapter 8: Compile-Time Programming
add_executable(isprime		"src/isprime.cpp")
add_executable(isprime11   	"src/isprime11.cpp")
add_executable(isprime14   	"src/isprime14.cpp")
