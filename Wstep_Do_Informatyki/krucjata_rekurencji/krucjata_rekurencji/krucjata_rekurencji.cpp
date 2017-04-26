

#include "stdafx.h"
#include <string>
#include <iostream>
using namespace std;
struct waga;
waga zmniejsz(waga pozostale, char litera);
bool wyraz_rek(string s2, string gen, waga pozostale, int pos);
struct waga
{
	int s_vovels = 0;
	int s_asci = 0;
};
bool wyraz(string s1, string s2)
{
	waga s1waga;
	for (int i = 0; i < s1.length(); i++)
	{
		s1waga=zmniejsz(s1waga, s1[i]);
	}
	s1waga.s_asci *= (-1);
	s1waga.s_vovels *= (-1);
	return wyraz_rek(s2, "", s1waga, 0);
}
waga zmniejsz(waga pozostale, char litera)
{
	switch (litera)
	{
	case 'a':
	case 'e':
	case 'i':
	case 'o':
	case 'u':
	case 'y':
		pozostale.s_vovels--;
		break;
	}
	pozostale.s_asci -= int(litera);
	return pozostale;
}
bool wyraz_rek(string s2, string gen, waga pozostale, int pos)
{
	if (pos == s2.length())
	{
		return false;
	}
	if (pozostale.s_vovels == 0 && pozostale.s_asci == 0)
	{
		//cout << gen;
		return true;
	}
	if (pozostale.s_vovels < 0 || pozostale.s_asci < 0)
	{
		return false;
	}
	return wyraz_rek(s2, gen + s2[pos], zmniejsz(pozostale, s2[pos]), pos + 1) || wyraz_rek(s2, gen, pozostale, pos + 1);
}
int main()
{
	string s1, s2;
	cin >> s1 >> s2;
	if (wyraz(s1, s2))
	{
		cout << "TAK";
	}
	else
	{
		cout << "NIE";
	}

	return 0;
}

