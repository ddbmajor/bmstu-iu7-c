#ifndef _DYN_ARRAY_H_

#include <stdlib.h>
#include <stdio.h>
#include "defines.h"
#include "film_struct.h"

struct dyn_array
{
	int len;
	int allocated;
	int step;
	struct film *data;
};

void init_dyn_array(struct dyn_array *arr);
void free_dyn_array(struct dyn_array *arr);
int append(struct dyn_array *arr, struct film f);
void printarr(struct dyn_array arr);

#define _DYN_ARRAY_H_
#endif