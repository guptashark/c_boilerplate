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

#endif
