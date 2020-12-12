#include <stddef.h>

#include "stack.h"

int test_init ( void );

int main ( void ) {

	test_init();

	return 0;
}

// this test is interesting in that we're
// directly checking the underlying data
// structure to see if the init is successful.
int test_init ( void ) {

	// test that the init works.
	// we expect that the size is 0.
	struct stack s;

	stack_ctor ( & s );

	if ( s.v_ptr == NULL ) {
		return 1;
	}

	if ( s.v.size != 0 ) {
		return 1;
	}

	if ( s.v.size <= 0 ) {
		return 1;
	}

	if ( s.v.arr == NULL ) {
		return 1;
	}

	stack_dtor ( & s );

	return 0;
}
