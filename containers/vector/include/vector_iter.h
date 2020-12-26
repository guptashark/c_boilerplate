#ifndef VECTOR_ITER_H
#define VECTOR_ITER_H

#include <stdbool.h>

// Note, it is likely that major modifications will be made to
// this iterator library as we try to figure out the best way
// to make this work with iterator functionality.
struct vector_iter {

	void ** p;
};

// increment:
// increment the iterator, since we don't have a ++ operator for structures.
void
vector_iter_inc
( struct vector_iter * it );

// dereference:
// deref the iterator to get the value the iterator is at.
void *
vector_iter_deref
( struct vector_iter * it );

// not equal:
// (use case is to compare with the end iterator returned by vector_end.
bool
vector_iter_neq
( struct vector_iter * it, struct vector_iter * end );

#endif
