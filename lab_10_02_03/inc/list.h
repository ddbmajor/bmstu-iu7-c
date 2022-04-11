#ifndef _LIST_H_

#include <stdlib.h>
#include "node.h"


void delete_list(node_t *head, void del_data(void *));
node_t *list_append(node_t *head, node_t *node);

#define _LIST_H_
#endif