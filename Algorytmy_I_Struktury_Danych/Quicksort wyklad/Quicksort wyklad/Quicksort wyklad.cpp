// Quicksort wyklad.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
int select(int A[], int n, int k)
{
	if (n == 1) return A[0];
	int q = Partition(A,0, n - 1);
	if (q == k) return A[q];
	else if (q < k) return select(A, q, k);
	else return select(A + q + 1, n - q - 1, k - q - 1);
}

int betterselect_so_selectbutbetter(int A[], int n, int k)///ciekawostka teoretyczna
{
//tylko opis algorytmu

}

void QuickSort(int A[], int p, int r)
{
	while (p < r) {
		int q = Partition(A, p, r);
		QuickSort(A, p, q - 1);
		p = q + 1;///po³owa rekurencyjnie
	}
}
int Partition(int A[], int p, int r)
{
	int x = A[r];
	int i, j;
	i = p - 1;
	for (j = p; j < r; j++)
	{
		if (A[j] <= x)
		{
			i++;
			swap(A[i], A[j]);
	}
	}
	swap(A[i + 1], A[r]);
	return i + 1;
}
int main()
{
    return 0;
}

