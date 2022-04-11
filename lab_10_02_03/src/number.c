#include "number.h"


static int power(int x, int p)
{
    int answer = 1;
    for (int i = 0; i < p; i++)
        answer *= x;

    return answer;
}


static int next_prime(int x)
{
    while (1)
    {
        int flag = 0;
        x++;
        for (int i = 2; i <= x; i++)
            if (x % i == 0)
                flag++;
        if (flag == 1)
            return x;
    }
}


node_t *create_number(int n)
{
    node_t *number = NULL;
    node_t *curr_node = NULL;
    factor_t *curr_factor = NULL;
    
    for (int t = 2; t <= n; t++)
    {
        int flag = 1;
        for (int i = 2; i * i <= t; i++)
        {
            if (t % i == 0)
            {
                flag = 0;
                break;
            }
        }
        if (flag)
        {
            int power = 0;
            while (n % t == 0)
            {
                power++;
                n /= t;
            }
            curr_factor = create_factor(power);
            curr_node = create_node(curr_factor);
            number = list_append(number, curr_node);
        }
    }
    return number;
}


void print_number(node_t *number)
{
    if (number == NULL)
    {
        printf("L");
        return;
    }

    node_t *curr = number;
    while (curr)
    {
        printf("%d ", ((factor_t *)(curr->data))->power);
        curr = curr->next;
    }

    printf("L");
}


node_t *multiply(node_t *a, node_t *b)
{
    node_t *res = NULL;
    node_t *curr_a = a;
    node_t *curr_b = b;

    factor_t *adding_factor;
    node_t *adding_node;

    while (curr_a && curr_b)
    {
        adding_factor = create_factor(((factor_t *)(curr_a->data))->power + ((factor_t *)(curr_b->data))->power);
        adding_node = create_node(adding_factor);
        res = list_append(res, adding_node);
        curr_a = curr_a->next;
        curr_b = curr_b->next;
    }

    while (curr_a)
    {
        adding_factor = create_factor(((factor_t *)(curr_a->data))->power);
        adding_node = create_node(adding_factor);
        res = list_append(res, adding_node);
        curr_a = curr_a->next;
    }

    while (curr_b)
    {
        adding_factor = create_factor(((factor_t *)(curr_b->data))->power);
        adding_node = create_node(adding_factor);
        res = list_append(res, adding_node);
        curr_b = curr_b->next;
    }

    return res;
}


node_t *square(node_t *number)
{
    if (number == NULL)
        return NULL;
    node_t *curr = number;
    while (curr)
    {
        ((factor_t *)(curr->data))->power *= 2;
        curr = curr->next;
    }
    return number;
}


int division(node_t **res, node_t *a, node_t *b)
{
    node_t *curr_a = a;
    node_t *curr_b = b;
    int num_a = 1, num_b = 1;
    int prime = 2;

    while (curr_a && curr_b)
    {
        if (((factor_t *)(curr_a->data))->power > ((factor_t *)(curr_b->data))->power)
        {
            ((factor_t *)(curr_a->data))->power -= ((factor_t *)(curr_b->data))->power;
            ((factor_t *)(curr_b->data))->power = 0;
        }
        else if (((factor_t *)(curr_a->data))->power < ((factor_t *)(curr_b->data))->power)
        {
            ((factor_t *)(curr_b->data))->power -= ((factor_t *)(curr_a->data))->power;
            ((factor_t *)(curr_a->data))->power = 0;
        }
        else
        {
            ((factor_t *)(curr_a->data))->power = 0;
            ((factor_t *)(curr_b->data))->power = 0;
        }

        num_a *= power(prime, ((factor_t *)(curr_a->data))->power);
        num_b *= power(prime, ((factor_t *)(curr_b->data))->power);
        prime = next_prime(prime);

        curr_a = curr_a->next;
        curr_b = curr_b->next;
    }

    while (curr_a)
    {
        num_a *= power(prime, ((factor_t *)(curr_a->data))->power);
        prime = next_prime(prime);
        curr_a = curr_a->next;
    }

    while (curr_b)
    {
        num_b *= power(prime, ((factor_t *)(curr_b->data))->power);
        prime = next_prime(prime);
        curr_b = curr_b->next;
    }

    int result = num_a / num_b;
    if (result == 0)
        return ZERO_ERROR;
    
    *res = create_number(result);
    return 0;
}