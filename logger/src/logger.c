#include <stdio.h>
#include <string.h>

#include "logger.h"

void
logger_init
( struct logger * lg, const char * filename ) {
	strcpy ( lg->filename, filename );
}

void
logger_trace
( struct logger * lg, const char * msg ) {
	printf("[TRACE]");
	printf("[%s]", lg->filename);
	printf(": %s\n", msg);
}
