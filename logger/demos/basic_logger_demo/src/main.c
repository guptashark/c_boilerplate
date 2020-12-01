#include <stdio.h>

#include "logger.h"

int main(void) {

	printf("Basic Logger Demo\n");

	struct logger main_lg;
	logger_init ( & main_lg, "main.c" );

	logger_trace ( & main_lg, "Hello World!");

	return 0;
}
