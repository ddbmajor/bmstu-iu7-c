#include "my_lib.h"
#include <stdio.h>

#define OK 0
#define CONSOLE_ERROR -1
#define FILE_ERROR -2


int main(int argc, char **argv)
{
	FILE *f;
	double disp;
	int rc;
	
	if (argc != 2)
		return CONSOLE_ERROR;
	
	f = fopen(argv[1], "r");
	if (f == NULL)
		return FILE_ERROR;
	
	rc = process(f, &disp);
	if (rc != 0)
		return rc;
	
	fclose(f);
	
	printf("%lf", disp);
	
	return OK;
}