#include <stdio.h>

int nod(int a, int b)
{
    while ((a != 0) && (b != 0))
    {
        if (a > b)
            a %= b;
        else
            b %= a;
    }
    return a + b;
}

int main(void)
{
    int a, b, c;
    int rc;
    rc = scanf("%d %d", &a, &b);
    if (rc != 2)
    {
        printf("input error");
        return 1;
    }
    else if ((a <= 0) || (b <= 0))
    {
        printf("the input must be positive");
        return 2;
    }
    else
    {
        c = nod(a, b);
        printf("%d", c);
    }
        
    return 0;
}
