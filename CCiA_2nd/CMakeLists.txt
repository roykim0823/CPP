cmake_minimum_required (VERSION 3.20)
project(CCiA CXX)

set(CMAKE_CXX_COMPILER "/usr/bin/clang++")
set(CMAKE_CXX_FLAGS "--std=c++20")

set(CXX_FLAGS
 -g
 # -DVALGRIND
 # -DCHECK_PTHREAD_RETURN_VALUE
 # -D_FILE_OFFSET_BITS=64
 -Wall
 # -Wextra
 # -Werror
 # -Wconversion
 # -Wno-unused-parameter
 # -Wold-style-cast
 # -Woverloaded-virtual
 # -Wpointer-arith
 # -Wshadow
 # -Wwrite-strings
 # -march=native
 -fcoroutines
 )

set(CMAKE_CXX_FLAGS_DEBUG "-O0")
set(CMAKE_CXX_FLAGS_RELEASE "-O2 -finline-limit=1000 -DNDEBUG")

#find_package(Boost COMPONENTS system thread REQUIRED)

#include_directories(${Boost_INCLUDE_DIRS})
include_directories("${PROJECT_SOURCE_DIR}/src/")

add_subdirectory(src)
