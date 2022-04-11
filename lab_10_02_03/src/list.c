#include "list.h"


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
