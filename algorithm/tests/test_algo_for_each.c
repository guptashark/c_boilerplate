#include "algorithm.h"

#include <assert.h>

void test_algo_for_each(void);

int main(void) {

	test_algo_for_each();
	return 0;
}

void my_sqr ( void * d ) {
	int * k = d;
	* k = ( * k ) * ( * k );
}

void test_algo_for_each(void) {

	struct vector v;
	vector_ctor ( & v );

	int data_len = 5;
	int data[5] = { 0, 1, 2, 3, 4};

	for ( int i = 0; i < data_len; i++ ) {
		vector_push_back ( & v, & data[i] );
	}

	struct vector_iter it = vector_begin ( & v );
	struct vector_iter end = vector_end ( & v ) ;

	algo_for_each ( & it, & end, my_sqr );

	for ( int i = 0; i < data_len; i++ ) {
		assert ( data[i] == i * i );
	}

	vector_dtor ( & v );
}
