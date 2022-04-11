#ifndef _MYSORT_H_

#include <stdio.h>
#include <string.h>
#include "dyn_array.h"
#include "film_struct.h"
#include "defines.h"

int titlesort(FILE *f, struct dyn_array *films);
int namesort(FILE *f, struct dyn_array *films);
int yearsort(FILE *f, struct dyn_array *films);

#define _MYSORT_H_
#endif