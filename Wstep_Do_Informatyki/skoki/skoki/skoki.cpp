// skoki.cpp : Defines the entry point for the console application.
//
#include "stdafx.h"
#include <iostream>
#include <time.h>
using namespace std;
const int mysize = 20;
int t[mysize][mysize];
bool search(int x, int y, int val);
int main()
{

	srand(time(0));
	for (int i = 0; i < mysize; i++)
	{
		for (int j = 0; j < mysize; j++)
		{
			t[j][i] = j+i;
			cout << t[j][i]<<" ";
		}
		cout << endl;
	}

	cout << endl<<endl;
	search(0, 0, INT_MIN);
    return 0;
}
bool search(int x, int y, int val)
{
	if (val > t[x][y])
	{
		return false;
	}
	if (x + y == mysize*2 - 2)
	{
		return true;
	}
	bool fl = false;
	if (x < mysize)
		fl=search(x + 1, y, t[x][y]);
	if (y < mysize && !fl)
		fl = search(x, y+1, t[x][y]);
	if (fl)
	{
		cout << x << " " << y << endl;
		return true;
	}
	return false;
}

