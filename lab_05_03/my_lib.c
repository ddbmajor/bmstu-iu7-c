#include "my_lib.h"
#include <stdio.h>
#include <time.h>
#include <stdlib.h>


// Находит размер файла
int file_size(FILE *f, size_t *size)
{
	long sz;
	
	if (fseek(f, 0L, SEEK_END))
		return 1;
	
	sz = ftell(f);
	if (sz < 0)
		return 1;
	
	*size = sz;
	return fseek(f, 0L, SEEK_SET);
}


// Получает целочисленное значение num в файле f на позиции pos
int get_number_by_pos(FILE *f, int pos, int *num)
{
	int rc, read;

	rc = fseek(f, pos * sizeof(int), SEEK_SET);
	if (rc != 0)
		return 1;
	read = fread(num, sizeof(int), 1, f);
	if (read != 1)
		return 2;
	
	return fseek(f, 0L, SEEK_SET);
}


// Ставит на позицию pos целочисленное значение num в файл f
int put_number_by_pos(FILE *f, int pos, int *num)
{
	int rc, wrote;

	rc = fseek(f, pos * sizeof(int), SEEK_SET);
	if (rc != 0)
		return 1;
	wrote = fwrite(num, sizeof(int), 1, f);
	if (wrote != 1)
		return 2;
	
	return fseek(f, 0L, SEEK_SET);
}


// Создает бинарный файл заполненный случайными целыми числами от 0 до 99
// в количестве stramount -> int
int create_int_file(char *stramount, char *filename)
{
	FILE *f;
	int num;
	int amount;
	size_t wrote;
	int rc = 0;
	
	amount = atoi(stramount);
	if (amount == 0)
		return INCORRECT_ARGS;
	
	f = fopen(filename, "wb");
	
	if (f == NULL)
		return OPEN_FILE_ERROR;
	
	srand(time(NULL));

	for (int i = 0; i < amount && !rc; i++)
	{
		num = rand() % 100;
		
		wrote = fwrite(&num, sizeof(int), 1, f);

		rc = (wrote != 1);
	}
	
	fclose(f);

	if (rc)
		return CREATE_FILE_ERROR;
	return OK;
}


// Печатает целые числа из файла
int print_file(char *filename)
{
	FILE *f;
	size_t size;
	int num;
	size_t read;
	int rc = 0;
	
	f = fopen(filename, "rb");
	
	if (f == NULL)
		return OPEN_FILE_ERROR;
	
	rc = fseek(f, 0L, SEEK_SET);
	if (rc != 0)
		return READ_FILE_ERROR;

	rc = file_size(f, &size);
	
	if (size % sizeof(int) != 0)
		return SIZE_ERROR;

	if (rc == 0)
	{
		for (size_t i = 0; !rc && i < size / sizeof(int); i++)
		{
			read = fread(&num, sizeof(int), 1, f);

			if (read == 1)
				printf("%d\n", num);
			else
				rc = 1;
		}
		return OK;
	}
	else
	{
		fclose(f);
		return SIZE_ERROR;
	}
}


// Сортирует целые числа в файле по возрастанию
int sort_file(char *filename)
{
	FILE *f;
	int rc;
	size_t size;
	int left, right;
	
	f = fopen(filename, "rb+");
	if (f == NULL)
		return OPEN_FILE_ERROR;
	
	rc = file_size(f, &size);
	
	if (size % sizeof(int) != 0)
		return SIZE_ERROR;
	
	if (!rc)
	{
		for (size_t i = 0; !rc && i < size / sizeof(int) - 1; i++)
			for (size_t j = 0; !rc && j < size / sizeof(int) - i - 1; j++)
			{
				rc = get_number_by_pos(f, j, &left);
				if (rc != 0)
					break;
				rc = get_number_by_pos(f, j + 1, &right);
				if (rc != 0)
					break;
				
				if (left > right)
				{
					left = left + right;
					right = left - right;
					left = left - right;
				
					rc = put_number_by_pos(f, j, &left);
					if (rc != 0)
						break;
					rc = put_number_by_pos(f, j + 1, &right);
					if (rc != 0)
						break;
				}
			}
		if (rc)
		{
			fclose(f);
			return SORT_FILE_ERROR;
		}
		else
		{
			fclose(f);
			return OK;
		}
	}
	else
	{
		fclose(f);
		return SIZE_ERROR;
	}
}
