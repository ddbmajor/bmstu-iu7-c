#include <stdio.h>
#include <math.h>

void dectobinprint(unsigned int a, int i)
{
    if (i == 32)
        return;
    dectobinprint(a / 2, i + 1);
    printf("%u", a % 2);
}

unsigned int syphering(unsigned int num)
{
    unsigned int new = 0;
    int left, right;
    for (int i = 0; i < 32; i += 2)
    {
        right = num % 2;
        num /= 2;
        left = num % 2;
        num /= 2;
        new += right * pow(2, i + 1) + left * pow(2, i);
    }
    return new;
}

int main(void)
{
    unsigned int a;
    int rc;
    
    rc = scanf("%u", &a);
    if ((rc != 1) || (rc == EOF))
    {
        printf("Error: input error");
        return 1;
    }
    
    a = syphering(a);
    printf("Result: ");
    dectobinprint(a, 0);

    return 0;
}