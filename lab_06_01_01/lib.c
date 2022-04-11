#include "lib.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>


// Check if string contain only space simbols
int isstrspace(char str[MAXLEN])
{
	for (int i = 0; str[i] != '\0'; i++)
	{
		if (!(isspace(str[i])))
			return 0;
	}
	return 1;
}


// Print array of struct's
void printarr(struct film arr[], int amount)
{
	for (int i = 0; i < amount; i++)
	{
		printf("%s\n", arr[i].title);
		printf("%s\n", arr[i].name);
		printf("%d\n", arr[i].year);
	}
}


void strndel(char str[MAXLEN + 3])
{
	for (int i = 0; str[i] != '\0'; i++)
		if (str[i] == '\n' || str[i] == '\r')
			str[i] = '\0';
}


// Read structure from a file
int structread(FILE *f, struct film *dst)
{
	char tmp[MAXLEN + 3] = "\0";
	char *endptr;
	long int tmpyear;
	
	if (fgets(tmp, sizeof(tmp), f) == NULL)
	{
		if (feof(f))
			return -1;
		else
			return INPUT_ERROR;
	}
	if (isstrspace(tmp))
		return EMPTY_STR_ERROR;
	strndel(tmp);
	if (tmp[MAXLEN] != '\0')
		return OVERFLOW_ERROR;
	strcpy(dst->title, tmp);
	
	if (fgets(tmp, sizeof(tmp), f) == NULL)
		return INPUT_ERROR;
	if (isstrspace(tmp))
		return EMPTY_STR_ERROR;
	strndel(tmp);
	if (tmp[MAXLEN] != '\0')
		return OVERFLOW_ERROR;
	strcpy(dst->name, tmp);
	
	if (fgets(tmp, sizeof(tmp), f) == NULL)
		return INPUT_ERROR;
	if (isstrspace(tmp))
		return EMPTY_STR_ERROR;
	strndel(tmp);
	tmpyear = strtol(tmp, &endptr, 10);
	if (*endptr == '\n' || *endptr == '\0' || *endptr == '\r')
	{
		if (tmpyear <= 0)
			return YEAR_ERROR;
		dst->year = tmpyear;
	}
	else
		return YEAR_ERROR;
	
	return 0;
}


// Sort array of struct's by film's title
int titlesort(FILE *f, struct film films[MAXAMOUNT + 1], int *amount)
{
	struct film curr;
	
	int rc;
	
	*amount = 0;
	
	for (int i = 0; i < MAXAMOUNT + 1; i++)
	{
		rc = structread(f, &curr);
		if (rc > 0)
			return rc;
		else if (rc < 0)
			break;
		
		if (*amount == 0)
			films[0] = curr;
		
		// Insert sort
		for (int j = 0; j < *amount; j++)
		{
			if (strcmp(curr.title, films[j].title) < 0)
			{
				for (int k = *amount; k > j; k--)
					films[k] = films[k - 1];
				films[j] = curr;
				break;
			}
			films[*amount] = curr;
		}
		(*amount)++;
	}
	if (*amount == 0)
		return EMPTY_FILE_ERROR;
	
	if (*amount > MAXAMOUNT)
		return AMOUNT_ERROR;
	
	return 0;
}


// Sort array of struct's by film's author name
int namesort(FILE *f, struct film films[MAXAMOUNT + 1], int *amount)
{
	struct film curr;
	
	int rc;
	
	*amount = 0;
	
	for (int i = 0; i < MAXAMOUNT + 1; i++)
	{
		rc = structread(f, &curr);
		if (rc > 0)
			return rc;
		else if (rc < 0)
			break;
		
		if (*amount == 0)
			films[0] = curr;
		
		// Insert sort
		for (int j = 0; j < *amount; j++)
		{
			if (strcmp(curr.name, films[j].name) < 0)
			{
				for (int k = *amount; k > j; k--)
					films[k] = films[k - 1];
				films[j] = curr;
				break;
			}
			films[*amount] = curr;
		}
		(*amount)++;
	}
	if (*amount == 0)
		return EMPTY_FILE_ERROR;
	
	if (*amount > MAXAMOUNT)
		return AMOUNT_ERROR;
	
	return 0;
}


