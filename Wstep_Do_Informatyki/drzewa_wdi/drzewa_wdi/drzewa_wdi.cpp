//graf ACYKLICZNY, z KORZENIEM
//HOMEWORK policz liczbê wezlow
//drzewo bst
//dwa plusy
#include "stdafx.h"
#include <iostream>
using namespace std;
struct node {
	//nie u¿ywa siê wskaznika na ojca w celu optymalizacji zuzycia pamiêci
	node*left=NULL;
	node* right = NULL;
	int value=0;
};
void printout(node * root) //wypisz zawartoœæ drzewa
{
	if (root == NULL)
		return;
	printout(root->left);
	printout(root->right);
	cout << root->value;
}
void printout2(node * root) //wypisz zawartoœæ drzewa, lepsze poniewa¿ ogranicza liczbê wywo³añ funkcji na ostatnim poziomie
{
	if (root->left == NULL)
	printout2(root->left);
	if (root->right == NULL)
	printout2(root->right);
	cout << root->value;
}
int max(int i, int j)
{
	if (i < j)
		return j;
	return i;
}

int countofnodes_at_nth_level(node * root,int level)
{
	if (root == NULL)
		return 0;
	if (level==1)
		return 1;
	return countofnodes_at_nth_level(root->left,level-1) + countofnodes_at_nth_level(root->right,level-1);
}
int countofleaves()//lisc ma oba nulle
{

}
int depth(node * root)
{
	int i = 1;
	int j=1;
	if (root->left != NULL)
		i = depth(root->left) + 1;
	if (root->right != NULL)
		j = depth(root->right) + 1;
	return max(i, j);

}
int count(node * root) //wypisz zawartoœæ drzewa, lepsze poniewa¿ ogranicza liczbê wywo³añ funkcji na ostatnim poziomie
{
	int i = 1;
	if (root->left == NULL)
		i+=count(root->left);
	if (root->right == NULL)
		i+=count(root->right);
	return i;
}
int main()
{
    return 0;
}

