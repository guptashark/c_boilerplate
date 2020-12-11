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
vector_dtor
( struct vector * v );

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

// if new_cap is larger than the current capacity, then the capacity
// of the array will be increased, with newly added storage.
// Otherwise, the function does nothing. (Ie, this function cannot
// be used to shrink the array)
//
// Additional note: If the memory allocation fails, ie, the allocator
// can't find a pointer to a block long enough, then this function
// does nothing.
void
vector_reserve
( struct vector * v, size_t new_cap );

size_t
vector_capacity
( struct vector * v );

// Will reduce the capacity to size. Ie, if the vector can hold
// 10 elements, and it currently holds 5, then a shrink_to_fit will
// reduce the capacity to 5.
void
vector_shrink_to_fit
( struct vector * v );

// Modifiers

// Clears the vector, but doesn't resize it, (no capacity change).
// The vector's size is set to 0.
// Array is now empty.
void
vector_clear
( struct vector * v );

void
vector_push_back
( struct vector * v, void * obj );

void
vector_pop_back
(struct vector * v );

#endif
