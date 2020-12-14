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

bool
queue_empty
( struct queue * q ) {
	return list_empty ( q->lst_ptr );
}

size_t
queue_size
( struct queue * q ) {
	return list_size ( q->lst_ptr );
}

void
queue_push
( struct queue * q, void * val ) {
	return list_push_back ( q->lst_ptr, val );
}
