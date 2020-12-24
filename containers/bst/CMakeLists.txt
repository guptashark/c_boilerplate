cmake_minimum_required ( VERSION 3.17 )

set ( this_project bst )
project ( ${this_project} )

add_library ( ${this_project} )

target_sources  (${this_project}
	PRIVATE src/bst.c
)

target_include_directories ( ${this_project}
	PUBLIC include
)

add_executable ( test_bst tests/test_bst.c )
target_include_directories ( test_bst PUBLIC include )
target_link_libraries ( test_bst ${this_project} )
add_test ( test_bst test_bst )
