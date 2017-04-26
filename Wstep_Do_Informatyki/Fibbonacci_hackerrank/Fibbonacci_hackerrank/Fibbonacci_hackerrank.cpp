// Fibbonacci_hackerrank.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
	unsigned long long a = 1;
	unsigned long long b = 1;
	int n;
	cin >> n;
	for (int i = 2; i < n; i++)
	{
		a = a + b;
		b = a - b;
	}

	cout << a;
	return 0;
}