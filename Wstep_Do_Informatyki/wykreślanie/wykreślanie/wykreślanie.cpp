// wykreœlanie.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>	
using namespace std;
void rek(int * t,int size,bool hasremoved,int pos, long long generated,int genlength)
{

	if (pos > size)
	{
		return;
	}
	if (pos == size && hasremoved)
	{
		bool isprime = true;
		if (generated == 2)
		{
			isprime = true;
		}
		else if (generated == 1 || generated%2==0)
		{
			isprime = false;
		}
		else
		{
			for (long long i = 3; i*i < generated && isprime; i=i+2)
			{
				if (i*(generated / i) == generated)
					isprime = false;
			}
		}
		if (isprime)
		{
			cout << generated<<endl;
		}
		else
		{
			return;
		}
	}
	rek(t, size, hasremoved, pos + 1, t[pos] * pow(10, genlength) + generated, genlength + 1);
	rek(t, size, true, pos + 1,generated, genlength);
	return;
}
int main()
{
	long long n,tn;
	cin >> n;
	tn = n;
	int size = 0;
	while (tn > 0)
	{
		size++;
		tn /= 10;
	}
	int * t = new int[size];
	tn = n;
	for (int i = 0; i < size; i++)
	{
		t[i] = tn % 10;
		tn /= 10;
	}
	rek(t, size, false, 0,0,0);
    return 0;
}

