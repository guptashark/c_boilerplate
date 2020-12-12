cmake_minimum_required ( VERSION 3.17 )

set ( this_project stack )
project ( ${this_project} )

add_library ( ${this_project} )

target_sources ( ${this_project}
	PRIVATE src/stack.c
)

target_include_directories ( ${this_project}
	PUBLIC include
	PUBLIC ${CONTAINERS_DIR}/vector/include
)

target_link_libraries ( ${this_project}
	PRIVATE vector
)

# Testing #####################################################################

add_executable ( test_stack_init tests/test_stack_init.c )
target_include_directories ( test_stack_init PUBLIC include )
target_link_libraries ( test_stack_init ${this_project} )
add_test (test_stack_init test_stack_init )
