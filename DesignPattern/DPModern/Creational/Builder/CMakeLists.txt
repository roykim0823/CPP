cmake_minimum_required(VERSION 2.8)
project(Creational)

set(CMAKE_CXX_FLAGS "-std=c++1z -g -Wall")

include_directories(include)
file(GLOB SRCS "src/*.cpp")

foreach(src IN LISTS SRCS) 
	message(STATUS "${src}")
	get_filename_component(filename ${src} NAME)
	string(REPLACE "." ";" temp ${filename})
	list(GET temp 0 target)
	add_executable(${target} ${src})
	if (UNIX AND NOT APPLE)
		target_link_libraries(${target} rt)
	endif()
	list(APPEND TARGET_LIST ${target})
endforeach()

add_subdirectory(compositeBuilder)
