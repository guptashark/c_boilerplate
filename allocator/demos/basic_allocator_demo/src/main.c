#include <stdio.h>

#include "allocator.h"

int main(void) {

	printf("basic_allocator_demo\n");

	print_data();

	int * x = ag_malloc(sizeof(int));

	* x = 512;

	if ( x == NULL ) {
		printf("ag_malloc returned NULL\n");
	} else {
		printf("ag_malloc returned %p\n", x);
	}

	print_data();

	return 0;
}
