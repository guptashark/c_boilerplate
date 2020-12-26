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

	int x = 0;
	int * x_ptr = & x;

	vector_push_back ( & v, x_ptr );
	assert ( v.size == 2 );

	uint32_t running_size = 2;

	// sort of an odd assertion,
	// but what kind of init fn would
	// allocate more than 1000. Plus, the
	// point of this test is to make sure
	// that we are in fact causing a realloc
	// at some point so that we can test
	// whether the vector handles it
	// correctly.
	assert ( v.capacity < 1000 );

	for ( int i = 0; i < 1000; i++ ) {
		vector_push_back ( & v, x_ptr );
		running_size++;
		assert ( v.size == running_size );
		assert ( v.capacity >= v.size );
	}

	vector_dtor ( & v );

	return 0;
}
