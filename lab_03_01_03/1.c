#include <stdio.h>

#define N 10

// m строк, n столбцов

int dimension_input(int *m, int *n)
{
	int rc;
	
	rc = scanf("%d%d", m, n);
	if (rc != 2)
		return 1;
	if ((*m > N) || (*n > N))
		return 2;
	if ((*m <= 0) || (*n <= 0))
		return 3;
	
	return 0;
}

int matrix_input(int a[N][N], int m, int n)
{
	int tmp;
	int rc;
	for (int i = 0; i < m; i++)
		for (int j = 0; j < n; j++)
		{
			rc = scanf("%d", &tmp);
			if (rc == EOF)
				return 2;
			if (rc != 1)
				return 1;
			a[i][j] = tmp;
		}
	return 0;
}

void matrix_output(int a[N][N], int m, int n)
{
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
			printf("%d ", a[i][j]);
		printf("\n");
	}
}

int monotonic_sequence_check(int a[], int n)
{
	int increment;
	int flag = 0;
	int issequenceraising;
	
	if (n == 1)
		return 0;
	for (int i = 0; i < n - 1; i++)
	{
		increment = a[i + 1] - a[i];
		if ((increment != 0) && (flag == 0))
		{
			flag = 1;
			if (increment > 0)
				issequenceraising = 1;
			else
				issequenceraising = 0;
		}
		if ((increment > 0) && (issequenceraising == 0))
			return 0;
		else if ((increment < 0) && (issequenceraising == 1))
			return 0;	
	}
	return 1;
}

void array_formation(int a[N][N], int m, int n, int b[])
{
	for (int i = 0; i < m; i++)
		if (monotonic_sequence_check(a[i], n))
			b[i] = 1;
		else
			b[i] = 0;
}

void array_print(int a[], int n)
{
	for (int i = 0; i < n; i++)
		printf("%d ", a[i]);
}

int main(void)
{
	int matrix[N][N];
	int array[N];
	int m, n;
	int rc;
	
	rc = dimension_input(&m, &n);
	if (rc == 1)
	{
		printf("input error");
		return 1;
	}
	else if (rc == 2)
	{
		printf("dimension bigger than ten");
		return 2;
	}
	else if (rc == 3)
	{
		printf("dimension must be positive");
		return 3;
	}
	
	rc = matrix_input(matrix, m, n);
	if (rc == 1)
	{
		printf("input error");
		return 1;
	}
	if (rc == 2)
	{
		printf("entered amount doesnt match actual");
		return 2;
	}
	
	array_formation(matrix, m, n, array);
	
	array_print(array, m);
	
	return 0;
}