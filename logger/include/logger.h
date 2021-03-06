#ifndef LOGGER_H
#define LOGGER_H

#include <stdint.h>
#include <stdarg.h>

struct logger {

	FILE * output_file;

	char filename[64];

	uint32_t stack_size;
	char fn_name_stack[16][32];

	uint32_t num_blacklisted;
	char blacklist[16][32];
};

void
logger_init
( struct logger * lg, FILE * output_file, const char * filename );

void
logger_trace
( struct logger * lg, const char * fmt_msg, ... );

void
logger_set_fn_name
( struct logger * lg, const char * fn_name );

void
logger_trace_begin
( struct logger * lg );

void
logger_trace_end
( struct logger * lg );

void
logger_trace_error
( struct logger * lg, const char * fmt_err, ... );

void
logger_blacklist_fn
( struct logger * lg, const char * fn_name );

#endif
