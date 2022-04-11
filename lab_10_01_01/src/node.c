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


node_t *find(node_t *head, const void *data, int (*comparator)(const void *, const void *))
{
    node_t *curr = head;
    while (curr)
    {
        if (comparator(curr->data, data) == 0)
            return curr;
        curr = curr->next;
    }
    return NULL;
}


void *pop_back(node_t **head)
{
    if (!head || !(*head))
        return NULL;
    node_t *curr = *head, *before_curr = NULL;
    while (curr->next)
    {
        before_curr = curr;
        curr = curr->next;
    }
    void *data = curr->data;
    free(curr);
    if (before_curr)
    {
        before_curr->next = NULL;
    }
    else
    {
        *head = NULL;
    }
    return data;
}