// pointers.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <time.h>
using namespace std;
struct node {
	int val = 0;
	node * next=NULL;
};
void createsortedlist(node * &f, int remain,int val)
{
	if (remain <= 0)
		return;
	f = new node;
	f->val = val;
	cout << val << " ";
	createsortedlist(f->next, remain - 1,val +1+rand()%10);
}
void insert(node * source, node * obj)
{
	node * prev_src=source;
	while (source != NULL && source->val < obj->val)
	{
		prev_src = source;
		source = source->next;
	}
	
	obj->next = source;
		prev_src->next = obj;
		return;

}
void createunsortedlist(node * &f, int remain)
{
	if (remain <= 0)
		return;
	f = new node;
	f->val = rand() % 100;
	cout << f->val << " ";
	createunsortedlist(f->next, remain - 1);
}
void out(node *n)
{
	n = n->next;
	while (n != NULL)
	{
		cout << n->val << " ";
		n = n->next;
	}
}

node * xor(node * e1, node * e2)
{
	node * b = new node;
	while (e1 != NULL || e2 != NULL)
	{
		if ((e1 != NULL && e2 != NULL) && e1->val == e2->val)
		{
			e1 = e1->next;
			e2 = e2->next;
		}
		else if (e1 == NULL || e1->val > e2->val)
		{
			node * t = e2;
			e2 = e2->next;
			t->next = b->next;
			b->next = t;
		}
		else
		{
			node * t = e1;
			e1 = e1->next;
			t->next = b->next;
			b->next = t;
		}
	}

	return b;
}
int main()
{
	srand(time(0));
	node * first_el1,* first_el2;
	cout << "chain1 sorted:" << " ";
	createsortedlist(first_el1, 100,0);

	cout <<endl<< "chain2 unsorted:" << " ";
	createunsortedlist(first_el2, 100);
	cout << endl << "xorchain:";
	while (first_el2 != NULL)
	{
		insert(first_el1, first_el2);
		first_el2 = first_el2->next;
	}
	out(first_el1);
	
    return 0;
}

