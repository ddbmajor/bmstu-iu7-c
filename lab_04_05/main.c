#include "format.h"
#include <stdio.h>

#define SL 256


int main(void)
{
	char str[SL + 1];
	int rc;
	
	if (!fgets(str, sizeof(str), stdin))
		return -1;
	
	rc = format_text(str);
	if (rc != 0)
		return -2;
	
	printf("%s", str);
	
	return 0;
}