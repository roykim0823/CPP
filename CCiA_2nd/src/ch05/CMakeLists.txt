#add_library(ch05 listing_5.1.cpp)

add_executable(listing_5.1_spin_lock listing_5.1_spin_lock.cpp)
target_link_libraries(listing_5.1_spin_lock pthread)

add_executable(listing_5.2_atomic_inter_threads listing_5.2_atomic_inter_threads.cpp)
target_link_libraries(listing_5.2_atomic_inter_threads pthread)

add_executable(listing_5.3 listing_5.3.cpp)
target_link_libraries(listing_5.3 pthread)

add_executable(listing_5.4_seq_cst listing_5.4_seq_cst.cpp)
target_link_libraries(listing_5.4_seq_cst pthread)

add_executable(listing_5.5_relaxed listing_5.5_relaxed.cpp)
target_link_libraries(listing_5.5_relaxed pthread)

add_executable(listing_5.6_relaxed_multi_threads listing_5.6_relaxed_multi_threads.cpp)
target_link_libraries(listing_5.6_relaxed_multi_threads pthread)

add_executable(listing_5.7_acquire_release listing_5.7_acquire_release.cpp)
target_link_libraries(listing_5.7_acquire_release pthread)

add_executable(listing_5.8_order_on_relaxed listing_5.8_order_on_relaxed.cpp)
target_link_libraries(listing_5.8_order_on_relaxed pthread)

add_executable(listing_5.9_transitive_sync listing_5.9_transitive_sync.cpp)
target_link_libraries(listing_5.9_transitive_sync pthread)

add_executable(listing_5.10_consume listing_5.10_consume.cpp)
target_link_libraries(listing_5.10_consume pthread)

add_executable(listing_5.11_release_sequence listing_5.11_release_sequence.cpp)
target_link_libraries(listing_5.11_release_sequence pthread)

add_executable(listing_5.12_fence listing_5.12_fence.cpp)
target_link_libraries(listing_5.12_fence pthread)

add_executable(listing_5.13 listing_5.13.cpp)
target_link_libraries(listing_5.13 pthread)

add_executable(ex_5_1_1_atomic_flag ex_5_1_1_atomic_flag.cpp)
target_link_libraries(ex_5_1_1_atomic_flag pthread)

add_executable(ex_5_1_2_atomic_bool ex_5_1_2_atomic_bool.cpp)
target_link_libraries(ex_5_1_2_atomic_bool pthread)

add_executable(ex_5_1_3_compare_and_exchange ex_5_1_3_compare_and_exchange.cpp)
target_link_libraries(ex_5_1_3_compare_and_exchange pthread)
