cmake_minimum_required(VERSION 3.5)
project(builder)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++1y")

# made with the 'incboost' macro
find_package(Boost)
if (Boost_FOUND)
  include_directories(${Boost_INCLUDE_DIR})
endif ()

add_executable(scenario  		src/0_scenario.cpp)
add_executable(simpleBuilder  	src/1_simpleBuilder.cpp)
add_executable(fluentBuilder  	src/2_fluentBuilder.cpp)
add_executable(CommunicatingIntent  src/3_CommunicatingIntent.cpp)
