#include <stddef.h>
#include <assert.h>

#include "list.h"

int cmp_ints ( void * a_ptr, void * b_ptr ) {

	int a = * ( int * ) a_ptr;
	int b = * ( int * ) b_ptr;

	return a - b;
}

int test_list_remove_01();
int test_list_remove_02();
int test_list_remove_03();
int test_list_remove_04();


int main ( void ) {

	// couple tests.
	//
	// 1)
	// empty list with remove is still empty.
	//
	// 2)
	// list of all the same elements, x, and with the
	// call to remove x. End list should be empty.
	//
	// 3)
	// list of elements, with no x, remove x means
	// that the list should be unchanged.
	//
	// 4)
	// list with one element x, remove that element,
	// the list should then be empty.
	//
	// 5)
	// list with mix of elements, elements.

	test_list_remove_01();
	test_list_remove_02();
	test_list_remove_02();
	test_list_remove_03();
	test_list_remove_04();

	return 0;
}

int test_list_remove_01( void ) {

	struct list s_obj;
	struct list * s = & s_obj;

	list_ctor ( s );

	int x = 0;
	list_remove ( s, & x, cmp_ints );

	assert ( list_size ( s ) == 0 );
	assert ( list_empty ( s ) );

	list_dtor ( s );
	return 0;
}

int test_list_remove_02( void ) {

	struct list s_obj;
	struct list * s = & s_obj;

	list_ctor ( s );

	const int data_len = 4;
	int data[4] = { 3, 3, 3, 3 };

	for ( int i = 0; i < 4; i++ ) {
		list_push_back ( s, & data[i] );
	}

	assert ( list_size ( s ) == 4 );
	assert ( list_empty ( s ) == false );

	int cmp_val = 3;

	list_remove ( s, & cmp_val, cmp_ints );

	assert ( list_size ( s ) == 0 );
	assert ( list_empty ( s ) );

	list_dtor ( s );
	return 0;
}

int test_list_remove_03( void ) {

	struct list s_obj;
	struct list * s = & s_obj;

	list_ctor ( s );

	const int data_len = 4;
	int data[4] = { 1, 2, 4, 5 };

	for ( int i = 0; i < 4; i++ ) {
		list_push_back ( s, & data[i] );
	}

	assert ( list_size ( s ) == 4 );
	assert ( list_empty ( s ) == false );

	int cmp_val = 3;

	list_remove ( s, & cmp_val, cmp_ints );

	assert ( list_size ( s ) == 4 );
	assert ( list_empty ( s ) == false );

	list_dtor ( s );
	return 0;
}

int test_list_remove_04( void ) {

	struct list s_obj;
	struct list * s = & s_obj;

	list_ctor ( s );

	const int data_len = 1;
	int data[1] = { 2 };

	for ( int i = 0; i < 1; i++ ) {
		list_push_back ( s, & data[i] );
	}

	assert ( list_size ( s ) == 1 );
	assert ( list_empty ( s ) == false );

	int cmp_val = 2;

	list_remove ( s, & cmp_val, cmp_ints );

	assert ( list_size ( s ) == 0 );
	assert ( list_empty ( s ) );

	list_dtor ( s );
	return 0;
}
