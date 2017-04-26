// map.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <string>
#include <math.h>
using namespace std;
struct node
{
	node * prt=NULL;
	node * d0=NULL;
	node * d1=NULL;
	string * val=NULL;
};
node * createnode(node * _prt, bool iszero, string _val)
{
	node * obj = new node;
	obj->prt = _prt;
	if (iszero)
		_prt->d0 = obj;
	else	
		_prt->d1 = obj;
	return obj;
}
unsigned long binarise(string key)
{
	unsigned long r=0;
	for (int i = 0; i < 8 && key.length()>i; i++)
	{
		r += pow(256, i)*key[i];
	}
return r;
}
void setstring(string ** str,string val)
{
	if (*str == NULL)
		*str = new string();
	(**str) = val;
}
void set(node * headnode, unsigned long index,string val)
{
	if (index % 2 == 0 && headnode->d0 == NULL)
		createnode(headnode, true, val);
	if (index % 2 == 1 && headnode->d1 == NULL)
		createnode(headnode, false, val);
	if (index == 0)
	{
		setstring(&headnode->val, val);
		return;
	}
	if (index % 2 == 0)
		set(headnode->d0, index / 2, val);
	else
		set(headnode->d1, index / 2, val);
}
void unset(node * headnode, unsigned long index)
{
	if (headnode == NULL)
	{
		return;
	}
	if (index == 0)
	{
		headnode->val = NULL;
		return;
	}
	if (index % 2 == 0)
		unset(headnode->d0, index / 2);
	else
		unset(headnode->d1, index / 2);
}
string get(node * headnode, unsigned long index)
{
	if (index % 2 == 0 && headnode->d0 == NULL)
		return "EMPTY";
	if (index % 2 == 1 && headnode->d1 == NULL)
		return "EMPTY";
	if (index == 0)
	{
		if (headnode->val == NULL)
			return "EMPTY";
		else
			return *headnode->val;
	}
	string s;
	if (index % 2 == 0)
		s=get(headnode->d0, index / 2);
	else
		s=get(headnode->d1, index / 2);
	return s;
}
int main()
{
	long z;
	cin >> z;
	string op, key;
	string val;
	node * headnode = new node;
	for (long i = 0; i < z; i++)
	{
		cin >> op >> key;

		if (op == "UNSET")
			unset(headnode, binarise(key));
		if (op == "GET")
			cout << get(headnode, binarise(key))<<endl;
		if (op == "SET")
		{
			cin >> val;
			set(headnode, binarise(key), val);
		}
		
		
	}
    return 0;
}

