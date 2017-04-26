// cwiczenia4(countsort+radixsort).cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <time.h>
using namespace std;
/*
zaproponuj algorytm który w czasie liniowym posortuje tablicê A zawieraj¹c¹ n liczb z zakresu [0,n^2)
kube³kowe [0,n) [n,2n) itd.

WyobraŸmy sobie ¿e mamy napisy
ró¿nej d³ugoœci
n napisów
k-suma d³ugoœci wszystkich s³ów
posortowaæ napisy w czasie O(k)

Maj¹c dwa s³owa a i b o d³ugoœci n sprawdza czy a,b s¹ anagramami nad alfabetem d³ugoœci K


*/
struct sum {
	int x;
	int y;
};
bool anagrams(char a[], char b[], int N, int K)
{
	int * characters = new int[K];
	for (int i = 0; i < N; i++)
	{
		characters[a[i]] = 0;
	}
	for (int i = 0; i < N; i++)
	{
		characters[a[i]]++;
		characters[b[i]]--;
	}
	for (int i = 0; i < K; i++)
	{
		if (0 != characters[a[i]]) return false;
	}
	return true;
}
//pewien eksperyment fizyczny generuje krótkie ci¹gi liczb ca³kowitych od 0 do 9^9
//ci¹g ró¿nej d³ugoœci elementów elementów
//pomiar polega na okreœleniu ile róznych liczb jest w ci¹gu w czasie O(n)

//tablica booli, czyœcimy po sobie

//lider ci¹gu jest w z³o¿onoœci O(n)

//wyszukiwanie sumy - dana jest posortowana tablica A[n], X
//czy istniej¹ indeksy 
sum findsum1(int a[],int s)
{
	int p = 0;
	int q = 49;
	sum str;
	while (q >= p)
	{
		if (a[p] + a[q] == s)
		{
			str.x = a[p];
			str.y = a[q];
			return str;
		}
		if (a[p] + a[q] > s)
		{
			q--;
		}
		else
		{
			p++;
		}
	}
	str.x = 0;
	str.y = 0;
	return str;
}
sum findsum2(int a[],int s)
{
	sum str;
	for (int i = 0; i < 50; i++)
	{
		for (int j = i; j < 50; j++)
		{
			if (a[i] + a[j] == s)
			{
				str.x = a[i];
				str.y = a[j];
				return str;
			}
		}
	}
	str.x = 0;
	str.y = 0;
	return str;
}
bool equal(sum s1, sum s2)
{
	return s1.x == s2.x&&s1.y == s2.y;
}
void verif()
{
	srand(time(0));
	int* a = new int[50];
	for (int i = 0; i < 10000; i++)
	{
		for (int j = 0; j < 50; j++)
		{
			a[j] = j * 30 + rand() % 20;
		}
		int s = 1000;
		sum s1 = findsum1(a, s);
		sum s2 = findsum2(a, s);
		if (!equal(s1, s2))
		{

			cout << "NO \n";
		}
		else
		{
			cout << ".";
		}

	}
	return;
}
void swap(int &p, int &r)
{
	int tmp = r;
	r = p;
	p = tmp;
}
void genrand(int* &a, int s)
{
	srand(time(0));
	a = new int[s];
	for (int i = 0; i < s; i++)
	{
		a[i] = rand() % (s * 5);
	}
}
void outstr(int* a, int s)
{
	for (int i = 0; i < s; i++)
	{
		cout << a[i] << " ";
	}
	cout << "\n";
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
struct node {
	int val;
	node* next;
};
void sort(node* &head)
{
	node* h2=new node;
	while (head != NULL)
	{
		node* el = head;
		head = head->next;

		node*t = h2;
			while (t->next != NULL && t->next->val<el->val)
			{
				t = t->next;
			}
			node *tmp = t->next;
			t->next = el;
			el->next = tmp;
	}
	head = h2->next;
}
node* getnode(int val)
{
	node* n = new node;
	n->val = val;
}
void insert(node* bucket, int val)
{
	node* tmp;
	if (bucket == NULL)
	{
		bucket = getnode(val);
	}
	else
	{
		tmp = bucket->next;
		bucket->next = getnode(val);
		bucket->next->next = tmp;
	}
}
void bort(int *A, int n)
{
	int max = 10;
	int bucketcnt = n / 2;
	node* buckets[bucketcnt];
	for (int i = 0; i < n; i++)
	{
		insert(buckets[A[i] / (max / bucketcnt)], A[i]);
	}
}

int partition(int *a, int p,int q)
{
	int pivot = a[q];
	int e = p;
	for (int i = p; i < q; i++)
	{
		if (a[i] < pivot)
		{
			swap(a[i], a[e]);
			e++;
		}
		
	}
	swap(a[e], a[q]);
	return e;
}

void quicksort(int *a, int p,int q)
{
	if ( p>=q) return;
		
	int piv = partition(a, p, q);
	quicksort(a, p, piv - 1);
	quicksort(a, piv + 1, q);
}
int main()
{
	int* a;
	int s = 100;
	genrand(a, s);
	qs2(a, 0, s - 1);
	outstr(a, s);
	return 0;
}

