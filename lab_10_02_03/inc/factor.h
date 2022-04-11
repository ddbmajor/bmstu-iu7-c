#ifndef _FACTOR_H_

#include <stdlib.h>

typedef struct
{
    int power;
} factor_t;


factor_t *create_factor(int power);
void delete_factor(void *data);

#define _FACTOR_H_
#endif