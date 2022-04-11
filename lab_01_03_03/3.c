#include <stdio.h>

int main(void)
{
	double v0, a, t, s;
	scanf("%lf", &v0);
	scanf("%lf", &a);
	scanf("%lf", &t);
	s = v0 * t + a * t * t / 2.0;
	printf("%lf", s);
	return 0;
}