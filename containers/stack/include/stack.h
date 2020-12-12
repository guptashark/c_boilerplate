#ifndef STACK_H
#define STACK_H

#include "vector.h"

struct stack {
	// our internal structure
	// that we use to manage our stack.
	struct vector v;

	// convenience member fn for more legible code.
	struct vector * v_ptr;
};

void
stack_ctor
( struct stack * s );

void
stack_dtor
( struct stack * s );

// Element access
void *
stack_top
( struct stack * s );

#endif
