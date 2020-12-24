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

// Capacity

bool
bst_empty
( struct bst * b );

// Modifiers

void
bst_insert
( struct bst * b, void * key, void * val );

// Lookup

// Return the number of number of elements matching the given key.
// Since the bst has unique keys, this fn returns 0 or 1.
size_t
bst_count
( struct bst * b, void * key );

#endif
