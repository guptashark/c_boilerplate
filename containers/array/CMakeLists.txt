cmake_minimum_required ( VERSION 3.17 )

set ( this_project array )
project ( ${this_project} )

add_library ( ${this_project} )

target_sources  (${this_project}
	PRIVATE src/array.c
)

target_include_directories ( ${this_project}
	PUBLIC include
)
