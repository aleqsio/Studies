// operacjedoliczbypierwszej.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <string>
using namespace std;
bool rek(string s, int v, int op)
{
	if (op == 0)
	{
		return false;
	}
	
	bool isprime = v%2;
	for (int i = 3; i*i <= v && isprime; i = i + 2)
	{
		if ((v / i)*i == v)
			isprime = false;
	}
	if (v == 2)
	{
		isprime = true;
	}
	if (v == 1)
	{
		isprime = false;
	}
	if (isprime)
	{
		cout << s;
		return true;
	}
	int tmpv = v;
	int dlast = tmpv % 10;
	tmpv /= 10;
	int dsecond = tmpv % 10;
	tmpv /= 10;
	int vswap = tmpv * 100 + dlast * 10 + dsecond;
	return rek(s + "A", v + 3, op - 1) || rek(s + "B", 2 * v, op - 1) || rek(s + "C", vswap, op - 1);
}

int main()
{
	rek("", 16, 10);
    return 0;
}

