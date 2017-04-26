#include "stdafx.h"
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

void parse(string, long *, int *);
void parse_s2(string, bool *);
bool rek(string s, bool*vovarr, int start, int end, long weight, int vovels);
int main() {
	string s1,s2;
	cin >> s1 >> s2;
	bool *vovarr = new bool[s2.length()];
	long weight;
	int vovels;
	parse(s1,&weight,&vovels);
	parse_s2(s2, vovarr);
	if (s2.length() == 1)
	{
		if (s2 == s1)
			cout << "TAK";
		else
			cout << "NIE";
			return 0;

	}
	if(rek(s2, vovarr, 0, s2.length(), weight, vovels))
	{
		cout << "TAK";
	}
	else
	{
		cout << "NIE";
	}
	return 0;
}
bool rek(string s,bool*vovarr,int start, int end, long weight,int vovels)
{
	if (vovels < 0)
		return false;
	if (weight < 0)
		return false;
	if(weight==0&&vovels==0)
		return true;
	if (start > end)
	{
		return false;
	}
	if (weight == 0 && vovels > 0)
	{
		return false;
	}
	
	bool res=false;
	int boolvovarr=0;
		if (vovarr[start])
		{
			boolvovarr = 1;
		}
	res=rek(s, vovarr, start + 1, end, weight - s[start], vovels - boolvovarr);
	
	if (res)
	{
		return true;
	}
	res = rek(s, vovarr, start + 1, end, weight, vovels);
	if (res)
	{
		return true;
	}
	return false;
}
void parse(string s, long *w, int *v)
{
		(*w) = 0;
		(*v) = 0;
	string comp = "aeyiou";
	for (int i = 0; i < s.length(); i++)
	{
		for (int j = 0; j < 6; j++)
		{

			if (s[i] == comp[j])
			{
				(*v)++;
				j = 7;
			}
		}
			
		(*w) += s[i];
	}
}

void parse_s2(string s, bool* vovarr)
{
	string comp = "aeiuoy";
	for (int i = 0; i < s.length(); i++)
	{
		vovarr[i] = false;
		for (int j = 0; j < 6 &&!vovarr[i]; j++)
		{
			if (s[i] == comp[j])
			{
				vovarr[i] = true;
			}
		}
		cout << vovarr[i];
	}
}