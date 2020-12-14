#ifndef QUEUE_H
#define QUEUE_H

#include "list.h"

struct queue {
	// our internal structure
	// that we use to manage our stack.
	struct list lst;

	// convenience member fn for more legible code.
	struct list * lst_ptr;
};

void
queue_ctor
( struct queue * q );

void
queue_dtor
( struct queue * q );

// Element access

void *
queue_front
( struct queue * q );

void *
queue_back
( struct queue * q );

#endif
