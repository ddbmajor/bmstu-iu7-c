#include "lib.h"
#include <stdio.h>
#include <string.h>


int main(int argc, char **argv)
{
	FILE *f;
	int rc;
	
	if (argc < 2)
		return ARG_ERROR;
	f = fopen(argv[1], "r");
	if (f == NULL)
		return FILE_ERROR;
	
	if (argc >= 3)
	{
		if (strcmp(argv[2], "title") == 0)
		{
			if (argc == 3)
			{
				rc = titleprint(f);
				if (rc != 0)
					return rc;
			}
			else if (argc == 4)
			{
				rc = titlefind(f, argv[3]);
				if (rc != 0)
					return rc;
			}
			else
				return ARG_ERROR;
		}
		else if (strcmp(argv[2], "name") == 0)
		{
			if (argc == 3)
			{
				rc = nameprint(f);
				if (rc != 0)
					return rc;
			}
			else if (argc == 4)
			{
				rc = namefind(f, argv[3]);
				if (rc != 0)
					return rc;
			}
			else
				return ARG_ERROR;
		}
		else if (strcmp(argv[2], "year") == 0)
		{
			if (argc == 3)
			{
				rc = yearprint(f);
				if (rc != 0)
					return rc;
			}
			else if (argc == 4)
			{
				rc = yearfind(f, argv[3]);
				if (rc != 0)
					return rc;
			}
			else
				return ARG_ERROR;
		}
		else
			return ARG_ERROR;
	}
	else
		return ARG_ERROR;
	
	fclose(f); 
	
	return 0;
}