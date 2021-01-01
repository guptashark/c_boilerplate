cmake_minimum_required ( VERSION 3.17 )

set ( this_project algorithm )
project ( ${this_project} )

add_library ( ${this_project} )

target_sources  (${this_project}
	PRIVATE src/algorithm.c
)

target_include_directories ( ${this_project}
	PUBLIC include
	PUBLIC ${C_BOILERPLATE_DIR}/containers/vector/include
)

# message ( STATUS "my boilerplate value: ${C_BOILERPLATE}" )

target_link_libraries ( ${this_project}
	PRIVATE vector
)

# Testing #####################################################################

# Testing for each.
add_executable ( test_algo_for_each tests/test_algo_for_each.c )
target_include_directories ( test_algo_for_each
	PUBLIC include
	PUBLIC ${C_BOILERPLATE}/containers/vector/include
)

target_link_libraries ( test_algo_for_each ${this_project} )
add_test ( test_algo_for_each test_algo_for_each )

# Testing all of.
add_executable ( test_algo_all_of tests/test_algo_all_of.c )
target_include_directories ( test_algo_all_of
	PUBLIC include
	PUBLIC ${C_BOILERPLATE}/containers/vector/include
)

target_link_libraries ( test_algo_all_of ${this_project} )
add_test ( test_algo_all_of test_algo_all_of )

# Testing any_of
add_executable ( test_algo_any_of tests/test_algo_any_of.c )
target_include_directories ( test_algo_any_of
	PUBLIC include
	PUBLIC ${C_BOILERPLATE}/containers/vector/include
)

target_link_libraries ( test_algo_any_of ${this_project} )
add_test ( test_algo_any_of test_algo_any_of )

# Testing none_of
add_executable ( test_algo_none_of tests/test_algo_none_of.c )
target_include_directories ( test_algo_none_of
	PUBLIC include
	PUBLIC ${C_BOILERPLATE}/containers/vector/include
)

target_link_libraries ( test_algo_none_of ${this_project} )
add_test ( test_algo_none_of test_algo_none_of )
