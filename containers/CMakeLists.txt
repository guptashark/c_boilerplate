cmake_minimum_required ( VERSION 3.17 )

set ( this_project containers )
project ( ${this_project} )

set ( CONTAINERS_DIR ${CMAKE_CURRENT_LIST_DIR} )

add_subdirectory ( vector )
add_subdirectory ( array )
add_subdirectory ( stack )
add_subdirectory ( queue )
add_subdirectory ( list )
add_subdirectory ( bst )
