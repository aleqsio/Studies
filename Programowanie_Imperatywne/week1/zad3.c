#define _XOPEN_SOURCE
#define N1 8
#define N2 10
#define _min(x,y) x<y ? x : y
#include <stdlib.h>
#include <stdio.h>

void genrand(int* arr, int size)
{
	srand(time(0));
	for (int i = 0; i < size; i++)
		arr[i] = 1 + rand() % 10;
}

void printarr(int *arr, int size)
{
	for (int i = 0; i < size; i++)
	{
		printf("%d ", arr[i]);
	}
	printf("\n");
}
void print(int* a1, int*a2)
{
	printf("array #1:\n");
	printarr(a1, N1);
	printf("array #2:\n");
	printarr(a2, N2);
}

void zamiana(int*arr, int p, int q)
{
	int tmp = arr[q];
	arr[q] = arr[p];
	arr[p] = tmp;
}
void odwroc(int*arr, int size)
{
	for (int i = 0; i < size / 2; i++)
	{
		zamiana(arr, i, size - 1 - i);
	}
}
void wymien_tablice(int *a1, int*a2, int s1, int s2)
{
	int k = _min(s1, s2);
	for (int i = 0; i < k; i++)
	{
		int tmp = a1[i];
		a1[i] = a2[i];
		a2[i] = tmp;
	}
}
int partition(int*arr, int p, int q)
{
	int piv = arr[q];
	int b = p;
	for (int i = p; i < q; i++)
	{
		if (arr[i] < piv)
		{
			zamiana(arr, b, i);
			b++;
		}
	}
	zamiana(arr, b, q);
	return b;
}
int one_two(int*a1, int*a2, int **res)
{
	int*r = *(res);
	int p, q;
	p = 0;
	q = 0;
	int len = 0;
	while (p + q < N1 + N2)
	{
		if (p < N1 && q<N2)
		{
			if (a1[p] < a2[q])
			{
				len++;
				(r)[len - 1] = a1[p];
				p++;
			}
			if (a1[p] > a2[q])
			{
				len++;
				(r)[len - 1] = a2[q];
				q++;
			}
			if (a1[p] == a2[q])
			{
				len++;
				(r)[len - 1] = a1[p];
				p++;
				q++;
			}
		}
		else if (p < N1)
		{
			len++;
			(r)[len - 1] = a1[p];
			p++;
		}
		else
		{
			len++;
			(r)[len - 1] = a2[q];
			q++;
		}
	}
	int size = 1;
	int* arr = malloc(sizeof(int)*len);
	arr[0] = r[0];
	for (int i = 1; i < len; i++)
	{
		if (r[i - 1] != r[i])
		{
			arr[size] = r[i];
			size++;
		}
	}
	free(r);
	*res = arr;

	return size;
}
void quicksort(int*arr, int p, int q)
{
	if (q <= p) return;
	int piv = partition(arr, p, q);
	quicksort(arr, p, piv - 1);
	quicksort(arr, piv + 1, q);
}
int main(void)
{
	printf("randomowe\n");
	int*a1 = malloc(sizeof(int)*N1);
	genrand(a1, N1);
	int*a2 = malloc(sizeof(int)*N2);
	genrand(a2, N2);
	printf("zamiana #1 1<->2\n");
	print(a1, a2);
	zamiana(a1, 1, 2);
	print(a1, a2);
	printf("odwróæ #1\n");
	odwroc(a1, N1);
	print(a1, a2);
	printf("wymien tablice\n");
	wymien_tablice(a1, a2, N1, N2);
	print(a1, a2);
	printf("quicksort\n");
	quicksort(a1, 0, N1 - 1);
	quicksort(a2, 0, N2 - 1);
	print(a1, a2);
	printf("scalanie:\n");
	int*arr = malloc(sizeof(int)*(N1 + N2));
	int**res = &arr;
	int l = one_two(a1, a2, res);
	printarr(arr, l);
	return 0;
}

