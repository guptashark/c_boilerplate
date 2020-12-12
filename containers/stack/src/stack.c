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
