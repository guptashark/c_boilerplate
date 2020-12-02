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
( struct logger * lg, FILE * output_file, const char * filename ) {
	lg->output_file = output_file;
	strcpy ( lg->filename, filename );

	lg->stack_size = 0;
}

static
void
logger_print_helper
( struct logger * lg, enum log_type t ) {
	FILE * f = lg->output_file;
	fprintf ( f, "[%s]", log_type_str_vals[t] );
	fprintf ( f, "[%s]", lg->filename );
	fprintf ( f, "[%s]", lg->fn_name_stack[lg->stack_size - 1] );
}

void
logger_trace
( struct logger * lg, const char * fmt_msg, ... ) {
	logger_print_helper ( lg, TRACE );

	fprintf( lg->output_file, ": ");

	va_list args;
	va_start ( args, fmt_msg );
	vfprintf ( lg->output_file, fmt_msg, args );
	va_end ( args );

	fprintf( lg->output_file, "\n");
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
	fprintf ( lg->output_file, "[BEGIN]\n" );
}

void
logger_trace_end
( struct logger * lg ) {
	logger_print_helper ( lg, TRACE );
	fprintf ( lg->output_file, "[END]\n" );

	lg->stack_size--;
}

void
logger_trace_error
( struct logger * lg, const char * fmt_err, ... ) {
	logger_print_helper ( lg, ERROR );
	fprintf ( lg->output_file, ": " );

	va_list args;
	va_start ( args, fmt_err );
	vfprintf ( lg->output_file, fmt_err, args );
	va_end ( args );

	fprintf( lg->output_file, "\n");
}
