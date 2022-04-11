#include <stdio.h>

/*
Псевдоскалярное произведение позволяет определить в какую сторону будет
происходить поворот радус-вектора точки к прямой
*/
int proizv(int x1, int y1, int x2, int y2)
{
    return (x1 * y2 - x2 * y1);
}

int main(void)
{
    int xq, yq;
    int xr, yr;
    int xp, yp;
    int rc;
    
    rc = scanf("%d %d", &xq, &yq);
    if (rc != 2)
    {
        printf("input error");
        return 1;
    }
    
    rc = scanf("%d %d", &xr, &yr);
    if (rc != 2)
    {
        printf("input error");
        return 2;
    }
    
    rc = scanf("%d %d", &xp, &yp);
    if (rc != 2)
    {
        printf("input error");
        return 3;
    }
    
    /*
    проверка на совпадение точек
    */
    if (((xq == xr) && (yq == yr)) || ((xq == xp) && (yq == yp)) || ((xr == xp) && (yr == yp)))
    {
        printf("points coincide");
        return 4;
    }
    
    if (xr - xq >= 0)
    {
        if (proizv(xr - xq, yr - yq, xp - xq, yp - yq) > 0)
            printf("0");
        else if (proizv(xr - xq, yr - yq, xp - xq, yp - yq) == 0)
            printf("1");
        else
            printf("2");
    }
    else if (xr - xq < 0)
    {
        if (proizv(xr - xq, yr - yq, xp - xq, yp - yq) > 0)
            printf("2");
        else if (proizv(xr - xq, yr - yq, xp - xq, yp - yq) == 0)
            printf("1");
        else
            printf("0");
    }
    else
    {
        printf("line is veryical");
        return 5;
    }
    return 0;    
}