#include <stdlib.h>

#include "list.h"

// the node structure needed for a
// bidirectional list.
struct node {
	struct node * next;
	struct node * prev;

	void * val;
};

static
struct node *
create_empty_node ( void * val ) {
	struct node * ret = malloc ( sizeof ( struct node ) );
	ret->next = NULL;
	ret->prev = NULL;
	ret->val = val;
}

void
list_ctor
( struct list * lst ) {

	lst->size = 0;
	struct node * front = create_empty_node ( NULL );
	struct node * back = create_empty_node ( NULL );

	front->next = back;
	back->prev = front;

	lst->front = front;
	lst->back = back;
}

void
list_dtor
( struct list * lst ) {

	struct node * to_del = lst->front;
	struct node * curr = to_del->next;

	while ( curr != NULL ) {
		free ( to_del );
		to_del = curr;
		curr = curr->next;
	}

	// free the last node, since the while loop deletes all the
	// nodes except for the last one
	free ( to_del );
}

void *
list_front
( struct list * lst ) {

	struct node * front = lst->front;
	return front->next->val;
}

void *
list_back
( struct list * lst ) {

	struct node * back = lst->back;
	return back->prev->val;
}
