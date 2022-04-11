#include "process.h"


int titleprint(FILE *f)
{
	int rc;
	struct dyn_array films;
	init_dyn_array(&films);
	
	rc = titlesort(f, &films);
	if (rc != 0)
	{
		free_dyn_array(&films);
		return rc;
	}
	
	printarr(films);
	free_dyn_array(&films);
	
	return 0;
}


int nameprint(FILE *f)
{
	int rc;
	struct dyn_array films;
	init_dyn_array(&films);
	
	rc = namesort(f, &films);
	if (rc != 0)
	{
		free_dyn_array(&films);
		return rc;
	}
	
	printarr(films);
	free_dyn_array(&films);
	
	return 0;
}


int yearprint(FILE *f)
{
	int rc;
	struct dyn_array films;
	init_dyn_array(&films);
	
	rc = yearsort(f, &films);
	if (rc != 0)
	{
		free_dyn_array(&films);
		return rc;
	}
	
	printarr(films);
	free_dyn_array(&films);
	
	return 0;
}


int titlefind(FILE *f, char *title)
{
	int rc;
	struct dyn_array films;
	init_dyn_array(&films);
	
	rc = titlesort(f, &films);
	if (rc != 0)
	{
		free_dyn_array(&films);
		return rc;
	}
	else
	{
		
		int low = 0;
		int high = films.len - 1;
		int i = (high + low) / 2;

		while (strcmp(title, films.data[i].title) != 0 && low <= high)
		{
			if (strcmp(title, films.data[i].title) > 0)
				low = i + 1;
			else
				high = i - 1;
			i = (low + high) / 2;
		}
		if (low > high)
			printf("Not found");
		else
		{
			printf("%s\n", films.data[i].title);
			printf("%s\n", films.data[i].name);
			printf("%d\n", films.data[i].year);
		}
	}

	free_dyn_array(&films);
	return 0;
}


int namefind(FILE *f, char *name)
{
	int rc;
	struct dyn_array films;
	init_dyn_array(&films);
	
	rc = namesort(f, &films);
	if (rc != 0)
	{
		free_dyn_array(&films);
		return rc;
	}
	else
	{
		
		int low = 0;
		int high = films.len - 1;
		int i = (high + low) / 2;

		while (strcmp(name, films.data[i].name) != 0 && low <= high)
		{
			if (strcmp(name, films.data[i].name) > 0)
				low = i + 1;
			else
				high = i - 1;
			i = (low + high) / 2;
		}
		if (low > high)
			printf("Not found");
		else
		{
			printf("%s\n", films.data[i].title);
			printf("%s\n", films.data[i].name);
			printf("%d\n", films.data[i].year);
		}
	}
	
	free_dyn_array(&films);
	return 0;
}


int yearfind(FILE *f, char *year)
{
	int rc;
	struct dyn_array films;
	init_dyn_array(&films);
	
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
	
	rc = yearsort(f, &films);
	if (rc != 0)
	{
		free_dyn_array(&films);
		return rc;
	}
	else
	{
		int low = 0;
		int high = films.len - 1;
		int i = (high + low) / 2;

		while (films.data[i].year != intyear && low <= high)
		{
			if (intyear > films.data[i].year)
				low = i + 1;
			else
				high = i - 1;
			i = (low + high) / 2;
		}
		if (low > high)
			printf("Not found");
		else
		{
			printf("%s\n", films.data[i].title);
			printf("%s\n", films.data[i].name);
			printf("%d\n", films.data[i].year);
		}
	}

	free_dyn_array(&films);
	return 0;
}