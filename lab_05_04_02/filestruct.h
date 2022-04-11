#include <stdio.h>

#ifndef _FILESTRUCT_H_
#define _FILESTRUCT_H_
struct good
{
	char name[31];
	char maker[16];
	unsigned int price;
	unsigned int amount;
};
#endif


int get_struct_by_pos(FILE *f, int pos, struct good *target);
int put_struct_by_pos(FILE *f, int pos, struct good *target);
int file_size(FILE *f, size_t *size);
