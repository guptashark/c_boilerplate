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
bst_dtor
( struct bst * b );

// Capacity

bool
bst_empty
( struct bst * b );

size_t
bst_size
( struct bst * b );

// Modifiers

// Will clear out all the nodes, and size will be set to zero. However,
// will retain the less than function. (Ie, ctor doesn't need to be
// called again).
void
bst_clear
( struct bst * b );

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
