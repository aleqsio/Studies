#define _XOPEN_SOURCE

#include <stdlib.h>
#include <stdio.h>

void genrand(double* arr, int size)
{
	srand(time(0));
	for (int i = 0; i < size; i++)
		arr[i] = 55 + drand48() * 57;
}

void printarr(double *arr, int size)
{
	for (int i = 0; i < size; i++)
	{
		printf("%f ", arr[i]);
	}
	printf("\n");
}
int main(void)
{
	int size;
	scanf("%d", &size);
	double*arr = malloc(sizeof(double)*size);
	genrand(arr, size);
	double*t2 = malloc(sizeof(double)*(size + 1) / 2);
	for (int i = 0; i < size - 1; i = i + 2)
	{
		t2[i / 2] = (arr[i] + arr[i + 1]) / 2;
	}
	if (size % 2 == 1)
	{
		t2[(size + 1) / 2 - 1] = arr[size - 1];
	}
	printarr(arr, size);
	printarr(t2, (size + 1) / 2);
	return 0;
}

