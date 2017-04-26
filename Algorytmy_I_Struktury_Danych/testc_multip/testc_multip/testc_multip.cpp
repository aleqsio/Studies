#define _XOPEN_SOURCE
#include <stdlib.h>
#include <stdio.h>
#include "stdafx.h"
int read(char* p)
{
	char c = getchar();
	int i;
	for (i = 0; i<100 && c != EOF; i++)
	{
		p[i] = c;
		c = getchar();
	}
	i--;
	for (int j = i; j < 100; j++)
	{
		p[j] = 0;
	}
	return i != 0;
}
void printchararr(char *p)
{
	for (int i = 0; i < 100; i++)
	{
		printf("%c",p[i]);
	}
}
int main(void)
{
	char n1[100];
	char n2[100];
	printf("Podaj pierwsza liczbe");
	if (read(n1) == 1)  return;;
	printchararr(n1);
	printf("Podaj druga liczbe");
	if (read(n2) == 1) return;
	
	return 0;
}