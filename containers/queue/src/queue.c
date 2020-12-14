#include "queue.h"

void
queue_ctor
( struct queue * q ) {
	q->lst_ptr = & q->lst;
	list_ctor ( q->lst_ptr );
}

void
queue_dtor
( struct queue * q ) {
	list_dtor ( q->lst_ptr );
}

void *
queue_front
( struct queue * q ) {
	return list_front ( q->lst_ptr );
}

void *
queue_back
( struct queue * q ) {
	return list_back ( q->lst_ptr );
}
