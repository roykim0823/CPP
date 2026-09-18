cmake_minimum_required(VERSION 3.10)
project(Facade CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include_directories(include)

# The Facade itself: Console in front of Buffer/Viewport.
add_executable(facade src/facade.cpp src/Console.cpp)

# pimpl, for comparison: Person's implementation lives only in Person.cpp.
add_executable(pimpl src/pimpl.cpp src/Person.cpp src/Console.cpp)
