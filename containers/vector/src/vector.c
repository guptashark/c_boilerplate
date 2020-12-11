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
vector_dtor
( struct vector * v ) {
	free ( v->arr );
}
