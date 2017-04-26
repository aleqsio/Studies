using namespace std;
#include <stdio.h>
#include <iostream>
#include <cmath>

int main()
{
int a,i;
i=0;
double po,pn,d;
d=0;
cin>>a;
a=a;
pn=a/2;
do
{
	po=pn;
	pn=(po+(a/po))/2;
	cout<<pn<<"\n";
}while(abs(po-pn)>d);
	return 0;
}