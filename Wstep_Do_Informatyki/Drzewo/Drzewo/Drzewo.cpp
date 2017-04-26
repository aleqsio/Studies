// Drzewo.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
using namespace std;
struct node {
	node* right;
	node* left;
	node* prt;
	int val;
};

node* nast(node* curr)
{
	if (curr == NULL) return NULL;
	if (curr->right != NULL) return nast(curr->right);
	while (curr->prt != NULL && curr->prt->right == curr)  //ewaluowanie leniwe
	{
		curr = curr->prt;
	}
	if (curr->prt == NULL) return NULL;
	return curr->prt;
}
node* remove(node *root, int val)
{
	if (root == NULL) return NULL;
	if (root->val < val) root->right = remove(root->right,val);
	else  root->left = remove(root->left, val);
		if (root->val == val)
		{
			if (root->left == NULL && root->right == NULL)
			{
				delete root;
				return NULL;
			}
			if (root->left == NULL)
			{
				root->prt = root->right;
				root->prt = root->right;
				node*
			}
		}
}
node*search(node*root, int val)
{
	if (root == NULL) return NULL;
	if (val == root->val)
	return root;
	if (val > root->val)
		return search(root->right,val);
	else
		return search(root->left,val);

}
node*wstaw(node* root, int val)
{
	node* parent = root;
	node* prev_parent = NULL;
	bool left = false;
	while (parent != NULL)
	{
		if (parent->val < val)
		{
			prev_parent = parent;
			parent = parent->right;
			left = false;
		}
		else
		{
			prev_parent = parent;
			parent = parent->left;
				left = true;
		}
	}
	node*inserted = new node;
	inserted->val = val;
	if (prev_parent != NULL) {
		if (left) {
			prev_parent = NULL;
		}
	}
}

bool test(int a)
{
	cout << "WTF"<<a;
	return true;
}
int main()
{
}
