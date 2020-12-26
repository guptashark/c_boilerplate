#include <vector.h>

#include <assert.h>

void test_vector_iter_comprehensive(void);

int main(void) {

	test_vector_iter_comprehensive();
	return 0;
}

void test_vector_iter_comprehensive() {

	struct vector v;
	vector_ctor ( & v );

	int arr_len = 6;
	int arr[6] = { 3, 6, 1, 2, 4 };

	for ( int i = 0; i < arr_len; i++ ) {
		vector_push_back ( & v, & arr[i] );
	}

	{
		int i = 0;
		struct vector_iter it = vector_begin ( & v );
		struct vector_iter end = vector_end ( & v );

		while ( vector_iter_neq ( & it, & end ) ) {
			int * current_val = vector_iter_deref ( & it );
			assert ( * current_val == arr[i] );
			vector_iter_inc ( & it );
			i++;
		}
	}

	vector_dtor ( & v );
}
