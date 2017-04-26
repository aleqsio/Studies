// tablica_punktow.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <cmath>
//MAMY DAN¥ TABLICE PUNKTÓW TRZYWYMIAROWYCH
//LISTE S¥SIADOW PUNKTU STANOWI K NAJBLIZSZYCH W MIERZE EUKLIDESOWEJ PUNKTOW
//PUNKT NIE JEST SWOIM S¥SIADEM
//DWA PUNKTY S¥ MOCNYMI S¥SIADAMI,
//JESZELI ZNAJDUJ¥ SIÊ WZAJEMNIE NA SWOICH LISTACH S¥SIADÓW, NA LISTACH ICH S¥SIADÓW WYSTÊPUJE CONAJMNIEJ N WSPOLNYCH S¥SIADOW
//UWAGA WARTOSCI K I N S¥ PARAMETRAMI ALGORYTMU I PRZYPADKOWO K200 N150
//NAPISZ FUNKCJE KTÓRA WYZNACZY LICZBÊ PUNKTÓW POSIADAJ¥CYCH CO NAJMNIEJ 5 MOCNYCH S¥SIADÓW
//OPRACOWANIE STRUKTUR
//N MINIMÓW
//Mamy tablicê z nazwiskami uporz¹dkowanymi. Chcemy wyszukiwaæ szybciej ni¿ po³ówkowo(utwarzamy pomocnicz¹ tablicê a-z zawieraj¹c¹ pozycje pierwszej litery np: K:159)
static int min_size = 200;
static int required_count = 150;
struct point;
struct point_holder;
struct point_holder {
	point * content = NULL;
	float squared_distance = 0;
	point_holder * next = NULL;
};
struct point {
	float x, y, z;
	point_holder * first_neighbour = NULL;
	point * next = NULL;
};
	float dist(point * p1, point * p2)
	{
		return pow(p1->x - p2->x, 2) + pow(p1->y - p2->y, 2) + pow(p1->z - p2->z, 2);
	}
	point_holder * getpholder(point * pt, float dist)
	{
		point_holder * holder = new point_holder;
		holder->squared_distance = dist;
		holder->content = pt;
		return holder;
	}
	void ins_neighbour(point* curr, point *potential)
	{
		int counter = min_size;
		point_holder * f_neighbour = curr->first_neighbour;
		while (f_neighbour != NULL && f_neighbour->next != NULL && counter > 0 && f_neighbour->next->squared_distance < dist(curr, potential))
		{
			f_neighbour = f_neighbour->next;
		}
		if (f_neighbour == NULL)
		{
			curr->first_neighbour = getpholder(potential, dist(curr, potential));
		}
		else if (f_neighbour->next == NULL)
		{
			f_neighbour->next = getpholder(potential, dist(curr, potential));
		}
		else if (counter > 0)
		{
			point_holder* tmp = f_neighbour->next;
			f_neighbour->next = getpholder(potential, dist(curr, potential));
			f_neighbour->next->next = tmp;
		}
		else
		{
			delete f_neighbour->next;
			f_neighbour->next = NULL;
		}
	}
	        
	bool checkifstrongneighbour(point * p1, point *p2)
	{
		point_holder *i1, *i2;
		i1 = p1->first_neighbour;
		i2 = p2->first_neighbour;
		bool r1 = false;
		bool r2 = false;
		int counter = 0;
		while (i1 != NULL)
		{
			i2 = p2->first_neighbour;
			while (p2 != NULL)
			{
				if (i2->content == p1)
					r1 = true;
				if (i1->content == p2)
					r2 = true;
				if (i2->content == i1->content)
				{
					counter++;
				}
				i2 = i2->next;
			}
			i1 = i1->next;
		}
		return counter > required_count && r1 && r2;
	}
	void callinsforeach(point * pt)
	{
		point *p1, *p2;
		p1 = pt;
		while (p1 != NULL)
		{
			p2 = pt;
			while (p2 != NULL)
			{
				ins_neighbour(p1, p2);
				p2 = p2->next;
			}
			p1 = p1->next;
		}
	}

	int main()
	{
		point * first_point=NULL; //pierwszy punkt listy
		callinsforeach(first_point);
		//populuje pointy pointholderami zawieraj¹cymi s¹siadów
		return 0;
	}



