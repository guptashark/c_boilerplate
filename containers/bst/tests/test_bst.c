#include "bst.h"

#include <assert.h>

void test_bst_insert(void);

int main(void) {

	test_bst_insert();
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
}
