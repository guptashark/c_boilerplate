#ifndef ALGORITHM_H
#define ALGORITHM_H

#include "vector.h"

bool
algo_all_of(
	struct vector_iter * it_first,
	struct vector_iter * it_last,
	bool (* unary_predicate)(void *) );

// for these fns to work, we need to pass a vtable that has all the
// different functions to use on the given iterators.
//
// But for now, we specialize this fn for vectors.
void
algo_for_each(
	struct vector_iter * it_first,
	struct vector_iter * it_last,
	void (* unary_fn)(void *) );

#endif
