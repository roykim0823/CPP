set_source_files_properties(
    src/insertion_cpp98.cpp
    PROPERTIES COMPILE_FLAGS -std=c++98)
set_source_files_properties(
    src/insertion_cpp11.cpp
    PROPERTIES COMPILE_FLAGS -std=c++11)
set_source_files_properties(
    src/insertion_cpp14.cpp
    PROPERTIES COMPILE_FLAGS -std=c++14)

include_directories(include)
add_executable(insertion_cpp98 src/insertion_cpp98.cpp)
add_executable(insertion_cpp11 src/insertion_cpp11.cpp)
add_executable(insertion_cpp14 src/insertion_cpp14.cpp)
