#include <stdio.h>

#include "allocator.h"

int main(void) {

	printf("basic_allocator_demo\n");

	print_data();

	int * x = ag_malloc(sizeof(int));
	* x = 8;

	int * y = ag_malloc(sizeof(int));
	* y = 5;


	printf("after 2 allocs\n");
	print_data();
	ag_free( x );

	int * z = ag_malloc(sizeof(int));
	* z = 3;

	printf("after a free and another alloc\n");

	print_data();

	return 0;
}
