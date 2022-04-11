#ifndef _PROCESS_H_

#include <stdio.h>
#include <stdlib.h>
#include "defines.h"
#include "site.h"
#include "list.h"
#include "listsort.h"

int read_file(node_t **head, FILE *f);
int write_file(FILE *f, node_t **head);
int process(FILE *infile, FILE *outfile);

#define _PROCESS_H_
#endif