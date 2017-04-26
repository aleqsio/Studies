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
	int tmp;
	for (int i = 0; i < size; i++)
	{
		t[i] = rand() % 1000;
	}
	for (int i = 1; i < size; i++)
	{
		int tmp = t[i];
		int j = i - 1;
		while (j >= 0 && t[j] > tmp)
		{
			t[j + 1] = t[j];
			j--;
		}
		t[j + 1] = tmp;
	}
	for (int i = 0; i < size; i++)
	{
		cout << t[i] << " ";
	}
	return 0;
}

