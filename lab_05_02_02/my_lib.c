#include "my_lib.h"
#include <stdio.h>


// Finds the average of numbers from a file
int average(FILE *f, double *avg)
{
	*avg = 0;
	rewind(f);
	int counter = 0;
	double curr;
	
	if (fscanf(f, "%lf", avg) == 1)
	{
		counter++;
		while (fscanf(f, "%lf", &curr) == 1)
		{
			*avg += curr;
			counter++;
		}
		if (feof(f))
		{
			*avg = (*avg) / counter;
			return OK;
		}
		else
			return IO_ERROR;
	}
	
	if (feof(f))
		return NO_DATA;
	else
		return IO_ERROR;
}

// Finds the variance of numbers from a file
int variance(FILE *f, double avg, double *disp)
{
	*disp = 0;
	rewind(f);
	int counter = 0;
	double curr;
	
	if (fscanf(f, "%lf", &curr) == 1)
	{
		*disp += (avg - curr) * (avg - curr);
		counter++;
		while (fscanf(f, "%lf", &curr) == 1)
		{
			*disp += (avg - curr) * (avg - curr);
			counter++;
		}
		if (feof(f))
		{
			*disp = (*disp) / counter;
			return OK;
		}
		else
			return IO_ERROR;
	}
	
	if (feof(f))
		return NO_DATA;
	else
		return IO_ERROR;
}

int process(FILE *f, double *disp)
{
	double avg;
	int rc;
	
	rc = average(f, &avg);
	if (rc != 0)
		return rc;
	
	rc = variance(f, avg, disp);
	if (rc != 0)
		return rc;
	
	return OK;
}