// Sudokusolver.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
using namespace std;
bool ispossible(int x, int y, int value);
bool tryplacing(int,int);
void parseinput();
int sudoku[9][9];
void returnoutput();
int main()
{
	parseinput();
	tryplacing(0,0);
	returnoutput();
	return 0;
}
void returnoutput()
{
	for (int i = 0; i < 9; i++)
	{
		for (int j = 0; j < 9; j++)
		{
			cout << sudoku[j][i] << " ";
		}
		cout << endl;
	}
}
bool ispossible(int x, int y, int val)
{
	bool possible = true;
	for (int i = 0; i < 9&&possible; i++)
	{
		possible = sudoku[x][i] != val;
	}
	for (int i = 0; i < 9 && possible; i++)
	{
		possible = sudoku[i][y] != val;
	}
	for (int px = (x / 3) * 3; px < (x / 3 + 1) * 3&&possible; px++)
	{
		for (int py = (y / 3) * 3; py < (y / 3 + 1) * 3 && possible; py++)
		{
			possible = sudoku[px][py] != val;
		}
	}
	return possible;
}
bool tryplacing(int x,int y)
{
	if (y == 9)
	{
		return true;
	}
	bool success = false;
	if (sudoku[x][y] == 0)
	{
		for (int w = 1; w <= 9 && !success; w++)
		{
			if (ispossible(x, y, w))
			{
				sudoku[x][y] = w;
				success = tryplacing((1 + x + y * 9) % 9, (1 + x + y * 9) / 9);
				if (!success)
				sudoku[x][y] = 0;
			}
		}
	}else
	{
		success = tryplacing((1 + x + y * 9) % 9, (1 + x + y * 9) / 9);
	}
	if (success)
	return true;
	return false;
}
void parseinput()
{
	for (int i = 0; i < 9; i++)
	{
		for (int j = 0; j <9; j++)
		{
			cin >> sudoku[j][i];
		}
	}
}
