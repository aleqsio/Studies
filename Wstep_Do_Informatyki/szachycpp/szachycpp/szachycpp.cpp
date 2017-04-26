// szachycpp.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#include <iostream>
using namespace std;
int n;
int t[10][10];
int getsum(int, int, int, int);
int main()
{
	cin >> n;
	int max = -1000;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cin >> t[j][i];
		}
	}
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			for (int i2 = i; i2 < n; i2++)
			{
				for (int j2 = j; j2 < n; j2++)
				{
					int g = getsum(i, j, i2, j2);
					if (g > max)
					{
						max = g;
					}
				}
			}
		}
	}
	cout << max;
	return 0;
}
int getsum(int x1, int y1, int x2, int y2)
{
	if (x1 == x2 && y1 == y2)
	{
		return -1000;
	}
	int s = 0;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if ((i == x1 || i == x2) || (j == y1 || j == y2))
				if (!((i == x1&&j == y1) || (i == x2&&j == y2)))
				{
					s += t[i][j];
				}

		}
	}
	return s;
}

