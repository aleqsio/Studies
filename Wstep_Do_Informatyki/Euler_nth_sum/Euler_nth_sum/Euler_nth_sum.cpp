// Euler_nth_sum.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
using namespace std;

long long mypower(int n, int c);
bool mybreak = false;
void rek(int power, int last, long long sum, int pos)
{
	if (mybreak)
		return;
	if (pos == power - 2)
	{
		int c=1;
		long long r = 0;
		while (r < sum)
		{
			c++;
			r = mypower(c, power);
		}
		if (r == sum)
		{
			cout << c;
			mybreak = true;
			return;
		}
	}
	for (int i = 1; i <= last; i++)
	{
		rek(power, last-i, sum + mypower(i, power), pos + 1);
	}
}
long long mypower(int n, int c)
{
	long long r = 1;
	for (int i = 0; i < c; i++)
		r *= n;
	return r;
}
int main()
{
	int power = 5;
	for (int i = 2; i < 300 && !mybreak; i++)
	{
		cout << i << endl;
		rek(power, i, 0, 0);
	}
    return 0;
}

