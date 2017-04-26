// quicksort.cpp : Defines the entry point for the console application.
//
/*
ZBIORNIKI
s¹ zbiorniki 
silos o wysokoœci h o podstawie 1m^2
zbiorniki pzybite do œciany
i rurki z do³u poziomo do boku
struct zbiornik{
double w1,w2; wysokoœæ góry i dólu 
}
wlewamy l m^3 wody
ile zbiorników bêdzie zape³niony
*/
#include "stdafx.h"
struct node
{
	node* next;
	int val;
};
struct lista {
	node* first=NULL;
	node* last=NULL;
};
node* get(lista* lst)
{
	node*t = lst->first;
		lst->first = t->next;
		return t;
}
void quickersort(lista* lst)
{
	if (lst->first != NULL && lst->first == lst->last);

	lista l1, l2, l3;
	int x = lst->first->val;
	/*
	Wypinamy pierwszy element z listy, wpinamy do 1 lub drugiej listy w zale¿noœci od stosunku do pivota	
	*/
	quickersort(l1);
	quickersort(l2);
	lst = concatenate(l1, l2);
	return;
}
void swap(int &a, int &b)
{
	int tmp = a;
	a = b;
	b = tmp;
}
int part2(int A[], int p, int q)
{
	int x = A[q];
	int b = p;
	for (int a = p; a < q; a++)
	{
		if (A[a] < x)
		{
			swap(A[a], A[b]);
			b++;
		}
	}
	swap(A[q], A[b]);
	return b;
}
void qs2(int A[], int p, int q)
{
	if (p < q)
	{
		int piv = part2(A, p, q);
		qs2(A, p, piv - 1);
		qs2(A, piv + 1, q);
	}
}
void quicksort(int tab[], int l, int p)
{
	int i = l;
	int j = p;
	int x = tab[(l + p) / 2];
	while (i <= j)
	{
		while (tab[i] < x) i++;
		while (tab[i] > x)j--;
		if (i <= j)
		{
			swap(tab[i], tab[j]);
			i++;
			j--;
		}
		if (l < j)
		{
			quicksort(tab, l, j);
		}
		if (i > p)
		{
			quicksort(tab, i, p);
		}
	}
}
void QS(int A[], int p, int r)
{
	if (p < r) {
		int q = partition(A,p, r);
		QS(A, p, q - 1);
		QS(A, q + 1, r);
	}
}
int partition(int A[],int p,int r)
{
	int x = A[r];
	int i = p-1;
	for (int j = p; j < r; j++)
	{
		if (A[j] <= x)
			i++;
		swap(A[i], A[j]);
	}
	swap(A[i + 1], A[r]);
	while (i < p)
	{

	}
}
int main()
{
    return 0;
}

