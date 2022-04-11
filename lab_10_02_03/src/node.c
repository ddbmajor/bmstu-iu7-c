#include "node.h"


node_t *create_node(void *data)
{
    node_t *node = malloc(sizeof(node_t));
    if (node == NULL)
        return NULL;
    node->data = data;
    node->next = NULL;

    return node;
}


void delete_node(node_t *node, void del_data(void *))
{
    del_data(node->data);
    free(node);
}