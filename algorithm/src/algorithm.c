#include "algorithm.h"

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
