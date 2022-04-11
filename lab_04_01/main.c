#include "my_string.h"
#include <stdio.h>
#include <string.h>


int main(void)
{
	char *p1, *p2, *q1, *q2;
	char str1[] = "qwerty";
	char src1[] = "gjshrgk";
	char ch = 'e';
	
	
	
	p1 = my_strpbrk(str1, src1);
	printf("my version of strpbrk:\n");
	if (p1)
		printf("  %ld\n", p1 - str1 + 1);
	else
		printf("  No inclutions\n");
	
	p2 = strpbrk(str1, src1);
	printf("std version of strpbrk:\n");
	if (p2)
		printf("  %ld\n", p2 - str1 + 1);
	else
		printf("  No inclutions\n");
	
	
	q1 = my_strchr(str1, ch);
	printf("my version of strchr:\n");
	if (q1)
		printf("  %ld\n", q1 - str1 + 1);
	else
		printf("  No inclutions\n");
	
	q2 = strchr(str1, ch);
	printf("std version of strchr:\n");
	if (q2)
		printf("  %ld\n", q2 - str1 + 1);
	else
		printf("  No inclutions\n");
	
	printf("----------\n");
	
	
	char str2[] = "\0";
	
	p1 = my_strpbrk(str2, src1);
	printf("my version of strpbrk:\n");
	if (p1)
		printf("  %ld\n", p1 - str2 + 1);
	else
		printf("  No inclutions\n");
	
	p2 = strpbrk(str2, src1);
	printf("std version of strpbrk:\n");
	if (p2)
		printf("  %ld\n", p2 - str2 + 1);
	else
		printf("  No inclutions\n");
	
	
	q1 = my_strchr(str2, ch);
	printf("my version of strchr:\n");
	if (q1)
		printf("  %ld\n", q1 - str2 + 1);
	else
		printf("  No inclutions\n");
	
	q2 = strchr(str2, ch);
	printf("std version of strchr:\n");
	if (q2)
		printf(" %ld\n", q2 - str2 + 1);
	else
		printf("  No inclutions\n");
	
	printf("----------\n");
	
	
	
	q1 = my_strchr(str1, '\0');
	printf("my version of strchr:\n");
	if (q1)
		printf("  %ld\n", q1 - str1 + 1);
	else
		printf("  No inclutions\n");
	
	q2 = strchr(str1, '\0');
	printf("std version of strchr:\n");
	if (q2)
		printf("%ld\n", q2 - str1 + 1);
	else
		printf("  No inclutions\n");
	
	return 0;
}