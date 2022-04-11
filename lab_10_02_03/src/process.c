#include "process.h"


int out(void)
{
    int num;
    int rc;

    rc = scanf("%d", &num);
    if (rc != 1)
        return INPUT_ERROR;
    if (num <= 0)
        return NUM_ERROR;
    
    node_t *number = NULL;
    number = create_number(num);

    print_number(number);

    delete_list(number, delete_factor);
    return 0;
}


int mul(void)
{
    int num1;
    int num2;
    int rc;
    
    rc = scanf("%d\n%d", &num1, &num2);
    if (rc != 2)
        return INPUT_ERROR;
    if (num1 <= 0 || num2 <= 0)
        return NUM_ERROR;
    
    node_t *number1 = NULL, *number2 = NULL;
    number1 = create_number(num1);
    number2 = create_number(num2);

    node_t *result = NULL;
    result = multiply(number1, number2);

    delete_list(number1, delete_factor);
    delete_list(number2, delete_factor);

    print_number(result);

    delete_list(result, delete_factor);
    return 0;
}


int sqr(void)
{
    int num;
    int rc;

    rc = scanf("%d", &num);
    if (rc != 1)
        return INPUT_ERROR;
    if (num <= 0)
        return NUM_ERROR;
    
    node_t *number = NULL;
    number = create_number(num);

    number = square(number);

    print_number(number);

    delete_list(number, delete_factor);
    return 0;
}


int mydiv(void)
{
    int num1;
    int num2;
    int rc;
    
    rc = scanf("%d\n%d", &num1, &num2);
    if (rc != 2)
        return INPUT_ERROR;
    if (num1 <= 0 || num2 <= 0)
        return NUM_ERROR;
    
    node_t *number1 = NULL, *number2 = NULL;
    number1 = create_number(num1);
    number2 = create_number(num2);

    node_t *result = NULL;
    rc = division(&result, number1, number2);
    if (rc != 0)
    {
        delete_list(number1, delete_factor);
        delete_list(number2, delete_factor);
        return rc;
    }

    delete_list(number1, delete_factor);
    delete_list(number2, delete_factor);

    print_number(result);

    delete_list(result, delete_factor);
    return 0;
}