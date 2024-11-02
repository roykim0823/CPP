add_executable(listing_4.1 listing_4.1.cpp)
target_link_libraries(listing_4.1 pthread)

add_executable(listing_4.5 listing_4.5.cpp)
target_link_libraries(listing_4.5 pthread)

add_executable(listing_4.6 listing_4.6.cpp)
target_link_libraries(listing_4.6 pthread)

add_executable(listing_4.7 listing_4.7.cpp)
target_link_libraries(listing_4.7 pthread)

# add_executable(listing_4.11 listing_4.11.cpp)
# target_link_libraries(listing_4.11 pthread)

# add_executable(listing_4.12 listing_4.12.cpp)
# target_link_libraries(listing_4.12 pthread)

# add_executable(listing_4.13 listing_4.13.cpp)
# target_link_libraries(listing_4.13 pthread)

# add_executable(listing_4.14 listing_4.14.cpp)
# target_link_libraries(listing_4.14 pthread)

# add_executable(listing_4.15 listing_4.15.cpp)
# target_link_libraries(listing_4.15 pthread)

# add_executable(listing_4.16 listing_4.16.cpp)
# target_link_libraries(listing_4.16 pthread)

add_executable(example_4_1_driver_and_passner example_4_1_driver_and_passner.cpp)
target_link_libraries(example_4_1_driver_and_passner pthread)

add_executable(example_4_5_thread_safe_queue_low_level example_4_5_thread_safe_queue_low_level.cpp)
target_link_libraries(example_4_5_thread_safe_queue_low_level pthread)

add_executable(example_4_6_async example_4_6_async.cpp)
target_link_libraries(example_4_6_async pthread)

add_executable(example_4_7_parallel_accumulate example_4_7_parallel_accumulate.cpp)
target_link_libraries(example_4_7_parallel_accumulate pthread)

add_executable(example_4_9_package_task example_4_9_package_task.cpp)
target_link_libraries(example_4_9_package_task pthread)

add_executable(example_4_10_promise example_4_10_promise.cpp)
target_link_libraries(example_4_10_promise pthread)

add_executable(example_4_10_promise_exception example_4_10_promise_exception.cpp)
target_link_libraries(example_4_10_promise_exception pthread)

add_executable(example_4_10_shared_future example_4_10_shared_future.cpp)
target_link_libraries(example_4_10_shared_future pthread)