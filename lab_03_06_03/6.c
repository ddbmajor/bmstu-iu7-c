#include <stdio.h>

#define N 10

#define INPUT_ERROR "input error"
#define DIM_MORE_TEN "dimension bigger than ten"
#define DIM_NEG "dimension must be positive"
#define NOT_SQUARE "it's not a square matrix"

// x ->
// y |
//   ˅

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

void matrix_output(int a[N][N], int n)
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
			printf("%d ", a[i][j]);
		printf("\n");
	}
}

void matrix_formation(int a[N][N], int n)
{
	int counter = 1;
	int x = 0, y = 0;
	
	a[0][0] = 1;
	while (counter < n * n)
	{
		while ((y + 1 < n) && (a[y + 1][x] == 0))
		{
			y++;
			counter++;
			a[y][x] = counter;
		}
		while ((x + 1 < n) && (a[y][x + 1] == 0))
		{
			x++;
			counter++;
			a[y][x] = counter;
		}
		while ((y > 0) && (a[y - 1][x] == 0))
		{
			y--;
			counter++;
			a[y][x] = counter;
		}
		while ((x > 0) && (a[y][x - 1] == 0))
		{	
			x--;
			counter++;
			a[y][x] = counter;
		}
	}
}

int main(void)
{
	int rc;
	int n;
	int a[N][N];
	
	rc = dimension_input(&n);
	if (rc != 0)
		return rc;
		
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			a[i][j] = 0;
	
	matrix_formation(a, n);

	matrix_output(a, n);

	return 0;
}