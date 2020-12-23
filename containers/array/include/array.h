#ifndef ARRAY_H
#define ARRAY_H

#include <stddef.h>
#include <stdbool.h>

struct array {
	size_t size;
	void ** data;
};

void
array_ctor
( struct array * arr, size_t n );

void
array_dtor
( struct array * arr );

// Element Access

// Returns a pointer to the requested item in the array.
// In the case that pos is out of bounds, retuns null.
// (ie, pos >= size of the array )
void **
array_at
( struct array * arr, size_t pos );

// In the case that the array is empty, return null.
// (empty as in initialized as a size 0 )
void *
array_front
( struct array * arr );

// In the case that the array is empty, return null.
// (empty as in initialized as a size 0 )
void *
array_back
( struct array * arr );

// In the case that the array is empty, return null.
// (empty as in initialized as a size 0 )
void **
array_data
( struct array * arr );

// Capacity

bool
array_empty
( struct array * arr );

size_t
array_size
( struct array * arr );

// Operations

// Assign val to all the elements in the array.
void
array_fill
( struct array * arr, void * val );

#endif
