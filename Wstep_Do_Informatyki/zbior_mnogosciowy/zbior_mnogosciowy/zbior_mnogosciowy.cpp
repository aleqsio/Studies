// zbior_mnogosciowy.cpp : Defines the entry point for the console application.

#include "stdafx.h"
#include <iostream>
using namespace std;
struct node
{
	node * prt;
	int value;
};
bool wstawbezguardiana(node* start, int wartosc)
{
	if (/*znajdzbezguardiana(start, wartosc)*/false)
	{
		return true;
	}
	node* e = new node();
	if (e == NULL)
		return false;
	e->value = wartosc;
	e->prt = start;
	start = e;
	return true;
}
void wstaw(node* guardian, int wartosc)
{
	//wirth alg + str danch
	//mo¿e byæ ³añcuch z guardianem albo bez !tez opanuj! mo¿esz dodaæ ale pamiêtaj aby bo wyrzucic
	node* e=new node();
	e->value = wartosc;
	e->prt = guardian->prt;
	guardian->prt = e;
}

node * znajdzuporzadkowanyizwrocmozliwalokacje(node * guardian, int szukana)
{
	node * curr = guardian;
	node * prev=guardian;
	//zwraca poprzednik równego lub mniejszy
	while (curr->prt != NULL && curr->value < szukana)
	{
		prev = curr;
		curr = curr->prt;
	}
		return prev;
}

bool czyjest(node * prev, int val)
{
	if (prev->prt == NULL)
		return false;
	return prev->prt->value == val;
}
node * znajdzuporzadkowany(node * guardian, int szukana)
{
	node * curr = guardian;
	while (curr->prt != NULL && curr->value < szukana)
	{
		curr = curr->prt;
	}
	if (curr != guardian && curr->value==szukana)
		return curr;
	return NULL;
}
node * znajdz(node * guardian, int szukana)
{
	node * curr = guardian;
	while (curr->prt != NULL && curr->value != szukana)
	{
		curr = curr->prt;
	}
	if(curr!=guardian)
	return curr;
	return NULL;
}
int main()
{
	node * guardian = new node();
	guardian->value = -1;
	for (int i = 0; i < 100; i++)
	{
		wstaw(guardian, 100-i);
	}
	cout<<znajdzuporzadkowanyizwrocmozliwalokacje(guardian, 15)->value;
    return 0;
}

