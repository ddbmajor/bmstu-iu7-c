#include <stdio.h>

/*
Функция сортирует массив
*/
void bubbblesort(int *a, int n)
{
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n - i - 1; j++)
			if (a[j] > a[j + 1])
			{
				a[j] = a[j] + a[j + 1];
				a[j + 1] = a[j] - a[j + 1];
				a[j] = a[j] - a[j + 1];	
			}
}

/*
Функция ввода массива
*/
int insert(int *a, int *n)
{
	int rc;
	int tmp;
	int i = 0;
	while (1)
	{
		rc = scanf("%d", &tmp);
		if (rc != 1)
			break;
		else
		{
			if (i == 10)
			{
				*n = 10;
				return 100;
			}
			a[i] = tmp;
			i++;
		}
	}
	*n = i;
	return 0;
}

void printarray(const int *array, int amount)
{
	for (int i = 0; i < amount; i++)
	{
		printf("%d ", array[i]);
	}
}

int main(void)
{
	int arr[10];
	int n = 0;
	int rc, output = 0;
	
	rc = insert(arr, &n);
	if (rc == 100)
		output = rc;
	if (n == 0)
	{
		printf("empty list");
		return 1;
	}
	
	bubbblesort(arr, n);
	printarray(arr, n);
	
	return output;
}