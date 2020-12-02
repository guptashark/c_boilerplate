#include <stdio.h>

#include "heapsort.h"

#include "logger.h"

static struct logger hp_log;

void heapsort_module_init ( void ) {
	logger_init ( & hp_log, stdout, "heapsort.c" );
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
