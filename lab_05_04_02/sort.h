#include <stdio.h>

#ifndef OK
#define OK 0
#endif

#ifndef OPEN_FILE_ERROR
#define OPEN_FILE_ERROR 1
#endif

#ifndef READ_FILE_ERROR
#define READ_FILE_ERROR 2
#endif

#ifndef COPY_ERROR
#define COPY_ERROR 3
#endif

#ifndef BAD_FILE
#define BAD_FILE 4
#endif

#ifndef SIZE_ERROR
#define SIZE_ERROR 5
#endif

#ifndef SORT_FILE_ERROR
#define SORT_FILE_ERROR 6
#endif

#ifndef FIND_ERROR
#define FIND_ERROR 7
#endif

int filecpy(FILE *src, FILE *dst);
int first_sort(char *filename);
int second_sort(char *filename);
int sort(char *srcfn, char *dstfn);
