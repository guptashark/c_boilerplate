#include <stddef.h>
#include <assert.h>

#include "queue.h"

int test_queue_comprehensive ( void );

int main ( void ) {

	test_queue_comprehensive();
	return 0;
}

int test_queue_comprehensive( void ) {

	// test that the init works.
	// we expect that the size is 0.
	struct queue q;

	queue_ctor ( & q );
	assert ( queue_size ( & q ) == 0 );
	assert ( queue_front ( & q ) == NULL );
	assert ( queue_empty ( & q ) == true );

	int x = 0;
	int y = 0;

	queue_push ( & q, & x );
	assert ( queue_front ( & q ) == & x );
	assert ( queue_back ( & q ) == & x );
	assert ( queue_size ( & q ) == 1 );
	assert ( queue_empty ( & q ) == false );

	queue_push ( & q, & y );
	assert ( queue_front ( & q ) == & x );
	assert ( queue_back ( & q ) == & y );
	assert ( queue_size ( & q ) == 2 );
	assert ( queue_empty ( & q ) == false );

	queue_pop ( & q );
	assert ( queue_front ( & q ) == & y );
	assert ( queue_back ( & q) == & y );
	assert ( queue_size ( & q ) == 1 );
	assert ( queue_empty ( & q ) == false );

	// In the case that the queue has size 0,
	// doing a pop will have no effect.
	queue_pop ( & q );
	assert ( queue_size ( & q ) == 0 );
	assert ( queue_front ( & q ) == NULL );
	assert ( queue_empty ( & q ) == true );

	queue_dtor ( & q );

	return 0;
}
