#include "bst.h"

#include <assert.h>

void test_bst_insert(void);
void test_bst_count(void);

int main(void) {

	test_bst_insert();
	test_bst_count();
	return 0;
}

bool int_less ( void * a_p, void * b_p ) {
	int * a = a_p;
	int * b = b_p;

	if ( * a < * b ) {
		return true;
	} else {
		return false;
	}
}

void test_bst_insert(void) {

	int arr[3] = {5, 3, 7};

	struct bst b;
	bst_ctor ( & b, int_less );
	assert ( b.size == 0 );
	assert ( b.root == NULL );

	bst_insert ( & b, & arr[0], NULL );
	assert ( b.size == 1 );
	assert ( b.root != NULL );

	bst_insert ( & b, & arr[1], NULL );
	assert ( b.size == 2 );

	bst_insert ( & b, & arr[2], NULL );
	assert ( b.size == 3 );

	bst_dtor ( & b );
}

void test_bst_count(void) {

	int arr[3] = {5, 3, 7};

	struct bst b;
	bst_ctor ( & b, int_less );
	assert ( b.size == 0 );
	assert ( b.root == NULL );

	bst_insert ( & b, & arr[0], NULL );
	assert ( b.size == 1 );
	assert ( b.root != NULL );

	bst_insert ( & b, & arr[1], NULL );
	assert ( b.size == 2 );

	bst_insert ( & b, & arr[2], NULL );
	assert ( b.size == 3 );

	// testing the counts.
	int expected_counts_len = 10;
	int expected_counts[10] = { 0, 0, 0, 1, 0, 1, 0, 1, 0, 0 };

	for ( int i = 0; i < expected_counts_len; i++ ) {
		int key = i;
		assert ( bst_count ( & b, & key ) == expected_counts[i] );
	}

	bst_dtor ( & b );
}
