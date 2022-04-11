#include <stdio.h>
#include <stdlib.h>

#define N 10

#define INPUT_ERROR "input error"
#define DIM_MORE_TEN "dimension bigger than ten"
#define DIM_NEG "dimension must be positive"
#define COUNT_MATCH_ERROR "entered amount doesnt match actual"
#define NO_MATRIX "empty matrix"
#define DIGIT_ERROR "it is not a digit"

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

int number_check(int num, int digit)
{
	num = abs(num);
	if (num == digit)
		return 1;
	while (num > 0)
	{
		if (num % 10 == digit)
			return 1;
		else
			num /= 10;
	}
	return 0;
}

void column_delete(int a[N][N], int m, int *n, int i)
{
	int (*rp)[N]; //row pointer
	
	for (rp = a; rp < a + m; rp++)
		for (int j = i; j < *n - 1; j++)
		{
			(*rp)[j] = (*rp)[j + 1];
		}
	(*n)--;
}

void matrix_transform(int a[N][N], int m, int *n, int digit)
{
	int (*rp)[N]; //row pointer
	
	for (rp = a; rp < a + m; rp++)
		for (int i = 0; i < *n; i++)
			if (number_check((*rp)[i], digit))
			{
				column_delete(a, m, n, i);
				i--;
			}
}

int main(void)
{
	int rc;
	int m, n;
	int a[N][N];
	int digit;
	
	rc = dimension_input(&m, &n);
	if (rc != 0)
		return rc;
	
	rc = matrix_input(a, m, n);
	if (rc != 0)
		return rc;
	
	rc = scanf("%d", &digit);
	if (rc != 1)
	{
		printf(INPUT_ERROR);
		return 1;
	}
	if ((digit < 0) || (digit > 9))
	{
		printf(DIGIT_ERROR);
		return 6;
	}
	
	matrix_transform(a, m, &n, digit);
	if (n == 0)
	{
		printf(NO_MATRIX);
		return 5;
	}
	
	matrix_output(a, m, n);
	
	return 0;
}