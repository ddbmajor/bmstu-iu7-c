#include <stdio.h>

#define N 10

#define INPUT_ERROR "input error"
#define DIM_MORE_TEN "dimension bigger than ten"
#define DIM_NEG "dimension must be positive"
#define COUNT_MATCH_ERROR "entered amount doesnt match actual"
#define NOT_SQUARE "it's not a square matrix"

// m строк, n столбцов

int dimension_input(int *n)
{
	int rc;
	int tmp;
	
	rc = scanf("%d%d", n, &tmp);
	if (rc != 2)
	{
		printf(INPUT_ERROR);
		return 1;
	}
	if ((tmp > N) || (*n > N))
	{
		printf(DIM_MORE_TEN);
		return 2;
	}
	if ((tmp <= 0) || (*n <= 0))
	{
		printf(DIM_NEG);
		return 3;
	}
	if (tmp != *n)
	{
		printf(NOT_SQUARE);
		return 5;
	}
	return 0;
}

int matrix_input(int a[N][N], int n)
{
	int tmp;
	int rc;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
		{
			rc = scanf("%d", &tmp);
			if (rc == EOF)
			{
				printf(COUNT_MATCH_ERROR);
				return 4;
			}
			if (rc != 1)
			{
				printf(INPUT_ERROR);
				return 1;
			}
			a[i][j] = tmp;
		}
	return 0;
}

void matrix_output(int a[N][N], int n)
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
			printf("%d ", a[i][j]);
		printf("\n");
	}
}

void column_swap(int a[N][N], int n, int i)
{
	int (*rp)[N]; //row pointer
	int tmp;
	
	for (rp = a + i; rp < a + n - i; rp++)
	{
		tmp = (*rp)[i];
		(*rp)[i] = (*rp)[n - 1 - i];
		(*rp)[n - 1 - i] = tmp;
	}
}

void butterfly_column_swap(int a[N][N], int n)
{
	for (int i = 0; i < n / 2; i++)
		column_swap(a, n, i);
}

int main(void)
{
	int rc;
	int n;
	int a[N][N];
	
	rc = dimension_input(&n);
	if (rc != 0)
		return rc;
	
	rc = matrix_input(a, n);
	if (rc != 0)
		return rc;
	
	butterfly_column_swap(a, n);
	
	matrix_output(a, n);
	
	return 0;
}