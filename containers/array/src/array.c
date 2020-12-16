#include "array.h"

#include <stdlib.h>

void
array_ctor
( struct array * arr, size_t n ) {

	arr->size = n;
	arr->data = malloc( sizeof ( void * ) * n );
}

void
array_dtor
( struct array * arr ) {
	free ( arr->data );
}

void *
array_front
( struct array * arr ) {

	if ( arr->size == 0 ) {
		return NULL;
	}

	return arr->data[0];
}
