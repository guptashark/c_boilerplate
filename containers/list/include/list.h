#ifndef LIST_H
#define LIST_H

#include <stdbool.h>
#include <stddef.h>

struct list {

	size_t size;
	void * front;
	void * back;
};

void
list_ctor
( struct list * lst );

void
list_dtor
( struct list * lst );

// Element access

// if the list is empty, the front and back functions will
// return NULL.
void *
list_front
( struct list * lst );

void *
list_back
( struct list * lst );

// Capacity

bool
list_empty
( struct list * lst );

size_t
list_size
( struct list * lst );

// Modifiers

// in the case that the list is empty, this fn has no effect.
void
list_clear
( struct list * lst );

void
list_push_back
( struct list * lst, void * val );

// in the case that the list is empty, this fn has no effect.
void
list_pop_back
( struct list * lst );

void
list_push_front
( struct list * lst, void * val );

// in the case that the list is empty, this fn has no effect.
void
list_pop_front
( struct list * lst );

// Operations

// removes all occurrences of val in the list.
void
list_remove(
	struct list * lst,
	void * val,
	int ( * cmp_fn)(void *, void *));

void
list_remove_if(
	struct list * lst,
	bool ( * unary_predicate )( void * ));

void
list_reverse
( struct list * lst );

#endif
