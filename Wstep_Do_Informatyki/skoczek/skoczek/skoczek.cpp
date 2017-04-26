// skoczek.cpp : Defines the entry point for the console application.
//
#include "stdafx.h"
#include <stdio.h>
#include <iostream>

using namespace std;
const int mysize=8;
bool skocz(void *t1, int x, int y, int step);
int main()
{
	int x, y;
	cout << "punkt:";
	cin >> x >> y;
	int t[mysize][mysize];
	for (int i = 0; i<mysize*mysize; i++)
	{
		t[i / mysize][i%mysize] = 0;
	}
	skocz(&t, x, y, 1);
	for (int i = 0; i<mysize*mysize; i++)
	{
		cout << t[i%mysize][i / mysize] << "  ";

		if (t[i%mysize][i / mysize] < 10)
			cout << " ";
		if (i%mysize == mysize - 1)
		{
			cout << endl;
		}
	}
	return 0;
}
bool skocz(void *t1, int x, int y, int step)
{

	int(*t)[mysize][mysize] = (int(*)[mysize][mysize])t1;
	(*t)[x][y] = step;
	if (step == mysize*mysize)
	{
		return true;
	}
	int x_m[8] = { -2,-2,-1,-1,1,1,2,2 };
	int y_m[8] = { -1,1,2,-2,2,-2,1,-1 };
	bool flag = false;
	for (int i = 0; i<8; i++)
	{
		if (x + x_m[i] >= 0 && x + x_m[i]<mysize && y + y_m[i] >= 0 && y + y_m[i]<mysize && (*t)[x + x_m[i]][y + y_m[i]] == 0 && !flag)
		{
			flag = skocz(t, x + x_m[i], y + y_m[i], step + 1);
		}
	}
	if (flag)
	{
		return true;
	}
	(*t)[x][y] = 0;
	return false;
}