// Sort array of struct's by film's year of release
int yearsort(FILE *f, struct film films[MAXAMOUNT + 1], int *amount)
{
	struct film curr;
	
	int rc;
	
	*amount = 0;
	
	for (int i = 0; i < MAXAMOUNT + 1; i++)
	{
		rc = structread(f, &curr);
		if (rc > 0)
			return rc;
		else if (rc < 0)
			break;
		
		if (*amount == 0)
			films[0] = curr;
		
		// Insert sort
		for (int j = 0; j < *amount; j++)
		{
			if (curr.year < films[j].year)
			{
				for (int k = *amount; k > j; k--)
					films[k] = films[k - 1];
				films[j] = curr;
				break;
			}
			films[*amount] = curr;
		}
		(*amount)++;
	}
	if (*amount == 0)
		return EMPTY_FILE_ERROR;
	
	if (*amount > MAXAMOUNT)
		return AMOUNT_ERROR;
	
	return 0;
}


// Print sorted by title array of struct's
int titleprint(FILE *f)
{
	int rc;
	struct film films[MAXAMOUNT + 1];
	int amount = 0;
	
	rc = titlesort(f, films, &amount);
	if (rc != 0)
		return rc;
	
	printarr(films, amount);
	
	return 0;
}


// Print sorted by name array of struct's
int nameprint(FILE *f)
{
	int rc;
	struct film films[MAXAMOUNT + 1];
	int amount = 0;
	
	rc = namesort(f, films, &amount);
	if (rc != 0)
		return rc;
	
	printarr(films, amount);
	
	return 0;
}


// Print sorted by year array of struct's
int yearprint(FILE *f)
{
	int rc;
	struct film films[MAXAMOUNT + 1];
	int amount = 0;
	
	rc = yearsort(f, films, &amount);
	if (rc != 0)
		return rc;
	
	printarr(films, amount);
	
	return 0;
}


// Find film with needed title
int titlefind(FILE *f, char title[MAXLEN + 3])
{
	int rc;
	struct film films[MAXAMOUNT + 1];
	int amount = 0;
	
	rc = titlesort(f, films, &amount);
	if (rc != 0)
		return rc;
	else
	{
		
		int low = 0;
		int high = amount - 1;
		int i = (high + low) / 2;

		while (strcmp(title, films[i].title) != 0 && low <= high)
		{
			if (strcmp(title, films[i].title) > 0)
				low = i + 1;
			else
				high = i - 1;
			i = (low + high) / 2;
		}
		if (low > high)
			printf("Not found");
		else
		{
			printf("%s\n", films[i].title);
			printf("%s\n", films[i].name);
			printf("%d\n", films[i].year);
		}
	}
	
	return 0;
}


// Find film with needed author's name
int namefind(FILE *f, char name[MAXLEN + 3])
{
	int rc;
	struct film films[MAXAMOUNT + 1];
	int amount = 0;
	
	
	rc = namesort(f, films, &amount);
	if (rc != 0)
		return rc;
	else
	{
		int low = 0;
		int high = amount - 1;
		int i = (high + low) / 2;

		while (strcmp(name, films[i].name) != 0 && low <= high)
		{
			if (strcmp(name, films[i].name) > 0)
				low = i + 1;
			else
				high = i - 1;
			i = (low + high) / 2;
		}
		if (low > high)
			printf("Not found");
		else
		{
			printf("%s\n", films[i].title);
			printf("%s\n", films[i].name);
			printf("%d\n", films[i].year);
		}
	}
	
	return 0;
}


// Find film with needed year
int yearfind(FILE *f, char year[MAXLEN + 3])
{
	int rc;
	struct film films[MAXAMOUNT + 1];
	int amount = 0;
	
	int intyear;
	char *endptr;
	intyear = strtol(year, &endptr, 10);
	if (*endptr == '\n' || *endptr == '\0' || *endptr == '\r')
	{
		if (intyear <= 0)
			return ARG_ERROR;
	}
	else
		return YEAR_ERROR;
	
	rc = yearsort(f, films, &amount);
	if (rc != 0)
		return rc;
	else
	{
		int low = 0;
		int high = amount - 1;
		int i = (high + low) / 2;

		while (films[i].year != intyear && low <= high)
		{
			if (intyear > films[i].year)
				low = i + 1;
			else
				high = i - 1;
			i = (low + high) / 2;
		}
		if (low > high)
			printf("Not found");
		else
		{
			printf("%s\n", films[i].title);
			printf("%s\n", films[i].name);
			printf("%d\n", films[i].year);
		}
	}
	return 0;
}