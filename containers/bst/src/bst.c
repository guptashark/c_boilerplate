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

static
struct bst_node *
create_empty_node ( void * key, void * val ) {
	struct bst_node * ret = malloc ( sizeof ( struct bst_node ) );
	ret->left = NULL;
	ret->right = NULL;

	ret->key = key;
	ret->val = val;

	return ret;
}

void
bst_ctor
( struct bst * b, bool ( *less )( void *, void *) ) {
	b->size = 0;
	b->root = NULL;
	b->less = less;
}

// Will insert the key and value into the bst. In the case that
// the key already exists, the existing value will be overwritten
// with the new one.
//
// Note: This fn has a markedly different signature from the one
// in the C++ standard for maps.
void
bst_insert
( struct bst * b, void * key, void * val ) {

	struct bst_node * new_node = create_empty_node ( key, val );

	struct bst_node * par = NULL;
	struct bst_node * curr = b->root;

	while ( curr != NULL ) {
		par = curr;
		if ( b->less ( key, curr->key ) ) {
			curr = curr->left;
		} else {
			curr = curr->right;
		}
	}

	// tree is empty, so set the root.
	if ( par == NULL )  {
		b->root = new_node;
	} else {
		if ( b->less ( par->key, key ) ) {
			par->right = new_node;
		} else {
			par->left = new_node;
		}
	}

	b->size++;
}

size_t
bst_count
( struct bst * b, void * key ) {

	struct bst_node * curr = b->root;

	while ( curr != NULL ) {

		if ( b->less ( key, curr->key ) ) {
			curr = curr->left;
		} else if ( b->less ( curr->key, key ) ) {
			curr = curr->right;
		} else {
			return 1;
		}
	}

	return 0;
}
