#include <stdio.h>
#include <stdint.h>

static uint32_t storage[64];

struct allocator {

	// data structure that keeps track of allocations.
	uint8_t markers[64];
};

static struct allocator alloc;

void * ag_malloc ( size_t num_bytes ) {

	// currently can only handle 4 byte values or less.
	if ( num_bytes > 4 ) {
		return NULL;
	}

	for ( int i = 0; i < 64; i++) {
		if ( alloc.markers[i] == 0 ) {
			alloc.markers[i] = '1';
			return  & storage[i];
		}
	}

	// if we got here, there is no more memory to allocate.
	return NULL;
}

void print_data(void) {

	for(int i = 0; i < 64; i++) {
		printf("%d", storage[i]);
	}

	printf("\n");
}
