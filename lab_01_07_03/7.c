#include <stdio.h>
#include <math.h>

double s(double x, double eps)
{
    double x0 = x;
    double x1;
    double sum = x;
    int k = 3;
    x1 = (-1) * x0 * x * x;
    sum += x1 / k;
    while (fabs(x1 / k) >= eps)
    {
        x0 = x1;
        k += 2;
        x1 = (-1) * x0 * x * x;
        sum += x1 / k;
    }
    return sum;
}

int main(void)
{
    double x, eps;
    double sum, f;
    double delta, phi;
    int rc;
    
    rc = scanf("%lf %lf", &x, &eps);
    if (rc != 2)
    {
        printf("input error");
        return 1;
    }
    if (fabs(x) > 1)
    {
        printf("x must be in [1;1]");
        return 2;
    }
    if ((eps <= 0) || (eps > 1))
    {
        printf("eps must be in (0;1]");
        return 3;
    }
    
    sum = s(x, eps);
    f = atan(x);
    delta = fabs(f - sum);
    if (fabs(f) < 10e-8)
        phi = 0;
    else
        phi = delta / fabs(f);
    printf("%lf\n", sum);
    printf("%lf\n", f);
    printf("%lf\n", delta);
    printf("%lf\n", phi);
    
    return 0;    
}