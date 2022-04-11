#include <stdio.h>

#define N 10

#define INPUT_ERROR "input error"
#define DIM_MORE_TEN "dimension bigger than ten"
#define DIM_NEG "dimension must be positive"
#define COUNT_MATCH_ERROR "entered amount doesnt match actual"

// m строк, n столбцов

int dimension_input(int *m, int *n)
{
	int rc;
	
	rc = scanf("%d%d", m, n);
	if (rc != 2)
	{
		printf(INPUT_ERROR);
		return 1;
	}
	if ((*m > N) || (*n > N))
	{
		printf(DIM_MORE_TEN);
		return 2;
	}
	if ((*m <= 0) || (*n <= 0))
	{
		printf(DIM_NEG);
		return 3;
	}
	
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

void matrix_output(int a[N][N], int m, int n)
{
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
			printf("%d ", a[i][j]);
		printf("\n");
	}
}

int array_min(int a[], int n)
{
	int min = a[0];
	for (int i = 1; i < n; i++)
		if (a[i] < min)
			min = a[i];
	return min;
}

/*
На вход: матрица, длина строки, номера строк, которые надо поменять
*/
void row_swap(int a[N][N], int n, int i, int j)
{
	int tmp;
	for (int k = 0; k < n; k++)
	{
		tmp = a[i][k];
		a[i][k] = a[j][k];
		a[j][k] = tmp;
	}
}

void matrix_sort(int a[N][N], int m, int n)
{
	int flag = 1;
	while (flag)
	{
		flag = 0;
		for (int i = 0; i < m - 1; i++)
			if (array_min(a[i], n) < array_min(a[i + 1], n))
			{
				row_swap(a, n, i, i + 1);
				flag = 1;
			}
	}
}

int main(void)
{
	int rc;
	int m, n;
	int a[N][N];
	
	rc = dimension_input(&m, &n);
	if (rc != 0)
		return rc;
	
	rc = matrix_input(a, m, n);
	if (rc != 0)
		return rc;
	
	matrix_sort(a, m, n);
	
	matrix_output(a, m, n);
	
	return 0;
}