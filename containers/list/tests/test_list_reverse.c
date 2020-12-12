#include <stddef.h>
#include <assert.h>

#include "list.h"

int test_list_reverse ( void );

int main ( void ) {

	test_list_reverse();
	return 0;
}

int test_list_reverse ( void ) {

	struct list s_obj;
	struct list * s = & s_obj;

	const int data_len = 10;
	int data[10];

	for ( int i = 0; i < data_len; i++ ) {
		data[i] = i;
	}

	list_ctor ( s );

	for ( int i = 0; i < data_len; i++ ) {
		list_push_front ( s, & data[i] );
	}

	list_reverse ( s );

	for ( int i = 0; i < data_len; i++ ) {
		int * p = list_front ( s );
		list_pop_front( s );
		assert ( * p == i );
	}

	assert ( list_size ( s ) == 0 );

	list_dtor ( s );
	return 0;
}

int test_list_clear ( void ) {

	struct list s;

	list_ctor ( & s );

	int x = 0;

	list_push_back ( & s, & x );
	list_push_back ( & s, & x );

	assert ( list_size ( & s ) == 2 );
	assert ( list_empty ( & s ) == false );

	list_clear ( & s );

	assert ( list_size ( & s ) == 0 );
	assert ( list_empty ( & s ) == true );

	list_dtor ( & s );

	return 0;
}

int test_list_comprehensive( void ) {

	// test that the init works.
	// we expect that the size is 0.
	struct list s;

	list_ctor ( & s );
	assert ( list_size ( & s ) == 0 );
	assert ( list_empty ( & s ) == true );

	int x = 0;
	int y = 0;

	list_push_back ( & s, & x );
	assert ( list_size ( & s ) == 1 );
	assert ( list_empty ( & s ) == false );
	assert ( list_back ( & s ) == & x );
	assert ( list_front ( & s ) == & x );

	list_push_back ( & s, & y );
	assert ( list_size ( & s ) == 2 );
	assert ( list_back ( & s ) == & y );
	assert ( list_front ( & s ) == & x );
	assert ( list_empty ( & s ) == false );

	list_pop_back ( & s );
	assert ( list_size ( & s ) == 1 );
	assert ( list_back ( & s ) == & x );
	assert ( list_front ( & s ) == & x );
	assert ( list_empty ( & s ) == false );

	// In the case that the list has size 0,
	// doing a pop will have no effect.
	list_pop_back ( & s );
	assert ( list_size ( & s ) == 0 );
	assert ( list_back ( & s ) == NULL );
	assert ( list_front ( & s ) == NULL );
	assert ( list_empty ( & s ) == true );

	list_dtor ( & s );

	return 0;
}
