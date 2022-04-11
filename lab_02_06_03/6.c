#include <stdio.h>
#include <stdlib.h>
#include <inttypes.h>
#include <sys/time.h>

int process_1(int a[], int n)
{
	int min = a[0] * a[1];
	int curr;
	for (int i = 1; i < n - 1; i++)
	{
		curr = a[i] * a[i + 1];
		if (curr < min)
			min = curr;
	}
	return min;
}

int process_2(int *a, int n)
{
	int min = *(a) * *(a + 1);
	int curr;
	for (int i = 1; i < n - 1; i++)
	{
		curr = *(a + i) * *(a + i + 1);
		if (curr < min)
			min = curr;
	}
	return min;
}

int process_3(int *pb, int *pe)
{
	int min;
	int *pa = pb;
	int curr;
	min = (*pb) * *(pb + 1);
	while (pa < pe - 1)
	{
		curr = *(pa) * *(pa + 1);
		if (curr < min)
			min = curr;
		pa++;
	}
	return min;
}

void copyarr(const int *old, int *new, int n)
{
	for (int i = 0; i < n; i++)
	{
		new[i] = old[i];
	}
}

int main(void)
{
	int amount;
	int n;
	int64_t sum;
	struct timeval tv_start, tv_stop;
	
	
	scanf("%d%d", &n, &amount);
	
	int o[amount], a[amount];
	
	for (int i = 0; i < amount; i++)
		o[i] = rand() % 151 - 50;
	
	
	sum = 0;
	for (int i = 0; i < n; i++)
	{
		copyarr(o, a, amount);
		gettimeofday(&tv_start, NULL);
		process_1(a, amount);
		gettimeofday(&tv_stop, NULL);
		sum += (tv_stop.tv_sec - tv_start.tv_sec) * 1000000LL + (tv_stop.tv_usec - tv_start.tv_usec);
	}
	sum /= n;
	printf("process_1 time: %" PRId64 "\n", sum);
	
	sum = 0;
	for (int i = 0; i < n; i++)
	{
		copyarr(o, a, amount);
		gettimeofday(&tv_start, NULL);
		process_2(a, amount);
		gettimeofday(&tv_stop, NULL);
		sum += (tv_stop.tv_sec - tv_start.tv_sec) * 1000000LL + (tv_stop.tv_usec - tv_start.tv_usec);
	}
	sum /= n;
	printf("process_2 time: %" PRId64 "\n", sum);
	
	sum = 0;
	for (int i = 0; i < n; i++)
	{
		copyarr(o, a, amount);
		int *pb = a;
		int *pe = pb + amount;
		gettimeofday(&tv_start, NULL);
		process_3(pb, pe);
		gettimeofday(&tv_stop, NULL);
		sum += (tv_stop.tv_sec - tv_start.tv_sec) * 1000000LL + (tv_stop.tv_usec - tv_start.tv_usec);
	}
	sum /= n;
	printf("process_3 time: %" PRId64 "\n", sum);
	
	return 0;
}