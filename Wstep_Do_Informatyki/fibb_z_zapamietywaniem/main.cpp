using namespace std;
#include <stdio.h>
#include <iostream>
int fib(int tab[],int n)
{
	if(tab[n]!=0)
	{
		return tab[n];
	}
	if(n==1 or n==2)
	{
		tab[2]=1;
		tab[1]=1;
		return 1;
	}
	int r= fib(tab,n-1)+ fib(tab,n-2);
	tab[n]=r;
	return r;
}
int main()
{
	int n;
	cin>>n;
	int tab[n+1];
	for(int i=0;i<n+1;i++)
	{
		tab[i]=0;
	}
	cout<<fib(tab,n);
	return 0;
}
