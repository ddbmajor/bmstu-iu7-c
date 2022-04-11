#include <stdio.h>
#include <math.h>

#define PI 3.14159265

int main(void)
{
	double a, b;
	double angle;
	scanf("%lf%lf%lf", &a, &b, &angle);
	angle = angle * PI / 180.0;
	double area = a * b * sin(angle) / 2.0;
	printf("%lf", area);
	return 0;
}