#include <stdio.h>
#include <math.h>

double func(double g, double x, int i)
{
    g = g / (x + i);
    
    return g;
}

int main(void)
{
    double g, x;
    int i = 2;
    int rc;
    
     
    rc = scanf("%lf", &x);
    if (rc != 1)
    {
        printf("input error");
        return 1;
    }
    if (x < 0)
    {
        printf("empty list");
        return 1;
    }
    
    g = 1 / (x + 1);
    while (1)
    {
        rc = scanf("%lf", &x);
        if (rc != 1)
        {
            printf("input error");
            return 1;
        }
        if (x < 0)
            break;
        g = func(g, x, i);
        i += 1;
    }
    g = exp(g);
    printf("%lf", g);
    
    return 0;
}