#include "libfuncs_for_py.h"

int fibFillArray(int *array, int size)
{
    if (array == NULL)
        return NULL_ARRAY_ERROR;
    if (size <= 0)
        return SIZE_ERROR;
    if (size >= 1)
        array[0] = 0;
    if (size >= 2)
        array[1] = 1;
    for (int i = 2; i < size; i++)
    {
        array[i] = array[i - 2] + array[i - 1];
    }
    return 0;
}

static int findInArray(int value, int *array, int size)
{
    for (int i = 0; i < size; i++)
    {
        if (value == array[i])
            return 1;
    }
    return 0;
}

int uniqueArray(int *array, int size, int *newArray, int new_array_size)
{
    if (array == NULL)
        return NULL_ARRAY_ERROR;
    if (size <= 0)
        return SIZE_ERROR;
    int *tmp = malloc(size * sizeof(int));
    if (!tmp)
        return ALLOC_ERROR;
    
    int count = 0;
    for (int i = 0; i < size; ++i)
    {
        if (!(findInArray(array[i], tmp, count)))
        {
            tmp[count] = array[i];
            count++;
        }
    }

    if (count > new_array_size)
    {
        free(tmp);
        return count;
    }
    else
    {
        if (!newArray)
        {
            free(tmp);
            return NULL_ARRAY_ERROR;
        }
        for (int i = 0; i < count; i++)
        {
            newArray[i] = tmp[i];
        }
    }
    free(tmp);
    return 0;
}