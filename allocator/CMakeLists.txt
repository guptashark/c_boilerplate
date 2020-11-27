cmake_minimum_required ( VERSION 3.17 )

add_subdirectory ( demos/basic_allocator_demo )

set ( this_project allocator)
project ( ${this_project} )

add_library ( ${this_project} )

target_sources ( ${this_project}
	PRIVATE src/allocator.c
)

target_include_directories ( ${this_project}
	PUBLIC include
)
