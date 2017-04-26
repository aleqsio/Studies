// lancuch.cpp : Defines the entry point for the console application.
/*
jest lancuch zakonczony cyklem. napisz funkcje ktora zwraca d³ugoœæ cyklu. wiadomo ze l. elementów nie przekracza 100.
nie wiadomo ile jest elementów - dwa wskazniki, jeden krok, drugi 2 kroki.

startuj¹ dwa wskazniki, jeden idzie 2x szybciej a¿ siê zrównaj¹

usuwamy elementy
*/

#include <iostream>
#include "stdafx.h"
using namespace std;
struct node {
	node * next;
	int val;
};
bool kasuj(node *, node *, int val)
{
	//kasuje kolejne wyst¹pienia tego val, 
}
void usun(node *p)
{
	if (p == NULL || p->next == NULL)	//przerywalne
		return;
	node * p,* n;
	while (n != NULL)
	{
		if (kasuj(p, n, n->val))
		{

		}
	}
}
node * start(node *p)
{
	node * x1 = p;
	node * x2 = p->next;
	while (x1 != x2)
	{
		x1 = x1->next;
		x2 = x2->next->next;
	}
	return x1;
}
int count(node *g)
{
	node * k = g;
	int len = 1;
	g = g->next;
	while (k != g)
	{
		len++;
		g = g->next;
	}
	return len;
}
int main()
{
	node * g;
	count(start(g));
    return 0;
}

