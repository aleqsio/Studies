// cwiczenia_wdi_3.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
using namespace std;
#include <iostream>
//za tydzien kartkówka, tablice globalne dwuwymiarowe
//scal dwa posortowane niemalej¹co ³añcuchy w jeden
//mamy implementacje zbiorów w postaci uporz¹dkowanego zbioru, mamy aimplementowaæ operacje sumy i iloczynu
//wynulluj p1,p2
//funkcja ktora rozdziela elementy lancucha wejsciowego na 10 lancuchow
//w drugim kroku powsta³e ³añcuchy nale¿y po³¹czyæ w jeden ³añcuch posortowany niemalej¹co wed³ug ostatniej cyfry
// nowy + <3
//HOMEWORK
/*
mamy tablice dwu wymiarow¹ true false
i jakby ka¿dy element wskazuje na kolejny element true po prawej i na dole
mamy tablicê u góry i po lewej do pierwszego w wierszu/kolumnie
na koñcu do NULLA
*/
struct node
{
	node * next;
	int value;
};
void wstaw(node* &chain, node * node)
{
	if (chain != NULL)
	{
		if (node != NULL)
		{
			node->next = chain;
			chain = node;
		}
	}
	else
		chain = node;
}
node * separate(node * &p)
{
	node *tab[10][2];
	for (int i = 0; i < 20; i++)
		tab[i / 10][i % 2] = 0;
	node* q;
	while (p != NULL)
	{
		q = p->next;
		//insert(tab[p->value%10][0],tab[p->value%10][1],p) to ma byæ ten mój insert
		p = w;
	}

}
node * scal(node* &p1, node* &p2)
{
	node*pn = new node;
	pn->value = -5;
	node*tn=pn;
	while (p1 != NULL && p2 != NULL)
	{
		if (p1->value > p2->value)
		{
			tn->next = p2;
			p2 = p2->next;
		}
		else
		{
			tn->next = p1;
			p1=p1->next;
		}
		tn = tn->next;
	}
	wstaw(tn, p1);
	wstaw(tn, p2);
	return pn->next;
}
int main()
{
	node *p2 = NULL;
	node *p1 = NULL;
	for (int i = 1; i < 100; i=i+2)
	{
		node * mynode = new node();
		mynode->value = 100-i;
		node * mynode2 = new node();
		mynode2->value = 99 - i;
		wstaw(p2, mynode);
		wstaw(p1, mynode2);
	}
	node* pn = scal(p1, p2);
	while (pn != NULL)
	{
		cout << pn->value << endl;
		pn = pn->next;
	}
    return 0;
}
