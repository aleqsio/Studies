// heap_bit.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
using namespace std;
//implementacja na tablicy
//A|BB|CCCC|DDDDDDDD //odpowiednie poziomy drzewa
//reapify

void swap(int &a, int &b)
{
	int tmp = a;
	a = b;
	b = tmp;
}
void heapify(int t[], int n, int i)
{
	
	int top = i;
	int left = 2*i + 1;
	int right = 2 * i + 2;
	if (left < n)
	{
		if (t[top] < t[left])
		{
			top = left;
			if (right < n)
			{
				if (t[top] < t[right]) top = right;
			}
			if (top != i) { swap(t[i], t[top]); }
			heapify(t, n, top);
		}
	}
}
int main()
{
	auto a = [](int a, int b) {return a + b; };
	cout << a(1, 2);
	
    return 0;
}

