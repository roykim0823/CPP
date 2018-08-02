cmake_minimum_required(VERSION 3.5)
project(compositeBuilder)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++1y")

# made with the 'incboost' macro
find_package(Boost)
if (Boost_FOUND)
	include_directories(${Boost_INCLUDE_DIR})
endif ()

include_directories(include)
file(GLOB SRC "src/*.cpp")
add_executable(compositeBuilder ${SRC})
