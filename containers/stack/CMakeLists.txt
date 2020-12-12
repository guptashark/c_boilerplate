cmake_minimum_required ( VERSION 3.17 )

set ( this_project stack )
project ( ${this_project} )

add_library ( ${this_project} )

target_sources ( ${this_project}
	PRIVATE src/stack.c
)

target_include_directories ( ${this_project}
	PUBLIC include
	PUBLIC ../vector/include
)

target_link_libraries ( ${this_project}
	PRIVATE vector
)
