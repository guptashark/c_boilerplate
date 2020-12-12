#include "stack.h"

void
stack_ctor
( struct stack * s ) {
	s->v_ptr = & ( s->v );
	vector_ctor ( s->v_ptr );
}

void
stack_dtor
( struct stack * s ) {
	vector_dtor ( s->v_ptr );
}

void *
stack_top
( struct stack * s ) {
	return vector_back ( s->v_ptr );
}

bool
stack_empty
( struct stack * s ) {
	return vector_empty ( s->v_ptr );
}

size_t
stack_size
( struct stack * s ) {
	return vector_size ( s->v_ptr );
}

void
stack_push
( struct stack * s, void * val ) {
	vector_push_back ( s->v_ptr, val );
}
