#include <stdio.h>
#include <math.h>

#define N 10

/*
Функция считывает количество и проверяет его корректность
*/
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
	if (temp > N)
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
	
	*amount = temp;
	
	return 0;
}

/*
Функция формирования массива
На вход: массив, количество считываемых элементов
Возвращает: код ошибки(0 - если таковых нет)
Изменяет переданный массив
*/
int inputarray(int *array)
{
	int rc;
	int a = 0;
	int counter = 0;
	for (int i = 0; i < N; i++)
	{
		rc = scanf("%d", &a);
		if (rc == EOF)
			break;
		if (rc != 1)
		{
			printf("input error");
			return -2;
		}
		array[i] = a;
		counter++;
	}
	
	return counter;
}

/*
Функция реверса числа
*/
int reverse(int num)
{
	int revnum = 0;
	while (num > 0)
	{
		revnum = revnum * 10 + num % 10;
		num /= 10;
	}
	return revnum;
}

/*
Функция добавляющая в массив элементы
*/
int changearray(int *arr, int *amount)
{
	int flag = 0;
	for (int i = 0; i < *amount; i++)
	{
		if (arr[i] > 0)
		{
			for (int j = *amount + 1; j > i + 1; j--)
				arr[j] = arr[j - 1];
			(*amount)++;
			flag = 1;
			i++;
			arr[i] = reverse(arr[i - 1]);
		}
	}
	if (flag)
		return 0;
	else
	{
		printf("no positive numbers");
		return -1;
	}
}

//Функция вывода массива
void printarray(const int *array, int amount)
{
	for (int i = 0; i < amount; i++)
	{
		printf("%d ", array[i]);
	}
}

int main(void)
{
	int input[20];
	int amount;
	int rc;

	//Ввод количества элементов массива
	rc = amountchecker(&amount);
	if (rc != 0)
		return rc;
	
	//Ввод массива
	rc = inputarray(input);
	if (rc < 0)
		return rc;

	//Проверка на равенство количества введенных чисел и заявленного
	if (rc != amount)
	{
		printf("entered amount doesnt match actual");
		return 1;
	}
	
	rc = changearray(input, &amount);
	if (rc != 0)
		return rc;
	else
		printarray(input, amount);
	
	return 0;
}