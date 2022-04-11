#include <stdio.h>
#include "process.h"
#include "defines.h"


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
				{
					fclose(f);
					return rc;
				}
			}
			else if (argc == 4)
			{
				rc = titlefind(f, argv[3]);
				{
					fclose(f);
					return rc;
				}
			}
			else
			{
				fclose(f);
				return ARG_ERROR;
			}
		}
		else if (strcmp(argv[2], "name") == 0)
		{
			if (argc == 3)
			{
				rc = nameprint(f);
				{
					fclose(f);
					return rc;
				}
			}
			else if (argc == 4)
			{
				rc = namefind(f, argv[3]);
				{
					fclose(f);
					return rc;
				}
			}
			else
			{
				fclose(f);
				return ARG_ERROR;
			}
		}
		else if (strcmp(argv[2], "year") == 0)
		{
			if (argc == 3)
			{
				rc = yearprint(f);
				{
					fclose(f);
					return rc;
				}
			}
			else if (argc == 4)
			{
				rc = yearfind(f, argv[3]);
				if (rc != 0)
				{
					fclose(f);
					return rc;
				}
			}
			else
			{
				fclose(f);
				return ARG_ERROR;
			}
		}
		else
		{
			fclose(f);
			return ARG_ERROR;
		}
	}
	else
	{
		fclose(f);
		return ARG_ERROR;
	}
	
	fclose(f); 
	
	return 0;
}