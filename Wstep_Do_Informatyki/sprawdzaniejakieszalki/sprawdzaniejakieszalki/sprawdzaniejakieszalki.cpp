#include "stdafx.h"
#include <stdio.h>
#include <iostream>
using namespace std;
bool compute(int*, int, int, int);
int counter = 0;
int main()
{
	int mincountofweights=INT_MAX;
	int* sizes=new int[20];
	int*tmp;
	int* minsizes=new int[20];
	for (int i = 0; i < 20; i++)
	{
		minsizes[i] = 0;
		sizes[i] = 0;
	}
	for (long maxmask = pow(2, 20) - 1; maxmask >= 0; maxmask--)
	{
		if (maxmask % 1000000)
		{
			cout<<" MASK:" << maxmask << " WEIGHTS:"<<mincountofweights<<" SIZES:";
			for (int i = 0; i < mincountofweights && i<20; i++)
			{
					cout << minsizes[i] << ",";
			}
		}
		int countofweights=0;
		long currmask = maxmask;
		while (currmask > 0)
		{
			if (currmask % 2 == 1)
			{
				countofweights++;
			}
			currmask /= 2;
		}
		if (maxmask % 1000000)
		{
			cout << countofweights;
			cout << endl;

		}
		if (mincountofweights <= countofweights)
		{
			continue;
		}
		currmask = maxmask;
		int pos = 0;
		int it = 1;
		while (currmask > 0)
		{
			if (currmask % 2 == 1)
			{
				sizes[pos] = it;
				pos++;
			}
			it++;
			currmask /= 2;
		}
		bool posible = true;
		for (int w = 1; w <= 20 && posible; w++)
		{
			posible = compute(sizes, countofweights, 0, w);
		}
		if (posible)
		{
			mincountofweights = countofweights;
			tmp = sizes;
			sizes = minsizes;
			minsizes=tmp;
		}
	}
	for (int i = 0; i < 20; i++)
	{
		cout<<"RESULT"<<endl << minsizes[i] << " ";
	}
}
bool compute(int* sizes, int num, int curr, int weight)
{
	if (curr>num - 1)
	{
		return false;
	}
	if (weight == 0)
	{
		return true;
	}
	if (compute(sizes, num, curr + 1, weight - sizes[curr]))
	{
		return true;
	}
	if (compute(sizes, num, curr + 1, weight + sizes[curr]))
	{
		return true;
	}
	return compute(sizes, num, curr + 1, weight);
}

