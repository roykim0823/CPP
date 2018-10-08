add_executable(runtime_output01 src/runtime_output01.cpp)
add_executable(runtime_output02 src/runtime_output02.cpp)
add_executable(boost_type_index src/boost_type_index.cpp)

add_library(item04 src/ide_editors.cpp
            src/compiler_diagnostics.cpp)

find_package(Boost 1.56 REQUIRED)
include_directories(${Boost_INCLUDE_DIRS})

target_link_libraries(boost_type_index ${Boost_LIBRARIES})
