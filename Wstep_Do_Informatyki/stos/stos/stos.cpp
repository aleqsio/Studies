#include "stdafx.h"
#include <iostream>
#include <string>
using namespace std;
struct node
{
	node * next = NULL;
	int val = 0;
};
void push(node * headnode, int val)
{
	node * obj = new node;
	obj->val = val;
	if (headnode->next == NULL)
	{
		headnode->next = obj;
		return;
	}
	node * tmp = headnode->next;
	headnode->next = obj;
	obj->next = tmp;
	return;
}

bool top(node * headnode,int &res)
{
	if (headnode->next == NULL)
		return false;
	res = headnode->next->val;
	return true;
}
void pop(node * headnode)
{
	if (headnode->next != NULL)
	{
		if (headnode->next->next == NULL)
		{
			delete headnode->next;
			headnode->next = NULL;
		}
		else
		{
			delete headnode->next;
			node * tmp = headnode->next->next;
			headnode->next = tmp;
		}
	}
		return;
}

int main()
{
	long z;
	cin >> z;
	string op;
	int val;
	node * headnode = new node();
	for (long i = 0; i < z; i++)
	{
		cin >> op;
		if (op == "POP")
			pop(headnode);
		if (op == "TOP")
		{
			int result = 0;
			if (top(headnode, result))
				cout << result << endl;
			else
				cout << "EMPTY" << endl;
		}
		if (op == "PUSH")
		{
			cin >> val;
			push(headnode, val);
		}


	}
	return 0;
}

