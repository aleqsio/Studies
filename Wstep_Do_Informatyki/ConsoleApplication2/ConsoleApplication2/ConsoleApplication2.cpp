// ConsoleApplication2.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
using namespace std;
#include <stdio.h>
#include <iostream>

int main()
{

	int i = 1;
	int i_shadow = 0;
	for(int c=1;i>i_shadow;c++)
	{
		i_shadow = i;
		i = i * 2;
		cout << c;
	}

}
