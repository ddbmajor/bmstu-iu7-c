#include "my_lib.h"
#include <stdio.h>
#include <string.h>

#define N 128
#define WL 16

int ch_in_str(const char ch, const char str[WL])
{
	for (int i = 0; str[i] != '\0'; i++)
		if (str[i] == ch)
			return 1;
	return 0;
}

int read_line(char *str, int n)
{
	int ch, i = 0;
	while ((ch = getchar()) != '\n' && ch != EOF)
		if (i < n - 1)
			str[i++] = ch;
		else
		{
			str[i] = '\0';
			return -1;
		}
	str[i] = '\0';
	return i;
}

int read_line_by_words(char *str, char arr[N][WL + 1])
{
	int i = 0, j = 0, n = 0;
	char separators[] = " ,;:-.!?";
	
	while (str[i] != '\0')
	{
		while (ch_in_str(str[i], separators) && str[i] != '\0')
			i++;
		while (!(ch_in_str(str[i], separators)) && str[i] != '\0')
		{
			if (j < WL + 1)
			{
				arr[n][j++] = str[i];
				i++;
			}
			else
				return -1;
		}
		if (!(ch_in_str(str[i - 1], separators)) && str[i - 1] != '\0')
		{
			arr[n][j] = '\0';
			j = 0;
			n++;
		}
	}
	return n;
}


int is_there_word(char str[WL + 1], char arr[N][WL + 1], int n)
{
	short int flag = 0;
	for (int i = 0; i < n; i++)
		if (strcmp(str, arr[i]) == 0)
			flag = 1;
	if (flag == 0)
		return 0;
	else
		return 1;
}

int unique_words(char a_1[N][WL + 1], int n1, char a_2[N][WL + 1], int n2, char res[N][WL + 1])
{
	short int flag = 0;
	int counter = 0;
	for (int i = 0; i < n1; i++)
	{
		for (int j = 0; j < n1; j++)
			if (i != j)
				if (strcmp(a_1[i], a_1[j]) == 0)
					flag = 1;
		if (flag == 0)
			if (is_there_word(a_1[i], a_2, n2) == 0)
			{
				strncpy(res[counter], a_1[i], WL + 1);
				counter++;
			}
		flag = 0;
	}
	return counter;
}
