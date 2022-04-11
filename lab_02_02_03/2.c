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
Функция, которая проверяет является ли передаваемое число
числом Армстронга
*/
int isitnarcissisticnum(int n)
{
	int originnum;
	double s = 0;
	int count = 0;
	
	if (n <= 0)
		return 0;
	
	originnum = n;
	while (n > 0)
	{
		n /= 10;
		count++;
	}
	
	n = originnum;
	
	while (n > 0)
	{
		s += pow(n % 10, count);
		n /= 10;
	}
	
	if (fabs(s - originnum) < 10e-5)
		return 1;
	else
		return 0;
}

int formarray(const int *arrayin, int amount, int *arrayout)
{
	int count = 0;
	
	for (int i = 0; i < amount; i++)
	{
		if (isitnarcissisticnum(arrayin[i]))
		{
			arrayout[count] = arrayin[i];
			count++;
		}
	}
	if (count == 0)
	{
		printf("no narcis numbers");
		return 0;
	}
	else
		return count;
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
	int input[N];
	int output[N];
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
	
	//Формирование нового массива
	rc = formarray(input, amount, output);
	if (rc == 0)
		return -1;
	else
		printarray(output, rc);
	
	return 0;
}