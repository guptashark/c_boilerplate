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

// Capacity
bool
stack_empty
( struct stack * s );

size_t
stack_size
( struct stack * s );

// Modifiers
void
stack_push
( struct stack * s, void * val );

// In the case that the stack is empty, has no effect.
void
stack_pop
( struct stack * s );

#endif
