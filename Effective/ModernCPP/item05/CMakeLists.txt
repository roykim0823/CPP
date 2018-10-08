set_source_files_properties(src/simple_joys.cpp PROPERTIES COMPILE_FLAGS -std=c++11)
set_source_files_properties(src/auto.cpp PROPERTIES COMPILE_FLAGS -std=c++14)

include_directories(include)
add_executable(auto src/auto.cpp)

add_library(simple_joys src/simple_joys.cpp)
