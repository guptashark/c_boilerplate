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

	return ret;
}

// connects the two nodes a and b, so
// that they are in this order in the list.
static
void
connect_nodes
( struct node * a, struct node * b ) {
	a->next = b;
	b->prev = a;
}

void
list_ctor
( struct list * lst ) {

	lst->size = 0;
	struct node * front = create_empty_node ( NULL );
	struct node * back = create_empty_node ( NULL );

	connect_nodes ( front, back );

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
list_clear
( struct list * lst ) {

	if ( lst->size == 0 ) {
		return;
	}

	struct node * front_dummy = lst->front;
	struct node * back_dummy = lst->back;
	struct node * to_del = front_dummy->next;
	struct node * curr = to_del->next;

	while ( curr != NULL ) {
		free ( to_del );
		to_del = curr;
		curr = curr->next;
	}

	// don't need to free to_del, since we're not deleting the
	// back_dummy.

	connect_nodes ( front_dummy, back_dummy );

	lst->size = 0;
}

void
list_push_back
( struct list * lst, void * val ) {

	struct node * new_back = create_empty_node ( val );
	struct node * back_dummy = lst->back;
	struct node * old_back = back_dummy->prev;

	connect_nodes ( old_back, new_back );
	connect_nodes ( new_back, back_dummy );

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

	connect_nodes ( new_back, back_dummy );

	lst->size--;
}

void
list_push_front
( struct list * lst, void * val ) {

	struct node * new_front = create_empty_node ( val );
	struct node * front_dummy = lst->front;
	struct node * old_front = front_dummy->next;

	connect_nodes ( front_dummy, new_front );
	connect_nodes ( new_front, old_front );

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

	connect_nodes ( front_dummy, new_front );

	lst->size--;
}

void
list_remove
(
	struct list * lst,
	void * val,
	int ( * cmp_fn)(void *, void *)
) {
	if ( lst->size == 0 ) {
		return;
	}

	struct node * front_dummy = lst->front;
	struct node * curr = front_dummy->next;

	while ( curr != lst->back ) {

		if ( cmp_fn ( val, curr->val ) == 0 ) {

			struct node * curr_prev = curr->prev;
			struct node * to_del = curr;
			curr = curr->next;

			free ( to_del );

			connect_nodes ( curr_prev, curr );
			lst->size--;
		} else {
			curr = curr->next;
		}
	}
}

void
list_remove_if
(
	struct list * lst,
	bool ( * unary_predicate)(void *)
) {
	if ( lst->size == 0 ) {
		return;
	}

	struct node * front_dummy = lst->front;
	struct node * curr = front_dummy->next;

	while ( curr != lst->back ) {

		if ( unary_predicate ( curr->val ) ) {

			struct node * curr_prev = curr->prev;
			struct node * to_del = curr;
			curr = curr->next;

			free ( to_del );

			connect_nodes ( curr_prev, curr );
			lst->size--;
		} else {
			curr = curr->next;
		}
	}
}

void
list_reverse
( struct list * lst ) {

	struct node * curr = lst->front;
	struct node * tmp = NULL;

	while ( curr != NULL ) {
		tmp = curr->prev;
		curr->prev = curr->next;
		curr->next = tmp;

		curr = curr->prev;
	}

	tmp = lst->front;
	lst->front = lst->back;
	lst->back = tmp;
}
