#include "algorithm.h"

bool
algo_all_of(
	struct vector_iter * it_first,
	struct vector_iter * it_last,
	bool (* unary_predicate)(void *)
) {
	while ( vector_iter_neq ( it_first, it_last) ) {
		void * val = vector_iter_deref ( it_first );
		if ( unary_predicate ( val ) != true ) {
			return false;
		}

		vector_iter_inc ( it_first );
	}

	return true;
}

bool
algo_any_of(
	struct vector_iter * it_first,
	struct vector_iter * it_last,
	bool (* unary_predicate)(void *)
) {
	while ( vector_iter_neq ( it_first, it_last) ) {
		void * val = vector_iter_deref ( it_first );
		if ( unary_predicate ( val ) == true ) {
			return true;
		}

		vector_iter_inc ( it_first );
	}

	return false;
}

void
algo_for_each(
	struct vector_iter * it_first,
	struct vector_iter * it_last,
	void (* unary_fn)(void *)
) {
	while ( vector_iter_neq ( it_first, it_last ) ) {
		void * val = vector_iter_deref ( it_first );
		unary_fn ( val );
		vector_iter_inc ( it_first );
	}
}
