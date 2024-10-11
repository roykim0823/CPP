add_executable(listing_1.1 listing_1.1.cpp)
target_link_libraries(listing_1.1 pthread)

add_executable(example_launch_threads example_launch_threads.cpp)
target_link_libraries(example_launch_threads pthread)
