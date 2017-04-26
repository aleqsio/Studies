// prostewstawianie.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
struct node {
	int w;
	node* next;
};
void WstawDoPosortowanego(node* f, node* p)
{
	while (f->next != NULL && f->next->w<p->w)
	{
		f = f->next;
	}
	p->next = f->next;
	f->next = p;
}
void Sort(node *&f)
{
	node *g = new node();
	while (f != NULL)
	{
		node * p = f;
		WstawDoPosortowanego(g, p);
		f = f->next;
	}
	f = g->next;
	delete g;
}
int main()
{
    return 0;
}

