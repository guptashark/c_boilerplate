#include "vector.h"

#include <stdlib.h>

void
vector_ctor
( struct vector * v ) {

	v->size = 0;
	v->capacity = 4;

	v->arr = malloc ( sizeof ( void * ) * v->capacity );
}

void
vector_push_back
( struct vector * v, void * obj ) {

	if ( v->size == v->capacity ) {
		v->capacity = v->capacity * 2;
	}

	v->arr = realloc ( v->arr, sizeof ( void * ) * v->capacity );

	v->arr[v->size] = obj;
}

void
vector_dtor
( struct vector * v ) {
	free ( v->arr );
}
