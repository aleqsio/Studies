// mergesortlisty.cpp : Defines the entry point for the console application.


#include "stdafx.h"
struct node {
	node* next = NULL;
	int val;
};
node* merge(node *a1, node *a2)
{
	if (a1 == NULL)
		return a2;
	else if (a2 == NULL)
		return a1;
	if (a1->val > a2->val)
	{
		a1->next = merge(a1->next, a2);
		return a1;
	}
	else
	{
		a1->next = merge(a1, a2->next);
		return a2;
	}
}
int main()
{
	return 0;
}

