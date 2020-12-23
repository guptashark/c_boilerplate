#include <stdlib.h>

#include "bst.h"

// the node structure needed for a
// bidirectional list.
struct bst_node {
	struct bst_node * left;
	struct bst_node * right;

	void * key;
	void * val;
};

void
bst_ctor
( struct bst * b ) {
	b->size = 0;
	b->root = NULL;
}
