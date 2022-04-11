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
int formarray(int *array)
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
Функция нахождения среднего геометрического положитительных элементов
На вход: неизменяемый массив, количество элементов в нем
На выход: -3 - если положительных элементов нет
			среднее геометрическое, если есть
*/
double geom(const int *a, int n)
{
	int counter = 0;
	int flag = 0;
	double s = 1;
	for (int i = 0; i < n; i++)
	{
		if (a[i] > 0)
		{
			s *= a[i];
			flag = 1;
			counter++;
		}
	}
	if (flag)
	{
		s = pow(s, 1.0 / counter);
		return s;
	}
	else
		return -3;
}

int main(void)
{
	int array[N];
	double s;
	int rc;
	int amount;
	
	//Ввод количества элементов массива
	rc = amountchecker(&amount);
	if (rc != 0)
		return rc;
	
	//Ввод массива
	rc = formarray(array);
	if (rc < 0)
		return rc;

	//Проверка на равенство количества введенных чисел и заявленного
	if (rc != amount)
	{
		printf("entered amount doesnt match actual");
		return 1;
	}
	
	//Вычисление среднего геометрического
	s = geom(array, amount);
	if (s < 0)
	{
		printf("no positiv elements");
		return 2;
	}
	else
		printf("%lf", s);
	
	
	return 0;
}