cmake_minimum_required(VERSION 3.5)
project(Factories)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++1y")

# made with the 'incboost' macro
find_package(Boost)
if (Boost_FOUND)
	include_directories(${Boost_INCLUDE_DIR})
endif ()

include_directories(include)
file(GLOB SRCS "src/*.cpp")

foreach(src IN LISTS SRCS)
	message(STATUS "${src}")
	get_filename_component(filename ${src} NAME)
	string(REPLACE "." ";" temp ${filename})
	list(GET temp 0 target)
	add_executable(${target} ${src})
	target_link_libraries(${target} rt)
	list(APPEND TARGET_LIST ${target})
endforeach()
