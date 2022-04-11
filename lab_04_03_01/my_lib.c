#include "my_lib.h"
#include <stdio.h>
#include <string.h>

#define WL 16
#define SL 256
#define N 128

void format_word(char str[WL + 1], char newstr[WL + 1])
{
	char already_found[SL + 1] = "\0";
	int counter = 0;
	int k = 0;
	for (int i = 0; str[i] != '\0'; i++)
		if (!(strchr(already_found, str[i])))
		{
			newstr[counter] = str[i];
			counter++;
			already_found[k] = str[i];
			k++;
		}
	newstr[counter] = '\0';
}

int form_word_array(char arr[N][WL + 1])
{
	char str[SL + 1];
	char tmp[1];
	int len;
	
	if (!fgets(str, sizeof(str), stdin))
		return -1;
	
	len = strlen(str);
	if (str[len - 1] == '\n')
		str[len - 1] = '\0';
	else if (fgets(tmp, sizeof(tmp), stdin))
		return -2;
	
	int n = 0;
	char *pch = strtok(str, " ,;:-.!?");
	while (pch != NULL)
	{
		if (strlen(pch) > WL)
			return -2;
		strncpy(arr[n], pch, WL + 1);
		n++;
		pch = strtok(NULL, " ,;:-.!?");
	}
	
	return n;
}

int form_string(char str[SL + 1], char arr[N][WL + 1], int n)
{
	char word[WL + 1];
	int pos = 0;
	for (int i = n - 2; i >= 0; i--)
		if (strcmp(arr[i], arr[n - 1]) != 0)
		{
			format_word(arr[i], word);
			for (int j = 0; word[j] != '\0'; j++)
				str[pos++] = word[j];
			str[pos++] = ' ';
		}
	str[pos] = '\0';
	
	return (strlen(str));
}
