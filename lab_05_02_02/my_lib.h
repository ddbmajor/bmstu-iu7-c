#include <stdio.h>

#ifndef OK
#define OK 0
#endif

#ifndef CONSOLE_ERROR
#define CONSOLE_ERROR -1
#endif

#ifndef FILE_ERROR
#define FILE_ERROR -2
#endif

#ifndef IO_ERROR
#define IO_ERROR -3
#endif

#ifndef NO_DATA
#define NO_DATA -4
#endif

int average(FILE *f, double *avg);
int variance(FILE *f, double avg, double *disp);
int process(FILE *f, double *disp);