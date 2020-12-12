cmake_minimum_required ( VERSION 3.17 )

set ( this_project containers )
project ( ${this_project} )

set ( CONTAINERS_DIR ${CMAKE_CURRENT_LIST_DIR} )

enable_testing()

add_subdirectory ( vector )
add_subdirectory ( stack )
