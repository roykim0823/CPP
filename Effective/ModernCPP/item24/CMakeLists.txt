# TODO: use Boost TypeIndex instead.
#include_directories(../../3rd_party)

set_source_files_properties(src/record_time.cpp PROPERTIES COMPILE_FLAGS "-std=c++14")

add_executable(urefs_initialization src/urefs_initialization.cpp)
add_executable(urefs_form src/urefs_form.cpp)

add_library(item24 src/rrefs_examples.cpp
                   src/urefs_contexts.cpp
                   src/no_type_deduction.cpp
                   src/record_time.cpp)
