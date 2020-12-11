#include <assert.h>
#include <stddef.h>

#include "vector.h"

int test_push_back ( void );

int main ( void ) {

	test_push_back();
	return 0;
}

int test_push_back( void ) {

	struct vector v;

	vector_ctor ( & v );

	vector_push_back ( & v, NULL );

	assert ( v.size == 1 );

	vector_dtor ( & v );

	return 0;
}
