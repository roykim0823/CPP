include_directories(../../Foundation_Classes)
include_directories(../../Behavioral_Patterns/Iterator)
include_directories(include)

set(facade_SRCS
    src/Compiler.cpp
    src/ExpressionNode.cpp)

add_library(facade SHARED ${facade_SRCS})
