// usuwanie_listy.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
/*
Wartownik
Node**
!!Xorowana lista dwukierunkowa 
odwracanie listy
*/
struct node {
	node* next;
	int val;
};
node * rev(node * head)
{
	node * head2=NULL;
	while (head != NULL)
	{
		node * next = head->next;
		head->next = head2;
		head2 = head;
		head = next;
	}
	return head2;
}
int main()
{
    return 0;
}

