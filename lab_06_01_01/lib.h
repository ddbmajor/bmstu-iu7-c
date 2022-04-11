#ifndef _LIB_H_

#include <stdio.h>

#define MAXLEN 25
#define MAXAMOUNT 15

#define FILE_ERROR 1
#define ARG_ERROR 2
#define INPUT_ERROR 3
#define OVERFLOW_ERROR 4
#define FIND_ERROR 5
#define YEAR_ERROR 6
#define EMPTY_STR_ERROR 7
#define AMOUNT_ERROR 8
#define EMPTY_FILE_ERROR 9

struct film
{
	char title[MAXLEN + 3];
	char name[MAXLEN + 3];
	int year;
};

int isstrspace(char str[MAXLEN]);
void printarr(struct film arr[], int amount);
void strndel(char str[MAXLEN + 3]);
int structread(FILE *f, struct film *dst);
int titlesort(FILE *f, struct film films[MAXAMOUNT + 1], int *amount);
int namesort(FILE *f, struct film films[MAXAMOUNT + 1], int *amount);
int yearsort(FILE *f, struct film films[MAXAMOUNT + 1], int *amount);
int titleprint(FILE *f);
int nameprint(FILE *f);
int yearprint(FILE *f);
int titlefind(FILE *f, char title[MAXLEN + 3]);
int namefind(FILE *f, char name[MAXLEN + 3]);
int yearfind(FILE *f, char year[MAXLEN + 3]);


#define _LIB_H_

#endif