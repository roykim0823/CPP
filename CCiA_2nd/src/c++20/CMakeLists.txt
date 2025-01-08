add_executable(1_jthread 1_jthread.cpp)
target_link_libraries(1_jthread pthread)

add_executable(2_jthread_local 2_jthread_local.cpp)
target_link_libraries(2_jthread_local pthread)

add_executable(3_coroutines 3_coroutines.cpp)
target_link_libraries(3_coroutines pthread)