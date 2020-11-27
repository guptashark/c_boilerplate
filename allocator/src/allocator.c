#include <stdio.h>
#include <stdint.h>

#define NUM_STORED_INTS 4

static uint32_t storage[NUM_STORED_INTS];

struct allocator {

	// data structure that keeps track of allocations.
	uint8_t markers[NUM_STORED_INTS];
};

static struct allocator alloc;

void * ag_malloc ( size_t num_bytes ) {

	// currently can only handle 4 byte values or less.
	if ( num_bytes > 4 ) {
		return NULL;
	}

	for ( int i = 0; i < NUM_STORED_INTS; i++) {
		if ( alloc.markers[i] == 0 ) {
			alloc.markers[i] = '1';
			return  & storage[i];
		}
	}

	// if we got here, there is no more memory to allocate.
	return NULL;
}

void ag_free ( void * p ) {

	// very inefficient, but it works.
	for ( int i = 0; i < NUM_STORED_INTS; i++ ) {
		if ( p == & storage[i] ) {
			// no need to clear the spot.
			alloc.markers[i] = 0;
		}
	}
}

void print_data(void) {

	for(int i = 0; i < NUM_STORED_INTS; i++) {
		printf("%d", storage[i]);
	}

	printf("\n");
}
