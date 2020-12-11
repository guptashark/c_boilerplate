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
	v->size++;
}

void *
vector_at
( struct vector * v, size_t i ) {
	if ( i >= v->size ) {
		return NULL;
	}

	return v->arr[i];
}

void *
vector_front
( struct vector * v ) {

	if ( v->size == 0 ) {
		return NULL;
	}

	return v->arr[0];
}

void *
vector_back
( struct vector * v ) {

	if ( v->size == 0 ) {
		return NULL;
	}

	return v->arr[v->size - 1];
}

size_t
vector_size
( struct vector * v ) {
	return v->size;
}

void
vector_dtor
( struct vector * v ) {
	free ( v->arr );
}
