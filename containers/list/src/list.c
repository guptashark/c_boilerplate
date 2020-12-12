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

bool
list_empty
( struct list * lst ) {
	return ( lst->size == 0 );
}

size_t
list_size
( struct list * lst ) {
	return lst->size;
}

void
list_push_back
( struct list * lst, void * val ) {

	struct node * new_back = create_empty_node ( val );
	struct node * back_dummy = lst->back;
	struct node * old_back = back_dummy->prev;

	old_back->next = new_back;
	new_back->prev = old_back;

	new_back->next = back_dummy;
	back_dummy->prev = new_back;

	lst->size++;
}

void
list_pop_back
( struct list * lst ) {

	if ( lst->size == 0 ) {
		return;
	}

	struct node * back_dummy = lst->back;
	struct node * curr_back = back_dummy->prev;
	struct node * new_back = curr_back->prev;

	free ( curr_back );

	new_back->next = back_dummy;
	back_dummy->prev = new_back;

	lst->size--;
}

void
list_push_front
( struct list * lst, void * val ) {

	struct node * new_front = create_empty_node ( val );
	struct node * front_dummy = lst->front;
	struct node * old_front = front_dummy->next;

	old_front->prev = new_front;
	new_front->next = old_front;

	new_front->prev = front_dummy;
	front_dummy->next = new_front;

	lst->size++;
}

void
list_pop_front
( struct list * lst ) {

	if ( lst->size == 0 ) {
		return;
	}

	struct node * front_dummy = lst->front;
	struct node * curr_front = front_dummy->next;
	struct node * new_front = curr_front->next;

	free ( curr_front );

	new_front->prev = front_dummy;
	front_dummy->next = new_front;

	lst->size--;
}
