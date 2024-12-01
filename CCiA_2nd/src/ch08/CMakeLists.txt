# add_executable(listing_8.1 listing_8.1.cpp)
# target_link_libraries(listing_8.1 pthread)

add_executable(ex_8_3_matrix ex_8_3_matrix.cpp)
target_link_libraries(ex_8_3_matrix pthread)

add_executable(listing_8.8_parallel_for_test listing_8.8_parallel_for_test.cpp)
target_link_libraries(listing_8.8_parallel_for_test pthread)

add_executable(listing_8.11_parallel_partial_sum listing_8.11_parallel_partial_sum.cpp)
target_link_libraries(listing_8.11_parallel_partial_sum pthread)