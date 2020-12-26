#include "vector.h"
#include "vector_iter.h"

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

struct vector_iter
vector_begin
( struct vector * v ) {
	struct vector_iter ret;
	ret.p = v->arr;
	return ret;
}

struct vector_iter
vector_end
( struct vector * v ) {
	struct vector_iter ret;
	ret.p = & v->arr[v->size];
	return ret;
}

bool
vector_empty
( struct vector * v ) {
	return v->size == 0;
}

size_t
vector_size
( struct vector * v ) {
	return v->size;
}

void
vector_reserve
( struct vector * v, size_t new_cap ) {

	if ( v->capacity >= new_cap ) {
		return;
	}

	void ** new_arr = realloc ( v->arr, new_cap );

	// in the case that realloc fails, a NULL is returned.
	// Hence, we will keep the original array in case the
	// realloc fails.
	if ( new_arr != NULL ) {
		v->arr = new_arr;
		v->capacity = new_cap;
	}
}

size_t
vector_capacity
( struct vector * v ) {
	return v->capacity;
}

void
vector_shrink_to_fit
( struct vector * v ) {

	// if 0 is given to realloc, it is implementation defined.
	// Instead, we can free the array and set both size and
	// capacity to zero.
	if ( v->size == 0 ) {
		free ( v->arr );
		v->capacity = 0;
	} else {
		void ** new_arr = realloc ( v->arr, v->size );
		if ( new_arr != NULL ) {
			v->arr = new_arr;
			v->capacity = v->size;
		}
	}
}

void
vector_clear
( struct vector * v ) {
	v->size = 0;
}

void
vector_push_back
( struct vector * v, void * obj ) {

	// Need to always have the capacity bigger than
	// the size so that the vector_end iterator works.
	if ( ( v->size + 1 ) == v->capacity ) {
		v->capacity = v->capacity * 2;
	}

	v->arr = realloc ( v->arr, sizeof ( void * ) * v->capacity );

	v->arr[v->size] = obj;
	v->size++;
}

void
vector_pop_back
( struct vector * v ) {

	if ( v->size > 0 ) {
		v->size--;
	}
}
