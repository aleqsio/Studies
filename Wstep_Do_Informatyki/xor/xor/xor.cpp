
#include "stdafx.h"
#include <iostream>
using namespace std;
struct node
{
	int w;
	node *next;

};
node *create(node *first, int a) {
	first = new node;
	cin >> first->w;
	first->next = NULL;
	node *last = first;
	for (int i = 0; i<a; i++) {
		first->next = new node;
		first = first->next;
		cin >> first->w;
		first->next = NULL;
	}
	return last;
}

node *ksor(node *l1, node *l2) {
	node *first = NULL;
	node *w = new node;
	first = w;
	while (l1 != NULL && l2 != NULL) {
		if (l1->w<l2->w) {
			first->next = l1;
			l1 = l1->next;
			first = first->next;
		}
		if (l1!=NULL && l2!=NULL && l2->w<l1->w) {
			first->next = l2;
			l2 = l2->next;
			first = first->next;
		}
		if (l1 != NULL && l2 != NULL && l2->w == l1->w) {
			l1 = l1->next;
			l2 = l2->next;
		}
	}
	if (l1 != NULL) {
		first->next = l1;
	}
	if (l2 != NULL) {
		first->next = l2;
	}
	first->next = NULL;
	first = w->next;
	delete w;
	return first;
}
int main() {
	int a;
	node *l1=NULL;
	node *l2=NULL;
	cout << "dlugosc pierwszej listy " << endl;
	cin >> a;
	l1 = create(l1, a - 1);
	cout << "dlugosc drugiej listy " << endl;
	cin >> a;
	l2 = create(l2, a - 1);
	l1 = ksor(l1, l2);
	cout << "wypisuje liste" << endl;
	while (l1 != NULL) {
		cout << l1->w << endl;
		l1 = l1->next;
	}

}