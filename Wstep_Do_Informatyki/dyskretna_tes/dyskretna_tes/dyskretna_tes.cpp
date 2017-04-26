// dyskretna_tes.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
using namespace std;
int main()
{
	int ts=0;
	for (long i = 1000000; i <= 9999999; i=i+2)
	{
		long ti = i;
		long s = 0;
		int hasbeen[2];
		for (int t = 0; t < 2; t++)
		{
			hasbeen[t] = 0;
		}
		int read = 0;
		while (ti>0)
		{
			read = ti % 10;
			ti /= 10;
			if (read ==0)
			{
				hasbeen[0]++;
				
			}
			if (read == 1)
			{
				hasbeen[1]++;
			}
		}
		if (hasbeen[0]==1 && hasbeen[1]==1)
		{

			//cout << i<<endl;
			ts++;
		}
	}
	cout << ts;
    return 0;
}

