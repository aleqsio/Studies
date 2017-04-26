// cwiczenia6.cpp : Defines the entry point for the console application.
//			

#include "stdafx.h"
/*
stack s1,s2;
push(x)
pop(x)
isEmpty()

enqueue(x)
{
s1.push(x)
if(s2.isEmpty())
{
while(s1.isEmpty()){
s2.push(s1,pop());
}
przesuniêcie tablicy o 3
zamiana czêsci, zamiana 

który element w drzewie kolejnoœci
*/

struct BSTNode
{
	BSTNode* prt;
	BSTNode* left;
	BSTNode* right;
	int left_count;
	int key;
};
BSTNode* BSTInsert(BSTNode* root, BSTNode* n)
{
	if (root == NULL)
	{
		return n;
	}
	BSTNode* p,* q;
	q = root;
	while (q != NULL)
	{
		p = q;
		if (n->key>q->key)
			q = q->right;
		else
			q = q->left;
	}
	if (n->key > p->key)
		p->right = n;
	else
		p->left = n;
	n->prt = p;
	return root;
}
BSTNode* maximum(BSTNode*root)
{
	while (root->right != NULL)
		root = root->right;
	return root;
}
BSTNode* minimum(BSTNode*root)
{
	while (root->left != NULL)
		root = root->left;
	return root;
}
BSTNode* successor(BSTNode*n)
{
	if (n->right != NULL)
		return minimum(n->right);
	BSTNode* p = n->prt;
	while (p != NULL)
	{
		if (p->key > n->key) return p;
		p = p->prt;
	}
	return NULL;
}
BSTNode* searchbyrank(BSTNode* root, int rank)
{
	if (root->left_count >= rank)
		return searchbyrank(root->left, rank);
	if (root->left_count + 1 == rank)	return root;
	return searchbyrank(root->right, rank - root->left_count - 1);
}
int main()
{	

    return 0;
}

