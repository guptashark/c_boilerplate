#include <stdio.h>
#include <assert.h>

#include "heapsort.h"

#include "logger.h"


struct logger main_lg;

// test the is_sorted fn.
void test_is_sorted ( void );

// test the is_heap fn.
void test_is_heap ( void );

// test the heapify fn.
void test_heapify ( void );

int main(void) {

	printf("Heapsort Logger Demo\n");

	logger_init ( & main_lg, stdout, "main.c" );
	heapsort_module_init();

	logger_set_fn_name ( & main_lg, "main" );
	logger_trace_begin ( & main_lg );

	test_is_sorted();
	test_is_heap();
	test_heapify();

	logger_trace_end ( & main_lg );

	return 0;
}


void test_is_sorted ( void ) {

	logger_set_fn_name ( & main_lg, "test_is_sorted" );
	logger_trace_begin ( & main_lg );

	{
		const int arr_len = 5;
		int arr_01[5] = { 1, 2, 3, 4, 5 };
		int arr_02[5] = { 1, 2, 3, 3, 4 };

		assert ( is_sorted ( arr_01, arr_len ) );
		assert ( is_sorted ( arr_02, arr_len ) );
	}

	logger_trace_end ( & main_lg );
}

void test_is_heap ( void ) {

	logger_set_fn_name ( & main_lg, "test_is_heap" );
	logger_trace_begin ( & main_lg );

	{
		const int arr_len = 5;
		int arr_01[5] = { 1, 2, 3, 4, 5 };
		int arr_02[5] = { 1, 5, 7, 6, 4 };

		assert ( is_heap ( arr_01, arr_len ) );
		assert ( is_heap ( arr_02, arr_len ) == false );
	}

	logger_trace_end ( & main_lg );
}

void test_heapify ( void ) {
	logger_set_fn_name ( & main_lg, "test_heapify" );
	logger_trace_begin ( & main_lg );

	{
		const int arr_len = 5;
		int arr_01[5] = { 5, 4, 3, 2, 1 };

		assert ( is_heap ( arr_01, arr_len ) == false );

		heapify ( arr_01, arr_len );

		assert ( is_heap ( arr_01, arr_len ) == true );
	}

	logger_trace_end ( & main_lg );

}
