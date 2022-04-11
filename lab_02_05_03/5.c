#include <stdio.h>

int amountchecker(int *amount)
{
	int rc;
	int temp;
	
	rc = scanf("%d", &temp);
	if (rc != 1)
	{
		printf("input error");
		return -1;
	}
	if (temp > 10)
	{
		printf("amount can't be bigger than ten");
		return -1;
	}
	if (temp < 0)
	{
		printf("amount must be positive");
		return -1;
	}
	if (temp == 0)
	{
		printf("empty list");
		return -1;
	}
	if (temp == 1)
	{
		printf("need at least two elements");
		return -1;
	}
	
	*amount = temp;
	
	return 0;
}

int inputarr(int *pb, int *pe)
{
	int rc;
	int *pa = pb + 1;
	while (pa < pe)
	{
		rc = scanf("%d", pa);
		if (rc == EOF)
			return -1;
		else if (rc != 1)
		{
			printf("input error");
			return -2;
		}
		pa++;
	}
	return 0;
}

int minfunc(int *pb, int *pe)
{
	int min;
	int *pa = pb;
	int curr;
	min = (*pb) * *(pb + 1);
	while (pa < pe - 1)
	{
		curr = *(pa) * *(pa + 1);
		if (curr < min)
			min = curr;
		pa++;
	}
	return min;
}

int main(void)
{
	int a[10];
	int n;
	int *pb = a;
	int *pe = NULL;
	int rc;
	int min;
	
	rc = amountchecker(&n);
	if (rc != 0)
		return -1;
	rc = scanf("%d", pb);
	if (rc != 1)
	{
		printf("input error");
		return -1;
	}
	pe = pb + n;
	
	rc = inputarr(pb, pe);
	if (rc == -1)
	{
		printf("entered amount doesnt match actual");
		return -1;
	}
	else if (rc == -2)
		return -2;
	
	min = minfunc(pb, pe);
	printf("%d", min);
	
	return 0;
}