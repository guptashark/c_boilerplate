#include <stddef.h>
#include <assert.h>

#include "stack.h"

int test_stack_comprehensive ( void );

int main ( void ) {

	test_stack_comprehensive();
	return 0;
}

int test_stack_comprehensive( void ) {

	// test that the init works.
	// we expect that the size is 0.
	struct stack s;

	stack_ctor ( & s );
	assert ( stack_size ( & s ) == 0 );
	assert ( stack_top ( & s ) == NULL );
	assert ( stack_empty ( & s ) == true );

	int x = 0;
	int y = 0;

	stack_push ( & s, & x );
	assert ( stack_size ( & s ) == 1 );
	assert ( stack_top ( & s ) == & x );
	assert ( stack_empty ( & s ) == false );

	stack_push ( & s, & y );
	assert ( stack_size ( & s ) == 2 );
	assert ( stack_top ( & s ) == & y );
	assert ( stack_empty ( & s ) == false );

	stack_pop ( & s );
	assert ( stack_size ( & s ) == 1 );
	assert ( stack_top ( & s ) == & x );
	assert ( stack_empty ( & s ) == false );

	// In the case that the stack has size 0,
	// doing a pop will have no effect.
	stack_pop ( & s );
	assert ( stack_size ( & s ) == 0 );
	assert ( stack_top ( & s ) == NULL );
	assert ( stack_empty ( & s ) == true );

	stack_dtor ( & s );

	return 0;
}
