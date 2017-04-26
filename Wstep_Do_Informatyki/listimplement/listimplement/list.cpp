#include "stdafx.h"
#include "list.h"

struct node {
	node *next=NULL;
	node *prev=NULL;
};
node *guardian;
list::list()
{
	guardian = new node;

}
bool add()