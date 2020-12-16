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

// In the case that the array is empty, return null.
// (empty as in initialized as a size 0 )
void *
array_front
( struct array * arr );

#endif
