#ifndef ALGORITHM_H
#define ALGORITHM_H

#include "vector.h"

bool
algo_all_of(
	struct vector_iter * it_first,
	struct vector_iter * it_last,
	bool (* unary_predicate)(void *) );

// Purpose:
// Determines if any of the values in between the two iterators
// satisfies the predicate.
//
// Return value:
// Returns true if the predicate returns true for any value between the
// iterators. Returns false otherwise. In the case of no elements,
// the fn returns false.
bool
algo_any_of(
	struct vector_iter * it_first,
	struct vector_iter * it_last,
	bool (* unary_predicate)(void *) );

bool
algo_none_of(
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
