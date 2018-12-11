include_directories(../../Foundation_Classes)
include_directories(../../Behavioral_Patterns/Iterator)

include_directories(include)
set(composite_SRCS
    src/Bus.cpp
    src/Cabinet.cpp
    src/Card.cpp
    src/Chassis.cpp
    src/CompositeEquipment.cpp
    src/Equipment.cpp
    src/FloppyDisk.cpp)

add_library(composite SHARED ${composite_SRCS})

add_executable(composite1 src/main.cpp)

target_link_libraries(composite1 composite)
