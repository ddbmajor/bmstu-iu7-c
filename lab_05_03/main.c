#include "my_lib.h"
#include <stdlib.h>
#include <string.h>


#define OK 0
#define INCORRECT_ARGS 1


int main(int argc, char **argv)
{
	int rc;
	
	if (argc == 3)
	{
		if (strcmp(argv[1], "p") == 0)
		{
			rc = print_file(argv[2]);
			return (rc == 0) ? OK : rc;
		}
		else if (strcmp(argv[1], "s") == 0)
		{
			rc = sort_file(argv[2]);
			return (rc == 0) ? OK : rc;
		}
		else
			return INCORRECT_ARGS;
	}
	if (argc == 4)
	{
		if (strcmp(argv[1], "c") == 0 && atoi(argv[2]))
		{
			rc = create_int_file(argv[2], argv[3]);
			return (rc == 0) ? OK : rc;
		}
		else
			return INCORRECT_ARGS;
	}
	
	return INCORRECT_ARGS;
}
