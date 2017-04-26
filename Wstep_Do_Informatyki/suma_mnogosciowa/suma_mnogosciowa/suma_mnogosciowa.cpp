// suma_mnogosciowa.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
using namespace std;
struct node {
	int val=0;
	node * next=NULL;
};
void addaelements(node * wart,bool sorted, int count)
{
	int scale=100;
	if (sorted)
	{
		scale = 10;
	}
	int last = 0;
	for (int i = 0; i < count; i++)
	{
		node * n = new node;
		n->val =last + rand() % scale;
		if (sorted)
			last = n->val;
		wart->next = n;
		wart = wart->next;
	}
}
void insert(node * wart, node * obj)
{
	node * ghost = wart;
	while (wart != NULL && wart->val < obj->val)
	{
		ghost = wart;
		wart = wart->next;
	}
	ghost->next = obj;
	obj->next = wart;
}
int main()
{
	node * w1 = new node;
	node * w2 = new node;
	addaelements(w1, true, 100);
	addaelements(w2, false, 100);
	node * w2pnt = w2;
	while (w2pnt != NULL)
	{
		node * el = w2pnt;
		w2pnt = w2pnt->next;
		el->next = NULL;
		insert(w1, el);
	}
    return 0;
}

