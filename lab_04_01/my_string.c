#include "my_string.h"
#include <stdio.h>


char *my_strchr(const char *str, char n)
{
	int i;
	for (i = 0; str[i] != '\0'; i++)
		if (str[i] == n)
			return ((char *)(str + i));
	
	if (str[i] == n)
		return ((char *)(str + i));
	
	return NULL;
}

char *my_strpbrk(const char *str1, const char *str2)
{
	for (int i = 0; str1[i] != '\0'; i++)
		if (my_strchr(str2, str1[i]))
			return ((char *)(str1 + i));
		
	return NULL;
}
