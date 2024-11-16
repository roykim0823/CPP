#add_library(ch05 listing_5.1.cpp)

add_executable(listing_5.1 listing_5.1.cpp)
target_link_libraries(listing_5.1 pthread)

add_executable(listing_5.2 listing_5.2.cpp)
target_link_libraries(listing_5.2 pthread)

add_executable(listing_5.3 listing_5.3.cpp)
target_link_libraries(listing_5.3 pthread)

add_executable(listing_5.4_seq_cst listing_5.4_seq_cst.cpp)
target_link_libraries(listing_5.4_seq_cst pthread)

add_executable(listing_5.5 listing_5.5.cpp)
target_link_libraries(listing_5.5 pthread)

add_executable(listing_5.6 listing_5.6.cpp)
target_link_libraries(listing_5.6 pthread)

add_executable(listing_5.7 listing_5.7.cpp)
target_link_libraries(listing_5.7 pthread)

add_executable(listing_5.8 listing_5.8.cpp)
target_link_libraries(listing_5.8 pthread)

add_executable(listing_5.9 listing_5.9.cpp)
target_link_libraries(listing_5.9 pthread)

add_executable(listing_5.10 listing_5.10.cpp)
target_link_libraries(listing_5.10 pthread)

add_executable(listing_5.11 listing_5.11.cpp)
target_link_libraries(listing_5.11 pthread)

add_executable(listing_5.12 listing_5.12.cpp)
target_link_libraries(listing_5.12 pthread)

add_executable(listing_5.13 listing_5.13.cpp)
target_link_libraries(listing_5.13 pthread)

add_executable(ex_5_1_1_atomic_flag ex_5_1_1_atomic_flag.cpp)
target_link_libraries(ex_5_1_1_atomic_flag pthread)

add_executable(ex_5_1_2_atomic_bool ex_5_1_2_atomic_bool.cpp)
target_link_libraries(ex_5_1_2_atomic_bool pthread)

add_executable(ex_5_1_3_compare_and_exchange ex_5_1_3_compare_and_exchange.cpp)
target_link_libraries(ex_5_1_3_compare_and_exchange pthread)

