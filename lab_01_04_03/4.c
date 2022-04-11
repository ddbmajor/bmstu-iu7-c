#include <stdio.h>
#include <math.h>

int main(void)
{
	int chislo;
	int proizv = 1;
	scanf("%d", &chislo);
	chislo = fabs(chislo);
	while (chislo > 0)
	{
		proizv *= chislo % 10;
		chislo /= 10;
	}
	printf("%d", proizv);
	return 0;
}