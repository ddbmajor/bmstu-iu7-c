#include "my_lib.h"
#include <ctype.h>

int is_it_phonenum(char *str)
{
	int i = 0;
	int counter = 0;
	short int flag = 0;
	
	while (str[i] != '\0' && isspace(str[i]))
		i++;
	
	if (str[i] == '+')
	{
		i++;
		while (str[i] != '(' && str[i] != '\0')
		{
			if (!isdigit(str[i++]))
				return 0;
			flag = 1;
		}
		if (!flag)
			return 0;
	}
	
	flag = 0;
	if (str[i] == '(')
	{
		i++;
		while (str [i] != ')' && str[i] != '\0')
		{
			if (!isdigit(str[i++]))
				return 0;
			counter++;
		}
		if (counter != 3)
			return 0;
		flag++;
		i++;
	}
	
	counter = 0;
	if (str[i] == '-')
	{
		i++;
		while (str[i] != '-' && str[i] != '\0')
		{
			if (!isdigit(str[i++]))
				return 0;
			counter++;
		}
		if (counter != 3)
			return 0;
		flag++;
	}
	
	counter = 0;
	if (str[i] == '-')
	{
		i++;
		while (str[i] != '-' && str[i] != '\0')
		{
			if (!isdigit(str[i++]))
				return 0;
			counter++;
		}
		if (counter != 2)
			return 0;
		flag++;
	}
	
	counter = 0;
	if (str[i] == '-')
	{
		i++;
		while (str[i] != '\0' && !isspace(str[i]))
		{
			if (!isdigit(str[i++]))
				return 0;
			counter++;
		}
		if (counter != 2)
			return 0;
		flag++;
	}
	
	if (flag == 4)
	{
		for (; str[i] != '\0'; i++)
			if (!isspace(str[i]))
				return 0;
		return 1;
	}
	else
		return 0;
}