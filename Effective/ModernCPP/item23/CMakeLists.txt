include_directories(include)
set_source_files_properties(src/std_move_in_cpp14.cpp PROPERTIES COMPILE_FLAGS "-std=c++14")

add_executable(typical_use_of_std_forward
               src/typical_use_of_std_forward.cpp)

#add_library(item23 src/std_move_in_cpp11.cpp
#                   src/std_move_in_cpp14.cpp
add_library(item23 src/annotation.cpp
                   src/move_constructor_with_move.cpp
                   src/move_constructor_with_forward.cpp)
