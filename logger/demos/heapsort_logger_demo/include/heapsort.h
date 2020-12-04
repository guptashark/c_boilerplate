#ifndef HEAPSORT_H
#define HEAPSORT_H

#include <stdbool.h>

void heapsort_module_init ( void );

bool is_sorted ( int * arr, int n );

bool is_heap ( int * arr, int n );

// build a min heap using William's method.
void heapify ( int * arr, int n );

#endif
