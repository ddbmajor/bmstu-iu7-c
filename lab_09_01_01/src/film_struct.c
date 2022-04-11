#include "film_struct.h"

int structread(FILE *f, struct film *dst)
{
	char *tmp = NULL;
	size_t len = 0;
	ssize_t read;
	char *endptr;
	long int tmpyear;
	
	read = getline(&tmp, &len, f);
	if (read < 1)
	{
		free(tmp);
		if (feof(f))
			return -1;
		else
			return INPUT_ERROR;
	}
	if (isstrspace(tmp))
	{
		free(tmp);
		return EMPTY_STR_ERROR;
	}
	strndel(tmp);
	dst->title = strdup(tmp);
	
	read = getline(&tmp, &len, f);
	if (read < 1)
	{
		free(dst->title);
		free(tmp);
		return INPUT_ERROR;
	}
	if (isstrspace(tmp))
	{
		free(dst->title);
		free(tmp);
		return EMPTY_STR_ERROR;
	}
	strndel(tmp);
	dst->name = strdup(tmp);
	
	read = getline(&tmp, &len, f);
	if (read < 1)
	{
		free(dst->title);
		free(dst->name);
		free(tmp);
		return INPUT_ERROR;
	}
	if (isstrspace(tmp))
	{
		free(dst->title);
		free(dst->name);
		free(tmp);
		return EMPTY_STR_ERROR;
	}
	strndel(tmp);
	tmpyear = strtol(tmp, &endptr, 10);
	if (*endptr == '\n' || *endptr == '\0' || *endptr == '\r')
	{
		if (tmpyear <= 0)
		{
			free(dst->title);
			free(dst->name);
			free(tmp);
			return YEAR_ERROR;
		}
		dst->year = tmpyear;
	}
	else
	{
		free(dst->title);
		free(dst->name);
		free(tmp);
		return YEAR_ERROR;
	}
	free(tmp);
	return 0;
}


void strndel(char *str)
{
	for (int i = 0; str[i] != '\0'; i++)
		if (str[i] == '\n' || str[i] == '\r')
			str[i] = '\0';
}


int isstrspace(char *str)
{
	for (int i = 0; str[i] != '\0'; i++)
	{
		if (!(isspace(str[i])))
			return 0;
	}
	return 1;
}