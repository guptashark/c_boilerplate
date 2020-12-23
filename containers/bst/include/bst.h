#ifndef BST_H
#define BST_H

#include <stdbool.h>
#include <stddef.h>

struct bst_node;

struct bst {

	size_t size;
	struct bst_node * root;
};

void
bst_ctor
( struct bst * b );

#endif
