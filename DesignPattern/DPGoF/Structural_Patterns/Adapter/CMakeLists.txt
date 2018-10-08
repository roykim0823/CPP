cmake_minimum_required(VERSION 2.8)
project(Adapter)

include_directories(include)

set(adapter_SRCS
    src/TextManipulator.cpp
    src/TextView.cpp)

add_library(adapter SHARED ${adapter_SRCS})

include_directories(../../Foundation_Classes)

add_subdirectory(class_adapter)
add_subdirectory(object_adapter)
