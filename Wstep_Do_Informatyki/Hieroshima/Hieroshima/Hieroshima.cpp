// Hieroshima.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <time.h>
using namespace std;
const int mysize = 100;
int map[mysize][mysize];

void wyspy(int x, int y,int penalty)
{
	if (!(x >= 0 && x < mysize && y >= 0 && y < mysize))
		return;
	if (map[x][y] == true || penalty>40)
		return;
	map[x][y] = true;
	wyspy(x + 1, y,penalty+rand()%5);
	wyspy(x , y+1, penalty + rand() % 10);
	wyspy(x  -1, y, penalty + rand() % 10);
	wyspy(x, y-1, penalty + rand() % 10);
	return;
}
int utop(int x, int y)
{
	if (!(x >= 0 && x < mysize && y >= 0 && y < mysize))
		return 0;
	if (map[x][y] == false)
		return 0;
	int s = 1;
	map[x][y] = false;
	s += utop(x + 1, y);
	s += utop(x, y + 1);
	s += utop(x - 1, y);
	s += utop(x, y - 1);
	return s;
}
void wyp(bool set)
{
	for (int i = 0; i < mysize; i++)
	{
		for (int j = 0; j < mysize; j++)
		{
			if (set)
			{
				map[i][j] = false;
			}
			else
			{
				cout << map[i][j];
			}
		}
		if (!set)
		{
			cout << endl;
		}
	}
}
int main()
{
	srand(time(0));
	wyp(true);
	for (int i = 0; i < 4; i++)
	{

		wyspy(rand()%100, rand()%100, rand()%40-80);
	}
	wyp(false);
    return 0;
}

