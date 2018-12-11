set(decorator_SRCS
    src/BorderDecorator.cpp
    src/Decorator.cpp
    src/ScrollDecorator.cpp
    src/DropShadowDecorator.cpp
    src/VisualComponent.cpp
    src/Window.cpp)

include_directories(include)
add_library(decorator SHARED ${decorator_SRCS})
add_executable(decorator1 src/decorator1.cpp)
target_link_libraries(decorator1 decorator)
