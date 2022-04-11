#include "filestruct.h"
#include "find.h"
#include <string.h>
#include <stdio.h>


int strrstr(char *str, char *fstr)
{
	int n = strlen(str), fn = strlen(fstr);
	
	if (fn > n)
		return 0;
	int answer = 1;
	for (int i = 1; i <= fn; ++i)
	{
		if (str[n - i] != fstr[fn - i])
			answer = 0;
	}
	return answer;
}


int find(char *src, char *substr)
{
	FILE *f;
	struct good tmpgood = { 0 };
	int rc, read;
	size_t size;
	
	f = fopen(src, "rb");
	if (f == NULL)
		return OPEN_FILE_ERROR;

	rc = file_size(f, &size);
	
	if (size % sizeof(struct good) != 0)
	{
		fclose(f);
		return BAD_FILE;
	}

	int flag = 0;
	if (rc == 0)
	{
		for (size_t i = 0; !rc && i < size / sizeof(int); i++)
		{
			read = fread(&tmpgood, sizeof(struct good), 1, f);

			if (read == 1)
			{
				if (strrstr(tmpgood.name, substr))
				{
					flag = 1;
					printf("%s\n", tmpgood.name);
					printf("%s\n", tmpgood.maker);
					printf("%u\n", tmpgood.price);
					printf("%u\n", tmpgood.amount);
				}
			}
			else
				rc = 1;
		}
		if (flag)
		{
			fclose(f);
			return OK;
		}
		else
		{
			fclose(f);
			return FIND_ERROR;
		}
	}
	else
	{
		fclose(f);
		return SIZE_ERROR;
	}
	
	return 0;
}