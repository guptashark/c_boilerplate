#include <stdio.h>
#include <string.h>

#include "logger.h"

enum log_type {
	TRACE = 0,
	ERROR = 1,
	DEBUG = 2,
	INFO = 3
};

static const char *log_type_str_vals [4] = {
	"TRACE",
	"ERROR",
	"DEBUG",
	"INFO"
};

void
logger_init
( struct logger * lg, const char * filename ) {
	strcpy ( lg->filename, filename );

	lg->stack_size = 0;
}

static
void
logger_print_helper
( struct logger * lg, enum log_type t ) {
	printf ( "[%s]", log_type_str_vals[t] );
	printf ( "[%s]", lg->filename );
	printf ( "[%s]", lg->fn_name_stack[lg->stack_size - 1] );
}

void
logger_trace
( struct logger * lg, const char * fmt_msg, ... ) {
	logger_print_helper ( lg, TRACE );
	printf(": ");

	va_list args;
	va_start ( args, fmt_msg );

	vprintf ( fmt_msg, args );
	va_end ( args );
	printf("\n");
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
	logger_print_helper ( lg, TRACE );
	printf ( "[BEGIN]\n" );
}

void
logger_trace_end
( struct logger * lg ) {
	logger_print_helper ( lg, TRACE );
	printf ( "[END]\n" );

	lg->stack_size--;
}

void
logger_trace_error
( struct logger * lg, const char * fmt_err, ... ) {
	logger_print_helper ( lg, ERROR );
	printf ( ": " );

	va_list args;
	va_start ( args, fmt_err );

	vprintf ( fmt_err, args );

	va_end ( args );

	printf("\n");
}
