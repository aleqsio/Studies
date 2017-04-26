// sort.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <time.h>
using namespace std;
int main()
{
	const int size = 5000;
	srand(time(0));
	int t[size];
	for (int i = 0; i < size; i++)
	{
		t[i] = rand() % 1000;
	}
	int l_ind=0;
	int tmp;
	for (int i = 0; i < size-1; i++)
	{
		for (int j = i+1; j < size; j++)
		{
			l_ind = i;
			if (t[j] < t[l_ind])
			{
				l_ind = j;
			}
			tmp = t[l_ind];
			t[l_ind] = t[i];
			t[i] = tmp;
		}
		cout << t[i]<<" ";
	}
    return 0;
}

