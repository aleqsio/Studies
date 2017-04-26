// scalanieseriinaturalnych.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
void mergesort(int t[], int n)
{
	bool b = true;
	while (b)
	{
		b = false;
		int b1 = 0;
		int b2 = 0;
		int b3 = 0;
		while (b3 < n)
		{
			b2 = series(t, n, b1);
			if (b2 == n)
			{
				break;
			}
			b3 = series(t, n, b2);
			b = true;
			mergetwo(t, b1, b2, b3);
			b1 = b3;
		}
	}
}
int series(int t[], int n,int begin)//zwracamy numer nastêpnego
{
	
}
void mergetwo(int t[], int b1, int b2, int b3)//b1=pocz¹tek 1szej	b2-pocz¹tek 2ej	b3-koniec 3 +1		//funkcja scalaj¹ca dwie tablice
{

}
int main()
{
    return 0;
}

