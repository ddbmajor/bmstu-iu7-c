#include "sort.h"
#include "find.h"
#include <string.h>

#define OK 0

int main(int argc, char **argv)
{
	int rc;
	if (argc == 4)
	{
		if (strcmp(argv[1], "sb") == 0)
		{
			rc = sort(argv[2], argv[3]);
			return (rc == 0) ? OK : rc;
		}
		else if (strcmp(argv[1], "fb") == 0)
		{
			rc = find(argv[2], argv[3]);
			return (rc == 0) ? OK : rc;
		}
		else
			return 53;
	}
	else
		return 53;
}