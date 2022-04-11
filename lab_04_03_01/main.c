#include "my_lib.h"
#include <stdio.h>

#define WL 16
#define SL 256
#define N 128

#define SCAN_ERROR 1
#define OVERFLOW_ERROR 2
#define NO_WORDS 3
#define EMPTY_OUTPUT 4

int main(void)
{
	int n;
	int len;
	char wordarr[N][WL + 1];
	char newstr[SL + 1];
	
	n = form_word_array(wordarr);
	if (n == -1)
		return SCAN_ERROR;
	else if (n == -2)
		return OVERFLOW_ERROR;
	else if (n == 0)
		return NO_WORDS;
	
	len = form_string(newstr, wordarr, n);
	if (len == 0)
		return EMPTY_OUTPUT;
	
	printf("Result: %s\n", newstr);
	
	return 0;
}
