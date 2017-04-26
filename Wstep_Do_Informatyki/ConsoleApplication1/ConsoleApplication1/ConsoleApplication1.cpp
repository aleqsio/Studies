// ConsoleApplication1.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
using namespace std;
#include <stdio.h>
#include <iostream>

int main()
{
	long long a, b, c;
	const long long limit = 4000000;
	a = 1;
	long long sum = 0;
	b = 2;
	while (b<limit)
	{
		if (b % 2 == 0)
		{
			sum += b;
			
		}
		c = a;
		a = b;
		b = c + b;
	}
	cout << sum;
}
