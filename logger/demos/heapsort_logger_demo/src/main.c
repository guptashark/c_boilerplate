#include <stdio.h>

#include "logger.h"

int main(void) {

	printf("Heapsort Logger Demo\n");

	struct logger main_lg;
	logger_init ( & main_lg, stdout, "main.c" );

	logger_set_fn_name ( & main_lg, "main" );
	logger_trace_begin ( & main_lg );

	logger_trace_end ( & main_lg );

	return 0;
}
