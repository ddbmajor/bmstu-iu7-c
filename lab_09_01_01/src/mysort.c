#include "mysort.h"


int titlesort(FILE *f, struct dyn_array *films)
{
	struct film curr;
	
	int rc = 0;
	
	int amount = 0;;
	
	while (rc == 0)
	{
		rc = structread(f, &curr);
		if (rc > 0)
			return rc;
		else if (rc < 0)
			break;
	
		rc = append(films, curr);
		if (rc != 0)
			return rc;

		
		// Insert sort
		for (int j = 0; j < amount; j++)
		{
			if (strcmp(curr.title, films->data[j].title) < 0)
			{
				for (int k = amount; k > j; k--)
					films->data[k] = films->data[k - 1];
				films->data[j] = curr;
				break;
			}
			films->data[amount] = curr;
		}
		amount++;
	}
	if (amount == 0)
		return EMPTY_FILE_ERROR;
	
	return 0;
}


int namesort(FILE *f, struct dyn_array *films)
{
	struct film curr;
	
	int rc = 0;
	
	int amount = 0;;
	
	while (rc == 0)
	{
		rc = structread(f, &curr);
		if (rc > 0)
			return rc;
		else if (rc < 0)
			break;
		
		rc = append(films, curr);
		if (rc != 0)
			return rc;
		
		// Insert sort
		for (int j = 0; j < amount; j++)
		{
			if (strcmp(curr.name, films->data[j].name) < 0)
			{
				for (int k = amount; k > j; k--)
					films->data[k] = films->data[k - 1];
				films->data[j] = curr;
				break;
			}
			films->data[amount] = curr;
		}
		amount++;
	}
	if (amount == 0)
		return EMPTY_FILE_ERROR;

	return 0;
}


int yearsort(FILE *f, struct dyn_array *films)
{
	struct film curr;
	
	int rc = 0;
	
	int amount = 0;;
	
	while (rc == 0)
	{
		rc = structread(f, &curr);
		if (rc > 0)
			return rc;
		else if (rc < 0)
			break;
		
		rc = append(films, curr);
		if (rc != 0)
			return rc;
		
		// Insert sort
		for (int j = 0; j < amount; j++)
		{
			if (curr.year < films->data[j].year)
			{
				for (int k = amount; k > j; k--)
					films->data[k] = films->data[k - 1];
				films->data[j] = curr;
				break;
			}
			films->data[amount] = curr;
		}
		amount++;
	}
	if (amount == 0)
		return EMPTY_FILE_ERROR;
	
	return 0;
}