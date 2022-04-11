#include "factor.h"


factor_t *create_factor(int power)
{
    factor_t *factor = malloc(sizeof(factor_t));
    if (factor == NULL)
        return NULL;
    factor->power = power;

    return factor;
}


void delete_factor(void *data)
{
    factor_t *factor = data;
    free(factor);
}
