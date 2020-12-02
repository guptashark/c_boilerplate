#include <stdio.h>
#include <string.h>

#include "logger.h"

void
logger_init
( struct logger * lg, const char * filename ) {
	strcpy ( lg->filename, filename );

	lg->stack_size = 0;
}

void
logger_trace
( struct logger * lg, const char * msg ) {
	printf("[TRACE]");
	printf("[%s]", lg->filename);
	printf("[%s]", lg->fn_name_stack[lg->stack_size - 1]);

	printf(": %s\n", msg);
}

void
logger_set_fn_name
( struct logger * lg, const char * fn_name ) {

	if ( lg->stack_size == 16 ) {
		printf("reached logger capacity!\n");
		return;
	}

	strcpy ( lg->fn_name_stack[lg->stack_size], fn_name );
	lg->stack_size++;
}

void
logger_trace_begin
( struct logger * lg ) {
	printf ( "[TRACE]" );
	printf ( "[%s]", lg->filename );
	printf ( "[%s]", lg->fn_name_stack[lg->stack_size - 1] );
	printf ( "[BEGIN]\n" );
}

void
logger_trace_end
( struct logger * lg ) {
	printf ( "[TRACE]" );
	printf ( "[%s]", lg->filename );
	printf ( "[%s]", lg->fn_name_stack[lg->stack_size - 1] );
	printf ( "[END]\n" );

	lg->stack_size--;
}

void
logger_trace_error
( struct logger * lg, const char * err ) {
	printf ( "[ERROR]" );
	printf ( "[%s]", lg->filename );
	printf ( "[%s]", lg->fn_name_stack[lg->stack_size - 1] );

	printf ( ": %s\n", err );
}
