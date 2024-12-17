add_executable(listing_3.1 listing_3.1.cpp)
target_link_libraries(listing_3.1 pthread)

add_executable(listing_3.2 listing_3.2.cpp)
target_link_libraries(listing_3.2 pthread)

add_executable(listing_3.5 listing_3.5.cpp)
target_link_libraries(listing_3.5 pthread)

add_executable(listing_3.7 listing_3.7.cpp)
target_link_libraries(listing_3.7 pthread)

add_executable(listing_3.8 listing_3.8.cpp)
target_link_libraries(listing_3.8 pthread)

add_executable(listing_3.10 listing_3.10.cpp)
target_link_libraries(listing_3.10 pthread)

add_executable(listing_3.11 listing_3.11.cpp)
target_link_libraries(listing_3.11 pthread)

add_executable(listing_3.12 listing_3.12.cpp)
target_link_libraries(listing_3.12 pthread)

add_executable(listing_3.13 listing_3.13.cpp)
target_link_libraries(listing_3.13
						${Boost_SYSTEM_LIBRARY}
						${Boost_THREAD_LIBRARY}
)

add_executable(example_3_6_deadlock example_3_6_deadlock.cpp)
target_link_libraries(example_3_6_deadlock pthread)

add_executable(example_3_7_deadlock_resolved example_3_7_deadlock_resolved.cpp)
target_link_libraries(example_3_7_deadlock_resolved pthread)
