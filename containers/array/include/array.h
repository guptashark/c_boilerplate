#ifndef ARRAY_H
#define ARRAY_H

#include <stddef.h>

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

#endif
