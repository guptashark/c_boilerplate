cmake_minimum_required ( VERSION 3.17 )

set ( this_project vector )
project ( ${this_project} )

add_library ( ${this_project} )

target_sources  (${this_project}
	PRIVATE src/vector.c
)

target_include_directories ( ${this_project}
	PUBLIC include
)

# Testing #####################################################################

enable_testing()

add_executable ( test_init tests/test_init.c )
target_include_directories ( test_init PUBLIC include )
target_link_libraries ( test_init ${this_project} )

add_test ( test_init test_init )
