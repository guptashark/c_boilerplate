cmake_minimum_required ( VERSION 3.17 )

set ( this_project list )
project ( ${this_project} )

add_library ( ${this_project} )

target_sources  (${this_project}
	PRIVATE src/list.c
)

target_include_directories ( ${this_project}
	PUBLIC include
)

# Testing #####################################################################

add_executable ( test_list_comprehensive tests/test_list_comprehensive.c )
target_include_directories ( test_list_comprehensive PUBLIC include )
target_link_libraries ( test_list_comprehensive ${this_project} )
add_test (test_list_comprehensive test_list_comprehensive )
