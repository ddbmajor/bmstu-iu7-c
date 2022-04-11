#include "dyn_array.h"


void init_dyn_array(struct dyn_array *arr)
{
	arr->len = 0;
	arr->allocated = 0;
	arr->data = NULL;
	arr->step = 2;
}


void free_dyn_array(struct dyn_array *arr)
{
	for (int i = 0; i < arr->len; i++)
	{
		free(arr->data[i].name);
		free(arr->data[i].title);
	}
	free(arr->data);
	arr->len = 0;
	arr->allocated = 0;
}


int append(struct dyn_array *arr, struct film f)
{
	if (!arr->data)
	{
		arr->data = malloc(sizeof(struct film));
		if (!arr->data)
			return ALLOC_ERROR;
		arr->allocated = 1;
	}
	else
	{
		if (arr->len >= arr->allocated)
		{
			struct film *tmp = realloc(arr->data, arr->allocated * arr->step * sizeof(struct film));
			if (!tmp)
			{
				return ALLOC_ERROR;
			}
			arr->data = tmp;
			arr->allocated *= arr->step;
		}
	}
	arr->data[arr->len] = f;
	arr->len++;
	return 0;
}


void printarr(struct dyn_array arr)
{
	for (int i = 0; i < arr.len; i++)
	{
		printf("%s\n", arr.data[i].title);
		printf("%s\n", arr.data[i].name);
		printf("%d\n", arr.data[i].year);
	}
}