#include "algorithm.h"

#include <assert.h>

void test_algo_all_of(void);

int main(void) {

	test_algo_all_of();
	return 0;
}

bool my_is_even( void * d ) {
	return ((*(int *)d) % 2) == 0;
}

void test_algo_all_of(void) {

	struct vector v;
	vector_ctor ( & v );

	int data_len = 5;
	int data[5] = { 2, 4, 6, 8, 10};

	for ( int i = 0; i < data_len; i++ ) {
		vector_push_back ( & v, & data[i] );
	}

	struct vector_iter it = vector_begin ( & v );
	struct vector_iter end = vector_end ( & v ) ;

	assert ( algo_all_of ( & it, & end, my_is_even ) == true );

	vector_dtor ( & v );
}
