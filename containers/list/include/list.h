#ifndef LIST_H
#define LIST_H

struct node;

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

#endif
