// prostewybieranie.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
struct node {
	node* next;
	int key;
};
void Sort(node *&f)
{
	node*wart = new node;
	wart->next = f;
	node *p = NULL;
	while (wart->next != NULL)
	{
		node *q = GiveMax(wart);
		q->next = p;
		p = q;
	}
	f = p;
}
node* GiveMax(node*f) {
	node* max = f;
	while (f->next != NULL)
	{
		if (f->next->key > max->next->key)
		{
			max = f;
		}
	}
	if (max == f) return NULL;
		node*p = max->next;
		max->next=p->next;
		return p;
	 
}

int main()
{

    return 0;
}

