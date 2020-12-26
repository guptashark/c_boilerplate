cmake_minimum_required ( VERSION 3.17 )

set ( this_project vector )
project ( ${this_project} )

add_library ( ${this_project} )

target_sources  (${this_project}
	PRIVATE src/vector.c
	PRIVATE src/vector_iter.c
)

target_include_directories ( ${this_project}
	PUBLIC include
)

# Testing #####################################################################

add_executable ( test_vector_init tests/test_vector_init.c )
target_include_directories ( test_vector_init PUBLIC include )
target_link_libraries ( test_vector_init ${this_project} )
add_test ( test_vector_init test_vector_init )

add_executable ( test_vector_push_back tests/test_vector_push_back.c )
target_include_directories ( test_vector_push_back PUBLIC include )
target_link_libraries ( test_vector_push_back ${this_project} )
add_test ( test_vector_push_back test_vector_push_back )

add_executable ( test_vector_at tests/test_vector_at.c )
target_include_directories ( test_vector_at PUBLIC include )
target_link_libraries ( test_vector_at ${this_project} )
add_test ( test_vector_at test_vector_at )

add_executable ( test_vector_iter_comprehensive tests/test_vector_iter_comprehensive.c )
target_include_directories ( test_vector_iter_comprehensive PUBLIC include )
target_link_libraries ( test_vector_iter_comprehensive ${this_project} )
add_test ( test_vector_iter_comprehensive test_vector_iter_comprehensive )
