// sk³adniki.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
using namespace std;
long long mycount=0;
struct listelement
{
	listelement* prtnode;
	int value;
	int sum;
	int * test;
	bool isprt;
};

listelement* createnode(listelement * prt, int sum, int value, bool isprt)
{
	listelement* e=new listelement();
	e->sum = sum;
	e->value = value;
	e->prtnode = prt;
	e->isprt = isprt;
	return e;
}
void wypisz(listelement* node)
{
	if (node->isprt)
	{
		cout << endl;
		return;
	}
		cout << node->value<<" ";
		wypisz(node->prtnode);
}
void rozbij(listelement* node)
{
	if (node->sum < 0)
	return;
	if (node->sum == 0)
	{
		wypisz(node);
		mycount++;
		return;
	}
	for (int i = 1; i <= node->value && i<=node->sum; i++)
	{
		rozbij(createnode(node, node->sum - i, i,false));
	}
}

int main()
{
	int n;
	cin >> n;
	rozbij(createnode(NULL, n, n,true));
	cout << mycount;
    return 0;
}

