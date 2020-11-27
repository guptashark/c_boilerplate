#include <stdio.h>

#include "allocator.h"

int main(void) {

	printf("basic_allocator_demo\n");

	int * x = ag_malloc(sizeof(int));

	if ( x == NULL ) {
		printf("ag_malloc returned NULL\n");
	} else {
		printf("ag_malloc returned %p\n", x);
	}

	return 0;
}
