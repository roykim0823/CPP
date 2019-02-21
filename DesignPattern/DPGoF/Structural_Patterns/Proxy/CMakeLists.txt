include_directories(../../Foundation_Classes)
include_directories(include)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++1y")
set(proxy_SRCS
    src/Graphic.cpp
    src/TextDocument.cpp
    src/Image.cpp
    src/ImageProxy.cpp)

add_executable(proxy src/main.cpp)
add_library(proxylib SHARED ${proxy_SRCS})
target_link_libraries(proxylib foundation_classes)
target_link_libraries(proxy proxylib)
