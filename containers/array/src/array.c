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

void **
array_at
( struct array * arr, size_t pos ) {
	if ( pos >= arr->size ) {
		return NULL;
	}

	return & arr->data[pos];
}

void *
array_front
( struct array * arr ) {

	if ( arr->size == 0 ) {
		return NULL;
	}

	return arr->data[0];
}

void *
array_back
( struct array * arr ) {
	
	if ( arr->size == 0 ) {
		return NULL;
	}

	return arr->data[arr->size - 1];
}

void **
array_data
( struct array * arr ) {

	if ( arr->size == 0 ) {
		return NULL;
	}

	return arr->data;
}

bool
array_empty
( struct array * arr ) {
	return arr->size == 0;
}

size_t
array_size
( struct array * arr ) {
	return arr->size;
}

void
array_fill
( struct array * arr, void * val ) {
	for ( size_t i = 0; i < arr->size; i++ ) {
		arr->data[i] = val;
	}
}
