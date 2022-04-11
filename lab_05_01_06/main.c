#include "my_lib.h"
#include <stdio.h>


int main(void)
{
	int rc;
	int len = 0; // max length of monotonic part
	
	rc = process(stdin, &len);
	if (rc != 0)
		return rc;
	
	printf("%d", len);
	
	return rc;
}