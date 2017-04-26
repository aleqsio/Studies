// Liczby_naturalne.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
using namespace std;
int dwojki(int liczba)
{
	int s = 0;
	while (liczba > 0)
	{
		if (liczba % 2 == 1)
			s++;
		liczba /= 2;
	}
	return s;
}
bool rek(int * t,int &len, int suma1, int suma2, int suma3, int pos)
{
	if (pos == len)
	{
		if (suma1 == suma2 && suma2 == suma3)
			return true;
		return false;
	}
	int jedynki = dwojki(t[pos]);
	return rek(t, len, suma1 + jedynki, suma2, suma3, pos + 1) || rek(t, len, suma1, suma2 + jedynki, suma3, pos + 1) || rek(t, len, suma1 , suma2, suma3 + jedynki, pos + 1);
}
int main()
{
	int t[] = { 5,7,15 };
	int n = 3;
	cout<<rek(t, n, 0, 0, 0, 0);
    return 0;
}

