#ifndef LOGGER_H
#define LOGGER_H

#include <stdint.h>

struct logger {

	char filename[64];

	uint32_t stack_size;
	char fn_name_stack[16][32];
};

void
logger_init
( struct logger * lg, const char * filename );

void
logger_trace
( struct logger * lg, const char * msg );

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
( struct logger * lg, const char * err );

#endif
