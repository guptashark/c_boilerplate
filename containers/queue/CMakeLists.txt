cmake_minimum_required ( VERSION 3.17 )

set ( this_project queue )
project ( ${this_project} )

add_library ( ${this_project} )

target_sources ( ${this_project}
	PRIVATE src/queue.c
)

target_include_directories ( ${this_project}
	PUBLIC include
	PUBLIC ${CONTAINERS_DIR}/list/include
)

target_link_libraries ( ${this_project}
	PRIVATE list
)

# Testing #####################################################################

add_executable ( test_queue_comprehensive tests/test_queue_comprehensive.c )
target_include_directories ( test_queue_comprehensive PUBLIC include )
target_link_libraries ( test_queue_comprehensive ${this_project} )
add_test (test_queue_comprehensive test_queue_comprehensive )
