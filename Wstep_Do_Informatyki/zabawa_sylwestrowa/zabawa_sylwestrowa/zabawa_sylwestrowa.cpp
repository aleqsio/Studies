// zabawa_sylwestrowa.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <string>
#include <iostream>
using namespace std;
struct node {
	string name;
	node * previous = NULL;
	node * next = NULL;
};
struct train {
	string name="";
	node * first=NULL;
};
int last_found_id;
string p1,p2;
train ** trains;
train * f_find(string name)//trainname
{
	train * newspot = NULL;
	int i = 0;
	while (newspot == NULL)
	{
		if (trains[i] != NULL && trains[i]->name==name)
		{
			newspot = trains[i];
			last_found_id = i;
		}
		if (i >= 20)
			return NULL;
		i++;
	}
	return newspot;
}
train * f_new(string name)
{
	train * newspot = NULL;
	int i = 0;
	while (newspot == NULL)
	{
		if (trains[i] == NULL)
		{
			train * t = new train;
			trains[i] = t;
			t->name = name;
			newspot = t;
		}
		if (i >= 20)
			return NULL;
		i++;
	}
	return newspot;
}
node * f_getlastperson(train * t)
{
	node * p = t->first;
	while (p != NULL && p->next != NULL) //in case train exists but doesn't contain any nodes, theoretically impossible
	{
		p = p->next;
	}
	return p;
}
void f_createlink(node * prev, node * next)
{
	prev->next = next;
	next->previous = prev;
}
node * f_generateperson(string name)
{
	node * new_person = new node;
	new_person->name = name;
	return new_person;
}
void f_clean_links(node *&person)
{
	person->previous = NULL;
	person->next = NULL;
}
node * f_front(node * new_person, train * c_train)
{
	node* last_first_person = c_train->first;
	if(last_first_person!=NULL)
	f_createlink(new_person, last_first_person);
	c_train->first = new_person;
	return new_person;
}
void f_reverse(train * c_train)
{
	node * p = c_train->first;
	node * tmp=NULL;
 	while (p != NULL)
	{
		tmp = p->next;
		p->next = p->previous;
		p->previous = tmp;
		tmp = p;
		p = p->previous;
	}
	if(tmp!=NULL)
	c_train->first = tmp;
}
void i_reverse(string name)
{
	f_reverse(f_find(name));
}
void f_back(string name, train * c_train) //node return not implemented
{
	f_createlink(f_getlastperson(c_train), f_generateperson(name));
}
void f_print(train *c_train)
{
	cout << "\"" << c_train->name << "\":"<<endl;
	node * p = c_train->first;
	while (p != NULL)
	{
		cout << p->name;
		p = p->next;
		if (p != NULL)
			cout<< "<-";
	}
	cout << endl;
}
void i_back(string train, string name)
{
	f_back(name, f_find(train));
}
void i_print(string name)
{
	f_print(f_find(name));
}
void i_new(string trainname, string person)
{
	train * t = f_new(trainname);
	f_front(f_generateperson(person), t);
}
void i_front(string train, string name)
{
	f_front(f_generateperson(name), f_find(train));
}
void f_instantiate(int max_size)
{
	trains = new train*[20];
	for (int i = 0; i < 20; i++)
	{
		trains[i] = NULL;
	}
}
void f_delete_train(train *c_train)
{
	f_find(c_train->name);
	delete c_train;
	trains[last_found_id] = NULL;
}
void f_union(train *remaining,train *joining)
{
	f_createlink(f_getlastperson(remaining), joining->first);
	f_delete_train(joining);
}
void f_delfront(string newtrainname, train * decreasing)
{
	node * person = decreasing->first;
	decreasing->first = person->next;
	if (person->next != NULL)
	{
		person->previous = NULL;
	}
	else
	{
		f_delete_train(decreasing);
	}
	f_clean_links(person);

	f_front(person, f_new(newtrainname));
}

void f_delback(train * decreasing, string newtrainname)
{
	node * person = f_getlastperson(decreasing);
	if (person->previous != NULL)
	{
		person->previous->next = NULL;
	}
	else
	{
		f_delete_train(decreasing);
	}
	f_clean_links(person);
	
	f_front(person, f_new(newtrainname));
}
void i_union(string t1, string t2)
{
	f_union(f_find(t1), f_find(t2));
}
void i_delfront( string newtrain, string decr_train)
{
	f_delfront(newtrain, f_find(decr_train));
}
void i_delback( string decr_train, string newtrain)
{
	f_delback(f_find(decr_train),newtrain);
}
void f_read(bool readtwo)
{
	cin >> p1;
	if (readtwo)
		cin >> p2;
}
void f_parse(string cmd)
{
	if (cmd == "NEW")
	{
		f_read(true);
		i_new(p1, p2);
	}
	else if (cmd == "BACK")
	{
		f_read(true);
		i_back(p1, p2);
	}
	else if (cmd == "FRONT")
	{
		f_read(true);
		i_front(p1, p2);
	}
	else if (cmd == "PRINT")
	{
		f_read(false);
		i_print(p1);
	}
	else if (cmd == "REVERSE")
	{
		f_read(false);
		i_reverse(p1);
	}
	else if (cmd == "UNION")
	{
		f_read(true);
		i_union(p1, p2);
	}
	else if (cmd == "DELFRONT")
	{
		f_read(true);
		i_delfront(p1, p2);
	}
	else if (cmd == "DELBACK")
	{

		f_read(true);
		i_delback(p1, p2);
	}
}
int main()
{
	long reps, orders;
	string cmd;

	f_instantiate(20);
	cin >> reps;
	for (long i = 0; i < reps; i++)
	{
		cin >> orders;
		for (long  j= 0; j < orders; j++)
		{
			cin >> cmd;
			f_parse(cmd);
		}
	}
	cin >> p1;
    return 0;
}

