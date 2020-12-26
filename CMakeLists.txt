cmake_minimum_required ( VERSION 3.17 )

set ( this_project c_boilerplate )
project ( ${this_project} )

set ( C_BOILERPLATE_DIR ${CMAKE_CURRENT_LIST_DIR} )

enable_testing()

add_subdirectory ( algorithm )
add_subdirectory ( allocator )
add_subdirectory ( containers )
add_subdirectory ( logger )
