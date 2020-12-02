#include <stdio.h>

#include "logger.h"

int main(void) {

	printf("Basic Logger Demo\n");

	struct logger main_lg;
	logger_init ( & main_lg, "main.c" );

	logger_set_fn_name ( & main_lg, "main" );
	logger_trace_begin ( & main_lg );

	logger_trace ( & main_lg, "Hello World!" );
	logger_trace ( & main_lg, "int val: %d", 3 );

	{
		logger_set_fn_name ( & main_lg, "foo" );
		logger_trace_begin ( & main_lg );

		{
			logger_set_fn_name ( & main_lg, "bar" );
			logger_trace_begin ( & main_lg );

			logger_trace_end ( & main_lg );
		}

		logger_trace_end ( & main_lg );
	}

	logger_trace_error ( & main_lg, "sample error mesage" );
	logger_trace_error ( & main_lg, "err_code: %d", 24 );

	logger_trace_end ( & main_lg );

	return 0;
}
