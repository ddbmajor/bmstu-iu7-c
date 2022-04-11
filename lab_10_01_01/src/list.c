#include "list.h"


node_t *reverse(node_t *head)
{
    node_t *a = head, *b = NULL, *c;
    while (a)
    {
        c = b;
        b = a;
        a = a->next;
        b->next = c;
    }
    return b;
}


void list_apply(node_t *head, void (*f)(node_t *node, void *), void *arg)
{
    for (; head; head = head->next)
    {
        f(head, arg);
    }
}


void list_count(node_t *node, void *arg)
{
    if (node)
    {
        int *counter = arg;
        (*counter)++;
    }
}


void delete_list(node_t *head, void del_data(void *))
{
    node_t *next;

    for (; head; head = next)
    {
        next = head->next;
        delete_node(head, del_data);
    }
}


node_t *list_append(node_t *head, node_t *node)
{
    node_t *curr = head;

    if (!head)
    {
        return node;
    }

    for (; curr->next; curr = curr->next);
    curr->next = node;

    return head;
}