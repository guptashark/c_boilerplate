cmake_minimum_required ( VERSION 3.17 )

add_subdirectory ( demos/basic_logger_demo EXCLUDE_FROM_ALL)
add_subdirectory ( demos/heapsort_logger_demo EXCLUDE_FROM_ALL)

set ( this_project logger)
project ( ${this_project} )

add_library ( ${this_project} )

target_sources ( ${this_project}
	PRIVATE src/logger.c
)

target_include_directories ( ${this_project}
	PUBLIC include
)
