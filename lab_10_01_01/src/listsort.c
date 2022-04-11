#include "listsort.h"


void front_back_split(node_t *head, node_t **back)
{
    if (head == NULL)
        return;
    int amount = 0;
    list_apply(head, list_count, &amount);
    if (amount == 0)
        return;

    int front_amount = (amount % 2) ? (amount / 2 + 1) : (amount / 2);

    node_t *curr = head;
    for (int i = 0; i < front_amount - 1; i++)
    {
        curr = curr->next;
    }
    *back = curr->next;
    curr->next = NULL;
}


node_t *sorted_merge(node_t **head_a, node_t **head_b, int (*comparator)(const void *, const void *))
{
    node_t *head_s = NULL;
    node_t *curr_a = *head_a, *curr_b = *head_b;
    node_t *tmp;
    while (curr_a && curr_b)
    {
        if (comparator(curr_a->data, curr_b->data) <= 0)
        {
            tmp = curr_a;
            curr_a = curr_a->next;
            tmp->next = NULL;
            head_s = list_append(head_s, tmp);
        }
        else
        {
            tmp = curr_b;
            curr_b = curr_b->next;
            tmp->next = NULL;
            head_s = list_append(head_s, tmp);
        }
    }
    while (curr_a)
    {
        tmp = curr_a;
        curr_a = curr_a->next;
        tmp->next = NULL;
        head_s = list_append(head_s, tmp);
    }
    while (curr_b)
    {
        tmp = curr_b;
        curr_b = curr_b->next;
        tmp->next = NULL;
        head_s = list_append(head_s, tmp);
    }

    *head_a = NULL;
    *head_b = NULL;
    return head_s;
}


node_t *sort(node_t *head, int (*comparator)(const void *, const void *))
{
    if (head == NULL || head->next == NULL)
        return head;

    node_t *sorted = NULL;
    node_t *back = NULL;

    front_back_split(head, &back);

    head = sort(head, comparator);
    back = sort(back, comparator);

    sorted = sorted_merge(&head, &back, comparator);
    return sorted;
}