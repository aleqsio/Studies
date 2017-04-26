#define _XOPEN_SOURCE
#define start 10
#define end 10000
#define base 8
#include <stdlib.h>
#include <stdio.h>

int pow(int a, int b)
{
	int res = 1;
	for (int i = 0; i < b; i++)
	{
		res *= a;
	}
	return res;
}
int isarmstrong(int b, int n)
{
	int size = 0;
	for (int tmp = n; tmp > 0; tmp /= b)	size++;
	int* a = malloc(sizeof(int)*size);
	int pos = 0;
	for (int tmp = n; tmp > 0; tmp /= b)
	{
		a[pos] = tmp%b;
		pos++;
	}
	int sum = 0;
	for (int i = 0; i < size; i++)
	{
		sum += pow(a[i], size);
	}
	free(a);
	return sum == n;
}

int main(void)
{
	for (int i = start; i <= end; i++)
	{
		if (isarmstrong(base, i))
		{
			printf("%d,", i);
		}
	}
	return 0;
}

