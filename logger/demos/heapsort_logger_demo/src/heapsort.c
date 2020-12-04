#include <stdio.h>

#include "heapsort.h"

#include "logger.h"

static struct logger hp_log;

void heapsort_module_init ( void ) {
	logger_init ( & hp_log, stdout, "heapsort.c" );
	logger_blacklist_fn ( & hp_log, "parent" );
}

bool is_sorted ( int * arr, int n ) {

	logger_set_fn_name( & hp_log, "is_sorted" );
	logger_trace_begin ( & hp_log );

	for ( int i = 0; i < n - 1; i++ ) {
		if ( arr[i] > arr[i+1] ) {
			return false;
		}
	}

	logger_trace_end ( & hp_log );

	return true;
}

static int left_child ( int i ) {
	logger_set_fn_name ( & hp_log, "left_child" );
	logger_trace_begin ( & hp_log );

	logger_trace_end ( & hp_log );
	return 2 * i + 1;
}

static int right_child ( int i ) {
	logger_set_fn_name ( & hp_log, "right_child" );
	logger_trace_begin ( & hp_log );

	logger_trace_end ( & hp_log );
	return 2 * i + 2;
}

// this function only works in the case
// when i > 0.
static int parent ( int i ) {
	logger_set_fn_name ( & hp_log, "parent" );
	logger_trace_begin ( & hp_log );

	logger_trace ( & hp_log, "par of %d is %d", i, ( i - 1 ) / 2 );

	logger_trace_end ( & hp_log );
	return ( i - 1 ) / 2;
}

bool is_heap ( int * arr, int n ) {

	logger_set_fn_name ( & hp_log, "is_heap" );
	logger_trace_begin ( & hp_log );

	bool heap_property = true;
	int i = 1;

	while ( i < n && heap_property ) {

		if ( arr[i] < arr[parent(i)] ) {
			heap_property = false;
		}

		i++;
	}

	logger_trace_end ( & hp_log );
	return heap_property;
}

// bubble up the element at the given index.
// this fn only works when index > 0.
static void bubble_up ( int * arr, int index ) {

	logger_set_fn_name ( & hp_log, "bubble_up" );
	logger_trace_begin ( & hp_log );

	bool in_correct_spot = false;

	do {
		if ( arr[index] < arr[parent(index)] ) {
			int tmp = arr[index];
			arr[index] = arr[parent(index)];
			arr[parent(index)] = tmp;

			index = parent(index);
		} else {
			// if no swapping, then the element is
			// now in the correct spot.
			in_correct_spot = true;
		}

	} while ( index > 0 && ( ! in_correct_spot ));

	logger_trace_end ( & hp_log );
}

void heapify ( int * arr, int n ) {

	logger_set_fn_name ( & hp_log, "heapify" );
	logger_trace_begin ( & hp_log );

	for ( int i = 1; i < n; i++ ) {
		bubble_up ( arr, i );
	}

	logger_trace_end ( & hp_log );
}
