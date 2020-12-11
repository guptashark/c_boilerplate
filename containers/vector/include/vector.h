#ifndef VECTOR_H
#define VECTOR_H

#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

struct vector {

	uint32_t size;
	uint32_t capacity;

	// an array of void pointers.
	void ** arr;
};

void
vector_ctor
( struct vector * v );

void
vector_push_back
( struct vector * v, void * obj );

// Element Access fns.

// if i is less than size, (a valid index) then return the element at i.
// Otherwise, return NULL.
void *
vector_at
( struct vector * v, size_t i );

// if the vector has size 0, will return NULL.
void *
vector_front
( struct vector * v );

// if the vector has size 0, will return NULL.
void *
vector_back
( struct vector * v );

// Capacity fns.

bool
vector_empty
( struct vector * v );

size_t
vector_size
( struct vector * v );

size_t
vector_capacity
( struct vector * v );

void
vector_dtor
( struct vector * v );

#endif
