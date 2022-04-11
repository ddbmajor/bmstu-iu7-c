#include "my_lib.h"
#include <stdio.h>


/*
Finds max of a, b, c
*/
int max(int a, int b, int c)
{
	if (a > b)
	{
		if (a > c)
			return a;
		else
			return c;
	}
	else
	{
		if (b > c)
			return b;
		else
			return c;
	}
}

int process(FILE *f, int *len)
{
	int num1, num2;
	int rc;
	
	rc = fscanf(f, "%d", &num1);
	
	if (rc != 1)
		return EMPTY_INPUT;
	
	rc = fscanf(f, "%d", &num2);
	
	if (rc != 1)
		return NO_SEQUENCE;
	
	int dec, inc; // lengths of decreasing and increasing fragments
	rc = 1;
	*len = 1;
	
	if (num1 > num2)
	{
		dec = 2;
		inc = 1;
	}
	else if (num1 < num2)
	{
		inc = 2;
		dec = 1;
	}
	else
		inc = dec = 1;
	
	while (rc)
	{
		*len = max(inc, dec, *len);
		
		num1 = num2;
		
		rc = fscanf(f, "%d", &num2);
		if (rc != 1)
			break;
		
		if (num1 > num2)
		{
			dec++;
			inc = 1;
		}
		else if (num1 < num2)
		{
			inc++;
			dec = 1;
		}
		else
			inc = dec = 1;
	}
	
	if ((*len) == 1)
	{
		*len = 0;
		return OK;
	}
	else
		return OK;
}