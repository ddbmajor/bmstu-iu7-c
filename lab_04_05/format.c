#include "format.h"
#include <stdio.h>
#include <ctype.h>
#include <string.h>

void space_remover(char str[SL + 1])
{
	int k;
	for (int i = 0; str[i] != '\0'; i++)
		if (isspace(str[i]))
			for (int j = i + 1; isspace(str[j]); j++)
			{
				for (k = j; str[k] != '\0'; k++)
					str[k] = str[k + 1];
				str[k] = '\0';
				j--;
			}
	if (isspace(str[0]))
	{
		for (k = 0; str[k] != '\0'; k++)
			str[k] = str[k + 1];
		str[k] = '\0';
	}

	k = strlen(str);
	if (isspace(str[k - 1]))
		str[k] = '\0';
}

void begin_mark_remover(char str[SL + 1])
{
	int i = 0;
	int k;
	while (str[i] != '\0' && (strchr(MARKS, str[i]) || str[i] == ' '))
	{
		for (k = i; str[k] != '\0'; k++)
			str[k] = str[k + 1];
		str[k] = '\0';
	}
}

void mark_space_remover(char str[SL + 1])
{
	int k;
	for (int i = 0; str[i] != '\0'; i++)
		if (strchr(MARKS, str[i]) && str[i - 1] == ' ')
		{
			for (k = i - 1; str[k] != '\0'; k++)
				str[k] = str[k + 1];
			str[k] = '\0';
		}
}

void mark_space_adder(char str[SL + 1])
{
	int len = strlen(str);
	for (int i = 0; str[i] != '\0'; i++)
		if (strchr(MARKS, str[i]) && str[i + 1] != ' ')
		{
			for (int j = len - 1; j > i + 1; j--)
				str[j] = str[j - 1];
			str[i + 1] = ' ';
			len++;
		}
}

void mark_remover(char str[SL + 1])
{
	int k;
	for (int i = 1; str[i] != '\0'; i++)
		if (strchr(MARKS, str[i]) && strchr(MARKS, str[i - 1]) && str[i] == str[i - 1])
		{
			for (k = i; str[k] != '\0'; k++)
				str[k] = str[k + 1];
			str[k] = '\0';
			i--;
		}
}

void upper(char str[SL + 1])
{
	str[0] = toupper(str[0]);
	
	for (int i = 0; str[i] != '\0'; i++)
		if (strchr("!.?", str[i]))
			str[i + 2] = toupper(str[i + 2]);
}

void dotter(char str[SL + 1])
{
	int len = strlen(str);
	
	if (str[len - 1] != '!' && str[len - 1] != '?' && str[len - 1] != '.')
		str[len] = '.';
	str[len + 1] = '\0'; 
}

int latinchecker(char str[SL + 1])
{
	int flag1 = 1;
	int flag2 = 0;
	for (int i = 0; str[i] != '\0'; i++)
	{
		if (str[i] > 126)
			flag1 = 0;
		if ((str[i] > 64 && str[i] < 91) || (str[i] > 96 && str[i] < 123))
			flag2 = 1;
	}
	if (flag1 && flag2)
		return 0;
	else
		return -1;
}

int format_text(char str[SL + 1])
{
	int rc = 0;
	rc = latinchecker(str);
	if (rc != 0)
		return -1;
	space_remover(str);
	begin_mark_remover(str);
	mark_remover(str);
	mark_space_remover(str);
	mark_space_adder(str);
	upper(str);
	if (isspace(str[strlen(str) - 1]))
		str[strlen(str) - 1] = '\0';
	dotter(str);
	if (strlen(str) == 0)
		rc = -2;
	return rc;
}