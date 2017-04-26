#include "stdafx.h"

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;
double value(double x);
void divide(double p, double q);
double coeff[10];
double breakpt;
double e = 2.7182818284;
int main() {
	double p, q;
	cin >> p >> q;
	breakpt = 1 / pow(10, 9);
	for (int i = 0; i < 10; i++)
	{
		cin >> coeff[i];
	}
	divide(p, q);
}
void divide(double p, double q)
{
	double middle = p / 2 + q / 2;
	if (value(p) == 0)
	{
		cout << p;
		return;
	}
	if (value(q) == 0)
	{
		cout << q;
		return;
	}
	if (value(middle) == 0)
	{
		cout << middle;
		return;
	}
	if (value(middle - breakpt)*value(middle) <= 0 || value(middle + breakpt)*value(middle) <= 0)
	{
		cout << middle;
		return;
	}
	if ((value(middle)<0 && value(p) > 0) || (value(middle)>0 && value(p) < 0))
		divide(p, middle);
	else
		divide(middle, q);
}
double value(double x)
{
	return coeff[0] * sin(coeff[1] * x + coeff[2]) + coeff[3] * pow(e, coeff[4] * x + coeff[5]) + coeff[6] * abs(coeff[7] * x + coeff[8]) + coeff[9];
}