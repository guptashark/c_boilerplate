#include <stddef.h>

#include "vector.h"

int test_init ( void );

int main ( void ) {

	int res = test_init();

	// this is a little redundant.
	if ( res != 0 ) {
		return 1;
	}

	return 0;
}

int test_init ( void ) {

	// test that the init works.
	// we expect that the size is 0.
	struct vector v;

	vector_ctor ( & v );

	if ( v.size != 0 ) {
		return 1;
	}

	if ( v.capacity <= 0 ) {
		return 1;
	}

	if ( v.arr == NULL ) {
		return 1;
	}

	vector_dtor ( & v );

	return 0;
}
