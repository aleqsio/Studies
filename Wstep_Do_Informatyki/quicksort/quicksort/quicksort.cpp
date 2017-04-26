using namespace std;
#include "stdafx.h"
#include <stdio.h>
#include <iostream>
#include <cmath>
#include <cstdlib>
#include <time.h>
int partition(int t[], int p, int k)
{
	int pivot = t[p];
	int i, j, tmp;
	i = p;
	j = k;
	while (true)
	{
		while (t[i] < pivot)
		{
			i++;
			
		}
		while (t[j] > pivot)
		{
			j--;
	
		}
		if (i < j)
		{
			tmp = t[i];
			t[i] = t[j];
			t[j] = tmp;
			i++;
			j--;
		}else
		{
			return j;
		}
		
	}
}
void quicksort(int t[], int p, int k)
{
	int q = partition(t, p, k);
	//cout << endl << "q: " << q;

	if (p < k)
	{
		quicksort(t, p, q);
		quicksort(t, q + 1, k);
	}
	

}
int main()
{
	srand(time(0));
	const int size = 10000;
	int t[size];
	for (int i = 0; i<size; i++)
	{
		t[i] = 0 + rand() % 100;
	}
	quicksort(t, 0, size - 1);
	for (int i = 0; i<size; i++)
	{
		cout << t[i] << " ";
	}
}