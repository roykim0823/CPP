set_source_files_properties(src/reasons_for_preferring_make_functions.cpp PROPERTIES COMPILE_FLAGS -std=c++14)
set_source_files_properties(src/limitations_of_make_functions.cpp PROPERTIES COMPILE_FLAGS -std=c++14)

add_executable(reasons_for_preferring_make_functions src/reasons_for_preferring_make_functions.cpp)
add_executable(limitations_of_make_functions src/limitations_of_make_functions.cpp)
