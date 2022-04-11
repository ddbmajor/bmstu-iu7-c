#include "my_lib.h"
#include <stdio.h>

#define SL 256

int main(void)
{
	char str[SL + 1];
	char tmpstr[1];
	
	if (!fgets(str, sizeof(str), stdin))
		return -1;
	if (fgets(tmpstr, sizeof(str), stdin))
		return -2;
	
	int rc;
	rc = is_it_phonenum(str);
	if (rc)
		printf("YES");
	else
		printf("NO");
	
	return 0;
}