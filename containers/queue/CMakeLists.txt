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
