// heapify.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include<stdlib.h>
#include <time.h>
struct arr {
	int length;
	int heapsize;
	int *t;
};
arr* genrandom()
{
	srand(time(0));
	arr*a = new arr();
	a->length = 1000;
	a->heapsize = 0;
	a->t = new int[a->length];
	for (int i = 0; i < a->length; i++)
	{
		a->t[i] = rand() % 1000;
	}
	return a;
}
void maxheapify(arr* a,int pos)
{

}
void buildmaxheap(arr* a)
{
	a->heapsize = a->length;
	for (int i = a->length/2; i <= 1; i--)
	{
		maxheapify(a, i);
	}
}
int main()
{
	arr* a = genrandom();
	buildmaxheap(a);
    return 0;
}

