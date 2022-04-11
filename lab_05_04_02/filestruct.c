#include "filestruct.h"
#include <stdio.h>


int get_struct_by_pos(FILE *f, int pos, struct good *target)
{
	int rc, read;

	rc = fseek(f, pos * sizeof(struct good), SEEK_SET);
	if (rc != 0)
		return 1;
	read = fread(target, sizeof(struct good), 1, f);
	if (read != 1)
		return 2;
	
	return fseek(f, 0L, SEEK_SET);
}


int put_struct_by_pos(FILE *f, int pos, struct good *target)
{
	int rc, wrote;

	rc = fseek(f, pos * sizeof(struct good), SEEK_SET);
	if (rc != 0)
		return 1;
	wrote = fwrite(target, sizeof(struct good), 1, f);
	if (wrote != 1)
		return 2;
	
	return fseek(f, 0L, SEEK_SET);
}

int file_size(FILE *f, size_t *size)
{
	long sz;
	
	if (fseek(f, 0L, SEEK_END))
		return 1;
	
	sz = ftell(f);
	if (sz < 0)
		return 1;
	
	*size = sz;
	return fseek(f, 0L, SEEK_SET);
}
