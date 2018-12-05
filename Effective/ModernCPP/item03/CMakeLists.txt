include_directories(include)

set_source_files_properties(
    src/typical_cases.cpp
    PROPERTIES COMPILE_FLAGS -std=c++98
)
set_source_files_properties(
    src/decltype_for_complicated_lvalues.cpp
    src/problem.cpp
    src/string_deque.cpp
    PROPERTIES COMPILE_FLAGS -std=c++11
)
set_source_files_properties(
    src/decltype_auto_for_function_return_types_cpp14.cpp
    src/decltype_auto_for_normal_auto_variables_cpp14.cpp
    src/return_statements_cpp14.cpp
    PROPERTIES COMPILE_FLAGS -std=c++14
)

add_executable(decltype_for_complicated_lvalues src/decltype_for_complicated_lvalues.cpp)

add_library(item03 src/problem.cpp
                   src/decltype_auto_for_function_return_types_cpp14.cpp
                   src/decltype_auto_for_normal_auto_variables_cpp14.cpp
                   src/typical_cases.cpp
                   src/string_deque.cpp
                   src/return_statements_cpp14.cpp)
