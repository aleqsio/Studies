// skokpotablicy.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <time.h>
using namespace std;
const int max = 100;
bool isprime(int n)
{
	for (int i = 2; i*i <= n; i = i + 1)
	{
		if (i*(n / i) == n)
		{
			return false;
		}
	}
	return true;
}
bool skocz(int * t,int p,int s)
{
	if (p >= max - 1)
	{
		if (p == max - 1)
		{
			cout << s;
			return true;
		}
		return false;
	}
	bool success = false;
	for (int i = 3; i <= t[p]&&!success; i=i+2)
	{
		if (i*(t[p] / i) == t[p] && isprime(i))
		{
			success = skocz(t, p + i,s+1);
		}
	}
	return success;
}
	
int main()
{
	int t[100];
	srand(time(0));
	for (int i = 0; i < 100; i++)
	{
		t[i] = rand() % 99 + 2;
	}
	if (!skocz(t, 0, 0))
		cout << -1;
    return 0;
}

