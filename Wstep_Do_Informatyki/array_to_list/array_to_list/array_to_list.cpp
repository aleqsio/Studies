// array_to_list.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <time.h>
using namespace std;

struct node
{
	node * nexty=NULL;
	node * nextx=NULL;
	int x, y;
	node(int px, int py)
	{
		x = px;
		y = py;
	} 
};
void followchain(node *p,bool vert)
{
	if (p == NULL)
		return;
	cout << p->x << " " << p->y << endl;
	if (!vert)
		return followchain(p->nextx, true);
	return followchain(p->nexty, false);
}
void fillrandom(int **arr, int n)
{
	srand(time(0));
	for (int i = 0; i < n*n; i++)
		arr[i%n][i / n] = (rand() % 5) / 4;
}
int main()
{
	int n;
	cin >> n;
	int **arr = new int *[n];
	for (int i = 0; i < n; i++)
	{
		arr[i] = new int[n];
	}
	fillrandom(arr, n);
	node **x=new node*[n];
	node **y=new node*[n];
	for (int i = 0; i < n; i++)
	{
		x[i] = y[i] = NULL;
	}
	for (int i = 0; i < n; i++)//x loop
	{
		for (int j = 0; j < n; j++)//y loop
		{
			if (arr[i][j] == true)
				continue;
			node * a = new node(i, j);
			if (x[i] == NULL)
				x[i] = a;
			else
				x[i]->nextx = a;
			if (y[j] == NULL)
				y[j] = a;
			else
				y[j]->nexty = a;
		}
	}
	cout << "X:" << endl;
	for (int i = 0; i < n; i++)
	{
		followchain(x[i], false);
	}
	cout << "Y:" << endl;
	for (int i = 0; i < n; i++)
	{
		followchain(y[i], true);
	}
    return 0;
}

