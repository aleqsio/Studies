// cwiczenia_kurdziel_2.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
using namespace std;
#include <stdlib.h>
#include <string>
const int maxh = 64;
struct SLNode {
	string key;
	int val;
	SLNode** next;
};
struct SkipList {
	SLNode* first, last;
	int height;
};
struct mdata {
	string key;
	int val;
};
mdata Htab[N];
const int N = 65535;

int h(string s)
{
	return 0;
}
bool find(string key, int* result)
{
	int licznik = 0;
	int index = h(key);
	while (Htab[index] != key && Htab[index] != "" && licznik < N)
	{
		index = (index + 1) % N;
		if (key == Htab[index].key)
		{

		}
	}

}
SLNode* Search(SkipList *s, int key)
{
	SLNode*q = s->first;
	for (int i = s->height - 1; i > 0; i--)
	{
		while (q->next[i]->key < key)
			q = q->next[i];
		if (q->key == key) return q;
	}
}
int max(int x, int y)
{
	return x < y ? y : x;
}
int rand()
{
	return 0;
}
int randh()
{
	int H = 1;
	while (rand() % 2)
	{
		H++;
	}
}

int insert(SkipList*s, int key)
{
	//zak³adamy ¿e wstawiane klucze s¹ unikalne
	SLNode** update = new SLNode*[maxh];
	SLNode*q = s->first;
	int h = -1;
	for (int level = s->height - 1; level >= 0; level--)
	{
		while (q->next[level]->key < key)
			q = q->next[level];
		if (q->key == key)
		{
			update[level] = q;
			h = max(h, level+1);
		}
	}
	q = update[0]->next[0];
	int v = q->val;
	for (int level = 0; level < h; level++)
	{
		update[level]->next[level] = update[level]->next[level];
	}
	delete[] q->next;
	delete q;
	delete[] update;
	return v;
}
SLNode* insert(SkipList*s,int key,int val)
{
	//zak³adamy ¿e wstawiane klucze s¹ unikalne
	SLNode** update = new (SLNode*)[maxh];
	SLNode*q = s->first;
	SLNode*p = new SLNode;
	p->key = key;
	p->val = val;
	int pHeight = randh();
	p->next = new (SLNode*)[pHeight];
	int h = max(pHeight, s->height);
	for (int level=h-1; level >= 0; level--)
	{
		while (q->next[level]->key < key)
			q = q->next[key];
		if (level < pHeight)
			update[level] = q;
	}
	for (int level = 0; level < pHeight; level++)
	{
		p->next[level]=update[level]->next[level];
		update[level]->next[level] = p;
	}
	if (s->height < pHeight)
	{
		s->height = pHeight;
	}
	delete[] update;
	return p;
}
int main()
{
    return 0;
}

