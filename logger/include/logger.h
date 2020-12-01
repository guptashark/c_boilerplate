#ifndef LOGGER_H
#define LOGGER_H

struct logger {

	char filename[64];
};

void
logger_init
( struct logger * lg, const char * filename );

void
logger_trace
( struct logger * lg, const char * msg );

#endif
