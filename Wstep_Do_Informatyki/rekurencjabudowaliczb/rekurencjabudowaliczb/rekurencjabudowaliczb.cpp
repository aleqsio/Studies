#include "stdafx.h"
#include <iostream>
using namespace std;

int rek(int d1, int d0)
{
	if (d1 < 0 || d0 <= 0)
		return 0;
	if (d1 == 0 && d0 == 1)
		return 1;
	return rek(d1 - 1, d0) + rek(d1, d0 - 1);
}

int main()
{
	int d1, d0;
	cin >> d1 >> d0;
	cout<< rek(d1 - 1, d0);
    return 0;
}

