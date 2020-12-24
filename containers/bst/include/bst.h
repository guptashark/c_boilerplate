#ifndef BST_H
#define BST_H

#include <stdbool.h>
#include <stddef.h>

struct bst_node;

struct bst {

	size_t size;
	struct bst_node * root;

	bool ( *less )( void * k_01, void * k_02 );
};

// Note: The less fn ptr is required so that the bst can
// order the nodes in the structure.
//
// Interestingly enough, comparing the pointers themselves
// could work, if we had an avl tree. However, it's important
// to allow the client their own insertion fn.
void
bst_ctor
( struct bst * b, bool ( *less )( void *, void *));

void
bst_insert
( struct bst * b, void * key, void * val );

#endif
