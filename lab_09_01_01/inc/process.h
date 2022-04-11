#ifndef _PROCESS_H_

#include <stdio.h>
#include <string.h>
#include "dyn_array.h"
#include "mysort.h"
#include "defines.h"

int titleprint(FILE *f);
int nameprint(FILE *f);
int yearprint(FILE *f);
int titlefind(FILE *f, char *title);
int namefind(FILE *f, char *name);
int yearfind(FILE *f, char *year);

#define _PROCESS_H_
#endif