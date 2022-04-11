#ifndef _NODE_H_

#include <stdlib.h>

typedef struct node node_t;

struct node
{
    void *data;
    node_t *next;
};

node_t *create_node(void *data);
void delete_node(node_t *node, void del_data(void *));
node_t *find(node_t *head, const void *data, int (*comparator)(const void *, const void *));
void *pop_back(node_t **head);

#define _NODE_H_
#endif