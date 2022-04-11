#ifndef _NUMBER_H_

#include <stdio.h>
#include "defines.h"
#include "node.h"
#include "factor.h"
#include "list.h"

node_t *create_number(int n);
void print_number(node_t *number);
node_t *multiply(node_t *a, node_t *b);
node_t *square(node_t *number);
int division(node_t **res, node_t *a, node_t *b);

#define _NUMBER_H_
#endif