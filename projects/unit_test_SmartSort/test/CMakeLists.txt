set(SOURCES 
	test_smartsort.cpp
)

add_executable(test_smartsort ${SOURCES})
target_link_libraries(test_smartsort
	gtest_main 
	gmock_main 
	smart_sort_lib
)

add_test(smartsort_test test_smartsort)