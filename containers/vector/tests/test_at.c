#include <assert.h>
#include <stddef.h>

#include "vector.h"

int test_at( void );

int main ( void ) {

	test_at();
	return 0;
}

int test_at( void ) {

	struct vector v;

	vector_ctor ( & v );

	int x = 0;
	int * x_ptr = & x;
	int y = 0;
	int * y_ptr = & y;

	vector_push_back ( & v, x_ptr );
	vector_push_back ( & v, y_ptr );

	assert ( vector_at ( & v, 0 ) == x_ptr );
	assert ( vector_at ( & v, 1 ) == y_ptr );
	assert ( vector_at ( & v, 2 ) == NULL );

	vector_dtor ( & v );

	return 0;
}
