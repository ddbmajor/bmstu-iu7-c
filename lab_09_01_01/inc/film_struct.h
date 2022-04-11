#ifndef _FILM_STRUCT_H_

#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include "defines.h"

struct film
{
	char *title;
	char *name;
	int year;
};

int structread(FILE *f, struct film *dst);
int isstrspace(char *str);
void strndel(char *str);

#define _FILM_STRUCT_H_
#endif
