#include <stdio.h>

#ifndef OK
#define OK 0
#endif

#ifndef INCORRECT_ARGS
#define INCORRECT_ARGS 1
#endif

#ifndef OPEN_FILE_ERROR
#define OPEN_FILE_ERROR 2
#endif

#ifndef CREATE_FILE_ERROR
#define CREATE_FILE_ERROR 3
#endif

#ifndef READ_FILE_ERROR
#define READ_FILE_ERROR 4
#endif

#ifndef SORT_FILE_ERROR
#define SORT_FILE_ERROR 5
#endif

#ifndef SIZE_ERROR
#define SIZE_ERROR 6
#endif


int file_size(FILE *f, size_t *size);
int get_number_by_pos(FILE *f, int pos, int *num);
int put_number_by_pos(FILE *f, int pos, int *num);
int create_int_file(char *stramount, char *filename);
int print_file(char *filename);
int sort_file(char *filename);
