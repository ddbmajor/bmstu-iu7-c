#include "my_lib.h"
#include <stdio.h>

#define WL 16
#define N 128

#define EMPTY_STRING 1
#define TOO_BIG_STRING 2
#define NO_WORDS 3
#define TOO_BIG_WORD 4
#define NO_UNIQUE_WORDS 5

int main(void)
{
	char tmpstr[N + 1];
	char arr_1[N][WL + 1];
	char arr_2[N][WL + 1];
	int n1 = 0;
	int n2 = 0;
	char result_1[N][WL + 1];
	char result_2[N][WL + 1];
	int k1, k2;
	int rc;
	
	rc = read_line(tmpstr, N + 1);
	if (rc == 0)
		return EMPTY_STRING;
	else if (rc < 0)
		return TOO_BIG_STRING;
	
	rc = read_line_by_words(tmpstr, arr_1);
	if (rc == 0)
		return NO_WORDS;
	else if (rc < 0)
		return TOO_BIG_WORD;
	else
		n1 = rc;
		
	rc = read_line(tmpstr, N + 1);
	if (rc <= 0)
		return EMPTY_STRING;
	else if (rc < 0)
		return TOO_BIG_STRING;
	
	rc = read_line_by_words(tmpstr, arr_2);
	if (rc == 0)
		return NO_WORDS;
	else if (rc < 0)
		return TOO_BIG_WORD;
	else
		n2 = rc;
	
	k1 = unique_words(arr_1, n1, arr_2, n2, result_1);
	k2 = unique_words(arr_2, n2, arr_1, n1, result_2);
	
	if (k1 + k2 == 0)
		return NO_UNIQUE_WORDS;
	
	printf("Result:");
	for (int i = 0; i < k1; i++)
	{
		printf(" ");
		printf("%s", result_1[i]);
	}
	for (int i = 0; i < k2; i++)
	{
		printf(" ");
		printf("%s", result_2[i]);
	}
	
	
	return 0;
}