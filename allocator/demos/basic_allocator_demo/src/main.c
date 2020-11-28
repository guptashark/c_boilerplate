#include <stdio.h>
#include <stdbool.h>
#include <stdint.h>

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

	ag_free ( y );
	ag_free ( z );

	// dealing with the basics.
	{
		uint32_t * ptrs[10];
		for ( int i = 0; i < 10; i++) {
			ptrs[i] = NULL;
		}

		int num_allocs = 0;
		bool alloc_failed = false;

		do {
			ptrs[num_allocs] = ag_malloc(sizeof(uint32_t));

			if ( ptrs[num_allocs] == NULL ) {
				alloc_failed = true;
			} else {
				num_allocs++;
			}
		} while ( ! alloc_failed );

		printf("Out of memory after %d allocs.\n", num_allocs);
	}

	return 0;
}
