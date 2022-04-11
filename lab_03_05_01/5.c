#include <stdio.h>
#include <stdlib.h>

#define N 10

#define INPUT_ERROR "input error"
#define DIM_MORE_TEN "dimension bigger than ten"
#define DIM_NEG "dimension must be positive"
#define COUNT_MATCH_ERROR "entered amount doesnt match actual"
#define NO_NEEDED_ELEMENTS "there are no elements with the sum of digits more than ten"

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

int digit_sum(int n)
{
	int sum = 0;
	if (n == 0)
		return 0;
	n = abs(n);
	while (n > 0)
	{
		sum += n % 10;
		n /= 10;
	}
	return sum;
}

int array_formation(int a[N][N], int m, int n, int array[N*N])
{
	int counter = 0;
	for (int i = 0; i < m; i++)
		for (int j = 0; j < n; j++)
			if (digit_sum(a[i][j]) > 10)
			{
				array[counter] = a[i][j];
				counter++;
			}
	return counter;
}

void array_shift(int array[N], int n)
{
	int temp;
	for (int j = 0; j < 3; j++)
	{
		temp = array[0];
		for (int i = 1; i < n; i++) 
			array[i - 1] = array[i];
		array[n - 1] = temp;
	}
}

void matrix_formation(int a[N][N], int m, int n, int array[N], int size)
{
	int counter = 0;
	for (int i = 0; i < m; i++)
		for (int j = 0; j < n; j++)
			if (digit_sum(a[i][j]) > 10)
			{
				a[i][j] = array[counter];
				counter++;
				if (counter == size)
					return;
			}
}

int main(void)
{
	int rc;
	int m, n;
	int a[N][N];
	int size;
	int array[N*N];
	
	rc = dimension_input(&m, &n);
	if (rc != 0)
		return rc;
	
	rc = matrix_input(a, m, n);
	if (rc != 0)
		return rc;
	
	size = array_formation(a, m, n, array);
	if (size == 0)
	{
		printf(NO_NEEDED_ELEMENTS);
		return 5;
	}
	
	array_shift(array, size);
	
	matrix_formation(a, m, n, array, size);
	
	matrix_output(a, m, n);
	
	return 0;
}