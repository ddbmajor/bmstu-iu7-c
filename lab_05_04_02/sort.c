#include "filestruct.h"
#include "sort.h"
#include <stdio.h>


int filecpy(FILE *src, FILE *dst)
{
	struct good tmp = { 0 };
	int rc = 1;
	size_t size;
	
	rc = file_size(dst, &size);
	if (size % sizeof(struct good) != 0)
		return BAD_FILE;
	if (rc == 0)
	{
		rc = 1;
		while (rc)
		{
			rc = fread(&tmp, sizeof(tmp), 1, src);
			if (rc != 1)
				return OK;
			else
				rc = fwrite(&tmp, sizeof(tmp), 1, dst);
		}
		return COPY_ERROR;
	}
	else
		return SIZE_ERROR;
}


int first_sort(char *filename)
{
	FILE *dst;
	int rc;
	dst = fopen(filename, "rb+");
	if (dst == NULL)
		return OPEN_FILE_ERROR;
	
	size_t size;
	rc = file_size(dst, &size);
	if (!rc)
	{
		if (size % sizeof(struct good) != 0)
		{
			fclose(dst);
			return BAD_FILE;
		}
		
		struct good left = { 0 };
		struct good right = { 0 };
		struct good tmp = { 0 };

		
		for (size_t i = 0; !rc && i < size / sizeof(struct good) - 1; i++)
			for (size_t j = 0; !rc && j < size / sizeof(struct good) - i - 1; j++)
			{
				rc = get_struct_by_pos(dst, j, &left);
				if (rc != 0)
					break;
				rc = get_struct_by_pos(dst, j + 1, &right);
				if (rc != 0)
					break;
				
				if (left.price < right.price)
				{
					tmp = left;
					left = right;
					right = tmp;
					
					rc = put_struct_by_pos(dst, j, &left);
					if (rc != 0)
						break;
					rc = put_struct_by_pos(dst, j + 1, &right);
					if (rc != 0)
						break;
				}
			}
		
		if (rc)
		{
			fclose(dst);
			return SORT_FILE_ERROR;
		}
		else
		{	
			
			fclose(dst);
			return OK;
		}
	}
	else
	{
		fclose(dst);
		return SIZE_ERROR;
	}
}

int second_sort(char *filename)
{
	FILE *dst;
	int rc;
	dst = fopen(filename, "rb+");
	if (dst == NULL)
		return OPEN_FILE_ERROR;
	
	size_t size;
	rc = file_size(dst, &size);
	if (!rc)
	{
		if (size % sizeof(struct good) != 0)
			return BAD_FILE;
		
		struct good left = { 0 };
		struct good right = { 0 };
		struct good tmp = { 0 };

		size_t start = 0;
		size_t finish = 0;
		size_t k = 1;
		struct good curr = { 0 };
		unsigned int currprice;

		while (!rc && start < size / sizeof(struct good) - 1)
		{
			rc = get_struct_by_pos(dst, start, &curr);
			if (rc != 0)
				break;
			currprice = curr.price;
			while (curr.price == currprice && finish < size / sizeof(struct good) - 1)
			{
				rc = get_struct_by_pos(dst, start + k, &curr);
				if (rc != 0)
					break;
				if (curr.price == currprice)
					k++;
			}
			if (k > 1)
			{
				finish = start + k;
				for (size_t i = start; i < finish - 1; i++)
					for (size_t j = start; j < finish - 1; j++)
					{
						rc = get_struct_by_pos(dst, j, &left);
						if (rc != 0)
							break;
						rc = get_struct_by_pos(dst, j + 1, &right);
						if (rc != 0)
							break;
						
						if (left.amount < right.amount)
						{
							tmp = left;
							left = right;
							right = tmp;
							
							rc = put_struct_by_pos(dst, j, &left);
							if (rc != 0)
								break;
							rc = put_struct_by_pos(dst, j + 1, &right);
							if (rc != 0)
								break;
						}
					}
				start = finish;
				k = 1;
			}
			else
				start++;
		}
		if (rc)
		{
			fclose(dst);
			return SORT_FILE_ERROR;
		}
		else
		{	
			
			fclose(dst);
			return OK;
		}
	}
	else
	{
		fclose(dst);
		return SIZE_ERROR;
	}
}

int sort(char *srcfn, char *dstfn)
{
	FILE *src;
	FILE *dst;
	
	int rc;
	
	src = fopen(srcfn, "rb");
	if (src == NULL)
		return OPEN_FILE_ERROR;
	dst = fopen(dstfn, "wb");
	if (dst == NULL)
		return OPEN_FILE_ERROR;
	
	rc = filecpy(src, dst);
	if (rc != 0)
	{
		fclose(src);
		fclose(dst);
		return rc;
	}
	
	fclose(src);
	fclose(dst);
	
	rc = first_sort(dstfn);
	if (rc != 0)
		return SORT_FILE_ERROR;
	
	rc = second_sort(dstfn);
	if (rc != 0)
		return SORT_FILE_ERROR;
	
	return OK;
}