cmake_minimum_required ( VERSION 3.17 )

set ( this_project heapsort_logger_demo )
project ( ${this_project} )

add_executable ( ${this_project} )

target_sources ( ${this_project}
	PRIVATE src/main.c
	PRIVATE src/heapsort.c
)

target_include_directories ( ${this_project}
	PUBLIC include
)

target_link_libraries ( ${this_project}
	PRIVATE logger
)
