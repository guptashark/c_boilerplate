#ifndef VECTOR_H
#define VECTOR_H

#include <stdint.h>

struct vector {

	uint32_t size;
	uint32_t capacity;

	// an array of void pointers.
	void ** arr;
};

void
vector_ctor
( struct vector * v );

void
vector_dtor
( struct vector * v );

#endif
