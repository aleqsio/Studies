// Hanoi.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
using namespace std;
void hanoi(int, char, char, char);
int main()
{
	int sizehanoi;
	cin >> sizehanoi;
	hanoi(sizehanoi, 'A','B','C');
    return 0;
}
void hanoi(int pieces, char S, char B, char T)
{
	if (pieces == 1)
	{
		cout << S << "->" << T<<endl;
		return;
	}
	hanoi(pieces - 1, S, T, B);
	hanoi(1, S, B, T);
	hanoi(pieces - 1, B, S, T);
	return;
}

