#include "vector_iter.h"

void
vector_iter_inc
( struct vector_iter * it ) {
	it->p++;
}

void *
vector_iter_deref
( struct vector_iter * it ) {
	return * (it->p);
}

bool
vector_iter_neq
( struct vector_iter * it, struct vector_iter * end ) {
       return it->p == end->p;
}
