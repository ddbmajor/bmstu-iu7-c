#ifndef _LIST_H_

#include <stdlib.h>
#include "node.h"

node_t *reverse(node_t *head);
void list_apply(node_t *head, void (*f)(node_t *node, void *), void *arg);
void list_count(node_t *node, void *arg);
void delete_list(node_t *head, void del_data(void *));
node_t *list_append(node_t *head, node_t *node);

#define _LIST_H_
#endif